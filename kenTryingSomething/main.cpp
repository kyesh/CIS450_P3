
// From Prof example file
#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>


//Reference for sleeping http://stackoverflow.com/questions/4184468/sleep-for-milliseconds
#include <chrono>
#include <thread>

#define WAITING 0
#define GOING   1
#define DONE    2

//Array of Structures http://fresh2refresh.com/c-programming/c-array-of-structures/

typedef struct _vehicle_info {
   int id; // id
   char dir; // heading direction
   double inter_arrival_t; // inter-arrival time between this vehicle and next
} vehicle_info;

int GlobaGoNum = -1;
vehicle_info vQue[N];
int status sQue[N];

changeStatusTo(ti, int status){

   sQue[it.id] = status;
   updateGoNum();

}

void ArriveBridge(vechicle_info ti){


   changeStatusTo(ti, WAITING);
   while(gonum != GlobaGoNum){

   

   }

}

void CrossBridge(vechicle_info ti){
cout << "Time: " << time << ": Vechicle " << ti.id << "(" << dir << ") crossing";
changeStatusTo(ti, GOING);
std::this_thread::sleep_for(std::chrono::milliseconds(5000));

}

void ExitBridge(vechicle_info ti){

   changeStatusTo(ti, DONE);

}


void* VehicleAction(void* arg) {
   vehicle_info *ti = (vehicle_info *) arg;
   ArriveBridge(ti);
   CrossBridge(ti);
   ExitBridge(ti);
}

int main(int argc, char *argv[]) {
//Array of pthread_t http://stackoverflow.com/questions/14155055/how-to-save-pthread-t-id-to-an-array

	pthread_t p[N];

   for (int i = 0; i < N; i++) {
       std::this_thread::sleep_for(std::chrono::milliseconds(1000*p[i].inter_arrival_t));
       pthread_create(&p[i], NULL, VehicleAction, &vQue[i]);
   }


	pthread_join(p, (void **) &m);

	return 0;
}

