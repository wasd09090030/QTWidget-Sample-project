#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QAction *openAction = new QAction("打开", this);
    openAction->setShortcut(QKeySequence("Ctrl+O")); // 设定快捷键
  //  openAction->setIcon(QIcon(":/icons/open.png"));  // 设置图标（可选）

    // 连接信号槽：点击时弹出消息框
    connect(openAction, &QAction::triggered, this, []() {
        QMessageBox::information(nullptr, "信息", "打开文件");
    });

    // 添加到菜单
    QMenu *fileMenu = menuBar()->addMenu("文件");
    fileMenu->addAction(openAction);

    // 添加到工具栏
    QToolBar *toolBar = addToolBar("工具栏");
    toolBar->addAction(openAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}
