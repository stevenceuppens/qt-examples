#ifndef FOO_P_H
#define FOO_P_H

#include <QSharedData>
#include <QString>
#include <QDebug>

class FooData : public QSharedData
{
public:
    FooData()
    {
        qDebug() << "FooData - Default Ctor";
    }

public:
    QString member1;

};

#endif // FOO_P_H
