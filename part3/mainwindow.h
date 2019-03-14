#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"qtimer.h"
#include <QMainWindow>
#include"util.h"
#include"mythread.h"
#include <QtCharts>
#include<qlist.h>
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    Util util;
    QTimer *timer1;
    QTimer *timer3;
    MyThread* myThread;

    double total=0.0;
    double idle=0.0;
    double rate=0.0;

    bool searchMode=false;

    QValueAxis *axisYProcess;
    QValueAxis *axisXProcess;

    QValueAxis *axisYMem;
    QValueAxis *axisXMem;
    QValueAxis *axisYSwap;
    QValueAxis *axisXSwap;

    QLineSeries * linesProcess;
    QLineSeries * linesMem;
    QLineSeries * linesSwap;

    QList<QMap<QString,QString>>processMapList;
    QList<double> cpuStates;

    QList<double> memRates;

    int rowSelect=-1;

    int i=0;

    QChart*processLineChart;
    QChart*memLineChart;
    QChart*swapLineChart;

    QStringList header;
    void initWidgets();
    void initVarible();
    void initTableWidget();
    void chartViewPainted(QList<double> pointList,QLineSeries* lines,QChartView*  widget,
                          QChart * lineChart,QValueAxis* axisY,QValueAxis* axisX,QString title);

public slots:
    void initDynamicWidgets();
    void dynamicProcessRate();
    void dynamicMemRate();
    void dynamicSwapRate();
    void tableClicked(int row,int column);
    void killBtnClicked();
    void searchBtnClicked();
    void shutdown();
};



#endif // MAINWINDOW_H
