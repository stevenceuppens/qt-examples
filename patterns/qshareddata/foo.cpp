#include "foo.h"
#include "foo_p.h"

#include <QDebug>

Foo::Foo()
    : data(new FooData)
{
    qDebug() << "Foo - Default Ctor";
}

Foo::Foo(const Foo &other)
    : data(other.data)
{
    qDebug() << "Foo - Copy Ctor";
}

Foo &Foo::operator=(const Foo &other)
{
    qDebug() << "Foo - Assignment Operator";

    if (this != &other)
        data.operator=(other.data);
    return *this;
}

Foo::~Foo()
{ }

int Foo::ref() const
{
    return data->ref;
}

QString Foo::member1() const
{
    return data->member1;
}

void Foo::setMember1(const QString &member1)
{
    data->member1 = member1;
}
