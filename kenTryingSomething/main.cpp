
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

#define NotThere 0
#define WAITING  1
#define GOING    2
#define DONE     3

//Array of Structures http://fresh2refresh.com/c-programming/c-array-of-structures/

typedef struct _vehicle_info {
   int id; // id
   char dir; // heading direction
   int inter_arrival_t; // inter-arrival time between this vehicle and next
} vehicle_info;

void setVechicleInfo(vehicle_info &vinf, int id, char dir, double inter_arrival_t){

   vinf.id = id;
   vinf.dir = dir;
   vinf.inter_arrival_t = inter_arrival_t;

}

pthread_cond_t goNumTracker;
pthread_mutex_t queLock;

int cartime = 0;
int GlobaGoNum = -1;
vehicle_info vQue[N];
int sQue[N];

/* Greedy
void updateGoNum(){

     char activeDirection = 0;  
     int  bridgecount = 0;
      for(int i = 0 ; i < N; i++){
        if(sQue[i] == GOING){
          activeDirection = vQue[i].dir;
          bridgecount = bridgecount + 1;
          if(bridgecount > 2){
            return;
          }
        }
     }


     for(int i = 0 ; i < N; i++){
        if(sQue[i] == WAITING && (vQue[i].dir == activeDirection || activeDirection == 0 )){

          GlobaGoNum = i;
          std::cout << "GoNum is now: " << GlobaGoNum << std::endl;
          pthread_cond_broadcast(&goNumTracker);
          return;

        }

     }
    

}
*/

// FCFS
void updateGoNum(){

     char activeDirection = 0;  
     int  bridgecount = 0;
      for(int i = 0 ; i < N; i++){
        if(sQue[i] == GOING){
          activeDirection = vQue[i].dir;
          bridgecount = bridgecount + 1;
          if(bridgecount > 2){
            return;
          }
        }
     }


     for(int i = 0 ; i < N; i++){
        if(sQue[i] == WAITING && (vQue[i].dir == activeDirection || activeDirection == 0 )){

          GlobaGoNum = i;
          std::cout << "GoNum is now: " << GlobaGoNum << std::endl;
          pthread_cond_broadcast(&goNumTracker);
          return;

        }else if(sQue[i] == WAITING && vQue[i].dir != activeDirection){
          return;
        }

     }
    

}


void changeStatusTo(vehicle_info ti, int status){
   
   std::cout << "Vechicle " << ti.id << "(" << ti.dir << ") Status Changed to: "<< status  << std::endl;
   sQue[ti.id] = status;
   updateGoNum();

}

void ArriveBridge(vehicle_info ti){

   pthread_mutex_lock(&queLock);
   changeStatusTo(ti, WAITING);
   while(ti.id != GlobaGoNum){

   pthread_cond_wait(&goNumTracker, &queLock); 

   }

   pthread_mutex_unlock(&queLock);

}

void CrossBridge(vehicle_info ti){

pthread_mutex_lock(&queLock);
changeStatusTo(ti, GOING);
pthread_mutex_unlock(&queLock);

std::cout << "Time: " << cartime << ": Vechicle " << ti.id << "(" << ti.dir << ") crossing" << std::endl;

std::this_thread::sleep_for(std::chrono::milliseconds(5000));

}

void ExitBridge(vehicle_info ti){

   pthread_mutex_lock(&queLock);
   changeStatusTo(ti, DONE);
   pthread_mutex_unlock(&queLock);

   std::cout << "Time: " << cartime << ": Vechicle " << ti.id << "(" << ti.dir << ") finished" << std::endl;


}


void* VehicleAction(void* arg) {
   vehicle_info *ti = (vehicle_info *) arg;
   ArriveBridge(*ti);
   CrossBridge(*ti);
   ExitBridge(*ti);
}

int main(int argc, char *argv[]) {
//Array of pthread_t http://stackoverflow.com/questions/14155055/how-to-save-pthread-t-id-to-an-array

	pthread_t p[N];
        
        setVechicleInfo(vQue[0],0,'N',1.0);
        setVechicleInfo(vQue[1],1,'N',1.0);
        setVechicleInfo(vQue[2],2,'S',1.0);
        setVechicleInfo(vQue[3],3,'S',1.0);
        setVechicleInfo(vQue[4],4,'S',1.0);
        setVechicleInfo(vQue[5],5,'N',1.0);
        setVechicleInfo(vQue[6],6,'N',1.0);
        setVechicleInfo(vQue[7],7,'S',1.0);
        setVechicleInfo(vQue[8],8,'S',1.0);
        setVechicleInfo(vQue[9],9,'N',1.0);
        setVechicleInfo(vQue[10],10,'N',1.0);
        setVechicleInfo(vQue[11],11,'N',1.0);
        setVechicleInfo(vQue[12],12,'N',1.0);




   for (int i = 0; i < N; i++) {
      sQue[i] = 0;
      pthread_create(&p[i], NULL, VehicleAction, &vQue[i]);
      std::this_thread::sleep_for(std::chrono::milliseconds(975*vQue[i].inter_arrival_t));
      std::cout << "Time is now: " << cartime << std::endl;
      cartime = cartime + vQue[i].inter_arrival_t;
   }

   for (int i = 0; i < N*2; i++) {
      std::this_thread::sleep_for(std::chrono::milliseconds(975));
      std::cout << "Time is now: " << cartime << std::endl;
      cartime = cartime + 1;
   }


    for (int i = 0; i < N; i++)
       pthread_join(p[i], NULL);


	return 0;
}

