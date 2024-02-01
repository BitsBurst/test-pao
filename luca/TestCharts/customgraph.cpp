#include "customgraph.h"

CustomGraph::CustomGraph(QFrame *frame, QWidget *parent)
    : QWidget(parent)
{
  frame_ = frame;
  chart_ = new QChart();
  chart_view_ = new QChartView();
}

void CustomGraph::show()
{
  QLineSeries *series = new QLineSeries();
  series->append(0, 16);
  series->append(1, 25);
  series->append(2, 24);
  series->append(3, 19);
  series->append(4, 33);
  series->append(5, 25);
  series->append(6, 34);

  // Create chart, add data, hide legend, and add axis

  chart_->legend()->hide();
  chart_->addSeries(series);
  chart_->createDefaultAxes();

  // Customize the title font
  QFont font;
  font.setPixelSize(18);
  chart_->setTitleFont(font);
  chart_->setTitleBrush(QBrush(Qt::black));
  chart_->setTitle("Barry Bonds HRs as Pirate");

  // Change the line color and weight
  QPen pen(QRgb(0x000000));
  pen.setWidth(5);
  series->setPen(pen);

  chart_->setAnimationOptions(QChart::AllAnimations);

  // Used to display the chart
  chart_view_->setRenderHint(QPainter::Antialiasing);
  chart_view_->setChart(chart_);

  chart_view_->setParent(frame_);
  chart_view_->setFixedSize(frame_->size());

  chart_view_->show();
}
