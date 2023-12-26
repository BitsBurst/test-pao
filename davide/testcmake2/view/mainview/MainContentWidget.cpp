//
// Created by thebitninja on 12/26/23.
//

#include <QPushButton>
#include <QVBoxLayout>
#include "MainContentWidget.h"
MainContentWidget::MainContentWidget(QWidget *parent): QWidget(parent){
    std::list<QPushButton*> buttonList;
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    setLayout(layout);
    for(int i = 0; i < 10; i++){
        QString name = "Button ";
        name += std::to_string(i);
        buttonList.push_front(new QPushButton(name));
        layout->addWidget(buttonList.front());
        buttonList.front()->show();
    }
    setSizePolicy(QSizePolicy:: MinimumExpanding, QSizePolicy ::Expanding );
}