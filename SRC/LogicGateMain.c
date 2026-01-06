#include "LogicGateMain.h"

int main()
{
	printf("AND GATE TRUTH TABLE \n");
	TruthTableGen(AndGate);
	
	printf("OR GATE TRUTH TABLE \n");
	TruthTableGen(OrGate);
	
	printf("NAND GATE TRUTH TABLE \n");
	TruthTableGen(NandGate);
	
	printf("NOR GATE TRUTH TABLE \n");
	TruthTableGen(NorGate);
	
	printf("NOT GATE TRUTH TABLE \n");
	TruthTableGen1(NotGate);
	
	printf("BUFFER GATE TRUTH TABLE \n");
	TruthTableGen1(BufferGate);
	
	printf("XOR GATE TRUTH TABLE \n");
	TruthTableGen(XorGate);
	
	printf("XNOR GATE TRUTH TABLE \n");
	TruthTableGen(XnorGate);
	
	return 0;
}
