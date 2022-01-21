#include "guimsgbox.h"
#include "ui_guimsgbox.h"
#include "utils.h"

GuiMsgBox::GuiMsgBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuiMsgBox)
{
    auto util = CUtils::Inst();
    ui->setupUi(this);
    this->mousePressed = false;
    //设置窗体关闭时自动释放内存
    this->setAttribute(Qt::WA_DeleteOnClose);
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint);
    //关联关闭按钮
    connect(ui->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(close()));
    //设置图形字体
    util->SetIcon(ui->lab_Ico, QChar(0xf015), 12);
    util->SetIcon(ui->btnMenu_Close, QChar(0xf00d), 10);
    //窗体居中显示
    util->FormInCenter(this);
}

GuiMsgBox::~GuiMsgBox()
{
    delete ui;
}

void GuiMsgBox::SetMessage(const QString &msg, int type)
{
    if (type == 0)
    {
        ui->labIcoMain->setStyleSheet("border-image: url(:/image/info.png);");
        ui->btnCancel->setVisible(false);
        ui->lab_Title->setText("提示");
    } else if (type == 1)
    {
        ui->labIcoMain->setStyleSheet("border-image: url(:/image/question.png);");
        ui->lab_Title->setText("询问");
    } else if (type == 2)
    {
        ui->labIcoMain->setStyleSheet("border-image: url(:/image/error.png);");
        ui->btnCancel->setVisible(false);
        ui->lab_Title->setText("错误");
    }

    ui->labInfo->setText(msg);
}

void GuiMsgBox::on_btnOk_clicked()
{
    done(1);
    this->close();
}

void GuiMsgBox::mouseMoveEvent(QMouseEvent *e)
{
    if (mousePressed && (e->buttons() & Qt::LeftButton))
    {
        this->move(e->globalPos() - mousePoint);
        e->accept();
    }
}

void GuiMsgBox::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        mousePressed = true;
        mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}

void GuiMsgBox::mouseReleaseEvent(QMouseEvent *)
{
    mousePressed = false;
}
