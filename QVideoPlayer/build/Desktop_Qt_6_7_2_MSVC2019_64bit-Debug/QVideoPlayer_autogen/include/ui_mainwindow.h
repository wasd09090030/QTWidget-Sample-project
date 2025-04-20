/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_open;
    QAction *action_save;
    QAction *action_edit;
    QAction *action__SF;
    QAction *action_0_5play;
    QAction *action_2_0play;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_F;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        action_open = new QAction(MainWindow);
        action_open->setObjectName("action_open");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::CameraVideo));
        action_open->setIcon(icon);
        action_open->setMenuRole(QAction::MenuRole::NoRole);
        action_save = new QAction(MainWindow);
        action_save->setObjectName("action_save");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        action_save->setIcon(icon1);
        action_save->setMenuRole(QAction::MenuRole::NoRole);
        action_edit = new QAction(MainWindow);
        action_edit->setObjectName("action_edit");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditCut));
        action_edit->setIcon(icon2);
        action_edit->setMenuRole(QAction::MenuRole::NoRole);
        action__SF = new QAction(MainWindow);
        action__SF->setObjectName("action__SF");
        action__SF->setMenuRole(QAction::MenuRole::NoRole);
        action_0_5play = new QAction(MainWindow);
        action_0_5play->setObjectName("action_0_5play");
        action_0_5play->setMenuRole(QAction::MenuRole::NoRole);
        action_2_0play = new QAction(MainWindow);
        action_2_0play->setObjectName("action_2_0play");
        action_2_0play->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menu);
        menu_2->setObjectName("menu_2");
        menu_F = new QMenu(menubar);
        menu_F->setObjectName("menu_F");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName("toolBar_2");
        MainWindow->addToolBar(Qt::ToolBarArea::BottomToolBarArea, toolBar_2);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_F->menuAction());
        menu->addAction(action_open);
        menu->addAction(action_save);
        menu->addAction(menu_2->menuAction());
        menu_2->addAction(action__SF);
        menu_2->addAction(action_0_5play);
        menu_2->addAction(action_2_0play);
        menu_F->addAction(action_edit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_open->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\350\247\206\351\242\221", nullptr));
        action_save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(shortcut)
        action_save->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_edit->setText(QCoreApplication::translate("MainWindow", "\350\277\233\345\205\245\347\274\226\350\276\221\346\250\241\345\274\217", nullptr));
        action__SF->setText(QCoreApplication::translate("MainWindow", "\350\266\205\345\210\206\350\276\250\347\216\207", nullptr));
        action_0_5play->setText(QCoreApplication::translate("MainWindow", "\346\205\242\351\200\237\346\222\255\346\224\2760.5", nullptr));
        action_2_0play->setText(QCoreApplication::translate("MainWindow", "\345\212\240\351\200\237\346\222\255\346\224\2762", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\347\256\241\347\220\206\357\274\210&O\357\274\211", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\350\256\276\347\275\256", nullptr));
        menu_F->setTitle(QCoreApplication::translate("MainWindow", "\346\250\241\345\274\217\357\274\210&F\357\274\211", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
