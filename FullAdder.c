#include "FullAdder.h"
#include "XorGate.h"
#include "AndGate.h"
#include "OrGate.h"

void FullAdder(bool A, bool B, bool CARRY_IN, bool *SUM, bool *CARRY_OUT)
{
	if(SUM != NULL)
	{
		*SUM = XorGate(XorGate(A, B), CARRY_IN);
	}
	
	if(CARRY_OUT != NULL)
	{
		*CARRY_OUT = OrGate(AndGate(CARRY_IN, XorGate(A, B)), AndGate(A, B));
	}
}