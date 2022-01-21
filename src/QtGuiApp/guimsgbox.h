#ifndef GUIMSGBOX_H
#define GUIMSGBOX_H

#include <QDialog>

namespace Ui {
class GuiMsgBox;
}

class GuiMsgBox : public QDialog
{
    Q_OBJECT

public:
    explicit GuiMsgBox(QWidget *parent = 0);
    ~GuiMsgBox();

    void SetMessage(const QString &msg, int type);

protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void on_btnOk_clicked();

private:
    Ui::GuiMsgBox *ui;

    QPoint mousePoint;
    bool mousePressed;
};

#endif // GUIMSGBOX_H
