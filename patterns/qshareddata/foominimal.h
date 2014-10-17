#ifndef FOOMINIMAL_H
#define FOOMINIMAL_H

#include <QSharedDataPointer>

class FooMinimalData;
class FooMinimal
{
public:
    FooMinimal();
    FooMinimal(const FooMinimal &other);
    FooMinimal &operator=(const FooMinimal &other);
    ~FooMinimal();

private:
    QSharedDataPointer<FooMinimalData> data;
};

#endif // FOOMINIMAL_H
