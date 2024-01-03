#include "custominnerdata.h"

void CustomInnerData::setData(const std::string &newData)
{
  data_ = newData;
}

std::string CustomInnerData::data() const
{
  return data_;
}

CustomInnerData::CustomInnerData(std::string data)
    : data_(data)
{}

QJsonObject CustomInnerData::toJson() const
{
  QJsonObject jobject;
  jobject["data"] = QString::fromStdString(data_);

  return jobject;
}

CustomInnerData &CustomInnerData::fromJson(QJsonObject obj)
{
  data_ = obj["data"].toString().toStdString();

  return *this;
}
