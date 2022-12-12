/* Code: */
#include "Event.h"
#include "Semaphore.h"
#include <unistd.h>
#include <time.h>
#include <random>
#include <iostream>
Semaphore mainMutex(1);
char Event::printRandomLetter()
{
    char c;
    int r;
    srand (time(NULL));
    r = rand() % 26;
    c = 'a' + r;        
    return c;
}

Event::Event (){
    //mainMutex.Wait();
    randomChar=printRandomLetter();
    unsigned int microsecond = 1000000;
    usleep(1.0* microsecond);
    //std::cout <<"Produced "<<randomChar<<std::endl;
    //mainMutex.Signal();
}

void Event::consume()//convert Them to uppcase to check if consumed
{
    char randomCharUpper = randomChar-32;    
    if (randomCharUpper=='X'){
        std::cout << "Found X"<<std::endl;

    }
    std::cout << "Consumed = " <<randomCharUpper<<std::endl;

}
/* Event.h ends here */