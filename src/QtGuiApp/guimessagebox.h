#ifndef __GUIMESSAGEBOX_H
#define __GUIMESSAGEBOX_H

#include <QDialog>

namespace Ui {
class GuiMessageBox;
}

class GuiMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit GuiMessageBox(QWidget *parent = 0);
    ~GuiMessageBox();

    void SetMessage(const QString &msg, int type);

protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void on_btnOk_clicked();

private:
    Ui::GuiMessageBox *ui;

    QPoint mousePoint;
    bool mousePressed;
};

#endif // __GUIMESSAGEBOX_H
