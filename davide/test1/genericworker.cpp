#include "genericworker.h"
WorkObject::WorkObject(int workId, int workInput): workId(workId), workInput(workInput)
{

}
GenericWorker::GenericWorker(QObject *parent) : QThread(parent), emptyList(0) {
    start();
}
GenericWorker::~GenericWorker()
{
    wait();
}
void GenericWorker::doWork(const int wn, const int input)
{
    works.push_front(new WorkObject(wn, input));
    emptyList.release();
}
void GenericWorker::run() {
    while(true) {
        emptyList.acquire();
        WorkObject *wobj = works.back();
        works.pop_back();
        qDebug() << "WorkId: "<< wobj->workId << ", ThreadId: " << QThread::currentThreadId();
        QThread::sleep(1);
        emit workCompleted(wobj->workId, wobj->workInput);
    }
}
