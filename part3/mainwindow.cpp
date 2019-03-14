#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"util.h"
#include"qabstractitemview.h"
#include"qstringlist.h"
#include"QChartView"
#include"global.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer1=new QTimer();
    timer3=new QTimer();
    Util util;
    qWarning() << "**** " <<util.host_info ();
    qWarning() << "**** " <<util.sys_version ();
    qWarning() << "**** " <<util.CPU_model();
    qWarning() << "**** " <<util.CPU_frequence();
    util.process_stat ();
    initWidgets ();
    initDynamicWidgets ();
    initVarible ();
//    iniDynamicVarible ();
    dynamicMemRate ();
    dynamicProcessRate ();
    dynamicSwapRate ();
}

MainWindow::~MainWindow()
{
    delete timer1;
    delete timer3;
    delete axisXProcess;
    delete axisYProcess;
    delete axisXMem;
    delete axisYMem;
    delete axisXSwap;
    delete axisYSwap;
    delete myThread;
    delete ui;
}


void MainWindow::initVarible(){
    this->timer1=new QTimer();
    this->timer3=new QTimer();
    connect(timer1,SIGNAL (timeout()),this,SLOT(initDynamicWidgets ()));
//    connect(timer3,SIGNAL (timeout()),this,SLOT(iniDynamicVarible()));

    connect(timer3,SIGNAL (timeout()),this,SLOT(dynamicProcessRate()));
    connect(timer3,SIGNAL (timeout()),this,SLOT(dynamicMemRate()));
    connect(timer3,SIGNAL (timeout()),this,SLOT(dynamicSwapRate()));

    connect (ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT (tableClicked(int,int)));
    connect (ui->killer_btn,SIGNAL (clicked()),this,SLOT (killBtnClicked()));
    connect (ui->search_btn,SIGNAL (clicked()),this,SLOT (searchBtnClicked()));
    connect (ui->actionshutdown,SIGNAL (clicked()),this,SLOT(shutdown()));
    timer1->start (1000);
    timer3->start (1000);
//    connect (ui->tabWidget,SIGNAL(current))

//    myThread=new MyThread(this);
//    myThread->start ();

//    lineChart=new QChart;
//    memLineChart=new QChart;
//    swapLineChart=new QChart;

    axisYProcess=new QValueAxis();
    axisXProcess=new QValueAxis();
    axisYProcess->setRange (0,100);
    axisXProcess->setRange (0,100);
    axisXProcess->setTickCount(2); //主分隔个数：0到10分成20个单位
    axisXProcess->setMinorTickCount(4); //每个单位之间绘制了多少虚网线

    axisYMem=new QValueAxis();
    axisXMem=new QValueAxis();
    axisYMem->setRange (0,100);
    axisXMem->setRange (0,100);
    axisXMem->setTickCount(2); //主分隔个数：0到10分成20个单位
    axisXMem->setMinorTickCount(4); //每个单位之间绘制了多少虚网线

    axisYSwap=new QValueAxis();
    axisXSwap=new QValueAxis();
    axisYSwap->setRange (0,100);
    axisXSwap->setRange (0,100);
    axisXSwap->setTickCount(2); //主分隔个数：0到10分成20个单位
    axisXSwap->setMinorTickCount(4); //每个单位之间绘制了多少虚网线


    for(int i=0;i<=100;i++){
        cpuStates.push_back(-1.0);
        memRates.push_back (-1.0);
    }

}

void MainWindow::shutdown (){
    system ("halt");
}

void MainWindow::tableClicked(int row,int column){
    rowSelect=row;
    qDebug()<<rowSelect;

}
void MainWindow::killBtnClicked (){
    if(rowSelect==-1){
        return;
    }
    if(rowSelect>=processMapList.size ()){
        return;
    }
    QMap<QString,QString> process=processMapList.at(rowSelect);
    long pid=process["pid"].toLong ();
    if(pid>0){
        if(!kill(pid,SIGKILL))qDebug()<<"kill success";
    }
}


void MainWindow::dynamicProcessRate(){
    QStringList tmp=util.cpu_rates ();
    double total2=tmp[0].toDouble ();
    double idle2=tmp[1].toDouble();
    double rate2;
    rate2=(1-(idle2-idle)/(total2-total))*100.0;
    if(rate2<0)rate2-=rate2;
    if(rate2!=0&&rate2!=100){
        rate=rate2;
        total=total2;
        idle=idle2;
    }
    cpuStates.pop_front();
    cpuStates.push_back(rate);
    processLineChart=new QChart();
    chartViewPainted (cpuStates,linesProcess, ui->widget,processLineChart,axisYProcess,axisXProcess,"cpu frequence");
}

