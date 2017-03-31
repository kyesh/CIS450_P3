#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>

typedef struct __myarg_t {
	int a;
	int b;
} myarg_t;

typedef struct __myret_t {
	int x;
	int y;
} myret_t;

void *mythread(void *arg) { 
	myarg_t *m = (myarg_t *) arg; 
	printf("%d %d\n", m->a, m->b); 
	myret_t *r = malloc(sizeof(myret_t)); 
	r->x = 1;
	r->y = 2;
	return (void *) r;
}

void* VehicleAction(void* arg) {

	vehicle_info *ti = (vehicle_info *) arg;
	ArriveBridge(ti);
	CrossBridge(ti);
	ExitBridge(ti);

}

typedef struct _vehicle_info {
int id; // id
double inter_arrival_t; // inter-arrival time between this vehicle and next
int dir; // heading direction
} vehicle_info;



int main(int argc, char *argv[]) {
	int rc;

	pthread_t p;
	myarg_t args;
	myret_t *m;

	// North = 1, South = 0
	_vehicle_info[] cars = { 
		{ 0, 0.0, 1 }
		{ 1, 1.0, 1 }
		{ 2, 2.0, 0 }
		{ 3, 3.0, 0 }
		{ 4, 4.0, 0 }
		{ 5, 5.0, 1 }
		{ 6, 6.0, 1 }
		{ 7, 7.0, 0 }
		{ 8, 8.0, 0 }
		{ 9, 9.0, 1 }
		{ 10, 10.0, 1 }
		{ 11, 11.0, 1 }
		{ 12, 12.0, 1 }
	}; // end array


	args.a = 10;
	args.b = 20;
	rc = pthread_create(&p, NULL, mythread, &args);
	pthread_join(p, (void **) &m);

	printf("returned %d %d\n", 
			m->x, m->y); 
	return 0;
}

