LogicGates
LogicGates is a small C project that implements basic and derived logic gates and uses unit tests to verify their truth tables using the Unity framework.
​

Features
Implementation of common logic gates in C: AND, OR, NOT, NAND, NOR, XOR, XNOR, and BUFFER.
​

Simple API functions for each gate that operate on boolean-like integer inputs (0 or 1).
​

Unity-based unit tests for each gate, including truth table verification and test reports.
​

Project Structure
A typical layout for this project:

SRC/ – Gate implementations and shared logic (e.g. AndGate.c, OrGate.c, TruthTableGen.c).
​

INC/ – Header files declaring gate APIs and shared types.
​

TEST/ – Unit tests written with Unity, including unity.c and test runners.
​

OBJ/ – Intermediate object files generated during compilation.
​

TARGET/ – Final executables such as gate demos and test binaries.
​

makefile – Build rules for compiling sources, running tests, and cleaning artifacts.
​

You can adjust names in this section if your folders differ.

Building and Running
From the repository root:

bash
# Build all targets
make

# Build and run unit tests for all gates (example target)
make test

# Build and run a specific test binary
make TARGET/AndGate_test
./TARGET/AndGate_test

# Clean build artifacts
make clean
The make targets compile C sources under SRC into OBJ, then link into binaries under TARGET.
​

Test binaries use Unity and print a summary of passed/failed test cases to the console and optionally to test_report.txt.
​

Usage
Gate functions follow a simple signature pattern:

c
#include "AndGate.h"

int out = and_gate(1, 0);  // Example: 1 AND 0 -> 0
Inputs are integers treated as logical 0 or 1; outputs follow the corresponding truth table definition.
​

Similar functions exist for or_gate, not_gate, nand_gate, nor_gate, xor_gate, xnor_gate, and buffer_gate.
​

A truth-table generator helper can iterate all input combinations and print or log the resulting outputs for a given gate.
​

Development Notes
Unit tests use the standard Unity pattern with setUp() and tearDown() hooks defined in each test file.
​

The .gitignore is configured to exclude build artifacts like TARGET/ and test reports such as test_report.txt from version control.
​

Feel free to extend the project by adding new composite gates, more exhaustive tests, or a CLI interface to select gates and visualize truth tables.
​
