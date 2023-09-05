#include "pch.h"
#include <iostream>
#include "LibraryStatic.h"

int SquareStatic(int num) {
    return num * num;
}

void DisplayMessageStatic() {
    std::cout << "Hello from the static library!" << std::endl;
}
