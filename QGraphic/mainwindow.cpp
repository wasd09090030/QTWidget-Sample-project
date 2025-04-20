#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <QBrush>
#include <QPen>
#include <QLinearGradient>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建图形场景
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(-300, -200, 600, 400);  // 设置场景范围

    // 创建渐变天空（从上到下颜色逐渐变化）
    QLinearGradient skyGradient(0, -200, 0, 200);  // 垂直渐变
    skyGradient.setColorAt(0.0, QColor(133,206,235));   // 天空的上半部分（浅蓝色）
    skyGradient.setColorAt(1.0, Qt::blue);        // 天空的下半部分（深蓝色）

    // 创建背景矩形，使用渐变天空
    QGraphicsRectItem *skyItem = scene->addRect(-300, -200, 600, 400, QPen(), QBrush(skyGradient));

    // 创建绿地（一个简单的绿色矩形）
    QGraphicsRectItem *grassItem = scene->addRect(-300, 0, 600, 200, QPen(), QBrush(Qt::green));

    // 创建云朵（使用 QGraphicsEllipseItem 绘制多个圆形，组合成云朵）
    QGraphicsEllipseItem *cloud1 = scene->addEllipse(-250, -150, 150, 100, QPen(), QBrush(Qt::white));
    QGraphicsEllipseItem *cloud2 = scene->addEllipse(-150, -100, 150, 100, QPen(), QBrush(Qt::white));
    QGraphicsEllipseItem *cloud3 = scene->addEllipse(-50, -150, 150, 100, QPen(), QBrush(Qt::white));

    // 创建房子（矩形和三角形组合）
    QGraphicsRectItem *houseBase = scene->addRect(-50, 50, 200, 100, QPen(), QBrush(Qt::yellow));  // 房子主体
    QPolygonF houseRoof;
    houseRoof << QPointF(-60, 50) << QPointF(50, -50) << QPointF(160, 50);  // 三角形屋顶
    QGraphicsPolygonItem *roofItem = scene->addPolygon(houseRoof, QPen(), QBrush(Qt::red));

    // 设置视图，显示场景
    QGraphicsView *view = new QGraphicsView(scene);
    setCentralWidget(view);  // 设置中央窗口部件为视图
    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::SmoothPixmapTransform);
    view->setDragMode(QGraphicsView::ScrollHandDrag);  // 启用拖动模式
}

MainWindow::~MainWindow()
{
    delete ui;
}
