#include "HalfAdder.h"
#include "XorGate.h"
#include "AndGate.h"

void HalfAdder(bool A, bool B, bool *SUM, bool *CARRY)
{
	if(SUM != NULL)
	{
		*SUM = XorGate(A, B);
	}
	
	if(CARRY != NULL)
	{
		*CARRY = AndGate(A,B);
	}
}