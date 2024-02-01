//
// Created by thebitninja on 1/2/24.
//

#ifndef TESTCMAKE2_MYCLASS_H
#define TESTCMAKE2_MYCLASS_H

#include <QString>
#include <QList>
#include "myclass2.h"

class myclass {
public:
    myclass();
    QString name;
    myclass2 test;
    QList<myclass2> list;
};
QDataStream &operator<<(QDataStream &, const myclass &);
QDataStream &operator>>(QDataStream &, myclass &);
#endif //TESTCMAKE2_MYCLASS_H
