//
// Created by thebitninja on 1/2/24.
//

#include "myclass.h"

myclass::myclass(): name("name"), test() {
}
QDataStream &operator<<(QDataStream &out, const myclass &item)
{
    out << item.name
        << item.test
        << item.list;
    return out;
}
QDataStream &operator>>(QDataStream &in, myclass &item)
{
    in >> item.name
        >> item.test
        >> item.list;
    return in;
}