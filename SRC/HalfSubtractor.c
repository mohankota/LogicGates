#include "HalfSubtractor.h"
#include "XorGate.h"
#include "AndGate.h"
#include "NotGate.h"

void HalfSubtractor(bool A, bool B, bool *DIFFERENCE, bool *BORROW)
{
	if (DIFFERENCE != NULL)
	{
		*DIFFERENCE = XorGate(A, B);
	}
	
	if (BORROW != NULL)
	{
		*BORROW = AndGate(NotGate(A), B);
	}
}