# Lab 6: Producer and Consumers
**Brief:** This lab demonstrates the producer and consumer problem using a finite buffer. The producer generates random letters from 'a' to 'z' and adds it to a thread safe buffer. Once the buffer limit is reached a 'X' is added. The consumer takes these chracters and counts how many consumed until a 'X' is found.

- **Project Licence:** *This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/ or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.*\
<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.

- **Authors of Project:**
	- **Student:** Mohsin Tahir
	- **Lecturer:** Joseph Kehoe
- **Student Number:** C00250220
- **Institution:** SETU Carlow
- **Date:** 14/12/22<br>

- **How to install project:**
	- run `make` file in terminal
	- run `./prodCon`
    - run `make doc` to generate documentation
	
- **List of any required Libraries, platform issues, etc.:**
	- **Linux** - Environment
	- **g++** - Compiler
	- **emacs/VSC** - Editor
	- **make** - For creating Makefile
	- **gdb** - Debugger
	- **doxygen** - Code documentation (optional)
	
- **List of files and what they contain:**
	- **main.cpp** - the main project class
	- **Semaphore.cpp** - holds all sempahore code
	- **Semaphore.h** - header file for the semaphore class
    - **Event.cpp** - holds all event code
	- **Event.h** - header file for the event class
    - **SafeBuffer.cpp** - holds all safebuffer code
	- **SafeBuffer.h** - header file for the safebuffer class
	- **makefile** - compiling program
	- **README** - about the lab file
	
