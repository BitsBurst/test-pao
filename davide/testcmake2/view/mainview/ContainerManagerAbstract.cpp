//
// Created by thebitninja on 12/27/23.
//

#include "ContainerManagerAbstract.h"

ContainerManagerAbstract::ContainerManagerAbstract(QWidget *p): QWidget(p), layout(new QVBoxLayout(this)) {
    layout->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    setLayout(layout);
    setSizePolicy(QSizePolicy:: MinimumExpanding, QSizePolicy ::Expanding );
}

void ContainerManagerAbstract::addView(ViewAbstract *view) {
    viewList[typeid(*view).name()] = view;
    layout->addWidget(view);
}

ViewAbstract* ContainerManagerAbstract::getView(const std::string& view) {
    return viewList.find(view) != viewList.end() ? viewList[view] : nullptr;
}

void ContainerManagerAbstract::setInitialView(const std::string &view) {
    if(viewList.find(view) != viewList.end())
        viewList[view]->setVisible(true);
}

