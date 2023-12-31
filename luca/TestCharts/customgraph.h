#ifndef CUSTOMGRAPH_H
#define CUSTOMGRAPH_H

#include <QObject>
#include <QSizePolicy>
#include <QWidget>
#include <QtCharts>

#include <vector>

class CustomGraph : public QWidget
{
  Q_OBJECT

private:
  QFrame *frame_;
  QChart *chart_;
  QChartView *chart_view_;

public:
  CustomGraph(QFrame *frame = nullptr, QWidget *parent = nullptr);
  void show();
};

#endif // CUSTOMGRAPH_H
