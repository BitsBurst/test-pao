#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <customcomponent.h>
#include <workerqueque.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), genericQ1(true)
{
    ui->setupUi(this);
    CustomComponent *cc = new CustomComponent();
    setCentralWidget(cc);
    cc->show();
    genericQ1.doWork(1);
    genericQ2.doWork(2);
    genericQ1.doWork(3);
    genericQ2.doWork(4);

    qDebug() << "ThreadId: " << QThread::currentThreadId();
    connect(&genericQ1, &GenericQueque::workCompleted, this, &MainWindow::done1);
    connect(&genericQ2, &GenericQueque::workCompleted, this, &MainWindow::done2);
}
void MainWindow::done1(const int number)
{
    qDebug() << "Done1 Thread Result:" << number << ", ThreadId: " << QThread::currentThreadId();
}
void MainWindow::done2(const int number)
{
    qDebug() << "Done2 Thread Result:" << number << ", ThreadId: " << QThread::currentThreadId();
}
MainWindow::~MainWindow()
{
    delete ui;
}
