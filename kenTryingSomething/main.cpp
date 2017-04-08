
// From Prof example file
#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>


//Reference for sleeping http://stackoverflow.com/questions/4184468/sleep-for-milliseconds
#include <chrono>
#include <thread>

#include <iostream>

#define N      13

#define WAITING 0
#define GOING   1
#define DONE    2

//Array of Structures http://fresh2refresh.com/c-programming/c-array-of-structures/

typedef struct _vehicle_info {
   int id; // id
   char dir; // heading direction
   double inter_arrival_t; // inter-arrival time between this vehicle and next
} vehicle_info;

void setVechicleInfo(vehicle_info &vinf, int id, char dir, double inter_arrival_t){

   vinf.id = id;
   vinf.dir = dir;
   vinf.inter_arrival_t = inter_arrival_t;

}

int GlobaGoNum = -1;
vehicle_info vQue[N];
int sQue[N];

void updateGoNum(){

   

}

void changeStatusTo(vehicle_info ti, int status){

   sQue[ti.id] = status;
   updateGoNum();

}

void ArriveBridge(vehicle_info ti){


   changeStatusTo(ti, WAITING);
   while(ti.id != GlobaGoNum){

   

   }

}

void CrossBridge(vehicle_info ti){
std::cout << "Time: " << time << ": Vechicle " << ti.id << "(" << ti.dir << ") crossing" << std::endl;
changeStatusTo(ti, GOING);
std::this_thread::sleep_for(std::chrono::milliseconds(5000));

}

void ExitBridge(vehicle_info ti){

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
        
        setVechicleInfo(p[0],0,'N',0.0);
        setVechicleInfo(p[1],1,'N',1.0);
        setVechicleInfo(p[2],2,'S',1.0);
        setVechicleInfo(p[3],3,'S',1.0);
        setVechicleInfo(p[4],4,'S',1.0);
        setVechicleInfo(p[5],5,'N',1.0);
        setVechicleInfo(p[6],6,'N',1.0);
        setVechicleInfo(p[7],7,'S',1.0);
        setVechicleInfo(p[8],8,'S',1.0);
        setVechicleInfo(p[9],9,'N',1.0);
        setVechicleInfo(p[10],10,'N',1.0);
        setVechicleInfo(p[11],11,'N',1.0);
        setVechicleInfo(p[12],12,'N',1.0);




   for (int i = 0; i < N; i++) {
       std::this_thread::sleep_for(std::chrono::milliseconds(1000*p[i].inter_arrival_t));
       pthread_create(&p[i], NULL, VehicleAction, &vQue[i]);
   }

    for (int i = 0; i < N; i++)
       pthread_join(p[i], NULL);


	return 0;
}

