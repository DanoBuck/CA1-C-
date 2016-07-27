// Daniel Buckley X00109141

#include "Hashing.h"
/***************************************************************************************
*
*    Copied Completely - Not changed
*    Date: <28/10/2015>
*
*    Availability: http://www.partow.net/programming/hashfunctions/
*
***************************************************************************************/
unsigned int BPHash(const std::string& str)
{
	unsigned int hash = 0;
	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash = hash << 7 ^ str[i];
	}

	return hash;
}
/* End Of BP Hash Function */

