#ifndef CUSTOMDATA_H
#define CUSTOMDATA_H

#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include "custominnerdata.h"
#include <string>

class CustomData
{
private:
  CustomInnerData custom_inner_data_;
  std::string title_;

public:
  CustomData(std::string title = "", std::string data = "");

  QJsonObject toJson() const;
  CustomData &fromJson(QJsonDocument);
  std::string title() const;
  std::string innerTitle() const;
};

#endif // CUSTOMDATA_H
