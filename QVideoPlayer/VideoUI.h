#ifndef VIDEOUI_H
#define VIDEOUI_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QVideoWidget>
#include <QStackedWidget>
#include <qevent.h>
#include "videoplayer.h"

class VideoUI : public QWidget {
    Q_OBJECT
public:
    explicit VideoUI(QWidget *parent = nullptr);

private slots:
    void updatePlayPauseIcon(QMediaPlayer::PlaybackState state);
    bool eventFilter(QObject *watched, QEvent *event);
    void toggleVolumeSlider();

private:
    VideoPlayer *videoPlayer;   // 播放器逻辑
    QVideoWidget *videoWidget;  // 视频窗口

    QPushButton *playPauseButton;  // 播放 / 暂停按钮
    QPushButton *volumeButton;     // 音量按钮
    QSlider *volumeSlider;         // 音量滑块
    QStackedWidget *volumeStack;   // 音量控件切换
    QFrame *controlBar;            // 底部控制栏
    void setupUI();
};

#endif // VIDEOUI_H
