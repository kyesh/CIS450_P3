#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>


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


