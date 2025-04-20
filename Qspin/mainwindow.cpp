#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    centralWidget =new QWidget(this);
    setCentralWidget(centralWidget);

    layout =new QVBoxLayout(centralWidget);
    layout->setSpacing(20);
    layout->setContentsMargins(20,20,20,20);

    spinbox =new QSpinBox(centralWidget);
    spinbox->setMinimum(0);
    spinbox->setMaximum(100);
    spinbox->setSingleStep(1);
    spinbox->setValue(50);
    spinbox->setMinimumSize(200,40);
    //spinbox->setStyleSheet("QSpinBox{font-size:16px;border-radius:5px;}");
    layout->addWidget(spinbox);

    spinlabel = new QLabel(QString("整数当前值：%1").arg(spinbox->value()),centralWidget);
    spinlabel->setStyleSheet("QLabel{font-size:16px;");
    layout->addWidget(spinlabel);

    Dspinbox =new QDoubleSpinBox(centralWidget);
    Dspinbox->setMinimum(0.0);
    Dspinbox->setMaximum(10.0);
    Dspinbox->setSingleStep(0.1);
    Dspinbox->setDecimals(1);
    Dspinbox->setValue(5.0);
    Dspinbox->setMinimumSize(200,40);
    //Dspinbox->setStyleSheet("QDoubleSpinBox{font-size:16px;padding:5px; border:1px solid #ccc;border-radius:5px;}");
    layout->addWidget(Dspinbox);

    Dspinlabel = new QLabel(QString("整数当前值：%1").arg(Dspinbox->value()),centralWidget);
    Dspinlabel->setStyleSheet("QLabel{font-size:16px;");
    layout->addWidget(Dspinlabel);


    connect(spinbox,SIGNAL(valueChanged(int)),this,SLOT(onSpinBoxValueChanged(int)));
    connect(Dspinbox,SIGNAL(valueChanged(double)),this,SLOT(onDoubleSpinBoxValueChanged(double)));

}


void MainWindow::onSpinBoxValueChanged(int value){
    spinlabel->setText(QString("当前整数值：%1").arg(value));
}

void MainWindow::onDoubleSpinBoxValueChanged(double value){
    Dspinlabel->setText(QString("当前浮点数值：%1").arg(value));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete spinbox;
    delete Dspinbox;
    delete spinlabel;
    delete Dspinlabel;
    delete layout;
    delete centralWidget;
}
