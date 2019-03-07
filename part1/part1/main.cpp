#include "mainwindow.h"
#include <QApplication>
#include"mainwindow2.h"
#include"mainwindow3.h"
#include <sys/types.h>
#include <unistd.h>
#include<commonhelper.h>
int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    int pid1,pid2;
    switch (pid1=fork()) {
      case 0:{
            QApplication a(argc,argv);
             CommonHelper::setStyle(":/images/images/black.css");
            MainWindow2 w2;
            w2.move(150,190);
            w2.show();
            return a.exec();
       }
      case -1: exit(-1);
      default:
        switch (pid2=fork()) {
        case -1:{
            exit(-1);
        }
        case 0:{
            QApplication a(argc,argv);
            CommonHelper::setStyle(":/images/images/black.css");
            MainWindow3 w3;
            w3.move(250,290);
            w3.show();
            return a.exec();
        }
        default:
            QApplication a(argc,argv);
//            CommonHelper::setStyle(":/images/images/black.css");
            MainWindow w;
            w.move(350,390);
            w.show();
            return a.exec();
        }

    }

//    return a.exec();
}
