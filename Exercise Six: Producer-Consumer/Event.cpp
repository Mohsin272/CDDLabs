/* Code: */
#include "Event.h"
#include "Semaphore.h"
#include <unistd.h>
#include <time.h>
#include <random>
#include <iostream>
#include <cctype>
Event::Event (){
    randomChar='a'+rand()%26;
    std::cout <<"Produced "<<randomChar<<std::endl;
}
int count =0;
void Event::consume()
{
    char randomCharUpper = toupper(randomChar);    
    if (randomCharUpper=='X'){
        std::cout << "Number of chracters consumed until X found = "<<count<<std::endl;
        count =0;
    }
    else{
        count ++;
    }
}
/* Event.h ends here */