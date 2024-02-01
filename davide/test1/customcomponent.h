#ifndef CUSTOMCOMPONENT_H
#define CUSTOMCOMPONENT_H

#include <QLabel>
#include <QWidget>

class CustomComponent: public QWidget
{
    Q_OBJECT
public:
    CustomComponent(QWidget* parent = 0);
    void show();
private:
    QLabel* label;
};

#endif // CUSTOMCOMPONENT_H
