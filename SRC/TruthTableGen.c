#include "TruthTableGen.h"

void TruthTableGen(bool (*LogicGate)(bool, bool))
{
	int A, B;

	printf("A B | Y\n");
	printf("----|---\n");

	for(A = 0; A <= 1; A++)
	{
		for(B = 0; B <= 1; B++)
		{
			printf("%d %d | %d\n", A, B, LogicGate(A,B));
		}
	}
}

void TruthTableGen1(bool (*LogicGate)(bool))
{
	int A;
	
	printf("A | Y\n");
	printf("--|---\n");
	
	for(A = 0; A <= 1; A++)
	{
		printf("%d | %d\n", A, LogicGate(A));
	}
}
