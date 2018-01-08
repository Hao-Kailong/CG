#include "mainwindow.h"
#include "ui_mainwindow.h"

//中点椭圆生成算法
void MainWindow::hklDrawOval()
{
    const int cX=pix->width()/2;
    const int cY=pix->height()/2;
    QPainter painter;
    painter.begin(pix);
    //开始绘制
    int x = 0; int y = b;
    //上半部分
    double p = b*b-a*a*b+a*a/4;
    while (2*b*b*x <= 2*a*a*y)
    {
        painter.drawPoint(x + cX, y + cY);
        painter.drawPoint(x + cX, -y + cY);
        painter.drawPoint(-x + cX, -y + cY);
        painter.drawPoint(-x + cX, y + cY);
        if (p < 0)
            p = p + 2*b*b*x + 3*b*b;
        else {
            p = p + 2*b*b*x - 2*a*a*y + 2*a*a +3*b*b;
            --y;
        }
        ++x;
    }
    //下半部分
    double p1=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
    while(y>=0)
    {
        painter.drawPoint(x + cX, y + cY);
        painter.drawPoint(x + cX, -y + cY);
        painter.drawPoint(-x + cX, -y + cY);
        painter.drawPoint(-x + cX, y + cY);
        if (p1 > 0)
            p1 = p1 - 2*a*a*y + 3*a*a;
        else {
            p1 = p1 + 2*b*b*x - 2*a*a*y + 2*b*b +3*a*a;
            ++x;
        }
        --y;
    }
    repaint();
}

//Bresenham直线生成算法
void MainWindow::hklDrawLine(QPoint start,QPoint end)
{
    int x0=start.x(); int y0=start.y();
    int x1=end.x(); int y1=end.y();
    QPainter painter;
    painter.begin(pix);
    //开始绘制
    const static int THICK=1;//厚度为1
    const int dx = abs(x1 - x0);
    const int dy = abs(y1 - y0);
    int x = x0; int y = y0;
    const int cx = (x0 > x1) ? -1 : 1;//增量
    const int cy = (y0 > y1) ? -1 : 1;
    int p;
    if (dx == 0 && dy == 0) {//点
        painter.drawPoint(x,y);
    }
    else if (dx == 0) {//垂直线
        for (y =qMin(y0, y1); y <= qMax(y0, y1); ++y)
            for (int i = 0; i < THICK; ++i)
                painter.drawPoint(x + i, y);
    }
    else if (dy == 0) {//水平线
        for (x = qMin(x0, x1); x <= qMax(x0, x1); ++x)
            for (int i = 0; i < THICK; ++i)
                painter.drawPoint(x, y + i);
    }
    else if (dx >= dy) {//小倾角
        p = -dx;
        for (x = x0; (cx > 0 ? x <= x1 : x >= x1); x += cx) {
            for (int i = 0; i < THICK; ++i)
                painter.drawPoint(x, y + i);
            p += dy << 1;
            if (p > 0) {
                y += cy;
                p -= dx << 1;
            }
        }
    }
    else {//大倾角
        p = -dy;
        for (y = y0; (cy > 0 ? y <= y1 : y >= y1); y += cy) {
            for (int i = 0; i < THICK; ++i)
                painter.drawPoint(x + i, y);
            p += dx << 1;
            if (p > 0) {
                x += cx;
                p -= dy << 1;
            }
        }
    }
    repaint();
}

//递归填充算法
void MainWindow::hklFill(QPoint curPoint)
{
    QImage img=pix->toImage();
    if(img.pixelColor(curPoint)!=Qt::white)
        return;
    QPainter painter;
    painter.begin(pix);
    int w=pix->width();
    int h=pix->height();
    bool **visit=new bool*[w];
    for(int i=0;i<w;++i)
        visit[i]=new bool[h];
    for(int i=0;i<w;++i)
        for(int j=0;j<h;++j)
            visit[i][j]=false;
    QStack<QPoint> s;
    s.push(curPoint);
    while(!s.empty())
    {
        curPoint=s.pop();
        if(curPoint.x()<0||curPoint.y()<0||curPoint.x()>w||curPoint.y()>h)
            continue;
        if(img.pixelColor(curPoint)!=Qt::white)
            continue;
        if(visit[curPoint.x()][curPoint.y()]==true)
            continue;
        visit[curPoint.x()][curPoint.y()]=true;
        painter.drawPoint(curPoint);
        s.push(curPoint+QPoint(-1,0));
        s.push(curPoint+QPoint(1,0));
        s.push(curPoint+QPoint(0,1));
        s.push(curPoint+QPoint(0,-1));
    }
}

