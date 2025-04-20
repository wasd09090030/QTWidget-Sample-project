#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMouseTracking(true); // 追踪鼠标
    startTimer(10000);

    QPushButton *button1 = new QPushButton("按钮1", this);
    QPushButton *button2 = new QPushButton("按钮2", this);
    check = new QPushButton("check", this);
    checkbox = new QCheckBox("connect", this);
    timeLabel = new QLabel(QTime::currentTime().toString(), this);

    QVBoxLayout *layout = new QVBoxLayout;
    QWidget *centralWidget = new QWidget(this);

    button1->setGeometry(50, 50, 200, 200);
    button1->setStyleSheet("color:blue; background-color:lightyellow; font-size:30px");
    button1->setFlat(false);
    button1->setVisible(true);

    button2->setGeometry(300, 50, 50, 50);

    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(check);
    layout->addWidget(checkbox);
    layout->addWidget(timeLabel);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(button1, &QPushButton::clicked, []() {
        QMessageBox::information(nullptr, "提示", "你点击了按钮1");
    });

    connect(button2, &QPushButton::clicked, []() {
        QMessageBox::information(nullptr, "提示", "你点击了按钮2");
    });

    connect(check, &QPushButton::clicked, this, &MainWindow::onChecked);
    connect(checkbox, &QCheckBox::stateChanged, this, &MainWindow::onConnect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onChecked()
{
    statusBar()->showMessage("check按钮被点击");
}

void MainWindow::onConnect(int status)
{
    statusBar()->showMessage("");
    if (status == Qt::Checked) {
        disconnect(check, &QPushButton::clicked, this, &MainWindow::onChecked);
        connect(check, &QPushButton::clicked, this, &MainWindow::onChecked);
    } else if (status == Qt::Unchecked) {
        disconnect(check, &QPushButton::clicked, this, &MainWindow::onChecked);
    } else {
        qWarning() << "Unknown status value:" << status;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        QApplication::quit();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->pos().x();
    int y = event->pos().y();
    QString text = "坐标" + QString::number(x) + " , " + QString::number(y);
    statusBar()->showMessage(text);
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    timeLabel->setText(QTime::currentTime().toString());
}
