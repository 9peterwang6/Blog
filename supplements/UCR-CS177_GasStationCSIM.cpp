#include<iostream>
#include"cpp.h"
using namespace std;

// This program simulates a gas station.
// It rewrites the gas station model example
// previously mentioned in lecture 2 in CSIM.

facility_ms *pumps;

double serviceTime(int litres)
{
	double howLong = -6;
	
	for(int i =1; i<=12; i++)
	{
		howLong += uniform(0,1);
	}
	return 150 + 0.5 * litres + 30 * howLong;
}

void car()
{
	int litres = uniform(10,60);
	create("car");
	/* 
		The following lines of code were the original version
		submitted for grading. I don't think it takes into
		account the cars that are waiting when the pumps are
		all occupied.
		if(pumps->status() == BUSY)
		{
			double prob = (40 + litres)/(25*(3+pumps->qlength()));
			double balk = uniform(0,1);
			if(balk <= prob)
			{
				pumps->reserve();
			}
		}
		else
		{
			pumps->reserve();
			hold(serviceTime(litres));
			pumps->release();
		}
	*/
	// The following lines of code is a rewrite that I think
	// takes into account the waiting cars.
	int decideToBalk = 0;
	if(pumps->status() == BUSY)
	{
		double prob = (40 + litres)/(25*(3+pumps->qlength()));
		double balk = uniform(0,1);
		if(balk > prob) decideToBalk = 1;
	}
	if(decideToBalk > 0)
	{
		pumps->reserve();
		hold(serviceTime(litres));
		pumps->release();
		// the above lines of code can be replaced
		// by "pumps->use(serviceTime(litres));"
	}
}

extern "C" void sim()
{
	int end_time;
	int num_pumps;
	cout<<"please input the simulation time:"<<endl;
	cin>>end_time;
	cout<<"please input the number of pumps:"<<endl;
	cin>>num_pumps;
	pumps = new facility_ms("pumps", num_pumps);
	create("simulation");
	while(simtime()<end_time)
	{
		hold(exponential(50));
		car();
	}
	report();
	/*
		Here is the description of the columns in the report:
		"service disc" = service discipline (usually "first-come first-served", but the last one in the manual is "round robin")
		"service time" = average service time
		"util." = average  utilization, the fraction of time the facility is BUSY (reserved by a customer) rather than FREE (at least one member is not reserved)
		"throughput" = average number of customers served per unit time
		"queue length" = average number of customers waiting for access
		"response time" = average time between arrival and departure, includes waiting in the queue and time being served
		"compl  count" = total number of customer completions (aka departures). Does NOT count customers waiting in the queue or still being served when report is generated
	*/
}
