#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>
#include "Bridge.cpp"





class Car 
{

int id; // id
double inter_arrival_t; // inter-arrival time between this vehicle and next
int dir; // heading direction
public:
	Car(int, double, int);
	void ArriveBridge();
	void CrossBridge();
	void ExitBridge();
	
	pthread_t carPThread;

}; // end Car class

// start Car Constructor

Car::Car(int carid, double arrival_time, int direction)
{
	id = carid;
	inter_arrival_t = arrival_time;
	dir = direction;
}

void *carPThread(void *arg)
{
	myret_t *r = malloc(sizeof(myret_t))
	return (void *) r;
}


void Car::ArriveBridge()
{

}

void Car::CrossBridge()
{

}

void Car::ExitBridge()
{

}
