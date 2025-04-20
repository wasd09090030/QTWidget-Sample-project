#include "dialog.h"
#include "./ui_dialog.h"
#include <QtWidgets>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("Dialog对话框");
    ui->toolBox->setItemText(0, "输入对话");
    ui->toolBox->setItemText(1, "输入百分比数字");
     ui->toolBox->setItemText(2, "颜色选择");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    bool ok=false;
    int val=15,min=0,max=100,step=1;
    int value=QInputDialog::getInt(this,"输入数字","百分比",val,min,max,step,&ok);
    if(ok){
        ui->intInput->setText(QString::number(value)+"%");
    }
}




void Dialog::on_Color_change_btn_clicked()
{
    QColorDialog::ColorDialogOptions opt;
    if(ui->checkBox->isChecked())
        opt|=QColorDialog::DontUseNativeDialog;

    if(ui->checkBox_3->isChecked())
        opt|=QColorDialog::NoButtons;

    if(ui->checkBox_2->isChecked())
        opt|=QColorDialog::ShowAlphaChannel;

    const QColor color=QColorDialog::getColor(Qt::blue,this,"选择颜色",opt);
    if(color.isValid()){
        ui->labelColor->setText(color.name());
        ui->labelColor->setPalette(QPalette(color));
        ui->labelColor->setAutoFillBackground(true);
    }

}

