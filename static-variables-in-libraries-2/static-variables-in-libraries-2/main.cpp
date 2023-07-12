// static-variables-in-libraries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LibraryA.h"
#include "LibraryB.h"

int main()
{
    // Call functions from LibraryA and LibraryB
    libraryAFunction();
    libraryBFunction();
}