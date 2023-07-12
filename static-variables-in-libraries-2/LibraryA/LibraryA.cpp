#include "pch.h"

#include "LibraryA.h"
#include "LibraryC.h"
#include <iostream>

int VAR4;

// Function in LibraryA
void libraryAFunction() {
    // Update the value of VAR
    VAR = 20;
    VAR2 = 20;
    VAR3 = 20;
    VAR4 = 20;
    VAR5 = 20;

    std::cout << "Memory address of 'VAR' in " << "LibraryA" << ": " << &VAR <<", value : "<< VAR << std::endl;
    std::cout << "Memory address of 'VAR2' in " << "LibraryA" << ": " << &VAR2 <<", value : "<< VAR2 << std::endl;
    std::cout << "Memory address of 'VAR3' in " << "LibraryA" << ": " << &VAR3 <<", value : "<< VAR3 << std::endl;
    std::cout << "Memory address of 'VAR4' in " << "LibraryA" << ": " << &VAR4 <<", value : "<< VAR4 << std::endl;
    std::cout << "Memory address of 'VAR5' in " << "LibraryA" << ": " << &VAR5 <<", value : "<< VAR5 << std::endl;
    
    std::cout << "-----" << std::endl;
}