//中点圆生成算法
void MainWindow::hklDrawCircle(QPoint center,int r)
{
    QPainter painter;
    painter.begin(pix);
    int cX=center.x();
    int cY=center.y();
    int x = 0; int y = r;
    double p = 5.0 / 4.0 - r;
    while (x < y)
    {
        painter.drawPoint(x + cX, y + cY);
        painter.drawPoint(x + cX, -y + cY);
        painter.drawPoint(-x + cX, -y + cY);
        painter.drawPoint(-x + cX, y + cY);
        painter.drawPoint(y + cX, x + cY);
        painter.drawPoint(y + cX, -x + cY);
        painter.drawPoint(-y + cX, -x + cY);
        painter.drawPoint(-y + cX, x + cY);
        if (p < 0)
            p = p + 2 * x + 3;
        else {
            p = p + 2 * x - 2 * y + 3;
            --y;
        }
        ++x;
    }
    repaint();
}

//曲线绘制节点
void MainWindow::hklDrawPoint(QPoint point)
{
    QPainter painter;
    painter.begin(pix);
    painter.drawPoint(point);
    painter.drawPoint(point+QPoint(1,1));
    painter.drawPoint(point+QPoint(2,2));
    painter.drawPoint(point+QPoint(-1,-1));
    painter.drawPoint(point+QPoint(-2,-2));
    painter.drawPoint(point+QPoint(1,-1));
    painter.drawPoint(point+QPoint(2,-2));
    painter.drawPoint(point+QPoint(-1,1));
    painter.drawPoint(point+QPoint(-2,2));
}

//图形旋转算法
void MainWindow::hklPicReverse(double radian)
{
    QImage img;
    img=pix->toImage();
    int w=pix->width();
    int h=pix->height();
    int cX=w/2; int cY=h/2;
    pix->fill(Qt::white);
    QPainter painter;
    painter.begin(pix);
    for(int i=0;i<w;++i)
        for(int j=0;j<h;++j)
        {
            int x0=i-cX; int y0=j-cY;
            QColor tmpColor=img.pixelColor(i,j);
            if(tmpColor==Qt::white)
                continue;
            int x1=x0*qCos(radian)+y0*qSin(radian);
            int y1=-x0*qSin(radian)+y0*qCos(radian);
            int ri=x1+cX; int rj=y1+cY;
            if(ri<0||ri>=w||rj<0||rj>=h)
                continue;
            painter.drawPoint(ri,rj);
        }
    repaint();
}

//图形平移算法
void MainWindow::hklPicMove(int step)
{
    QImage img;
    img=pix->toImage();
    int w=pix->width();
    int h=pix->height();
    pix->fill(Qt::white);
    QPainter painter;
    painter.begin(pix);
    for(int i=0;i<w;++i)
        for(int j=0;j<h;++j)
        {
            QColor tmpColor=img.pixelColor(i,j);
            if(tmpColor==Qt::white)
                continue;
            int ri=i+step; int rj=j;
            if(ri<0||ri>=w)
                continue;
            painter.drawPoint(ri,rj);
        }
    repaint();
}

//图形缩放算法
void MainWindow::hklPicZoom(double zoom)
{
    QImage img;
    img=pix->toImage();
    int w=img.width();
    int h=img.height();
    pix->fill(Qt::white);
    QPainter painter;
    QPen pen;
    pen.setWidth(qMax(1,(int)zoom));
    painter.begin(pix);
    painter.setPen(pen);
    for(int i=0;i<w;++i)
        for(int j=0;j<h;++j)
        {
            QColor tmpColor=img.pixelColor(i,j);
            if(tmpColor==Qt::white)
                continue;
            int ri=i*zoom; int rj=j*zoom;
            if(ri<0||ri>=w||rj<0||rj>=h)
                continue;
            painter.drawPoint(ri,rj);
        }
    repaint();
}

