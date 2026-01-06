#include "BufferGate.h"

bool BufferGate(bool input)
{
	bool output;
	
	if (input == false)
	{
		output = false;
	}
	else if (input == true)
	{
		output = true;
	}
	else
	{
		//do nothing
	}
	
	return output;
}