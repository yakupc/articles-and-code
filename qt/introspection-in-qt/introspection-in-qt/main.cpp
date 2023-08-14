#include <QCoreApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>
#include <QMetaMethod>

#include "Person.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    Person           obj;
    obj.setObjectName("myObject");

    // Get the meta-object of the object
    const QMetaObject *metaObject = obj.metaObject();

    // Get the class name
    QString className = metaObject->className();
    qDebug() << "Class Name:" << className;

    // Get the number of properties
    int propertyCount = metaObject->propertyCount();
    qDebug() << "Property Count:" << propertyCount;

    // Iterate over the properties
    for ( int i = 0; i < propertyCount; ++i )
    {
        QMetaProperty property = metaObject->property(i);
        qDebug() << "Property Name:" << property.name() << "Type:" << property.typeName()
                 << "Value:" << property.read(&obj);
    }

    // Get the number of methods
    int methodCount = metaObject->methodCount();
    qDebug() << "Method Count:" << methodCount;

    // Iterate over the methods
    for ( int i = 0; i < methodCount; ++i )
    {
        QMetaMethod method = metaObject->method(i);
        qDebug() << "Method Signature:" << method.methodSignature();
    }
    return app.exec();
}