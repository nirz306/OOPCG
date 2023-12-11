#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <math.h>
#include<iostream>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void DDA(int ,int,int ,int);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
private:
    Ui::MainWindow *ui;
    int x1, y1, x2, y2, tx, ty, sx, sy, x3, y3, theta;
    const float PI= 3.14;
    int p, q, l, s;
    float r;
};
#endif // MAINWINDOW_H
