#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>

class VideoPlayer : public QObject {
    Q_OBJECT
public:
    explicit VideoPlayer(QObject *parent = nullptr);
    ~VideoPlayer();

     // 设置视频输出窗口
    void setVideoOutput(QVideoWidget *widget);
    //打开视频文件
    void openFile();
    // 播放 / 暂停切换
    void playPause();
    //设置音量
    void setVolume(float volume);

signals:
      // 播放状态变化信号（用于更新 UI 按钮）
    void stateChanged(QMediaPlayer::PlaybackState state);

private:
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
};

#endif // VIDEOPLAYER_H
