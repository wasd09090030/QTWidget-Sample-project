#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::lightGray));
    setAutoFillBackground(true);
    resize(600,300);
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);//启用抗锯齿
    painter.setRenderHint(QPainter::TextAntialiasing);
    qreal R=100;//半径
    const qreal Pi = 3.14159;  // 定义圆周率 Pi
    qreal deg = Pi * 72 / 180;  // 计算角度，72度对应 Pi * 72 / 180

    //五个点
    QPoint points[5]={QPoint(R,0),
                      QPoint(R*qCos(deg), -R*qSin(deg)),
                       QPoint(R*qCos(2*deg), -R*qSin(2*deg)),
                       QPoint(R*qCos(3*deg), -R*qSin(3*deg)),
                         QPoint(R*qCos(4*deg), -R*qSin(4*deg)),};

    //设置字体
    QFont font;
    font.setPointSize(4);
    painter.setFont(font);

    //设置画笔
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    painter.setPen(pen);

    //设置画刷
    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    //设计绘制五角星的PainterPath,来重复使用
    QPainterPath starPath;
    starPath.moveTo(points[0]);
    starPath.lineTo(points[2]);
       starPath.lineTo(points[4]);
          starPath.lineTo(points[1]);
             starPath.lineTo(points[3]);
          starPath.closeSubpath();//闭合路径，最后一个点与第一个点相容
             starPath.addText(points[0],font,"1");
              starPath.addText(points[1],font,"2");
               starPath.addText(points[2],font,"3");
                starPath.addText(points[3],font,"4");
                 starPath.addText(points[4],font,"5");


    //绘图,第一个五角星
    painter.save();
    painter.translate(100,120);//更换坐标原点
    painter.drawPath(starPath);
    painter.drawText(0,0,"S1");
    painter.restore();         //回复坐标状态

    //第二个
    painter.translate(300,120);
   painter.scale(0.8, 0.8);  // 缩放 80%
    painter.rotate(90);       //顺时针旋转
    painter.drawPath(starPath);
    painter.drawText(0,0,"S2");

    //第三个
    painter.resetTransform();
    painter.translate(500,120);
    painter.rotate(-135);
    painter.drawPath(starPath);
    painter.drawText(0,0,"S3");


}

MainWindow::~MainWindow()
{
    delete ui;
}
