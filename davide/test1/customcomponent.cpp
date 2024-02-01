#include "customcomponent.h"
#include <QVBoxLayout>
#include <QThread>
CustomComponent::CustomComponent(QWidget* parent): QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    label = new QLabel("Test");
    layout->addWidget(label);
}
void CustomComponent::show() {
    //QThread::msleep(5000);
}
