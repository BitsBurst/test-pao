#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <genericqueque.h>
#include <workerqueque.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void done1(const int number);
    void done2(const int number);
    GenericQueque genericQ1;
    GenericQueque genericQ2;
};
#endif // MAINWINDOW_H
