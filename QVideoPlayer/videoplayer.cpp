#include "videoplayer.h"
#include <QFileDialog>

VideoPlayer::VideoPlayer(QObject *parent) : QObject(parent) {
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // 连接播放状态变化信号，用于通知 UI 更新播放按钮
    connect(player, &QMediaPlayer::playbackStateChanged, this, &VideoPlayer::stateChanged);
}

VideoPlayer::~VideoPlayer() {
    // 释放播放器资源
    delete player;
    delete audioOutput;
}

void VideoPlayer::setVideoOutput(QVideoWidget *widget) {
    player->setVideoOutput(widget);
}

 // 弹出文件选择对话框
void VideoPlayer::openFile() {
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Select video", "", "Videos (*.mp4 *.mkv *.mov)");
    if (!fileName.isEmpty()) {
        player->setSource(QUrl::fromLocalFile(fileName));
        player->play();//选中后自动播放
    }
}

void VideoPlayer::playPause() {
    if (player->playbackState() == QMediaPlayer::PlayingState) {
        player->pause();
    } else {
        player->play();
    }
}

void VideoPlayer::setVolume(float volume) {
    audioOutput->setVolume(volume);
}
