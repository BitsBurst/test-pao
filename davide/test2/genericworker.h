#ifndef GENERICWORKER_H
#define GENERICWORKER_H

#include <QSemaphore>
#include <QThread>
#include <deque>
#include <QDebug>
#include <QWaitCondition>

using namespace std;
class WorkObject
{
public:
    int workId;
    int workInput;
    WorkObject(int, int);
    
};
class GenericWorker : public QThread
{
    Q_OBJECT
public:
    GenericWorker(QObject * = nullptr);
    ~GenericWorker();
    std::deque<WorkObject*> works;
    void doWork(const int, const int);
    QSemaphore emptyList;
signals:
    void workCompleted(const int, const int);
protected:
    void run() override;

};

#endif // GENERICWORKER_H
