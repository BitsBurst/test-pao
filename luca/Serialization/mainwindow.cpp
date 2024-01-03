#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  CustomData test("Titolo 1", "Titolo 2");

  QFile file("file.json");

  if (!file.open(QIODevice::ReadWrite | QFile::Text)) {
    QMessageBox::warning(nullptr, "Warning", "Can't open the file: " + file.errorString());
  }

  QJsonObject temp = test.toJson();
  file.write(QJsonDocument(temp).toJson());
  file.close();

  QFile file2("file.json");

  if (!file2.open(QIODevice::ReadWrite | QFile::Text)) {
    QMessageBox::warning(nullptr, "Warning", "Can't open the file: " + file.errorString());
  }
  QString val = file2.readAll();
  QJsonDocument jsonDoc = QJsonDocument::fromJson(val.toUtf8());

  CustomData read;
  read.fromJson(jsonDoc);

  qWarning() << read.title();
  qWarning() << read.innerTitle();
}

MainWindow::~MainWindow()
{
  delete ui;
}

