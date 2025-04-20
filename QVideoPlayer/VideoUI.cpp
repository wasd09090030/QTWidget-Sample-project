#include "VideoUI.h"

VideoUI::VideoUI(QWidget *parent) : QWidget(parent) {
    videoPlayer = new VideoPlayer(this);
    videoWidget = new QVideoWidget(this);
    videoPlayer->setVideoOutput(videoWidget);

    setupUI();

    connect(playPauseButton, &QPushButton::clicked, videoPlayer, &VideoPlayer::playPause);
    connect(videoPlayer, &VideoPlayer::stateChanged, this, &VideoUI::updatePlayPauseIcon);
}

void VideoUI::setupUI() {
    setWindowTitle("Qt6 视频播放器");
    resize(900, 600);
    setWindowIcon(QIcon(":/icons/MyPlayer.png"));

    // --- 控制栏 ---
    controlBar = new QFrame(this);
    controlBar->setStyleSheet("background-color: rgba(0, 0, 0, 150);");
    controlBar->setFixedHeight(60);

    // --- 播放 / 暂停按钮 ---
    playPauseButton = new QPushButton(this);
    playPauseButton->setFixedSize(50, 50);
    playPauseButton->setStyleSheet("border: none; background: transparent;");
    playPauseButton->setIcon(QIcon(":/icons/play.png"));
    playPauseButton->setIconSize(QSize(50, 50));

    // --- 打开文件按钮 ---
    QPushButton *openFileButton = new QPushButton("📂", this);
    openFileButton->setFixedSize(30, 30);
    connect(openFileButton, &QPushButton::clicked, videoPlayer, &VideoPlayer::openFile);

    // --- 音量按钮 ---
    volumeButton = new QPushButton(this);
    volumeButton->setFixedSize(40, 40);
    volumeButton->setStyleSheet("border: none; background: transparent;");
    volumeButton->setIcon(QIcon(":/icons/volume.png"));
    volumeButton->setIconSize(QSize(40, 40));
    connect(volumeButton, &QPushButton::clicked, this, &VideoUI::toggleVolumeSlider);

    // --- 音量滑块（浮动显示） ---
    // --- 音量滑块（浮动显示） ---
    volumeSlider = new QSlider(Qt::Vertical, nullptr);  // 让它成为独立窗口，不受父窗口布局影响
    volumeSlider->setRange(0, 100);
    volumeSlider->setStyleSheet("background: transparent;");
    volumeSlider->setValue(50);
    volumeSlider->setFixedSize(50, 120);
    volumeSlider->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);  // 让它作为浮动窗口
    volumeSlider->setAttribute(Qt::WA_TranslucentBackground);  // 透明背景
    volumeSlider->hide();
    connect(volumeSlider, &QSlider::valueChanged, this, [this](int value) {
        videoPlayer->setVolume(value);
    });

    // --- 监听点击外部区域以隐藏滑块 ---
    installEventFilter(this);

    // --- 布局 ---
    QHBoxLayout *controlLayout = new QHBoxLayout(controlBar);
    controlLayout->addWidget(openFileButton);
    controlLayout->addStretch();
    controlLayout->addWidget(playPauseButton);
    controlLayout->addStretch();
    controlLayout->addWidget(volumeButton);
    controlLayout->setContentsMargins(10, 5, 10, 5);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(videoWidget);
    mainLayout->addWidget(controlBar);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);
}

// --- 处理音量滑块的显示 / 隐藏逻辑 ---
void VideoUI::toggleVolumeSlider() {
    if (volumeSlider->isVisible()) {
        volumeSlider->hide();
    } else {
        // 计算音量按钮的位置，让滑块出现在音量按钮上方
        QPoint pos = volumeButton->mapToGlobal(QPoint(volumeButton->width() / 2 - volumeSlider->width() / 2, -volumeSlider->height() - 10));
        volumeSlider->move(pos);
        volumeSlider->show();
        volumeSlider->raise();  // 确保滑块置顶
    }
}


// --- 监听鼠标点击事件，点击音量滑块外部隐藏滑块 ---
bool VideoUI::eventFilter(QObject *watched, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        QPoint globalPos = mouseEvent->globalPosition().toPoint();  // 转换为 QPoint

        // 检查点击是否在音量滑块或音量按钮区域
        if (!volumeSlider->geometry().contains(volumeSlider->mapFromGlobal(globalPos)) &&
            !volumeButton->geometry().contains(volumeButton->mapFromGlobal(globalPos))) {
            volumeSlider->hide();
        }
    }
    return QWidget::eventFilter(watched, event);
}



// --- 更新播放 / 暂停按钮图标 ---
void VideoUI::updatePlayPauseIcon(QMediaPlayer::PlaybackState state) {
    if (state == QMediaPlayer::PlayingState) {
        playPauseButton->setIcon(QIcon(":/icons/pause.png"));
    } else {
        playPauseButton->setIcon(QIcon(":/icons/play.png"));
    }
}
