//
// Created by thebitninja on 1/3/24.
//

#include "myclass2.h"

myclass2::myclass2(): num(10) {

}
QDataStream &operator<<(QDataStream &out, const myclass2 &item)
{
    out << item.num;
    return out;
}
QDataStream &operator>>(QDataStream &in, myclass2 &item)
{
    in >> item.num;
    return in;
}