#include "widget.h"
#include "./ui_widget.h"
#include <QTimer>
#include <QPainter>
#include <QTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(200, 200);

    // 定时器每秒更新时间
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::updateTime);  // 修改为调用更新函数
    timer->start(1000); // 每秒更新时间
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateTime()
{
    currentTime = QTime::currentTime();  // 更新当前时间
    update();  // 重新触发绘制事件
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.translate(100,100);
    painter.setRenderHint(QPainter::Antialiasing);

    QPoint hourHand[3] = {QPoint(7, 8), QPoint(-7, 8), QPoint(0, -40)};
    QPoint minuteHand[3] = {QPoint(7, 8), QPoint(-7, 8), QPoint(0, -40)};
    QPoint secHand[3] = {QPoint(2, 8), QPoint(-2, 8), QPoint(0, -80)};

    // 获取时钟的中心和半径
    QPoint center(0, 0);
    int radius = qMin(width(), height()) / 2 - 10;

    // 绘制表盘
    painter.setPen(QPen(Qt::black, 2));
    painter.drawEllipse(center, radius, radius);

    // 时针的绘制
    painter.save();
    painter.rotate((currentTime.hour() + currentTime.minute() / 60.0) * 30);  // 计算时针角度
    painter.drawPolygon(hourHand, 3);
    painter.restore();

    // 分针的绘制
    painter.save();
    painter.rotate(currentTime.minute() * 6);  // 计算分针角度
    painter.drawPolygon(minuteHand, 3);
    painter.restore();

    // 秒针的绘制
    painter.save();
    painter.rotate(currentTime.second() * 6);  // 计算秒针角度
    painter.drawPolygon(secHand, 3);
    painter.restore();

    // 绘制刻度
    painter.setPen(QPen(Qt::black, 1));
    for (int i = 0; i < 60; ++i)
    {
        double angle = 6 * i * 3.14159 / 180.0;
        if (i % 5 == 0)
        {
            int x1 = center.x() + radius * 0.8 * cos(angle);
            int y1 = center.y() - radius * 0.8 * sin(angle);
            int x2 = center.x() + radius * cos(angle);
            int y2 = center.y() - radius * sin(angle);
            painter.drawLine(x1, y1, x2, y2);
        }
        else
        {
            int x1 = center.x() + radius * 0.9 * cos(angle);
            int y1 = center.y() - radius * 0.9 * sin(angle);
            int x2 = center.x() + radius * cos(angle);
            int y2 = center.y() - radius * sin(angle);
            painter.drawLine(x1, y1, x2, y2);
        }
    }
}


