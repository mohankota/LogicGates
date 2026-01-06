#ifndef TRUTHTABLEGEN_H
#define TRUTHTABLEGEN_H

#include <stdio.h>
#include <stdbool.h>
#include "AndGate.h"
#include "OrGate.h"
#include "NandGate.h"
#include "NorGate.h"
#include "NotGate.h"
#include "BufferGate.h"
#include "XorGate.h"
#include "XnorGate.h"

void TruthTableGen(bool (*LogicGate)(bool, bool));
void TruthTableGen1(bool (*LogicGate)(bool)); 

#endif
