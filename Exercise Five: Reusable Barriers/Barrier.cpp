// Author Mohsin Tahir
// License = This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
// International License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, 
// PO Box 1866, Mountain View, CA 94042, USA.
// Date 29/11/2022

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.

// Code:
#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>
/**
 * @brief Construct a new Barrier:: Barrier object
 * 
 * @param numofThreads The number of threads being used for the program 
 */
Barrier::Barrier (int numofThreads)
{
	 count =0;
     numThreads=numofThreads;
}
/**
 * @brief Setter method for the numofThreads value
 * 
 * @param numofThreads 
 */
void Barrier::setThreads(int numofThreads){
	numThreads=numofThreads;
}
/**
 * @brief Getter method for numofThreads value
 * 
 * @return int 
 */
int Barrier::getThreads(void){
	return numThreads;
}
/**
 * @brief Destroy the Barrier:: Barrier object
 * 
 */
Barrier::~Barrier()
{
}
/**
 * @brief phase1:: This is the first phase of the barrier. All threads go through and wait at 
 * rendezvous point
 * 
 */
void Barrier::phase1()
{
	mutex.Wait();
	count+=1;
	mutex.Signal();

	if(count == numThreads)
	{
		std::cout<<""<<std::endl;
		outerdoor.Wait();
		innerdoor.Signal();
	}
	innerdoor.Wait();
	innerdoor.Signal();
}
/**
 * @brief pahse2:: This is the second phase of the barrier. Once all threads have arrived at rendezvous 
 * point they are then released
 * 
 */
void Barrier::phase2()
{
	mutex.Wait();
	count-=1;
	mutex.Signal();
	if (count == 0)
	{
		std::cout<<""<<std::endl;
		innerdoor.Wait();
		outerdoor.Signal();
	}
	//mutex.Signal();
	outerdoor.Wait();
	outerdoor.Signal();

}
// 
// Barrier.cpp ends here