//B样条曲线算法
void MainWindow::hklDrawCurve()
{
    int n=stackAll.size()-1;
    for(int i=0;i<n;++i) //排序
        for(int j=n;j>i;--j)
            if(stackAll[j].x()<stackAll[j-1].x())
            {
                QPoint tmp=stackAll[j];
                stackAll[j]=stackAll[j-1];
                stackAll[j-1]=tmp;
            }
    vector<double> stackH; //计算步长
    for(int i=0;i<n;++i)
        stackH.push_back(stackAll[i+1].x()-stackAll[i].x());
    double **A=new double*[n+1];//生成矩阵A、B(AX=B)
    for(int i=0;i<=n;++i){
        A[i]=new double[n+1];
        for(int j=0;j<=n;++j)
            A[i][j]=0.0;
    }
    double *B=new double[n+1];
    for(int i=0;i<=n;++i){
        if(i==0||i==n)
            A[i][i]=1.0;
        else{
            A[i][i]=2.0*(stackH[i-1]+stackH[i]);
            A[i][i-1]=stackH[i-1];
            A[i][i+1]=stackH[i];
        }
    }
    for(int i=0;i<=n;++i){
        if(i==0||i==n)
            B[i]=0.0;
        else{
            double t1=(stackAll[i+1].y()-stackAll[i].y())/stackH[i];
            double t2=(stackAll[i].y()-stackAll[i-1].y())/stackH[i-1];
            B[i]=6.0*(t1-t2);
        }
    }
    double *a=new double[n+1];//Thmos算法求解矩阵X
    double *b=new double[n+1];
    double *c=new double[n+1];
    for(int i=0;i<=n;++i){
        if(i==0){
            a[i]=0; b[i]=A[i][i]; c[i]=A[i][i+1]/b[i];
        }
        else if(i==n){
            a[i]=A[i][i-1]; b[i]=A[i][i]-a[i]*c[i-1]; c[i]=0;
        }
        else{
            a[i]=A[i][i-1]; b[i]=A[i][i]-a[i]*c[i-1]; c[i]=A[i][i+1]/b[i];
        }
    }
    double *X=new double[n+1];
    X[0]=B[0]/b[0];
    for(int i=1;i<=n;++i)
        X[i]=(B[i]-a[i]*X[i-1])/b[i];
    X[n]=X[n];
    for(int i=n-1;i>=0;--i)
        X[i]=X[i]-c[i]*X[i+1];
    struct cfct{ //生成系数
        double a;
        double b;
        double c;
        double d;
    };
    QVector<struct cfct> stackCfct;
    for(int i=0;i<n;++i)
    {
        struct cfct tmp;
        tmp.a=stackAll[i].y();
        double t1=(stackAll[i+1].y()-stackAll[i].y())/stackH[i];
        double t2=(X[i+1]-X[i])*stackH[i]/6.0;
        tmp.b=t1-t2-stackH[i]*X[i]/2.0;
        tmp.c=X[i]/2;
        tmp.d=(X[i+1]-X[i])/stackH[i]/6.0;
        stackCfct.push_back(tmp);
    }
    for(int i=0;i<n;++i){ //分段绘制曲线
        struct cfct tmp=stackCfct[i];
        drawCurve(tmp.a,tmp.b,tmp.c,tmp.d,i);
    }
    repaint();
    stackAll.erase(stackAll.begin(),stackAll.end());//清空记录
}
void MainWindow::drawCurve(double a, double b, double c, double d, int i)
{
    int x0=stackAll[i].x();
    int x1=stackAll[i+1].x();
    QPainter painter;
    painter.begin(pix);
    for(int x=x0;x<=x1;++x){
        int y=a+b*(x-x0)+c*pow(x-x0,2)+d*pow(x-x0,3);
        if(y<0||y>sizeY)
            continue;
        painter.drawPoint(x,y);
    }
    repaint();
}

