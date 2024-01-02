#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  TestWidget *test = new TestWidget();
  test->show(Qt::black);

  TestWidget *test2 = new TestWidget();
  test2->show(Qt::red);

  QWidget *test_container = new QWidget(this);
  QHBoxLayout *layout = new QHBoxLayout(test_container);
  layout->addWidget(test);
  layout->addWidget(test2);

  layout->setContentsMargins(0, 0, 0, 0);

  test_container->setLayout(layout);

  setCentralWidget(test_container);
}

MainWindow::~MainWindow()
{
  delete ui;
}

