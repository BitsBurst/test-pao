#include "testwidget.h"

#include <QLineSeries>

TestWidget::TestWidget(QWidget *parent)
    : QWidget(parent)
{}

void TestWidget::show(Qt::GlobalColor color)
{
  QPalette pal = QPalette();
  pal.setColor(QPalette::Window, color);

  setAutoFillBackground(true);
  setPalette(pal);

  QVBoxLayout *layout = new QVBoxLayout(this);

  QLineSeries *series = new QLineSeries();
  series->append(0, 16);
  series->append(1, 25);
  series->append(2, 24);
  series->append(3, 19);
  series->append(4, 33);
  series->append(5, 25);
  series->append(6, 34);

  // Create chart, add data, hide legend, and add axis

  QChart *chart_ = new QChart();

  chart_->legend()->hide();
  chart_->addSeries(series);
  chart_->createDefaultAxes();

  chart_->setTitle("Barry Bonds HRs as Pirate");

  chart_->setAnimationOptions(QChart::AllAnimations);

  // Used to display the chart
  QChartView *chart_view_ = new QChartView();

  chart_view_->setRenderHint(QPainter::Antialiasing);
  chart_view_->setChart(chart_);

  chart_view_->show();
  layout->addWidget(chart_view_);

  setLayout(layout);
}
