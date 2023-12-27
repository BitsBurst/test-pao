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
    std::unordered_map<std::string, ViewAbstract*> viewList;
    QVBoxLayout* layout;
protected:
    void addView(ViewAbstract*);
    ViewAbstract* getView(const std::string& view);
    void setInitialView(const std::string& view);
};


#endif //TESTCMAKE2_CONTAINERMANAGERABSTRACT_H
