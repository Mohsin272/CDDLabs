#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <chrono>
//Author - Mohsin Tahir
//License - This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
//International License. To view a copy of this license, 
//visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, 
//PO Box 1866, Mountain View, CA 94042, USA.
//Date : 02/11/2022
/*! \class Signal
    \brief An Implementation of a Rendezvous using Semaphores

   Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads

*/
/*! Global variable used to keep count of threads*/
int count =0;//global var

/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void taskOne(std::shared_ptr<Semaphore> firstSem,std::shared_ptr<Semaphore>  secondSem, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout <<"Task One has arrived! "<< std::endl;
  firstSem->Signal();
  secondSem->Wait();
  //THIS IS THE RENDEZVOUS POINT!
  std::cout << "Task One has left!"<<std::endl;
}

/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void taskTwo(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem, int delay){
  std::this_thread::sleep_for(std::chrono::seconds(delay));
   firstSem->Wait();
   std::cout <<"Task Two has arrived "<<std::endl;
   secondSem->Signal();
  //THIS IS THE RENDEZVOUS POINT!
  std::cout << "Task Two has left "<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  int taskOneDelay=5;
  int taskTwoDelay=1;
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem1,sem2,taskTwoDelay);
  threadTwo=std::thread(taskOne,sem1,sem2,taskOneDelay);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
