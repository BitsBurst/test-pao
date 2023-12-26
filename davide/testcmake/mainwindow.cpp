#include <QHBoxLayout>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui->setupUi(this);
    QHBoxLayout * layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft|Qt::AlignTop);
}

MainWindow::~MainWindow()
{
    delete ui;
}
