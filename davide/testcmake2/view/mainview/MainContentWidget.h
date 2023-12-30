//
// Created by thebitninja on 12/26/23.
//

#ifndef TESTCMAKE2_MAINCONTENTWIDGET_H
#define TESTCMAKE2_MAINCONTENTWIDGET_H


#include <QWidget>
#include "CreateView.h"
#include "ModifyView.h"
#include "ContainerManagerAbstract.h"

class MainContentWidget: public ContainerManagerAbstract{
    Q_OBJECT
public:
    MainContentWidget(QWidget* = 0);
    void toggleView();
private:
    ViewAbstract *createView;
    ViewAbstract *modifyView;
};


#endif //TESTCMAKE2_MAINCONTENTWIDGET_H
