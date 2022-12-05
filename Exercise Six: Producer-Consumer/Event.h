/* Event.h --- 
 * 
 * Filename: Event.h
 * Description: 
 * Author: Joseph
 * Maintainer: 
 * Created: Tue Jan  8 12:30:05 2019 (+0000)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: Tue Jan  8 12:30:14 2019 (+0000)
 *           By: Joseph
 *     Update #: 1
 * URL: 
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change Log:
 * 
 * 
 */

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
#include "SafeBuffer.h"
#include <unistd.h>

class Event{
 public:
  Event(int i);
  virtual ~Event();
  void createEvent(int i);
  char printRandomString();
};

Event::Event (int i){
    char res ;
    res=printRandomLetter();
    unsigned int microsecond = 1000000;
    usleep(1.5* microsecond);
    //std::cout<<i<<":"<<res<<std::endl;
}
Event::~Event(){

}
char printRandomLetter()
{
    char c;
    int r;
    srand (time(NULL));
    r = rand() % 26;
    c = 'a' + r;        
    return c;
}
/* Event.h ends here */
