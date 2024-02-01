#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include "view/mainview/SideBarWidget.h"
#include "view/mainview/MainContentWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QHBoxLayout* h_layout;
    QWidget* fake_widget;
    SideBarWidget* sideBarWidget_;
    MainContentWidget* mainContentWidget_;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void clickBtn();
};
#endif // MAINWINDOW_H
