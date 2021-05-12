// Simulation of the Hertz airport shuttle bus, which picks up passengers
// from the airport terminal building going to the Hertz rental car lot.

#include <iostream>
#include "cpp.h"
#include <cstring>
using namespace std;

#define NUM_SEATS 6      // number of seats available on shuttle
#define TINY 1.e-20      // a very small time period
// named constants for labelling event set
#define CARLOT 0

int terminals = 1;
int mean = 10;
facility_set *buttons;  // customer queues at each stop
facility rest ("rest");           // dummy facility indicating an idle shuttle

event get_off_now("get_off_now");  // all customers can get off shuttle

event_set *hop_on;  // invite one customer to board at this stop
event boarded ("boarded");             // one customer responds after taking a seat

event_set *shuttle_called; // call buttons at each location

void make_passengers(long whereami, int mean);       // passenger generator
string places[2] = {"Terminal", "CarLot"}; // where to generate
long group_size();

void passenger(long whoami, long wheretogo);                // passenger trajectory
string people[2] = {"arr_cust","dep_cust"}; // who was generated

void shuttle();                  // trajectory of the shuttle bus consists of...
void loop_around_airport(long & seats_used, long route);      // ... repeated trips around airport
void load_shuttle(long whereami, long & on_board); // posssibly loading passengers
qtable shuttle_occ("bus occupancy");  // time average of how full is the bus

extern "C" void sim(int argc, char* argv[])      // main process
{ 
  if(argc == 2)
  {
    terminals = atoi(argv[1]);
  }
  if(argc == 3)
  {
    terminals = atoi(argv[1]);
    mean = atoi(argv[2]);
  }
  buttons = new facility_set("Curb", terminals + 1);
  hop_on = new event_set("Board Shuttle", terminals + 1);
  shuttle_called = new event_set("route call", terminals+1);
  create("sim");
  shuttle_occ.add_histogram(NUM_SEATS+1,0,NUM_SEATS);

  for(int i=0; i<=terminals; i++)
  {
   make_passengers(i, mean);
  }
  shuttle();                // create a single shuttle
  hold (1440);              // wait for a whole day (in minutes) to pass
  report();
  status_facilities();
}

// Model segment 1: generate groups of new passengers at specified location

void make_passengers(long whereami, int mean)
{
  if(whereami >=1)
  {
   const char* myName=places[1].c_str(); // hack because CSIM wants a char*
   create(myName);
  }
  else
  {
   const char* myName=places[0].c_str();
   create(myName);
  }
  while(clock < 1440.)          // run for one day (in minutes)
  {
    hold(expntl(mean/terminals));           // exponential interarrivals, mean 10 minutes
    long group = group_size();
    long wheretogo;
    if(whereami)               //if the passenger is not from the CARLOT
    {
      wheretogo = CARLOT;
    }
    else
    {
      wheretogo = uniform(1, terminals);
    }
    for (long i=0;i<group;i++)  // create each member of the group
      passenger(whereami, wheretogo);      // new passenger appears at this location
  }
}

// Model segment 2: activities followed by an individual passenger

void passenger(long whoami, long wheretogo)
{
  if(whoami >=1)
  {
  const char* myName=people[1].c_str(); // hack because CSIM wants a char*
  create(myName);
  }
  else
  {
   const char* myName=people[0].c_str();
   create(myName); 
  }
  
  if(whoami)
  {
  (*buttons)[whoami].reserve();     // join the queue at my starting location
  (*shuttle_called)[whoami].set();  // head of queue, so call shuttle
  (*hop_on)[whoami].queue();        // wait for shuttle and invitation to board
  (*shuttle_called)[whoami].clear();// cancel my call; next in line will push 
  hold(uniform(0.5,1.0));        // takes time to get seated
  boarded.set();                 // tell driver you are in your seat
  (*buttons)[whoami].release();     // let next person (if any) access button
  get_off_now.wait();            // everybody off when shuttle reaches next stop
  }
  else
  {
   (*buttons)[whoami].reserve();     // join the queue at my starting location
  (*shuttle_called)[wheretogo].set();  // head of queue, so call shuttle
  (*hop_on)[whoami].queue();        // wait for shuttle and invitation to board
  (*shuttle_called)[wheretogo].clear();// cancel my call; next in line will push 
  hold(uniform(0.5,1.0));        // takes time to get seated
  boarded.set();                 // tell driver you are in your seat
  (*buttons)[whoami].release();     // let next person (if any) access button
  get_off_now.wait();            // everybody off when shuttle reaches next stop
  }
}

// Model segment 3: the shuttle bus

void shuttle() {
  create ("shuttle");
  while(1) {  // loop forever
    // start off in idle state, waiting for the first call...
    rest.reserve();                   // relax at garage till called from somewhere
    long who_pushed = shuttle_called->wait_any();
    (*shuttle_called)[who_pushed].set(); // loop exit needs to see event
    rest.release();                   // and back to work we go!

    long seats_used = 0;              // shuttle is initially empty
    shuttle_occ.note_value(seats_used);

    hold(2);  // 2 minutes to reach car lot stop
    int route = 0;
    // Keep going around the loop until there are no calls waiting
    for(int i=1; i<=terminals; i++)
    {
       if((*shuttle_called)[i].state()==OCC)
       {
        route = i;
        break;
       }
       route = 0;
    }
    if(route > 0)
    {
      loop_around_airport(seats_used, route);
    }
  }
}

long group_size() {  // calculates the number of passengers in a group
  double x = prob();
  if (x < 0.3) return 1;
  else {
    if (x < 0.7) return 2;
    else return 5;
  }
}

void loop_around_airport(long & seats_used, long route) { // one trip around the airport
  // Start by picking up departing passengers at car lot
  load_shuttle(CARLOT, seats_used);
  shuttle_occ.note_value(seats_used);

  hold (uniform(3,5));  // drive to airport terminal
  
  // drop off all departing passengers at airport terminal
  if(seats_used > 0) {
    get_off_now.set(); // open door and let them off
    seats_used = 0;
    shuttle_occ.note_value(seats_used);
  }

  // pick up arriving passengers at airport terminal
  load_shuttle(route, seats_used);
  shuttle_occ.note_value(seats_used);

  hold (uniform(3,5));  // drive to Hertz car lot

  // drop off all arriving passengers at car lot
  if(seats_used > 0) {
    get_off_now.set(); // open door and let them off
    seats_used = 0;
    shuttle_occ.note_value(seats_used);
  }
  // Back to starting point. Bus is empty. Maybe I can rest...*/

}

void load_shuttle(long whereami, long & on_board)  // manage passenger loading
{
  // invite passengers to enter, one at a time, until all seats are full
  while((on_board < NUM_SEATS) &&
    ((*buttons)[whereami].num_busy() + (*buttons)[whereami].qlength() > 0))
  {
    (*hop_on)[whereami].set();// invite one person to board
    boarded.wait();  // pause until that person is seated
    on_board++;
    hold(TINY);  // let next passenger (if any) reset the button
  }
}

