#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTime>
#include <QVBoxLayout>
#include <QCheckBox>
#include<QPushButton>

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
};
#endif // MAINWINDOW_H
