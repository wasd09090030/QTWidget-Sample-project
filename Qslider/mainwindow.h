#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qslider.h>
#include <QLabel>
#include<QVBoxLayout>
#include <QWidget>


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
    void onSliderValueChanged(int value);

private:
    Ui::MainWindow *ui;
    QSlider *slider;
    QLabel *valuelabel;
};
#endif // MAINWINDOW_H
