#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
       startTimer(10000);
    check =new QPushButton("check",this);
    checkbox =new QCheckBox("connect",this);
    QVBoxLayout *layout =new QVBoxLayout;
    QWidget * centeralWid= new QWidget(this);

    timeLabel=new QLabel(QTime::currentTime().toString(),this);
    layout->addWidget(check);
    layout->addWidget(checkbox);
    layout->addWidget(timeLabel);

    centeralWid->setLayout(layout);
    setCentralWidget(centeralWid);


    connect(checkbox,&QCheckBox::stateChanged,this,&MainWindow::onConnect);
    connect(check,&QPushButton::clicked,this,&MainWindow::onChecked);

}
void MainWindow::onChecked() {
    statusBar()->showMessage("check按钮被点击") ;
}

void MainWindow::onConnect(int status)
{
    statusBar()->showMessage("");
    if (status == Qt::Checked)
        disconnect(check, &QPushButton::clicked, this, &MainWindow::onChecked);
    else
        // 断开连接
        disconnect(check, &QPushButton::clicked, this, &MainWindow::onChecked);
}


MainWindow::~MainWindow()
{
    delete ui;    
}
