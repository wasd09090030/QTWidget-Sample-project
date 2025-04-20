#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPoint>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);//设置窗口无边框化,且窗口无法移动
    setAttribute(Qt::WA_TranslucentBackground,true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint mousePos = event->globalPosition().toPoint();
    QPoint topLeft =this->geometry().topLeft();
    winPos=mousePos-topLeft;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint MouseP=event->globalPosition().toPoint();
    QPoint endPos=MouseP-winPos;
    this->move(endPos);
}
