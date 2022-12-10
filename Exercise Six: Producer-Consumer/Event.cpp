/* Code: */
#include "Event.h"
#include <unistd.h>
#include <time.h>
#include <random>
#include <iostream>

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
    randomChar=printRandomLetter();
    //unsigned int microsecond = 1000000;
    //usleep(1.0* microsecond);
    std::cout <<randomChar<<std::endl;
}

void Event::consume()//convert Them to uppcase first to detect capital X
{
    char randomCharUpper = randomChar-32;    
    std::cout << randomCharUpper<<std::endl;
}
/* Event.h ends here */