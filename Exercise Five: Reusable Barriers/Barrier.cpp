// Barrier.cpp --- 
// 
// Filename: Barrier.cpp
// Description: 
// Author: Joseph
// Maintainer: 
// Created: Tue Jan  8 12:14:02 2019 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: Tue Jan  8 12:15:21 2019 (+0000)
//           By: Joseph
//     Update #: 2
// URL: 
// Doc URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change Log:
// 
// 
// 
// 
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
// 
// 

// Code:
#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>

int count =0;

Barrier::Barrier (int numThreads){
    numThreads=numThreads;
}
Barrier::~Barrier()
{
}

void Barrier::wait(){

    Semaphore mutex(1);
    Semaphore innerdoor(0);
    Semaphore outerdoor(1);

    mutex.Wait();//Mutex for shared variables 
	count++;
	mutex.Signal();
	
	if (count == numThreads) 
    { // when last thread arrives
		outerdoor.Wait();//takes 1 away and now sets to 0 so door is closed now
		
		innerdoor.Signal();//opens the inner door now 
	}
	innerdoor.Wait();//closes inner door now once everyones arrived
	
	innerdoor.Signal();
	
	mutex.Wait();
	count --;
	mutex.Signal();
	
	if ( count ==0 )
    {//checks if everyones in the airlock now 
		innerdoor.Wait();//closes inner door
		outerdoor.Signal();//opens outer door
	}
	outerdoor.Wait(); //if not everyones arrived in airlock
	outerdoor.Signal();

}


// 
// Barrier.cpp ends here
