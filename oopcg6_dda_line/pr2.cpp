#include "pr2.h"
#include "ui_pr2.h"

QImage img(300,300,QImage::Format_RGB888);

pr2::pr2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pr2)
{
    ui->setupUi(this);
}

pr2::~pr2()
{
    delete ui;
}

void pr2::on_pushButton_clicked()   //display btn
{
    int x1,x2,y1,y2,xc,yc,r;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();

    xc=ui->textEdit_5->toPlainText().toInt();
    yc=ui->textEdit_6->toPlainText().toInt();
    r=ui->textEdit_7->toPlainText().toInt();


    dda(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
    circleBres(xc,yc,r);

}

void pr2::dda(int x1, int y1, int x2, int y2)   //dda
{

    float dx,dy,xi,yi,step,x,y,k,i;

                float sign1,sign2;

                dx = x2-x1;

                dy = y2-y1;

                if(abs(dx)>abs(dy)){step=abs(dx);}
                else {step=abs(dy);}

                x=x1;
                y=y1;
                i=0;
                xi=dx/step;
                yi=dy/step;

                while(i<=step)
                {
                    img.setPixel(x,y,qRgb(255,255,255));
                    x=x+xi;
                    y=y+yi;
                    i++;
                }
}

int pr2::signfn(float c1, float c2)
{
    if(c2>c2){return 1;}
    else {return -1;}
}

void pr2::sym(int xc, int yc, int x, int y)     //circle for all 8 quadrants
{

    img.setPixel(xc+x, yc+y, qRgb(255,255,255));
    img.setPixel(xc-x, yc+y, qRgb(255,255,255));
    img.setPixel(xc+x, yc-y, qRgb(255,255,255));
    img.setPixel(xc-x, yc-y, qRgb(255,255,255));
    img.setPixel(xc+y, yc+x, qRgb(255,255,255));
    img.setPixel(xc-y, yc+x, qRgb(255,255,255));
    img.setPixel(xc+y, yc-x, qRgb(255,255,255));
    img.setPixel(xc-y, yc-x, qRgb(255,255,255));

}

void pr2::circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;          //decision parameter
    sym(xc, yc, x, y);
    while (y >= x)
    {
        // for each pixel we will
        // draw all eight pixels

        x++;

        // check for decision parameter
        // and correspondingly
        // update d, x, y
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        sym(xc, yc, x, y);

    }
}



