//
// Created by Luca on 20/12/2023.
//

#ifndef TEST_2_CUSTOMIO_H
#define TEST_2_CUSTOMIO_H

#include <map>
#include <string>
#include <QFile>
#include <QTextStream>
#include <ostream>
#include <QFileDialog>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

using std::string;
using std::ostream;
using std::map;


class CustomIO {

private:
    static map<QString, QFile*> file_list_;

public:

    static void open(const QString& file_id = QString());
    static void close(const QString& file_id = QString());

    static map<QString, QFile*>& get_file_list();
    static QJsonObject get_content(const QString& file_id);

};


#endif //TEST_2_CUSTOMIO_H
