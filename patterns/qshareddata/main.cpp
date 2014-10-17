/*------------------------------------------------------------------------------------
 * QSharedData implements "implicit sharing" (copy-on-write)
 * ------------------------------------------------------------------------------------
 * # this to reduce memory usage.
 * # to avoid the needless copying of data.
 * # to easify memory managment
 * ------------------------------------------------------------------------------------
 */

/*------------------------------------------------------------------------------------
 * How does QSharedData knows when to create a copy of FooData ?
 *------------------------------------------------------------------------------------
 * # Getter functions are constant (they guarantee to not alter/modify the object)
 *
 * -> QString member1() const;
 *
 * when calling a const function, that accesses the FooData object, no copy will be executed
 *
 *------------------------------------------------------------------------------------
 * # Setter functions are not constant (they alter/modify the object)
 *
 * -> void setMember1(const QString &member1);
 *
 * when calling a non const function, that accesses the FooData object,
 * and when the reference count is greather than 1, executes a copy!
 *
 * ------------------------------------------------------------------------------------
 */

/*------------------------------------------------------------------------------------
 * When to use QSharedData
 *------------------------------------------------------------------------------------
 * # for objects that frequently needs to be copied
 * # for objects that act as a data type (QString, QRect, ...)
 * ------------------------------------------------------------------------------------
 */

#include <QDebug>

#include "foo.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    qDebug() << "# foo1 - create";
    // Calls the default ctor of Foo
    // Foo(1) object gets created
    // FooData(1) object gets created
    // -> FooData(1) Reference count = 1
    Foo foo1;
    qDebug() << "# foo1 - ref: " << foo1.ref();

    qDebug() << endl;

    qDebug() << "# foo1 - setMember1";
    // Change some data of foo1
    // -> FooData(1) Reference count = 1
    foo1.setMember1("hello");
    qDebug() << "# foo1 - ref: " << foo1.ref();

    qDebug() << endl;

    qDebug() << "# foo2 - copy from foo1";
    // Calls the copy ctor of Foo
    // Foo(2) object gets created
    // -> FooData(1) Reference count = 2
    Foo foo2(foo1);
    qDebug() << "# foo1 - ref: " << foo1.ref();
    qDebug() << "# foo2 - ref: " << foo2.ref();

    qDebug() << endl;

    qDebug() << "# foo3 - assign from foo2";
    // Calls the assignment operator of Foo
    // Foo(3) object gets created
    // -> FooData(1) Reference count = 3
    Foo foo3;
    qDebug() << "# foo1 - ref: " << foo1.ref();
    qDebug() << "# foo2 - ref: " << foo2.ref();
    qDebug() << "# foo3 - ref: " << foo3.ref();
    foo3 = foo2;
    qDebug() << "# foo1 - ref: " << foo1.ref();
    qDebug() << "# foo2 - ref: " << foo2.ref();
    qDebug() << "# foo3 - ref: " << foo3.ref();

    qDebug() << endl;

    // Read some data of foo3
    // -> FooData(1) Reference count = 3
    qDebug() << "#" << foo2.member1() << " - " << foo3.member1();

    qDebug() << "# foo3 - setMember1";
    // Change some data of foo3
    // FooData(2) object gets copyed
    // -> FooData(1) Reference count = 2
    // -> FooData(2) Reference count = 1
    foo3.setMember1("world");
    qDebug() << "# foo1 - ref: " << foo1.ref();
    qDebug() << "# foo2 - ref: " << foo2.ref();
    qDebug() << "# foo3 - ref: " << foo3.ref();

    qDebug() << endl;

    // Read some data of foo3
    // -> FooData(1) Reference count = 2
    // -> FooData(2) Reference count = 1
    qDebug() << "#" <<  foo2.member1() << " - " << foo3.member1();
}

