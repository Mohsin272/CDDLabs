// Author Mohsin Tahir
// License = This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
// International License. To view a copy of this license, 
// visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, 
// PO Box 1866, Mountain View, CA 94042, USA.
// Date 29/11/2022

/* Code: */
#pragma once
#include "Semaphore.h"
/**
 * @brief Barrier class definition
 * 
 */
class Barrier{
  /**
   * @brief variable used to store how many threads being used
   */
  int numThreads;
  /**
   * @brief count used to count the number of threads have reched and passed the barrier.
   * 
   */
  int count;
  /**
   * @brief Semaphore used as mutex and initialised to 1
   * 
   */
  Semaphore mutex{1};
  /**
   * @brief Semaphore used for managing the first door and initialsed as 0
   * 
   */
  Semaphore innerdoor{0};
  /**
   * @brief Semaphore used for managin the outerdoor and is intialised as 1
   * 
   */
  Semaphore outerdoor{1};
 public:
  Barrier(int numThreads);
  void setThreads(int numThreads);
  int getThreads(void);
  virtual ~Barrier();
  void phase1();
  void phase2();
};


/* Barrier.h ends here */
