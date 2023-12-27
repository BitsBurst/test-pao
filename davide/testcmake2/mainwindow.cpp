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
    setCentralWidget(fake_widget);

    // main layout setup
    h_layout->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);

    h_layout->addWidget(sideBarWidget_, 1);
    h_layout->addWidget(mainContentWidget_, 4);

    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::green);
    fake_widget->setAutoFillBackground(true);
    fake_widget->setPalette(pal);

    connect(sideBarWidget_, &SideBarWidget::BtnClick, this, &MainWindow::clickBtn);
}

MainWindow::~MainWindow() {}

void MainWindow::clickBtn() {
    qDebug() << "btn ok";
    mainContentWidget_->toggleView();
}
