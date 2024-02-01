//
// Created by thebitninja on 1/3/24.
//

#ifndef TESTCMAKE2_MYCLASS2_H
#define TESTCMAKE2_MYCLASS2_H


#include <QDataStream>

class myclass2 {
public:
    int num;
    myclass2();
};

QDataStream &operator<<(QDataStream &, const myclass2 &);
QDataStream &operator>>(QDataStream &, myclass2 &);
#endif //TESTCMAKE2_MYCLASS2_H
