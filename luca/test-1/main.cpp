#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

QJsonObject createJson()
{
  QJsonObject temp;
  temp["example-1"] = QString("Un esempio!");

  QJsonArray cat;
  for (int i = 0; i < 5; ++i)
    cat.append(i);
  temp["cat"] = cat;

  return temp;
}

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);

  QJsonDocument test_json;

  try {
    QString val;
    QFile file;
    file.setFileName(":/data/test.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    test_json = QJsonDocument::fromJson(val.toUtf8());
  }
  catch (...) {
    qWarning() << "Eccezione!";
    return 1;
  }

  QJsonObject obj_json = test_json.object();
  QJsonValue sensors = obj_json.value(QString("sensors"));
  QJsonArray sensor_item = sensors.toArray();

  QJsonValue categories = obj_json.value(QString("categories"));
  QJsonObject category_item = categories.toObject();

  qWarning() << sensor_item.at(0).toObject().keys();

  QFile saveFile("save.json");
  if (!saveFile.open(QIODevice::WriteOnly)) {
    qWarning("Unable to open the file!");
    return 1;
  }
  QJsonObject temp = createJson();
  saveFile.write(QJsonDocument(temp).toJson());
  saveFile.close();

  // MainWindow w;
  // w.show();
  return a.exec();
}
