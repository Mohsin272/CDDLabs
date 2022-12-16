// Author Mohsin Tahir
// License = This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
// International License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, 
// PO Box 1866, Mountain View, CA 94042, USA.
// Date 16/12/2022
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