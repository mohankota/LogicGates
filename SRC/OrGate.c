#include "OrGate.h"

bool OrGate(bool input1, bool input2)
{
	bool output;
	if (input1 == false && input2 == false)
	{
		output = false;
	}
	else if (input1 == false && input2 == true)
	{
		output = true;
	}
	else if (input1 == true && input2 == false)
	{
		output = true;
	}
	else if (input1 == true && input2 == true)
	{
		output = true;
	}
	else
	{
		//do nothing
	}

	return output;
}
