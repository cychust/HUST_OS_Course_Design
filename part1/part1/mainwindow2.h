#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include<QTime>
#include<QTimer>
namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

private:
    Ui::MainWindow2 *ui;
    void initTime();
    void initStyleSheets();
    QTimer* timer;
    QTime *timeRecord;
public slots:

    void updateTime();

};

#endif // MAINWINDOW2_H
