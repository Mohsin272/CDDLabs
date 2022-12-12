#include "Event.h"
#include "SafeBuffer.h"
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

Semaphore m(1);
static const int num_threads = 30;
const int size=20;
Semaphore countMutex(size);
int count=0;


/*! \fn producer
    \brief Creates events and adds them to buffer
*/

void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){
 
  for(int i=0;i<numLoops;++i){
      countMutex.Wait();
      //m.Wait();
      //count++;
      //m.Signal();

        Event e;

        theBuffer->put(e);

      //Event e;
      theBuffer->checkSize(size);
      // cunt --;
      countMutex.Signal();
    //Produce event and add to buffer 
    //m.Wait();
    // countMutex.Wait();
    // count ++;
    // countMutex.Signal();
    // std::cout<<"count = "<<count<<std::endl;
    // if (count == size){
    //   Event e;
    //   e.createX();
    //   theBuffer->put(e);
    // }
    //countMutex.Wait();
  //   m.Wait();
  //   count++;
  //  m.Signal();
  //   if(count != size)
  //   {
      // Event e;
      // theBuffer->put(e); 
  //   }
  //   else if (count == size){
  //     count=0;
  //     Event e;
  //     e.createX();
  //     theBuffer->buffer.push_back(e);
  //     count=0;
  //   } 
  // while(isSpace==true){
  //     Event e;
  //     theBuffer->put(e); 

  //     if(count == size){
  //       m.Wait();
  //       isSpace=false;
  //       m.Signal();
        
  //     }
  //     count =0;
  // }
    //countMutex.Signal();
     //m.Signal();
  }
 
}

/*! \fn consumer
    \brief Takes events from buffer and consumes them
*/

void consumer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){
  //mainMutex.Wait();
  for(int i=0;i<numLoops;++i){
    //Produce event and add to buffer
    //m.Wait();
    Event e;
    e = theBuffer->get();
    e.consume();
    // m.Wait();
    // isSpace=true;
    // m.Signal();
    //m.Signal();
  }
 // mainMutex.Signal();
  

}

int main(void){

  std::vector<std::thread> producers(num_threads);
  std::vector<std::thread> consumers(num_threads);
  std::shared_ptr<SafeBuffer> aBuffer( new SafeBuffer());
  /**< Launch the threads  */
  int i=0;
  for(std::thread& prod: producers)
  {
    prod=std::thread(producer,aBuffer,10);
  }
  for(std::thread& cons: consumers)
  {
    cons=std::thread(consumer,aBuffer,10);
  }
  /**< Join the threads with the main thread */
  for (auto& p :producers)
  {
      p.join();
  }
  for (auto& c :consumers)
  {
      c.join();
  }
  std::cout << "Program Finished"<<std::endl;
  return 0;
}
