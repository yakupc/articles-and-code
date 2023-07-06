#include "pch.h"
#include "LibraryB.h"
#include "LibraryC.h"
#include <iostream>

// Function in LibraryB
void libraryBFunction() {
    std::cout << "Memory address of 'STATIC_VAR' in " << "LibraryB" << ": " << &STATIC_VAR <<", value : "<< STATIC_VAR << std::endl;
}
