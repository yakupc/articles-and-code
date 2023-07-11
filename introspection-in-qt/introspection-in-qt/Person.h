#pragma once

#include <QObject>

class Person : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)
public:
    Person(QObject *parent = nullptr);
    virtual ~Person();
    QString getName() const { return m_name; }
    void    setName(const QString &name)
    {
        m_name = name;
        emit nameChanged();
    }
    int  getAge() const { return m_age; }
    void setAge(int age)
    {
        m_age = age;
        emit ageChanged();
    }
signals:
    void nameChanged();
    void ageChanged();

private:
    QString m_name;
    int     m_age;
};