#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include "myclass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    myclass2 aaa;
    myclass t1;
    t1.name = "can";
    t1.test.num = 12;
    t1.list.push_front(aaa);
    {
        QFile file("file.json");
        file.open(QIODevice::WriteOnly);
        QDataStream out(&file);
        out << t1;
    }
    {
        QFile file("file.json");
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        myclass t2;
        in >> t2;
        qDebug() << t2.name;
        qDebug() << t2.test.num;
        qDebug() << t2.list.front().num;
    }
    return a.exec();
}
