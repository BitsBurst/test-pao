#ifndef CUSTOMIO_H
#define CUSTOMIO_H

#include <QJsonObject>
#include <map>
#include <string>

using std::map;
using std::string;

class CustomIO
{
private:
  map<string, QJsonObject> file_list_;

public:
  CustomIO();
};

#endif // CUSTOMIO_H
