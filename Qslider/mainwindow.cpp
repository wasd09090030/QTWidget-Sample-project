#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout *layout =new QVBoxLayout;
    slider =new QSlider(Qt::Horizontal,this);
    slider->setMaximum(0);
    slider->setMaximum(100);
    slider->setValue(50);
    layout->addWidget(slider);

    valuelabel =new QLabel(QString::number(slider->value()),this);
    valuelabel->setAlignment(Qt::AlignCenter);//居中对齐
    layout->addWidget(valuelabel);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    connect(slider,&QSlider::valueChanged,this,&MainWindow::onSliderValueChanged);
}


void MainWindow::onSliderValueChanged(int value){
    valuelabel->setText(QString::number(value));
}

MainWindow::~MainWindow()
{
    delete ui;
}
