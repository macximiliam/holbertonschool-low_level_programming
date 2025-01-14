#include "main.h"
/** this funtion checks the uppercase character
*return: if c is ippercase, else retunr 0 otherwys*/

int _isupper(int c)
{
	if(c >= 'A'&& c <= 'Z')
		return(1);
	else
		return(0);
}	
