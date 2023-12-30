//
// Created by thebitninja on 12/26/23.
//

#include <QPushButton>
#include <QVBoxLayout>
#include "MainContentWidget.h"
MainContentWidget::MainContentWidget(QWidget *parent): ContainerManagerAbstract(parent), modifyView(new ModifyView), createView(new CreateView){
    /*for(int i = 0; i < 10; i++){
        QString name = "Button ";
        name += std::to_string(i);
        buttonList.push_front(new QPushButton(name));
        layout->addWidget(buttonList.front());
        buttonList.front()->show();
    }*/
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::yellow);
    setAutoFillBackground(true);
    setPalette(pal);
    setView(createView);
}

void MainContentWidget::toggleView() {
    if(getCurrentView() == modifyView){
        setView(createView);
    }else{
        setView(modifyView);
    }
}
