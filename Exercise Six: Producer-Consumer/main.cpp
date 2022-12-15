#include "Event.h"
#include "SafeBuffer.h"
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

static const int num_threads = 30;
const int size=20;
Semaphore spaces(size);
Semaphore mutex(1);
Semaphore items(0);

/*! \fn producer
    \brief Creates events and adds them to buffer
*/

void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){
 
  for(int i=0;i<numLoops;++i){
      spaces.Wait();
      mutex.Wait();
      //theBuffer->checkSize(size);
      Event e;
      theBuffer->put(e);
      mutex.Signal();
      items.Signal();
  }
}

/*! \fn consumer
    \brief Takes events from buffer and consumes them
*/

void consumer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){
  for(int i=0;i<numLoops;++i){
    items.Wait();
    mutex.Wait();
    Event e;
    e = theBuffer->get();
    e.consume();
    mutex.Signal();
    spaces.Signal();
    
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
