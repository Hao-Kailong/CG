#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);//禁止最大化按钮
    setFixedSize(this->width(),this->height());//禁止窗口大小改变
    pix=new QPixmap(sizeX,sizeY);
    pix->fill(Qt::white);
    status=DOODLE;
    startPos=QPoint(-1,-1);
    connect(ui->actionSave_S,SIGNAL(triggered(bool)),this,SLOT(saveFile()));//将动作和函数绑定
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(oX,oY,*pix);
}

void MainWindow::mousePressEvent(QMouseEvent *event)//按下鼠标
{
    if(ui->Fill->isChecked()){
        QPoint curPoint=event->pos()-QPoint(oX,oY);
        hklFill(curPoint);
        repaint();
    }
    else if(status==LINE)
    {
        if(startPos==QPoint(-1,-1)){
            startPos=event->pos()-QPoint(oX,oY);
            return;
        }
        hklDrawLine(startPos,event->pos()-QPoint(oX,oY));
        startPos=event->pos()-QPoint(oX,oY);
        repaint();
    }
    else if(status==CIRCLE)
    {
        static int cnt=0;
        if(startPos==QPoint(-1,-1) || cnt==0){
            startPos=event->pos()-QPoint(oX,oY);
            cnt=1;
            return;
        }
        QPoint curPoint=event->pos()-QPoint(oX,oY);
        int r=sqrt(pow(curPoint.x()-startPos.x(),2)+pow(curPoint.y()-startPos.y(),2));
        hklDrawCircle(startPos,r);
        cnt=0;
        repaint();
    }
    else if(status==DOODLE)
        startPos=event->pos()-QPoint(oX,oY);
    else if(status==SETPOINT){
        QPoint curPoint=event->pos()-QPoint(oX,oY);
        stackAll.push_back(curPoint);
        hklDrawPoint(curPoint);
        repaint();
    }
    else if(status==CUT){
        static int cntA=0;
        if(startPos==QPoint(-1,-1) || cntA==0){
            startPos=event->pos()-QPoint(oX,oY);
            hklDrawPoint(startPos);
            cntA=1;
            repaint();
            return;
        }
        QPoint curPoint=event->pos()-QPoint(oX,oY);
        hklDrawPoint(curPoint);
        repaint();
        hklCutPolygon(startPos,curPoint);
        cntA=0;
        repaint();
    }
    else;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)//移动鼠标
{
    if(ui->Fill->isChecked())
        return;
    if(status!=DOODLE)
        return;
    hklDrawLine(startPos,event->pos()-QPoint(oX,oY));
    startPos=event->pos()-QPoint(oX,oY);
    repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonLine_clicked()//直线
{
    status=LINE;
    ui->label->setText("Line");
}

void MainWindow::on_ButtonCircle_clicked()//圆
{
    status=CIRCLE;
    ui->label->setText("Circle");
}

void MainWindow::getData(int a,int b)//椭圆
{
    this->a=a;
    this->b=b;
    hklDrawOval();
}
void MainWindow::on_ButtonOval_clicked()
{
    status=OVAL;
    ui->label->setText("Oval");
    DialogOval *tmp = new DialogOval(this);
    connect(tmp, &DialogOval::returnData, this, &MainWindow::getData);
    tmp->show();
}

void MainWindow::on_ButtonDoodle_clicked()//涂鸦
{
    status=DOODLE;
    ui->label->setText("Doodle");
}

void MainWindow::on_Fill_clicked(bool checked)//填充
{
    if(checked)
        ui->label->setText("Fill");
    else{
        status=DOODLE;
        ui->label->setText("Doodle");
    }
}

void MainWindow::on_Reverse_clicked()//旋转
{
    double angle=ui->lineEditReverse->text().toDouble();
    double radian=-angle*PI/180.0;
    hklPicReverse(radian);
    repaint();
}

void MainWindow::on_Move_clicked()//平移
{
    int step=(int)ui->lineEditMove->text().toDouble();
    hklPicMove(step);
    repaint();
}

void MainWindow::on_Zoom_clicked()//缩放
{
    double zoom=ui->lineEditZoom->text().toDouble();
    hklPicZoom(zoom);
    repaint();
}

void MainWindow::saveFile()//保存文件
{
    QString filename=QFileDialog::getSaveFileName(this,"Save Image","draw.png","");
    if(filename.isEmpty())
        return;
    else pix->save(filename);
}

void MainWindow::on_Curve_clicked()//曲线
{
    if(ui->Curve->text()=="Curve"){
        status=SETPOINT;
        ui->label->setText("Set\nPoint");
        ui->Curve->setText("Draw");
    }
    else{
        ui->label->setText("Doodle");
        ui->Curve->setText("Curve");
        hklDrawCurve();
        repaint();
        status=DOODLE;
    }
}

void MainWindow::on_Polygon_clicked()//多边形
{
    if(ui->Polygon->text()=="Polygon"){
        status=SETPOINT;
        ui->label->setText("Set\nPoint");
        ui->Polygon->setText("Draw");
    }
    else{
        ui->label->setText("Doodle");
        ui->Polygon->setText("Polygon");
        hklDrawPolygon();
        repaint();
        status=DOODLE;
    }
}

void MainWindow::on_Cut_clicked()//裁剪
{
    status=CUT;
    ui->label->setText("Cut");
}

void MainWindow::on_pushButton_clicked()//清空
{
    pix->fill(Qt::white);
    repaint();
}

void MainWindow::on_D3_clicked()//3D绘制
{
    hklDraw3D();
    repaint();
}
