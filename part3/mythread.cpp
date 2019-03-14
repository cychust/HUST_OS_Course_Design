#include "mythread.h"

MyThread::MyThread(QObject *parent):QThread (parent)
{

}
MyThread::~MyThread(){

}

void MyThread::run(){
    while (true) {
       QString cpuRate=0;
       cpuRate=util.CPU_Utilization_Rate ();
//       qDebug()<<cpuRate;
       if(Global::cpuRates.size ()<100){
           Global::cpuRates.push_back (cpuRate);
           qDebug()<<Global::cpuRates.size ();
       }else{
           Global::cpuRates.pop_front();
           Global::cpuRates.push_back (cpuRate);
           QThread::sleep (2);
       }
    }

}
//QStringList MyThread::cpu_rates (){
//    return cpuRates;
//}
