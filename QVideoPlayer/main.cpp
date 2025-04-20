#include <QApplication>
#include "VideoUI.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    VideoUI ui;
    ui.show();

    return app.exec();
}
