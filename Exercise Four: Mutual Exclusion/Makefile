#Mohsin Tahir 07/11/2022
#Lab 4 Makefile
#Used to contain commands to compile projects
#License : This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 \
International License. To view a copy of this license, \
visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, \
PO Box 1866, Mountain View, CA 94042, USA.

CC=g++
CFLAGS= -std=c++11 -pthread

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: main.o Semaphore.o
	$(CC) -o mutualExclusion main.o Semaphore.o $(CFLAGS)  $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
