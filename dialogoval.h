#ifndef DIALOGOVAL_H
#define DIALOGOVAL_H

#include <QDialog>

namespace Ui {
class DialogOval;
}

class DialogOval : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOval(QWidget *parent = 0);
    ~DialogOval();
    void hklDrawOval();//中点椭圆生成算法

signals:
    void returnData(int a,int b);//信号

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::DialogOval *ui;
    int a,b;//长轴、短轴
};

#endif // DIALOGOVAL_H
