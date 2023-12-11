#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "QMouseEvent"
#include "QColorDialog"
using namespace std;


QImage img (500,500,QImage::Format_RGB888);
QColor color=QRgb();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    count=0;
    start=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()  //colour button
{
    color=QColorDialog::getColor();
}

void MainWindow::line(float x1,float y1,float x2,float y2)
{

    float xinc,yinc,step;
    dx=x2-x1;
    dy=y2-y1;
    if (abs(dx)>abs(dy)){
        step=abs(dx);
    }
    else{
        step=abs(dy);
    }
    xinc=dx/step;
    yinc=dy/step;

    int i=0;
    float x,y;
    x=x1;
    y=y1;
    while(i<step){

        x=x+xinc;
        y=y+yinc;
        img.setPixel(x,y,qRgb(color.red(),color.green(),color.blue()));
        i++;

    }
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(start)
    {
        int p=event->pos().x();
        int q=event->pos().y();

        a[count]=p;
        b[count]=q;

        if(event->button()==Qt::RightButton)            //right button is only clicked to end the polygon
        {
            line(a[count-1],b[count-1],a[0],b[0]);
        }
        else
        {
            if (count>0)
            {
                line(a[count],b[count],a[count-1],b[count-1]);
            }
            count++;
        }
    }
}

void MainWindow::on_pushButton_2_clicked()    //fill colour
{
    a[count]=a[0];
    b[count]=b[0];

    for(int i=0;i<count;i++)
    {
        dy=b[i+1]-b[i];
        dx=a[i+1]-a[i];
        if(dy==0.0f) slope[i]=1.0;
        if(dx==0.0f) slope[i]=0.0;
        if(dy!=0.0f && dx!=0.0f)
        {
            slope[i]=dx/dy;
        }
    }
    for(int y=0;y<500;y++)
    {
        k=0;
        for(i=0;i<count;i++)
        {
            if(((b[i]<=y)&&(b[i+1]>y))|| ((b[i]>y)&&(b[i+1]<=y)))
            {
            xi[k]=(a[i]+(slope[i]*(y-b[i])));
            k++;
            }
        }
        for(j=0;j<k-1;j++)
        {
            for(int i=0;i<k-j-1;i++)
            {
                if(xi[i+1]>xi[i])
                {
                    swap(xi[i],xi[i+1]);
                }
            }
        }
        for(int i=0;i<k;i+=2)
        {
            line(xi[i],y,xi[i+1],y);
        }
    }
}
