#ifndef WORKERQUEQUE_H
#define WORKERQUEQUE_H
#include <QThread>
#include <QWaitCondition>
class workerqueque : public QThread
{
    Q_OBJECT
public:
    workerqueque(QObject *parent = nullptr);
    ~workerqueque();

signals:
    void workCompleted(const int wn);

protected:
    void run() override;

private:
    int counter;
};

#endif // WORKERQUEQUE_H
