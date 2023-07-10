#pragma once

class InterfaceClass 
{
public:
    InterfaceClass();
    ~InterfaceClass();

    virtual void Initialize() = 0;
};
