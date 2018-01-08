#include "dialogoval.h"
#include "ui_dialogoval.h"

DialogOval::DialogOval(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOval)
{
    ui->setupUi(this);
}

DialogOval::~DialogOval()
{
    delete ui;
}

void DialogOval::on_pushButton_clicked()//OK
{
    a=ui->lineEdit->text().toInt();//长轴
    b=ui->lineEdit_2->text().toInt();//短轴
    emit returnData(a,b);//发信号
    this->close();
}

void DialogOval::on_pushButton_2_clicked()//Exit
{
    this->close();
}
