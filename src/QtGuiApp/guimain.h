#ifndef GUIMAIN_H
#define GUIMAIN_H

#include <QDialog>
#include "utils.h"

namespace Ui {
class GuiMain;
}

class GuiMain : public QDialog
{
    Q_OBJECT

public:
    explicit GuiMain(QWidget *parent = 0);
    ~GuiMain();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void on_btnMenu_Close_clicked();

    void on_btnMenu_Max_clicked();

    void on_btnMenu_Min_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::GuiMain *ui;

    QPoint mousePoint;
    bool mousePressed;
    bool max;
    QRect location;
    void InitStyle();

};

#endif // GUIMAIN_H
