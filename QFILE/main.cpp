#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>


int main() {
    // 写入文件
    QFile writeFile("example.txt");
    if (writeFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&writeFile);
        out << "Hello, Qt!" << Qt::endl;
        writeFile.close();
        qDebug()<<"写入成功"<<Qt::endl;
    } else {
        qWarning() << "Could not open file for writing";
    }

    // 读取文件
    QFile readFile("example.txt");
    if (readFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&readFile);
        QString content = in.readAll();
        qDebug() << "File content:" << content;
        readFile.close();
    } else {
        qWarning() << "Could not open file for reading";
    }

//QDir

    QDir dir;

    // 创建一个目录
    if (dir.mkdir("my_directory")) {
        qDebug() << "Directory 'my_directory' created successfully!";
    } else {
        qWarning() << "Failed to create directory.";
    }

  //  QDir::cd() 方法可以改变当前目录。改为当前文件目录
    if (dir.cd(QDir::currentPath())) {
        qDebug() << "Changed directory successfully. ";
        qDebug() << "Current directory:" << QDir::currentPath()<<Qt::endl;

    } else {
        qWarning() << "Failed to change directory.";
    }

    dir.setFilter(QDir::Dirs|QDir::Files);
    dir.setSorting(QDir::Size|QDir::Reversed);
    // QDir::Size：表示按照文件大小进行排序。文件会根据它们的字节大小从小到大排列。
    //     QDir::Reversed：表示反向排序，即将文件按大小从大到小排序。
    QFileInfoList list=dir.entryInfoList();

    qDebug()<<"Bytes   FileName"<<Qt::endl;
    for(auto &file:list){
        qDebug()<<file.size()<<"  "<<file.fileName()<<Qt::endl;
    }
    return 0;
}

// QIODevice::WriteOnly：只写模式。如果文件不存在，则会创建文件。
//     QIODevice::ReadWrite：读写模式。如果文件不存在，则会创建文件。
//         QIODevice::Append：追加模式。如果文件不存在，文件会被创建，但写入时会在文件末尾追加内容。
