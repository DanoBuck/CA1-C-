// Daniel Buckley X00109141

/*
**************************************************************************
*                                                                        *
*          General Purpose Hash Function Algorithms Library              *
*                                                                        *
* Author: Arash Partow - 2002                                            *
* URL: http://www.partow.net                                             *
* URL: http://www.partow.net/programming/hashfunctions/index.html        *
*                                                                        *
* Copyright notice:                                                      *
* Free use of the General Purpose Hash Function Algorithms Library is    *
* permitted under the guidelines and in accordance with the most current *
* version of the Common Public License.                                  *
* http://www.opensource.org/licenses/cpl1.0.php                          *
*                                                                        *
**************************************************************************
*/

/***************************************************************************************
*	 
*    Copied Completely - Not changed
*    Date: <28/10/2015>
*
*    Availability: http://www.partow.net/programming/hashfunctions/
*
***************************************************************************************/
#ifndef INCLUDE_HASHING_CPP_H
#define INCLUDE_HASHING_CPP_H
#include <string>
typedef unsigned int(*HashFunction)(const std::string&);
unsigned int BPHash(const std::string& str);
#endif

