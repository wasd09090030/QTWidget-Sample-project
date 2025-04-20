#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),direction(1),Gameover(false)
{
    setFixedSize(400,400);
    setFocusPolicy(Qt::StrongFocus);
    snake.append(QPoint(100,100));
    snake.append(QPoint(80,100));
    snake.append(QPoint(60,100));
    spawnFood();

    timer =new QTimer(this);
    //每100ms刷新一次，可调整timer来调整贪吃蛇的移动速度
    connect(timer,&QTimer::timeout,this,&MainWindow::UpdateGame);
    timer->start(100);

}

MainWindow::~MainWindow() {
    delete timer;
}

void MainWindow::UpdateGame()
{
    if(!Gameover){
        movesnake();
        checkCollision();
        update();
    }
}

void MainWindow::spawnFood()
{
    int x=QRandomGenerator::global()->bounded(0,width()/20)*20;
    int y=QRandomGenerator::global()->bounded(0,height()/20)*20;
    food=QPoint(x,y);

    for(QPoint &point:snake){
        if(food==point){
            spawnFood();
            return;
        }
    }
}

void MainWindow::drawSnake()
{
    QPainter paint(this);
    QBrush bru(Qt::green);
    paint.setBrush(bru);
    for(QPoint &point:snake){
        paint.drawRect(point.x(),point.y(),20,20);
    }
}

void MainWindow::drawFood()
{
    QPainter foodDraw(this);
    QBrush brushFood(Qt::red);
    foodDraw.setBrush(brushFood);
    foodDraw.drawEllipse(food.x(),food.y(),20,20);
}


void MainWindow::movesnake()
{
    QPoint head =snake.first();
    switch (direction) {
    case 0:
        head.ry() -=20;//返回 y 坐标的 可修改引用，允许直接修改 y 值，  .y()只读，不可修改
        break;
    case 1:
        head.rx() +=20;
        break;
    case 2:
        head.ry() +=20;
        break;
    case 3:
        head .rx() -=20;
        break;
    }
    snake.prepend(head);

    if (head != food) {
        snake.removeLast(); // 没吃到食物 -> 移除尾部，长度不变
    } else {
        spawnFood(); // 吃到食物 -> 生成新食物，不移除尾部，蛇变长
    }

}

void MainWindow::checkCollision()
{
    QPoint head =snake.first();
    //判断是否碰到边界
    if(head.x()<0||head.x()>=width()||head.y()<0||head.y()>=height()){
        Gameover=true;
        return;
    }
    //循环判断身体每一节是否重合
    for(int i=1;i<snake.size();i++){
        if(head==snake.at(i)){
            Gameover=true;
            return;
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter paint(this);
    QPen pen(Qt::blue,3);
    QBrush brush(Qt::green);
    paint.setBrush(brush);
    paint.setPen(pen);

    if(Gameover){
        paint.drawText(rect(),Qt::AlignCenter,"GAME OVER");
    }
    drawSnake();
    drawFood();

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Up:
        if(direction!=2)
            direction=0;
        break;
    case Qt::Key_Right:
        if(direction!=3)
            direction=1;
        break;
    case Qt::Key_Down:
        if(direction!=0)
            direction=2;
        break;
    case Qt::Key_Left:
        if(direction!=1)
            direction=3;
        break;

    default:
        QMainWindow::keyPressEvent(event);
    }
}
