#ifndef CUSTOMIO_H
#define CUSTOMIO_H

#include <QJsonObject>
#include <QIODevice>
#include <QFile>
#include <QJsonDocument>
#include <map>
#include <string>

using std::string;

class CustomIO
{
private:
  std::map<string, QFile*> file_list_;

public:
  CustomIO();

  QJsonObject get_data(string key_ = "") const;
  void write_data(string key_ = "", QJsonObject* data = new QJsonObject());

  void open_file(string file_path, string file_id);
  void close_file(string file_id)
};

#endif // CUSTOMIO_H
