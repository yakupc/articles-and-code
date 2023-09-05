#include <iostream>
#include "LibraryDynamic.h"
#include "LibraryStatic.h"

int main()
{
    std::cout << "Hello from the application!" << std::endl;

    int number = 5;

    // Calling functions from the static library
    DisplayMessageStatic();
    int squaredStatic = SquareStatic(number);
    std::cout << "The square of " << number << " is " << squaredStatic << std::endl;

    // Calling functions from the dynamic library
    DisplayMessageDynamic();
    int squaredDynamic = SquareDynamic(number);
    std::cout << "The square of " << number << " is " << squaredStatic << std::endl;
}