#include "FuncA.h"
#include "FuncC.h"
#include <iostream>

// Function in FuncA
void AFunction() {
    // Update the value of STATIC_VAR
    STATIC_VAR = 20;

    // Print the memory address and value of STATIC_VAR
    std::cout << "Memory address of 'STATIC_VAR' in " << "FuncA" << ": " << &STATIC_VAR <<", value : "<< STATIC_VAR << std::endl;
}
