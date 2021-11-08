// This is a simple program demonstrating how CSIM package works.
// The program simulates a barber where Joe is the barber.
// In the barber shop there are 3 extra chairs for people to wait
// if Joe is busy. The customers come in every (12, 24) minutes.
// The total simulation time is 480 minutes, which constitutes
// Joe's one working day.

// This program actually rewrites a piece of GPSS sample code in CSIM
// The sample code can be found at https://en.wikipedia.org/wiki/GPSS#Sample_code

#include<iostream>
#include"cpp.h" // CSIM's header file
using namespace std;

facility joe("barber"); // A facility is like a lock/binary semaphore.
facility_ms chairs("chairs", 3); // A facility_ms is a counting semaphore, in this case "3" is the queue size.

void customer()
{
	create("customer"); // You need to use create() to separate your model from the main process.
	chairs.reserve(); // If there is no chair left, it will get blocked until there is a chair available.
	cout<<"a customer has come"<<endl;
	joe.reserve();
	cout<<"having hair cut"<<endl;
	chairs.release();
	hold(uniform(12,20)); // Advance the simulation clock.
	joe.release();
	cout<<"finished"<<endl;
}

// sim() is the main process of the simulation program
// which starts a chunk scheduler. Chunk scheduler schedules
// your processes to run and makes sure that your model will
// execute one process at a time.
extern "C" void sim()
{
	create("sim");
	while(simtime() < 480)
	{
		hold(uniform(12,24));
		customer();
	}
}
