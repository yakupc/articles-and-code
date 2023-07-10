#include <QtCore/QCoreApplication>

#include "MyClass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClass myClass;

    return a.exec();
}
