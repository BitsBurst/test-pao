//
// Created by thebitninja on 12/26/23.
//

#include <QPushButton>
#include <QVBoxLayout>
#include "SideBarWidget.h"

SideBarWidget::SideBarWidget(QWidget *parent): QWidget(parent){
    std::list<QPushButton*> buttonList;
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    setLayout(layout);
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(pal);
    for(int i = 0; i < 10; i++){
        QString name = "Button ";
        name += std::to_string(i);
        buttonList.push_front(new QPushButton(name));
        layout->addWidget(buttonList.front(), 1);
        buttonList.front()->show();
        connect(buttonList.front(), &QPushButton::clicked, this, &SideBarWidget::clickBtn);
    }
    setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Expanding);
}

void SideBarWidget::clickBtn() {
    qDebug() << "btn clicked";
    emit BtnClick();
}
