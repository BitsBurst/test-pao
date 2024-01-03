//
// Created by thebitninja on 12/27/23.
//

#include "ContainerManagerAbstract.h"

ContainerManagerAbstract::ContainerManagerAbstract(QWidget *p): QWidget(p), layout(new QVBoxLayout(this)), currentView(
        nullptr) {
    layout->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    setLayout(layout);
    setSizePolicy(QSizePolicy:: MinimumExpanding, QSizePolicy ::Expanding );
}

void ContainerManagerAbstract::setView(ViewAbstract *view) {
    layout->addWidget(view);
    if(currentView != nullptr)
    currentView->setVisible(false);
    view->setVisible(true);
    if(currentView != nullptr)
    layout->removeWidget(currentView);
    currentView = view;
}

ViewAbstract *ContainerManagerAbstract::getCurrentView() {
    return currentView;
}

