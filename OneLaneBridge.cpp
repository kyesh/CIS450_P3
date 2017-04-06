#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>
#include "Car.cpp"



typedef struct __cararg_t {
	int carid;
	double arrival_time;
	int direction;
} cararg_t;

typedef struct __carReturn_t {
	double finish_time;
} carReturn_t;


int main(int argc, char *argv[]) {

	
	

	// North = 1, South = 0
	Car cars[] = { 
		Car(0, 0.0, 1),
		Car(1, 1.0, 1),
		Car(2, 2.0, 0),
		Car(3, 3.0, 0),
		Car(4, 4.0, 0)
		
		/*
		{ 0, 0.0, 1 },
		{ 1, 1.0, 1 },
		{ 2, 2.0, 0 },
		{ 3, 3.0, 0 },
		{ 4, 4.0, 0 },
		{ 5, 5.0, 1 },
		{ 6, 6.0, 1 },
		{ 7, 7.0, 0 },
		{ 8, 8.0, 0 },
		{ 9, 9.0, 1 },
		{ 10, 10.0, 1 },
		{ 11, 11.0, 1 },
		{ 12, 12.0, 1 }
		
		*/
	}; // end array
	int sizeOfArray = sizeof(cars)/sizeof(cars[0]);
	for (int i = 0; i < sizeOfArray; ++i)
	{
	
		int foo = pthread_create(&Car[i].carPThread, 
		NULL, Car[i].carPThread, 
	}

	cararg_t

	return 0;
} // end main

