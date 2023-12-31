#include "customio.h"

CustomIO::CustomIO()
{}

void CustomIO::open_file(string file_path, string file_id)
{
    QFile* file;

    file->setFileName(file_path);
    file->open(QIODevice::ReadWrite);

    file_list_.insert({ file_id, file });
}

void CustomIO::close_file(string file_id)
{
    QFile* temp = file_list_[file_id];
    temp->close();
}