#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include<QPen>
#include<QTimer>
#include<QRandomGenerator>
#include<QMessageBox>
#include<QKeyEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void UpdateGame();

private:
    void spawnFood();
    void drawSnake();
    void drawFood();
    void movesnake();
    void checkCollision();
    QTimer*timer;
    QVector<QPoint> snake;
    QPoint food;
    bool Gameover;
    int direction;//0,1,2,3/上左下右

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
