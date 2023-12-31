//
// Created by Luca on 20/12/2023.
//

#ifndef TEST_2_MAINWINDOW_H
#define TEST_2_MAINWINDOW_H

#include "CustomIO.h"

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
};

#endif //TEST_2_MAINWINDOW_H
