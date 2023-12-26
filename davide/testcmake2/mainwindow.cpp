#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    h_layout(new QHBoxLayout),
    fake_widget(new QWidget),
    mainContentWidget_(new MainContentWidget),
    sideBarWidget_(new SideBarWidget)
{
    //Setting Setup
    setMinimumSize(1920,1080);
    //Override CentralWidget
    fake_widget->setLayout(h_layout);
    fake_widget->setSizePolicy(QSizePolicy ::Maximum , QSizePolicy ::Maximum );
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::green);
    fake_widget->setAutoFillBackground(true);
    fake_widget->setPalette(pal);
    setCentralWidget(fake_widget);

    // main layout setup
    h_layout->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);

    h_layout->addWidget(sideBarWidget_, 1);
    h_layout->addWidget(mainContentWidget_, 4);
    h_layout->setSpacing(0);
}

MainWindow::~MainWindow() {}
