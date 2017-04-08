//Reference for sleeping http://stackoverflow.com/questions/4184468/sleep-for-milliseconds

#include <chrono>
#include <thread>

#define WAITING 0
#define GOING   1
#define DONE    2

typedef struct _vehicle_info {
   int id; // id
   char dir; // heading direction
   double inter_arrival_t; // inter-arrival time between this vehicle and next
} vehicle_info;


void* VehicleAction(void* arg) {
   vehicle_info *ti = (vehicle_info *) arg;
   ArriveBridge(ti);
   CrossBridge(ti);
   ExitBridge(ti);
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

