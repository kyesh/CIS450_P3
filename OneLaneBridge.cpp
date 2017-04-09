#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>



typedef struct __cararg_t {
	int carid;
	double arrival_time;
	int direction;
} cararg_t;

typedef struct __carReturn_t {
	double finish_time;
} carReturn_t;

// too lazy to do file includes / header files - Cris

class Bridge
{
	public: int state;
	/*
	state / 2 = count of cars currently on bridge
	state % 2 = direction of bridge
	North = 1
	South = 0
	*/
};


class Car 
{

public:

int carid; // id
double arrival_time; // inter-arrival time between this vehicle and next
int direction; // heading direction
public:
	Car(int, double, int);
	void ArriveBridge();
	void CrossBridge();
	void ExitBridge();
	
	pthread_t carPThread;

}; // end Car class


// start Car Constructor
Car::Car(int id, double arrival_t, int dir)
{
	carid = id;
	arrival_time = arrival_t;
	direction = dir;
}


void carPThread(void *arg)
{
	//cararg_t *carArg = (cararg_t *) arg;
	
	//carReturn_t *r = malloc(sizeof(carReturn_t));
	
	return; //(void *) r;
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


int main(int argc, char *argv[]) 
{
	bool FCFS;

	if (argc < 2)
	{
		 // greedy method
		 FCFS = false;
	}
	else
	{
		FCFS = true;
		// FCFS - enable timers
	}

	// North = 1, South = 0
	Car cars[] = { 
		Car(0, 0.0, 1),
		Car(1, 1.0, 1),
		Car(2, 2.0, 0),
		Car(3, 3.0, 0),
		Car(4, 4.0, 0),
		Car(5, 5.0, 1),
		Car(6, 6.0, 1),
		Car(7, 7.0, 0),
		Car(8, 8.0, 0),
		Car(9, 9.0, 1),
		Car(10, 10.0, 1),
		Car(11, 11.0, 1),
		Car(12, 12.0, 1),		
	}; // end cars array
	int sizeOfArray = sizeof(cars)/sizeof(cars[0]);
	for (int i = 0; i < sizeOfArray; ++i)
	{
		cararg_t carArgs;
		carArgs.carid = cars[i].carid;
		carArgs.arrival_time = cars[i].arrival_time;
		carArgs.direction = cars[i].direction;
		
		
		int threadReturn = pthread_create(&cars[i].carPThread, 
		NULL, cars[i].carPThread, &carArgs);
	}

	

	return 0;
} // end main















































// white space for Cris to scroll to
