#include "foominimal.h"
#include "foominimal_p.h"

FooMinimal::FooMinimal()
    : data(new FooMinimalData)
{ }

FooMinimal::FooMinimal(const FooMinimal &other)
    : data(other.data)
{ }

FooMinimal &FooMinimal::operator=(const FooMinimal &other)
{
    if (this != &other)
        data.operator=(other.data);
    return *this;
}

FooMinimal::~FooMinimal()
{ }
