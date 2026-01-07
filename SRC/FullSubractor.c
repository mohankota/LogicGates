#include "FullSubtractor.h"
#include "XorGate.h"
#include "AndGate.h"
#include "NotGate.h"
#include "OrGate.h"

void FullSubtractor(bool A, bool B, bool BorrowIn, bool *Difference, bool *BorrowOut)
{
	bool xor_ab = XorGate(A, B);
	
	if(Difference != NULL)
	{
		*Difference = XorGate(BorrowIn, xor_ab);
	}
	
	if(BorrowOut != NULL)
	{
		*BorrowOut = OrGate(AndGate(NotGate(xor_ab), BorrowIn), AndGate(NotGate(A), B));
	}
}