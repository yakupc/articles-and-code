#include "Person.h"

Person::Person(QObject *parent)
    : QObject(parent),m_name(""), m_age(0)
{}

Person::~Person()
{}
