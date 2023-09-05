// MyDynamicLibrary.cpp
#include "pch.h"
#include <iostream>
#include "LibraryDynamic.h"

int SquareDynamic(int num) {
    return num * num;
}

void DisplayMessageDynamic() {
    std::cout << "Hello from the dynamic library!" << std::endl;
}