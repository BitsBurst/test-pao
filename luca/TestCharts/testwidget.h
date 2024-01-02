#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QLabel>
#include <QObject>
#include <QPalette>
#include <QVBoxLayout>
#include <QWidget>

#include <QChart>
#include <QChartView>

class TestWidget : public QWidget
{
  Q_OBJECT
public:
  TestWidget(QWidget *parent = nullptr);
  void show(Qt::GlobalColor);
};

#endif // TESTWIDGET_H
