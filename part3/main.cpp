#include "mainwindow.h"
#include <QApplication>
#include"QtDebug"
#include<global.h>
//#include"QChartView"
//using namespace QtCharts;
QStringList Global::cpuRates;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
