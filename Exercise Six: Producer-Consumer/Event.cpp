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
 * @brief Fuction converts latter to uppercase and prints to screen when it has been consumed
 * 
 */
void Event::consume()
{
    char randomCharUpper = toupper(randomChar);    
    // if (randomCharUpper=='X'){
    //     // std::cout << "Number of chracters consumed until X found = "<<count<<std::endl;
    //     // count =0;
    //     std::cout <<"*********Found X in Buffer********"<<std::endl;
    //     std::cout <<"CharBuffer size is "<<Charbuffer.size()<<std::endl;
    //     std::map<char, int> count;
    //     for(int i=0; i<Charbuffer.size(); i++) {
    //         count[Charbuffer[i]]++;
    //     }
    //     for(const auto kvp : count) {
    //         std::cout << kvp.first << " occurs " << kvp.second << " times\n";
    //     }
    // }
    // else{
         std::cout<<"Consumed " << randomCharUpper <<std::endl;
    // }
}
/* Event.h ends here */