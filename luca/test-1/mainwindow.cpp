#include "mainwindow.h"
#include "buttongroup.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  vector<QPushButton *> buttons;
  vector<QPushButton *> buttons_2;

  for (int i = 0; i < 3; ++i) {
    buttons.push_back(new QPushButton(QString::fromStdString("Test" + std::to_string(i))));
  }

  ButtonGroup *btn_group = new ButtonGroup("Un titolo fantastico!", buttons);
  btn_group->show();

  for (int i = 3; i < 6; ++i) {
    buttons_2.push_back(new QPushButton(QString::fromStdString("Test " + std::to_string(i))));
  }

  buttons_2.push_back(buttons.at(1));

  ButtonGroup *btn_group_2 = new ButtonGroup("Un titolo fantastico!", buttons_2);
  btn_group_2->show();

  ui->horizontalLayoutWidget->layout()->addWidget(btn_group);
  ui->horizontalLayoutWidget->layout()->addWidget(btn_group_2);
}

MainWindow::~MainWindow()
{
  delete ui;
}

