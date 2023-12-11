#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QColorDialog>
#include<stdio.h>
#include "math.h"
#include "iostream"
using namespace std;
QImage img(500,500,QImage::Format_RGB888);
QColor c;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DDA(0,250,500,250);
    DDA(250,0,250,500);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::DDA(int x1, int y1, int x2, int y2)
{
    float dx,dy,lenght,xinc,yinc,x,y;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>=abs(dy))
        lenght=abs(dx);
    else{
        lenght =abs(dy);
    }
    xinc =dx/lenght;
    yinc =dy/lenght;
    x=x1;y=y1;
    int  i = 0;
    while(i<lenght)
    {
        img.setPixel(int(x),int(y),qRgb(255,255,255));
        x=x+xinc;
        y=y+yinc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::on_pushButton_clicked() //DDA BUTTON
{
    x1= ui->textEdit->toPlainText().toInt();
    y1= ui->textEdit_2->toPlainText().toInt();
    x2= ui->textEdit_3->toPlainText().toInt();
    y2= ui->textEdit_4->toPlainText().toInt();
    x3= ui->textEdit_9->toPlainText().toInt();
    y3= ui->textEdit_10->toPlainText().toInt();
    //DDA(x1+250, y1+250, x2+250, y2+250);
    DDA(x1+250, y1+250, x2+250, y2+250);
    DDA(x2+250, y2+250, x3+250, y3+250);
    DDA(x3+250, y3+250, x1+250, y1+250);
}
void MainWindow::on_pushButton_2_clicked()  //TRANSALTE BUTTON
{
    tx= ui->textEdit_5->toPlainText().toInt();
    ty= ui->textEdit_6->toPlainText().toInt();
    x1=x1+tx;
    y1=y1+ty;
    x2=x2+tx;
    y2=y2+ty;
    x3=x3+tx;
    y3=y3+ty;
    DDA(x1+250+tx, y1+250+ty, x2+250+tx, y2+250+ty);
    DDA(x2+250+tx, y2+250+ty, x3+250+tx, y3+250+ty);
    DDA(x3+250+tx, y3+250+ty, x1+250+tx, y1+250+ty);
}
void MainWindow::on_pushButton_3_clicked() //SCALING BUTTON
{
    sx= ui->textEdit_7->toPlainText().toInt();
    sy= ui->textEdit_8->toPlainText().toInt();
    x1=x1*sx;
    y1=y1*sy;
    x2=x2*sx;
    y2=y2*sy;
    x3=x3*sx;
    y3=y3*sy;
    DDA(x1+250, y1+250, x2+250, y2+250);
    DDA(x2+250, y2+250, x3+250, y3+250);
    DDA(x3+250, y3+250, x1+250, y1+250);
}
void MainWindow::on_pushButton_4_clicked() //ROTATE BUTTON
{
    theta= ui->textEdit_11->toPlainText().toInt();
    r=theta*(PI/180);
    p=x1*cos(r)-y1*sin(r);
    q=x1*sin(r)+y1*cos(r);
    l=x2*cos(r)-y2*sin(r);
    s=x2*sin(r)+y2*cos(r);
    DDA(p+250, q+250, l+250, s+250);
}
