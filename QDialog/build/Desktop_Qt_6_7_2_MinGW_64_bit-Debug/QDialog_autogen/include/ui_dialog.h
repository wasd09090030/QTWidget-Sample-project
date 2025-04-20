/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLineEdit *intInput;
    QWidget *page_4;
    QWidget *page_3;
    QGridLayout *gridLayout_2;
    QPushButton *Color_change_btn;
    QLabel *labelColor;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QWidget *page_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(332, 385);
        toolBox = new QToolBox(Dialog);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(0, 10, 221, 261));
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 221, 165));
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        intInput = new QLineEdit(page);
        intInput->setObjectName("intInput");

        gridLayout->addWidget(intInput, 0, 1, 1, 1);

        toolBox->addItem(page, QString::fromUtf8("Page 1"));
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        toolBox->addItem(page_4, QString::fromUtf8("\351\241\265"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        gridLayout_2 = new QGridLayout(page_3);
        gridLayout_2->setObjectName("gridLayout_2");
        Color_change_btn = new QPushButton(page_3);
        Color_change_btn->setObjectName("Color_change_btn");

        gridLayout_2->addWidget(Color_change_btn, 0, 0, 1, 1);

        labelColor = new QLabel(page_3);
        labelColor->setObjectName("labelColor");
        labelColor->setFrameShape(QFrame::Shape::Box);

        gridLayout_2->addWidget(labelColor, 0, 1, 1, 1);

        groupBox = new QGroupBox(page_3);
        groupBox->setObjectName("groupBox");
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(10, 20, 91, 16));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(10, 40, 91, 16));
        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(10, 60, 91, 16));

        gridLayout_2->addWidget(groupBox, 1, 0, 1, 2);

        toolBox->addItem(page_3, QString::fromUtf8("\351\241\265"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 221, 165));
        toolBox->addItem(page_2, QString::fromUtf8("Page 2"));

        retranslateUi(Dialog);

        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "\346\211\200\351\234\200\347\231\276\345\210\206\346\257\224", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("Dialog", "Page 1", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QCoreApplication::translate("Dialog", "\351\241\265", nullptr));
        Color_change_btn->setText(QCoreApplication::translate("Dialog", "\351\200\211\346\213\251\351\242\234\350\211\262", nullptr));
        labelColor->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("Dialog", "\351\200\211\351\241\271", nullptr));
        checkBox->setText(QCoreApplication::translate("Dialog", "\344\270\215\344\275\277\347\224\250\346\234\254\346\234\272\345\257\271\350\257\235\346\241\206", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Dialog", "\346\230\276\347\244\272Alpha\351\200\232\351\201\223", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Dialog", "\346\227\240\346\214\211\351\222\256", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("Dialog", "\351\241\265", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("Dialog", "Page 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
