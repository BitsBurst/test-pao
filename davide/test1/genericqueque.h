#ifndef GENERICQUEQUE_H
#define GENERICQUEQUE_H

#include "genericworker.h"
class GenericQueque: public QObject
{
    Q_OBJECT
public:
    GenericQueque(bool = false);
    void doWork(const int);
private:
    static GenericWorker* genericworker;
    static int queueCounters;
    GenericWorker* worker;
    int quequeId;
signals:
    void workCompleted(const int);
protected:
    void workDone(const int, const int);
};

#endif // GENERICQUEQUE_H
