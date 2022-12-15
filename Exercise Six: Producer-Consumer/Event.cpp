/* Code: */
#include "Event.h"
#include "Semaphore.h"
#include <unistd.h>
#include <time.h>
#include <random>
#include <iostream>
#include <cctype>
/**
 * @brief Construct a new Event:: Event object with a random letter
 * 
 */
Event::Event (){
    randomChar='a'+rand()%26;
    std::cout <<"Produced "<<randomChar<<std::endl;
}
/**
 * @brief Fuction converts letter to uppercase and prints to screen when it has been consumed.
 * 
 */
void Event::consume()
{
    char randomCharUpper = toupper(randomChar);    
    std::cout<<"Consumed " << randomCharUpper <<std::endl;

}
/* Event.h ends here */