void MainWindow::dynamicMemRate(){
    memRates.pop_front();
    double memRate=util.mem_rate ();
    memRates.push_back (memRate);
    memLineChart=new QChart();
    chartViewPainted (memRates,linesMem, ui->mem_widget,memLineChart,axisYMem,axisXMem,"MEMORY");

}
void MainWindow::dynamicSwapRate(){
    memRates.pop_front();
    double memRate=util.mem_rate ();
    memRates.push_back (memRate);
//    auto swapLineChart=new QChart();
    swapLineChart=new QChart();
    chartViewPainted (memRates,linesSwap, ui->swap_widget,swapLineChart,axisYSwap,axisXSwap,"SWAP ");
}
void MainWindow::chartViewPainted(QList<double> pointList,QLineSeries* lines, QChartView*  widget,QChart * lineChart,
                                  QValueAxis* axisY,QValueAxis* axisX,QString title){
    lines = new QLineSeries();
    for(int i=0;i<cpuStates.size ();i++){
        lines->append(i,cpuStates[i]);
    }
    lineChart->setTitle(title+QString::number(cpuStates[cpuStates.size ()-1],'f',1)+"%");
    lineChart->legend()->setVisible(false);
    lineChart->addSeries(lines);
    lineChart->setAxisY(axisY,lines);
    lineChart->setAxisX(axisX,lines);
//    lineChart->setGeometry(10, 4, 300, 260); // the method of QGraphicsWidget, move && resize
    lineChart->setBackgroundVisible(true);
    lineChart->setBackgroundPen(QPen(Qt::lightGray)); // the frame
    lineChart->setBackgroundBrush(QBrush(QColor(240, 240, 240)));
    widget->setChart (lineChart);
}
void MainWindow::initWidgets(){
    util.setText (ui->cpu_content_label,util.CPU_model ());
    util.setText (ui->sys_version_content_label,util.sys_version ());
    util.setText (ui->host_content_label,util.host_info ());
    util.setText (ui->systime_content_label,util.sys_time ());

    //tableWidget
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    header<<"PID"<<"COMM"<<"STATE"<<"PPID"<<"PRIORITY"<<"RSS";
    ui->tableWidget->setColumnCount (6);
       ui->tableWidget->setHorizontalHeaderLabels(header);
    //


}
void MainWindow::initDynamicWidgets(){
    util.setText (ui->runtime_content_label,util.run_time ());
//    ui->statusBar->showMessage(QDateTime::currentDateTime ().toString ("yyyy-MM-dd"));
    ui->status_label->setText (QDateTime::currentDateTime ().toString ("yyyy-MM-dd hh:mm:ss"));

    processMapList=util.process_stat ();
    initTableWidget ();
}

void MainWindow::initTableWidget(){
   if(processMapList.isEmpty ())return;
   ui->tableWidget->setRowCount (processMapList.size());
   ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
   int j=0;
   ui->tableWidget->clear ();
   for(int i=0;i<processMapList.size();i++){
       QMap<QString,QString> map=processMapList.at(i);
       if(searchMode){
           QString lineEdit=ui->lineEdit->text ();
           if(util.isNumberByString (lineEdit)){
               if(map["pid"]!=lineEdit)
//               qDebug()<<"is numer"<<map["pid"];
               continue;
           }else{
               if(!map["comm"].contains(lineEdit))
                   continue;
           }
       }
       ui->tableWidget->setItem (j,0,new QTableWidgetItem (map["pid"]));
       ui->tableWidget->setItem (j,1,new QTableWidgetItem (map["comm"]));
       ui->tableWidget->setItem (j,2,new QTableWidgetItem (map["task_state"]));
       ui->tableWidget->setItem (j,3,new QTableWidgetItem (map["ppid"]));
       ui->tableWidget->setItem (j,4,new QTableWidgetItem (map["priority"]));
       ui->tableWidget->setItem (j,5,new QTableWidgetItem (map["vsize"]));
       j++;
   }
}

void MainWindow::searchBtnClicked(){
    if(searchMode){
       searchMode=false;
       ui->search_btn->setText ("SEARCH");
    }else {
        searchMode=true;
        ui->search_btn->setText ("ALL");
    }
    initTableWidget();
}
