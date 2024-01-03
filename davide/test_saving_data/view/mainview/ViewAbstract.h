//
// Created by thebitninja on 12/27/23.
//

#ifndef TESTCMAKE2_VIEWABSTRACT_H
#define TESTCMAKE2_VIEWABSTRACT_H


#include <QWidget>

class ViewAbstract: public QWidget{
Q_OBJECT
public:
    ViewAbstract(QWidget * = 0, bool = false);
};


#endif //TESTCMAKE2_VIEWABSTRACT_H
