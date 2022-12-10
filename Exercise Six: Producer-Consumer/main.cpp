#include "Event.h"
#include "SafeBuffer.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 10;
const int size=20;


/*! \fn producer
    \brief Creates events and adds them to buffer
*/

void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Produce event and add to buffer
    Event e;
    theBuffer->put(e);
    std::cout<<"Produced"<<std::endl;
  }
}

/*! \fn consumer
    \brief Takes events from buffer and consumes them
*/

void consumer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Produce event and add to buffer
    Event e;
    e = theBuffer->get();
    e.consume();
    std::cout<<"Consumed"<<std::endl;
  }
  

}

int main(void){

  std::vector<std::thread> producers(num_threads);
  std::vector<std::thread> consumers(num_threads);
  std::shared_ptr<SafeBuffer> aBuffer( new SafeBuffer());
  /**< Launch the threads  */
  int i=0;
  for(std::thread& prod: producers)
  {
    prod=std::thread(producer,aBuffer,5);
  }
  for(std::thread& cons: consumers)
  {
    cons=std::thread(consumer,aBuffer,5);
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
  std::cout << std::endl;
  return 0;
}
