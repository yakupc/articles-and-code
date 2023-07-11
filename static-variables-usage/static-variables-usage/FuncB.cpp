#include "FuncB.h"
#include "FuncC.h"
#include <iostream>

// Function in FuncB
void BFunction() {
    std::cout << "Memory address of 'STATIC_VAR' in " << "FuncB" << ": " << &STATIC_VAR <<", value : "<< STATIC_VAR << std::endl;
}