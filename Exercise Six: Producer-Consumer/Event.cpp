/* Code: */
#include "Event.h"
#include "Semaphore.h"
#include <unistd.h>
#include <time.h>
#include <random>
#include <iostream>

Event::Event (){
    randomChar='a'+rand()%26;
    std::cout <<"Produced "<<randomChar<<std::endl;
}
int count =0;
void Event::consume()
{
    char randomCharUpper = randomChar-32;    
    if (randomCharUpper=='X'){
        //std::cout << "Found X"<<std::endl;
        std::cout << "Consumed Count until X found = "<<count<<std::endl;
        count =0;

    }
    else{
        count ++;
    }
    std::cout << "Consumed = " <<randomCharUpper<<std::endl;
    //count =0;

}
/* Event.h ends here */