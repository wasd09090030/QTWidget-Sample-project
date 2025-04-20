#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imagelaber =new QLabel(this);
    imagelaber->setAlignment(Qt::AlignCenter);
    imagelaber->setStyleSheet("border:1px;border-radius:6px;");

    openButon =new QPushButton("打开图片",this);
    openButon->setFixedHeight(35);
    openButon->setStyleSheet("background-color:green");
    openButon->setCursor(Qt::PointingHandCursor);//光标样式为手型

    QVBoxLayout *mainlayout= new QVBoxLayout;
    mainlayout->addWidget(imagelaber);
    mainlayout->addWidget(openButon);

    QWidget *centralWidget =new QWidget(this);
    centralWidget->setLayout(mainlayout);
    setCentralWidget(centralWidget);

    QPalette palette =this->palette();
    palette.setColor(QPalette::Window,QColor(245,245,245));
    this->setPalette(palette);

    QFont font("Arial",12);
    this->setFont(font);

    connect(openButon,&QPushButton::clicked,this,&MainWindow::onOpenButtonClicked);
}

void MainWindow::onOpenButtonClicked(){
    QString filePath =QFileDialog::getOpenFileName(this,"选择图片文件","C:\\Users\\qq862\\Desktop","图片文件 (*.png *.jpg *.jpeg)");
    if(!filePath.isEmpty()){
        QPixmap pixmap(filePath);
        if(!pixmap.isNull()){
            imagelaber->setPixmap(pixmap.scaled(imagelaber->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
