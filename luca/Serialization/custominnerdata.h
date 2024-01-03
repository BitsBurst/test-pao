#ifndef CUSTOMINNERDATA_H
#define CUSTOMINNERDATA_H

#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <string>

class CustomInnerData
{
private:
  std::string data_;

public:
  CustomInnerData(std::string data = "");
  QJsonObject toJson() const;
  CustomInnerData &fromJson(QJsonObject);
  void setData(const std::string &newData);
  std::string data() const;
};

#endif // CUSTOMINNERDATA_H
