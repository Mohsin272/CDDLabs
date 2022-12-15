/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "SafeBuffer.h"
#include <iostream>
#include <stdlib.h>
#include "Event.h"
#include <map>

/**
 * @brief Construct a new Safe Buffer:: Safe Buffer object
 * 
 * @param size Defines the size of the buffer
 */
SafeBuffer::SafeBuffer(int size)
{
    mutex = std::make_shared<Semaphore>(1);
    sem = std::make_shared<Semaphore>(0);
    BufferSize=size;
}
/**
 * @brief Method used to put an object to the buffer. Checks buffer size and places 'X' if limit is reached.
 * 
 * @param e Takes in an event object
 * @return int Returns the Size of the buffer after placement
 */
int SafeBuffer::put(Event e)
{
    mutex->Wait();
    if(buffer.size()==BufferSize-1)
    {
        e.randomChar='X';
        buffer.push_back(e);
        std::cout<<"Added buffer limit ending char X to vector, size = "<<buffer.size()<<std::endl;
    }
    else{
    buffer.push_back(e);
    }
    int size = buffer.size();
    std::cout<<"Added "<< e.randomChar<<" to vector, size = "<<buffer.size()<<std::endl;
    mutex->Signal();
    sem->Signal();
    return size;
}
/**
 * @brief Function to retrieve the last item placed on the buffer. If it is 'X' total number of letters 
 * consumed is printed.
 * 
 * @return Event 
 */
Event SafeBuffer::get()
{
    sem->Wait();
    mutex->Wait();
    Event e = buffer.back();
    buffer.pop_back();
    Charbuffer.push_back(e.randomChar);
    if (e.randomChar=='X'){
    std::cout <<"*********Found X in Buffer********"<<std::endl;
    std::cout <<"Total consumed characters are =  "<<Charbuffer.size()<<std::endl;
    std::map<char, int> count;
    for(int i=0; i<Charbuffer.size(); i++) {
        count[Charbuffer[i]]++;
    }
    for(const auto kvp : count) {
        std::cout << kvp.first << " occurs " << kvp.second << " times\n";
    }
        Charbuffer.clear();
    }
    else{
    std::cout<<"Consumed from vector, size = "<<buffer.size()<<std::endl;
    }
    mutex->Signal();
    return e;
}