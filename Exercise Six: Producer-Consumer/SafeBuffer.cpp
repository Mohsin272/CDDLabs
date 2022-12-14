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
/*! \page SafeBuffer
    \file SafeBuffer.cpp
    \author Mohsin Tahir
    \date 09/12/2022
    \copyright This code is covered by the GNU General Public License v3.0
    \name SafeBuffer implementation
    Implementing the SafeBuffer
*/
SafeBuffer::SafeBuffer(int size)
{
    mutex = std::make_shared<Semaphore>(1);
    sem = std::make_shared<Semaphore>(0);
    BufferSize=size;
}

// void SafeBuffer::checkSize(int BufferSize){
//     if (buffer.size()==BufferSize){
//         Event e;
//         e.randomChar='X';
//         buffer.push_back(e);
//         std::cout <<"BUffer LImit Reached Added X"<<std::endl;
//     }
// }

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

Event SafeBuffer::get()
{
    sem->Wait();
    mutex->Wait();
    Event e = buffer.back();
    buffer.pop_back();
    std::cout<<"Consumed from vector, size = "<<buffer.size()<<std::endl;
    mutex->Signal();
    return e;
}