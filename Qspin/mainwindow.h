#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include<QDoubleSpinBox>
#include<QLabel>
#include<QVBoxLayout>
#include<QWidget>

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
    void onSpinBoxValueChanged(int value);
    void onDoubleSpinBoxValueChanged(double value);

private:
    Ui::MainWindow *ui;

    QSpinBox* spinbox;
    QDoubleSpinBox*Dspinbox;
    QLabel*spinlabel;
    QLabel*Dspinlabel;
    QWidget*centralWidget;
    QVBoxLayout*layout;


};
#endif // MAINWINDOW_H
