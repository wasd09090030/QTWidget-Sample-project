#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpushbutton.h>
#include <QMessageBox>
#include <QKeyEvent> //触发键盘事件
#include <QMouseEvent>
#include <QLabel>
#include <QTime>
#include <QVBoxLayout>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onChecked();
    void onConnect(int status);

private:
    Ui::MainWindow *ui;
    QPushButton* check;
    QLabel* timeLabel;
    QCheckBox * checkbox;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void timerEvent(QTimerEvent *event);
};
#endif // MAINWINDOW_H
