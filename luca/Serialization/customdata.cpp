#include "customdata.h"

std::string CustomData::title() const
{
  return title_;
}

std::string CustomData::innerTitle() const
{
  return custom_inner_data_.data();
}

CustomData::CustomData(std::string title, std::string data)
    : title_(title)
    , custom_inner_data_(CustomInnerData(data))
{}

QJsonObject CustomData::toJson() const
{
  QJsonObject jobject;
  jobject["title"] = QString::fromStdString(title_);
  jobject["custom_inner_data"] = custom_inner_data_.toJson();

  return jobject;
}

CustomData &CustomData::fromJson(QJsonDocument doc)
{
  QJsonObject obj = doc.object();
  title_ = obj["title"].toString().toStdString();
  custom_inner_data_ = custom_inner_data_.fromJson(obj["custom_inner_data"].toObject());

  return *this;
}
