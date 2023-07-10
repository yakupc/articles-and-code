#pragma once

#include <QObject>
#include "InterfaceClass.h"

#define GENERATE_STATIC_META_OBJECT_ERROR

#ifdef  GENERATE_STATIC_META_OBJECT_ERROR
class MyClass  : public InterfaceClass, public QObject
{
    Q_OBJECT

public:
    MyClass(QObject *parent= nullptr);
    ~MyClass();

    void Initialize() {}
};

#else
class MyClass  : public QObject, public InterfaceClass
{
    Q_OBJECT

public:
    MyClass(QObject *parent= nullptr);
    ~MyClass();

    void Initialize() {}
};
#endif //  GENERATE_STATIC_META_OBJECT_ERROR


