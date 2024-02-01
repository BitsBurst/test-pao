//
// Created by thebitninja on 12/27/23.
//

#ifndef TESTCMAKE2_CONTAINERMANAGERABSTRACT_H
#define TESTCMAKE2_CONTAINERMANAGERABSTRACT_H


#include <QWidget>
#include <QVBoxLayout>
#include "ViewAbstract.h"

class ContainerManagerAbstract: public QWidget{
    Q_OBJECT
public:
    ContainerManagerAbstract(QWidget* = 0);
private:
    ViewAbstract* currentView;
    QVBoxLayout* layout;
protected:
    void setView(ViewAbstract* view);
    ViewAbstract* getCurrentView();
};


#endif //TESTCMAKE2_CONTAINERMANAGERABSTRACT_H
