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
/* Code: */
#pragma once
#include "Event.h"
#include "Semaphore.h"
#include <vector>
/**
 * @brief Safe Buffer class definition
 * 
 */
class SafeBuffer
{
    private:
        /**
         * @brief Vector used as a buffer to hold random chraacters
         * 
         */
        std::vector<Event> buffer;
        /**
         * @brief Semaphore used to ensure thread safe buffer 
         * 
         */
        std::shared_ptr<Semaphore> mutex;
        /**
         * @brief Second Semaphore used to make the buffer thread safe
         * 
         */
        std::shared_ptr<Semaphore> sem;
        /**
         * @brief Variable used to store the buffer size
         * 
         */
        int BufferSize;
        /**
         * @brief Vector of chars that stores all consumed letters
         * 
         */
        std::vector<char> Charbuffer;

    public:
        SafeBuffer(int size);
        int put(Event);
        Event get();

};
