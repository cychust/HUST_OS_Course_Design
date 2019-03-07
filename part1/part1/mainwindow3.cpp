#include "mainwindow3.h"
#include "ui_mainwindow3.h"

MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);
    this->ui->centralwidget->setFixedHeight(300);
    this->ui->centralwidget->setFixedWidth(600);
    this->ui->centralwidget->hide();
    initTime();
}

MainWindow3::~MainWindow3()
{
    delete ui;
}
void MainWindow3::initTime(){
    this->timer=new QTimer();
//    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    this->timer->start(1000);
}
void MainWindow3::updateTime(){
    //update time
//     QDateTime time = QDateTime::currentDateTime();
//     QString str = time.toString("yyyy-MM-dd hh:mm:ss");
//     ui->radiusBlueLabel->setText(str);
}

void MainWindow3::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    clockTick++;

    /* 时分秒所描绘不规则形状和长度 */
    // 时针
    static const QPoint hourHand[4] =
    {
        QPoint(7, 8),   //右
        QPoint(0, 13),  //上
        QPoint(-7, 8),  //左
        QPoint(0, -40)  //下
    };
    // 分针
    static const QPoint minuteHand[4] =
    {
        QPoint(7, 8),   //右
        QPoint(0, 13),  //上
        QPoint(-7, 8),  //左
        QPoint(0, -70)  //下
    };
    // 秒针
    static const QPoint secondHand[4] =
    {
        QPoint(7, 8),   //右
        QPoint(0, 13),  //上
        QPoint(-7, 8),  //左
        QPoint(0, -80)  //下
    };

    //-------------------------------------------------------------------------
    /* 时分秒针描绘的颜色 */
    // 时针
    QColor hourColor(127, 0, 127);
    // 分针
    //QColor minuteColor(0, 127, 127, 192);     //RGB(三原色)(0, 127, 127);alpha(透明度)(192).
    QColor minuteColor(0, 127, 127);
    // 秒针
    QColor secondColor(0, 0, 127);

    //-------------------------------------------------------------------------
    int side = qMin(this->width()-40, this->height()-40);
    QTime time = QTime::currentTime();          //当前系统时间

    //-------------------------------------------------------------------------
    QPainter painter(this);
    painter.translate(this->width() / 2, this->height() / 2);
                                                //原点
    painter.setRenderHint(QPainter::Antialiasing);
                                                //反锯齿,好看点
    painter.scale(side / 200.0, side / 200.0);  //伸缩

    //-------------------------------------------------------------------------
    painter.setPen(Qt::NoPen);                  //设置画笔
    painter.setBrush(QColor(0, 0, 0));          //设置画刷(黑色)
    painter.drawEllipse(-100, -100, 200, 200);  //画圆(表盘外圆)
    painter.setBrush(QColor(255, 255, 255));    //设置画刷(白色)
    painter.drawEllipse(-99, -99, 198, 198);    //画圆(表盘内圆)

    //-------------------------------------------------------------------------
    // 显示提示信息: "press ESC to exit!"
    //-------------------------------------------------------------------------
    QColor escColor(0, 0, 0);                   //黑色
    painter.setPen(escColor);                   //设置画笔
    painter.rotate(0.0);                        //顺时针旋转角度(0°)
    QFont font("宋体", 8, QFont::Normal, false);
    //使用字体
    painter.setFont(font);

    QString escText = "";
    //"press ESC to exit!"
    if(clockTick % 2)
    {
        escText = tr("press ESC to exit!");
    }

    painter.drawText(
        QRectF(-100, -40, 200, 40),             //画文本的矩形区域
        Qt::AlignHCenter,                       //文本的对齐方式(水平居中)
        escText                                 //文本的内容
        );

    //-------------------------------------------------------------------------
    QFont oldfont("宋体", 10, QFont::Normal, false);
    //使用字体
    painter.setFont(oldfont);

    /******************** 时钟 ********************/
    painter.setPen(Qt::NoPen);                  //设置画笔
    painter.setBrush(hourColor);                //设置画刷
    painter.save();
    painter.rotate((time.hour() * 30.0) + (time.minute() * (30.0 / 60)));
                                                //顺时针旋转角度(时角度＋分角度)
    painter.drawConvexPolygon(hourHand, sizeof(hourHand) / sizeof(QPoint));
                                                //描画的形状
    painter.restore();

    //-------------------------------------------------------------------------
    // 表盘(时)
    //-------------------------------------------------------------------------
    painter.setPen(hourColor);                  //设置画笔
    for(int i = 0; i < 12; i++)                 //描画刻度
    {
        painter.rotate(30.0);                   //顺时针旋转角度(360°/12=30°)

        //1,2,4,5,7,8,10,11
        if(0 != ((i + 1) % 3))
        {
            QFont font("宋体", 10, QFont::Normal, false);
            //使用字体
            painter.setFont(font);

            painter.drawLine(QPointF(80, 0), QPointF(90, 0));   //刻度(时)
            painter.drawText(
                QRectF(-20, -78, 40, 40),           //画文本的矩形区域
                Qt::AlignHCenter | Qt::AlignTop,    //文本的对齐方式
                QString::number(i + 1)              //文本的内容
                );
        }
        //3,6,9,12
        else
        {
            QFont font("宋体", 14, QFont::Bold, false);
            //使用字体
            painter.setFont(font);

            painter.drawLine(QPointF(75, 0), QPointF(90, 0));   //刻度(时)
            painter.drawText(
                QRectF(-20, -73, 40, 40),           //画文本的矩形区域
                Qt::AlignHCenter | Qt::AlignTop,    //文本的对齐方式
                QString::number(i + 1)              //文本的内容
                );
        }
    }

    //-------------------------------------------------------------------------
    QFont newfont("宋体", 10, QFont::Normal, false);
    //使用字体
    painter.setFont(newfont);

    /******************** 分钟 ********************/
    painter.setPen(Qt::NoPen);                  //设置画笔
    painter.setBrush(minuteColor);              //设置画刷
    painter.save();
    painter.rotate((time.minute() * 6.0) + (time.second() * (6.0 / 60)));
                                                //顺时针旋转角度(分角度)
    painter.drawConvexPolygon(minuteHand, sizeof(minuteHand) / sizeof(QPoint));
                                                //描画的形状
    painter.restore();

    //-------------------------------------------------------------------------
    // 表盘(分)
    //-------------------------------------------------------------------------
    painter.setPen(minuteColor);                //设置画笔
    for(int i = 0; i < 60; i++)                 //描画刻度
    {
        if(0 != (i % 5))                        //跳过时刻度
            painter.drawLine(QPointF(82, 0), QPointF(87, 0));   //刻度(分)

        painter.rotate(6.0);                    //顺时针旋转角度(360°/60=6°)
    }

    /******************** 秒钟 ********************/
    painter.setPen(Qt::NoPen);                  //设置画笔
    painter.setBrush(secondColor);              //设置画刷
    painter.save();
    painter.rotate(6.0 * time.second());        //顺时针旋转角度(秒角度)
    painter.drawConvexPolygon(secondHand, sizeof(secondHand) / sizeof(QPoint));
                                                //描画的形状
    painter.restore();
}

// 键盘事件(由系统自动调用)
void MainWindow3::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Escape:
            MainWindow3::close();
            break;

        default:
            break;
    }
}
