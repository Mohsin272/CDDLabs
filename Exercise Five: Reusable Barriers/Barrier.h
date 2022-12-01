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
 /**
  * @brief Construct a new Barrier object
  * 
  * @param numThreads 
  */
  Barrier(int numThreads);
  /**
   * @brief Set the Threads object
   * 
   * @param numThreads 
   */
  void setThreads(int numThreads);
  /**
   * @brief Get the Threads object
   * 
   * @return int 
   */
  int getThreads(void);
  /**
   * @brief Destroy the Barrier object
   * 
   */
  virtual ~Barrier();
  /**
   * @brief Defining the phase1 method
   * 
   * @return * void 
   */
  void phase1();
  /**
   * @brief Defining the phase2 method 
   * 
   */
  void phase2();
};


/* Barrier.h ends here */
