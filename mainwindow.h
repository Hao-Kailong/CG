#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QDebug>
#include <iostream>
#include <QPoint>
#include <QStack>
#include <QVector>
#include <QtMath>
#include <QImage>
#include <QFileDialog>
#include <QtAlgorithms>
#include <math.h>
#include "dialogoval.h"
using namespace std;

namespace Ui {
class MainWindow;
}

enum STATUS{
    LINE=0,
    CIRCLE,
    OVAL,
    DOODLE,
    SETPOINT,
    CUT
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void getData(int a,int b);//槽从对话框获取数据

    QPixmap *pix;

private slots:
    void on_ButtonLine_clicked();
    void on_ButtonCircle_clicked();
    void on_ButtonOval_clicked();
    void on_ButtonDoodle_clicked();
    void on_Fill_clicked(bool);
    void on_Curve_clicked();
    void on_Reverse_clicked();
    void on_Move_clicked();
    void on_Zoom_clicked();
    void saveFile();

    void on_Polygon_clicked();

    void on_Cut_clicked();

    void on_pushButton_clicked();

    void on_D3_clicked();

private:
    Ui::MainWindow *ui;

    const double PI=3.1415926;
    const int oX=70;
    const int oY=70;
    const int sizeX=800;
    const int sizeY=600;
    int a,b;//椭圆数据
    STATUS status;//绘制状态
    QPoint startPos;
    QVector<QPoint> stackAll;
    QVector<QPoint> stackPolygon;

public://绘图算法
    void hklDrawOval();//椭圆
    void hklDrawLine(QPoint start,QPoint end);//直线
    void hklFill(QPoint curPoint);//填充
    void hklDrawCircle(QPoint center,int r);//圆
    void hklDrawPoint(QPoint point);//节点
    void hklPicReverse(double radian);//旋转
    void hklPicMove(int step);//平移
    void hklPicZoom(double zoom);//缩放
    void hklDrawCurve();//曲线
    void drawCurve(double a,double b,double c,double d,int i);
    void hklDrawPolygon();//多边形
    void hklCutPolygon(QPoint a,QPoint c);//多边形裁剪
    int crossMultiply(QPoint a1,QPoint a2,QPoint b1,QPoint b2);
    bool isClockwise(QVector<QPoint> s);//顺时针
    bool isInside(QPoint s,QPoint e,QPoint p);
    QPoint getCrossPoint(QPoint a1,QPoint a2,QPoint b1,QPoint b2);//交点
    void hklDraw3D();//3D
};

#endif // MAINWINDOW_H
