#include "pch.h"

#include "LibraryA.h"
#include "LibraryC.h"
#include <iostream>

// Function in LibraryA
void libraryAFunction() {
    // Update the value of STATIC_VAR
    STATIC_VAR = 20;

    // Print the memory address and value of STATIC_VAR
    std::cout << "Memory address of 'STATIC_VAR' in " << "LibraryA" << ": " << &STATIC_VAR <<", value : "<< STATIC_VAR << std::endl;
}
