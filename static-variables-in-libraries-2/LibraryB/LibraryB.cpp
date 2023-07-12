#include "pch.h"
#include "LibraryB.h"
#include "LibraryC.h"
#include <iostream>

int VAR4;

// Function in LibraryB
void libraryBFunction() {
    std::cout << "Memory address of 'VAR' in " << "LibraryB" << ": " << &VAR <<", value : "<< VAR << std::endl;
    std::cout << "Memory address of 'VAR2' in " << "LibraryB" << ": " << &VAR2 <<", value : "<< VAR2 << std::endl;
    std::cout << "Memory address of 'VAR3' in " << "LibraryB" << ": " << &VAR3 <<", value : "<< VAR3 << std::endl;
    std::cout << "Memory address of 'VAR4' in " << "LibraryB" << ": " << &VAR4 <<", value : "<< VAR4 << std::endl;
    std::cout << "Memory address of 'VAR5' in " << "LibraryB" << ": " << &VAR5 <<", value : "<< VAR5 << std::endl;
}
