//
// Created by thebitninja on 12/26/23.
//

#include <QPushButton>
#include <QVBoxLayout>
#include "MainContentWidget.h"
MainContentWidget::MainContentWidget(QWidget *parent): ContainerManagerAbstract(parent){
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
    addView(new ModifyView);
    addView(new CreateView);
    setInitialView(typeid(ModifyView).name());
}

void MainContentWidget::toggleView() {
    if(!getView(typeid(ModifyView).name())->isVisible()){
        getView(typeid(ModifyView).name())->setVisible(true);
        getView(typeid(CreateView).name())->setVisible(false);
    }else{
        getView(typeid(ModifyView).name())->setVisible(false);
        getView(typeid(CreateView).name())->setVisible(true);
    }
}
