#ifndef PR2_H
#define PR2_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class pr2; }
QT_END_NAMESPACE

class pr2 : public QMainWindow
{
    Q_OBJECT

public:
    pr2(QWidget *parent = nullptr);
    ~pr2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pr2 *ui;
    void dda(int, int, int, int);
    int signfn(float,float);
    void sym(int xc, int yc, int x, int y);
    void circleBres(int xc, int yc, int r);
};
#endif // PR2_H
