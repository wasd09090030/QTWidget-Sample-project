#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout *layout =new QVBoxLayout;
    progressbar =new QProgressBar(this);
    progressbar->setRange(0,100);
    progressbar->setValue(0);
    progressbar->setFormat("%p%");//显示格式，可以自定义
    progressbar->setTextVisible(true);
    layout->addWidget(progressbar);

    startButton =new QPushButton("开始",this);
    layout->addWidget(startButton);

    QWidget* centralWidget =new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    timer =new QTimer(this);

    connect(startButton,&QPushButton::clicked,this,&MainWindow::onStartButtonClicked);
    connect(timer,&QTimer::timeout,this,&MainWindow::onTimerTimeOut);

}

void MainWindow::onStartButtonClicked(){
    if(timer->isActive()){
        timer->stop();
        startButton->setText("开始");
    }else {
        currentValue=0;
        progressbar->setValue(0);
        timer->start(100);
        startButton->setText("停止");
    }
}

void MainWindow::onTimerTimeOut(){
    currentValue++;
    progressbar->setValue(currentValue);
    if(currentValue>=progressbar->maximum()){
        timer->stop();
        startButton->setText("开始");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
