//
// Created by Luca on 20/12/2023.
//

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton* button = new QPushButton("Hello world!", nullptr);
    button->show();

    CustomIO::open("data");
    qWarning() << CustomIO::get_content("data");
    CustomIO::close("data");

    setCentralWidget(button);
}

MainWindow::~MainWindow() = default;