//多边形绘制算法
void MainWindow::hklDrawPolygon()
{
    int n=stackAll.size();
    for(int i=0;i<n-1;++i){
        QPoint start=stackAll[i];
        QPoint end=stackAll[i+1];
        hklDrawLine(start,end);
    }
    hklDrawLine(stackAll[n-1],stackAll[0]);
    repaint();
    stackPolygon.erase(stackPolygon.begin(),stackPolygon.end());
    stackPolygon=stackAll;
    if(!isClockwise(stackPolygon)){
        for(int i=0,j=stackPolygon.size()-1;i<j;++i,--j){
            QPoint tmp=stackPolygon[i];
            stackPolygon[i]=stackPolygon[j];
            stackPolygon[j]=tmp;
        }
    }
    stackAll.erase(stackAll.begin(),stackAll.end());
}

//多边形方向判断算法
bool MainWindow::isClockwise(QVector<QPoint> s)
{
    int n=s.size();
    int cntP=0;
    int cntN=0;
    for(int i=0;i<n-2;++i){
        QPoint a1=stackPolygon[i];
        QPoint a2=stackPolygon[i+1];
        QPoint a3=stackPolygon[i+2];
        if(crossMultiply(a1,a2,a2,a3)>0)
            ++cntP;
        else if(crossMultiply(a1,a2,a2,a3)<0)
            ++cntN;
    }
    QPoint a1=stackPolygon[n-2];
    QPoint a2=stackPolygon[n-1];
    QPoint a3=stackPolygon[0];
    if(crossMultiply(a1,a2,a2,a3)>0)
        ++cntP;
    else if(crossMultiply(a1,a2,a2,a3)<0)
        ++cntN;
    a1=stackPolygon[n-1];
    a2=stackPolygon[0];
    a3=stackPolygon[1];
    if(crossMultiply(a1,a2,a2,a3)>0)
        ++cntP;
    else if(crossMultiply(a1,a2,a2,a3)<0)
        ++cntN;
    if(cntN>=cntP){
        //以正视第一象限为方向
        return true;
    }
    return false;
}
int MainWindow::crossMultiply(QPoint a1,QPoint a2,QPoint b1,QPoint b2)
{
    return (a2.x()-a1.x())*(b2.y()-a2.y())-(a2.y()-a1.y())*(b2.x()-a2.x());
}

//3D图形透视生成
void MainWindow::hklDraw3D()
{
    //以z轴负方向透视投影后结果
    const QPoint p0(300,300);
    const QPoint p1(400,300);
    const QPoint p2(400,240);
    const QPoint p3(300,240);
    const QPoint p4=p0+QPoint(30,-30);
    const QPoint p5=p1+QPoint(30,-30);
    const QPoint p6=p2+QPoint(30,-30);
    const QPoint p7=p3+QPoint(30,-30);
    //消隐绘制直线
    hklDrawLine(p0,p1);
    hklDrawLine(p1,p2);
    hklDrawLine(p2,p3);
    hklDrawLine(p3,p0);
    hklDrawLine(p1,p5);
    hklDrawLine(p2,p6);
    hklDrawLine(p3,p7);
    hklDrawLine(p5,p6);
    hklDrawLine(p6,p7);
    repaint();
}

