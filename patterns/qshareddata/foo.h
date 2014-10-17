#ifndef FOO_H
#define FOO_H

#include <QSharedDataPointer>

// ! Forward declaration the FooData class

class FooData;

class Foo
{
public:
    // ! Default ctor
    Foo();

    // ! Copy ctor
    Foo(const Foo &other);

    // ! Assignment operator
    Foo &operator=(const Foo &other);

    // ! Dtor
    // ! Must be implemented, even if implementation is empty!
    // ! Otherwise you get a compiler error (invalid use of incomplete type 'class FooData')
    ~Foo();

public:
    // ! helper method for this example
    int ref() const;

public:
    // ! create getters for your members
    QString member1() const;

    // ! create setters for your members
    void setMember1(const QString &member1);

private:
    // ! Create a private QSharedDataPointer
    // ! for the forward declare class
    QSharedDataPointer<FooData> data;
};

#endif // FOO_H
