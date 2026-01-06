#include "NotGate.h"

bool NotGate(bool input)
{
	bool output;
	
	if (input == false)
	{
		output = true;
	}
	else if (input == true)
	{
		output = false;
	}
	else
	{
		//do nothing
	}
	
	return output;
}