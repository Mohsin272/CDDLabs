//Author - Mohsin Tahir
//License - This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
//International License. To view a copy of this license, 
//visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, 
//PO Box 1866, Mountain View, CA 94042, USA.
//Date : 02/11/2022
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

/*! A static variable to hold the number of threads to be used*/
static const int num_threads = 100;
/*! The variable that is shared and is being updated by all threads*/
int sharedVariable=0;
/*! Semaphore initialised as 1 to act as a mutex lock*/
Semaphore mutex(1);


/*! \fn updateTask
    \brief An Implementation of Mutual Exclusion using Semaphores

   Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous 
   for threads

*/
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates){
  
  mutex.Signal();
  for(int i=0;i<numUpdates;i++){
    //UPDATE SHARED VARIABLE HERE!
    sharedVariable++;
  }
  mutex.Wait();
}

int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Semaphore> aSemaphore( new Semaphore);
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(updateTask,aSemaphore,1000);
  }
  std::cout << "Launched from the main\n";
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
