#include "Event.h"
#include "SafeBuffer.h"
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

static const int num_threads = 30;
const int size=20;
Semaphore countMutex(size);
Semaphore m(1);
Semaphore m2(1);
int count=0;
bool space=true;

/*! \fn producer
    \brief Creates events and adds them to buffer
*/

void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){
 
  for(int i=0;i<numLoops;++i){
      m.Wait();
      countMutex.Wait();
      theBuffer->checkSize(size);
      Event e;
      theBuffer->put(e);
      m.Signal();
  }
}

/*! \fn consumer
    \brief Takes events from buffer and consumes them
*/

void consumer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){
  for(int i=0;i<numLoops;++i){
    //Produce event and add to buffer
    m2.Wait();
    Event e;
    e = theBuffer->get();
    e.consume();
    countMutex.Signal();
    m2.Signal();
  }
}

int main(void){

  std::vector<std::thread> producers(num_threads);
  std::vector<std::thread> consumers(num_threads);
  std::shared_ptr<SafeBuffer> aBuffer( new SafeBuffer(size));
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
