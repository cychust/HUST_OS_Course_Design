#ifndef MYTHREAD_H
#define MYTHREAD_H
#include"qthread.h"
#include"util.h"
#include"global.h"
class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(QObject*par);
    ~MyThread();
    void run();
//    QStringList cpu_rates();
private:
    Util util;
//    QStringList cpuRates;
};

#endif // MYTHREAD_H
