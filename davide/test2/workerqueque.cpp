#include "workerqueque.h"
#include <QDebug>
workerqueque::workerqueque(QObject *parent) : QThread(parent), counter(0) {}
workerqueque::~workerqueque()
{
    wait();
}

void workerqueque::run()
{
    while (true)
    {
        qDebug() << "Thread Operation"
                 << ", ThreadId: " << QThread::currentThreadId();
        QThread::sleep(1);
        counter++;
        emit workCompleted(counter);
    }
}
