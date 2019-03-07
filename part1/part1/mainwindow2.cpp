#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    this->ui->centralwidget->setFixedHeight(400);
    this->ui->centralwidget->setFixedWidth(600);
    initTime();

}

MainWindow2::~MainWindow2()
{

    delete ui;
    delete(this->timer);
    delete (this->timeRecord);
}

void MainWindow2::initTime(){
    this->timer=new QTimer();
    this->timeRecord=new QTime(0,0,0);
    this->ui->timer->setDigitCount(8);
    ui->timer->setSegmentStyle(QLCDNumber::Flat);
    ui->timer->display(timeRecord->toString("hh:mm:ss"));
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));

    timer->start(1000);
}
void MainWindow2::updateTime(){
    *timeRecord = timeRecord->addSecs(1);
    ui->timer->display(timeRecord->toString("hh:mm:ss"));
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->radiusBlueLabel->setText(str);
}
