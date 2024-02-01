#include "genericqueque.h"
#include <QObject>

GenericWorker *GenericQueque::genericworker = new GenericWorker();
int GenericQueque::queueCounters = 0;
GenericQueque::GenericQueque(bool myWorker) : quequeId(queueCounters++), worker(myWorker ? new GenericWorker() : GenericQueque::genericworker)
{
    connect(worker, &GenericWorker::workCompleted, this, &GenericQueque::workDone);
}
void GenericQueque::doWork(const int input)
{
    worker->doWork(quequeId, input);
}

void GenericQueque::workDone(const int wn, const int result)
{
    if (wn != quequeId)
        return;
    emit workCompleted(result);
}
