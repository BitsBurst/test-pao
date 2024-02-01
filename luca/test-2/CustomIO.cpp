//
// Created by Luca on 20/12/2023.
//

#include "CustomIO.h"

map<QString, QFile*> CustomIO::file_list_ = map<QString, QFile*>();

void CustomIO::open(const QString& file_id)
{
    QString filename = QFileDialog::getOpenFileName(nullptr, "Open File");
    QFile* file = new QFile(filename);
    if (!file->open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(nullptr, "Warning", "Can't open the file: " + file->errorString());
    }

    file_list_.insert({file_id, file});
    file->close();
}

void CustomIO::close(const QString& file_id)
{
    map<QString, QFile*>::iterator iterator = file_list_.find(file_id);
    if (iterator == file_list_.end()) {
        QMessageBox::warning(nullptr, "Warning", "This file doesen't exist");
        return;
    }
    delete file_list_.at(file_id);
    file_list_.erase(file_id);
}

QJsonObject CustomIO::get_content(const QString& file_id)
{
    map<QString, QFile*>::iterator iterator = file_list_.find(file_id);
    if (iterator == file_list_.end()) {
        QMessageBox::warning(nullptr, "Warning", "This file doesen't exist");
        return QJsonObject();
    }

    QFile* file = file_list_.at(file_id);
    if (!file->open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(nullptr, "Warning", "Can't open the file: " + file->errorString());
    }

    QString val = file->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());

    return doc.object();
}

map<QString, QFile*>& CustomIO::get_file_list() {
    return file_list_;
}