//多边形Sutherland-Hodgman裁剪算法
void MainWindow::hklCutPolygon(QPoint a,QPoint c)
{
    QVector<QPoint> stackCut;
    QPoint b,d;
    if(c.x()>a.x()&&c.y()<a.y() || c.x()<a.x()&&c.y()>a.y()){
        d=QPoint(a.x(),c.y());
        b=QPoint(c.x(),a.y());
    }
    else if(c.x()>a.x()&&c.y()>a.y() || c.x()<a.x()&&c.y()<a.y()){
        d=QPoint(c.x(),a.y());
        b=QPoint(a.x(),c.y());
    }
    else;
    stackCut.push_back(a);
    stackCut.push_back(b);
    stackCut.push_back(c);
    stackCut.push_back(d);    
    QVector<QPoint> stackResult;//开始逐边裁剪
    for(int i=0;i<4;++i)
    {
        QPoint sCut,eCut;
        sCut=stackCut[i];
        eCut=stackCut[(i+1)%4];
        bool flag;//内1外0
        flag=isInside(sCut,eCut,stackPolygon[stackPolygon.size()-1]);
        QPoint pre=stackPolygon[stackPolygon.size()-1];
        for(int j=0;j<stackPolygon.size();++j)
        {
            QPoint p=stackPolygon[j];
            if(isInside(sCut,eCut,p))
            {
                if(!flag){//入交点
                    QPoint tmp=getCrossPoint(sCut,eCut,pre,p);
                    stackResult.push_back(tmp);
                }
                stackResult.push_back(p);
                flag=true;
            }
            else
            {
                if(flag){
                    QPoint tmp=getCrossPoint(sCut,eCut,pre,p);
                    stackResult.push_back(tmp);
                }
                flag=false;
            }
            pre=p;
        }
        stackPolygon=stackResult;//新多边形
        stackResult.erase(stackResult.begin(),stackResult.end());
    }
    stackAll=stackPolygon;
    QPainter painter;//外部置空
    QPen pen;
    QImage img=pix->toImage();
    pen.setColor(Qt::white);
    painter.begin(pix);
    painter.setPen(pen);
    for(int i=0;i<pix->width();++i)
        for(int j=0;j<pix->height();++j)
        {
            if(img.pixelColor(i,j)==Qt::white)
                continue;
            if(!(i>=qMin(a.x(),c.x())&&i<=qMax(a.x(),c.x())&&j>=qMin(a.y(),c.y())&&j<=qMax(a.y(),c.y())))
                painter.drawPoint(i,j);
        }
    painter.end();
    hklDrawPolygon();//绘制裁剪后图形
    repaint();
}
bool MainWindow::isInside(QPoint s,QPoint e,QPoint p)
{
    if((e.x()-s.x())*(p.y()-s.y())-(p.x()-s.x())*(e.y()-s.y())<=0)
        return true;
    return false;
}

//直线交点算法
QPoint MainWindow::getCrossPoint(QPoint a1,QPoint a2,QPoint b1,QPoint b2)
{
    int x,y;
    if(a1.x()==a2.x()){ //垂直
        if(b1.x()==b2.x())
            return QPoint();
        else if(b1.y()==b2.y())
            return QPoint(a1.x(),b1.y());
        else{
            x=a1.x();
            y=(x-b2.x())/(double)(b1.x()-b2.x())*(b1.y()-b2.y())+b2.y();
            return QPoint(x,y);
        }
    }
    else if(a1.y()==a2.y()){ //水平
        if(b1.y()==b2.y())
            return QPoint();
        else if(b1.x()==b2.x())
            return QPoint(b1.x(),a1.y());
        else{
            y=a1.y();
            x=(y-b2.y())/(double)(b1.y()-b2.y())*(b1.x()-b2.x())+b2.x();
            return QPoint(x,y);
        }
    }
    else{ //倾斜
        if(b1.y()==b2.y()){
            y=b1.y();
            x=(y-a2.y())/(double)(a1.y()-a2.y())*(a1.x()-a2.x())+a2.x();
            return QPoint(x,y);
        }
        else if(b1.x()==b2.x()){
            x=b1.x();
            y=(x-a2.x())/(double)(a1.x()-a2.x())*(a1.y()-a2.y())+a2.y();
            return QPoint(x,y);
        }
        else{
            double m1,n1,m2,n2;
            m1=(a1.y()-a2.y())/(double)(a1.x()-a2.x());
            n1=a1.y()-m1*a1.x();
            m2=(b1.y()-b2.y())/(double)(b1.x()-b2.x());
            n2=b1.y()-m2*b1.x();
            x=(n2-n1)/(m1-m2);
            y=m1*x+n1;
            return QPoint(x,y);
        }
    }
}


