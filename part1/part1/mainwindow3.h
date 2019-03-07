#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H

#include <QMainWindow>
#include<QTimer>
#include<QDateTime>
#include<QPainter>
#include<QPainter>
#include<QKeyEvent>
namespace Ui {
class MainWindow3;
}

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow3(QWidget *parent = nullptr);
    ~MainWindow3();

private:
    Ui::MainWindow3 *ui;
    int clockTick;
    void initTime();
    void initStyleSheets();
    QTimer* timer;
public slots:
    void updateTime();
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
};

#endif // MAINWINDOW3_H
