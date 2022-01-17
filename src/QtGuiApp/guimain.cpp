#include "guimain.h"
#include "ui_guimain.h"
#include "utils.h"

GuiMain::GuiMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GuiMain)
{
    auto& util = CUtils::Inst();
    ui->setupUi(this);

    util.FormInCenter(this);
    this->InitStyle();
}

GuiMain::~GuiMain()
{
    delete ui;
}

void GuiMain::InitStyle()
{
    auto& util = CUtils::Inst();
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    location = this->geometry();
    max = false;
    mousePressed = false;

    //安装事件监听器,让标题栏识别鼠标双击
    ui->lab_Title->installEventFilter(this);

    util.SetIcon(ui->btnMenu_Close, QChar(0xf00d), 10);
    util.SetIcon(ui->btnMenu_Max, QChar(0xf096), 10);
    util.SetIcon(ui->btnMenu_Min, QChar(0xf068), 10);
    util.SetIcon(ui->btnMenu, QChar(0xf0c9), 10);
    util.SetIcon(ui->lab_Ico, QChar(0xf015), 12);
}

bool GuiMain::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        this->on_btnMenu_Max_clicked();
        return true;
    }
    return QObject::eventFilter(obj, event);
}

void GuiMain::mouseMoveEvent(QMouseEvent *e)
{
    if (mousePressed && (e->buttons() & Qt::LeftButton) && !max)
    {
        this->move(e->globalPos() - mousePoint);
        e->accept();
    }
}

void GuiMain::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        mousePressed = true;
        mousePoint = e->globalPos() - this->pos();
        e->accept();
    }
}

void GuiMain::mouseReleaseEvent(QMouseEvent *)
{
    mousePressed = false;
}

void GuiMain::on_btnMenu_Close_clicked()
{
    qApp->exit();
}

void GuiMain::on_btnMenu_Max_clicked()
{
    auto& util = CUtils::Inst();
    if (max)
    {
        this->setGeometry(location);
        util.SetIcon(ui->btnMenu_Max, QChar(0xf096), 10);
        ui->btnMenu_Max->setToolTip("最大化");
    }
    else
    {
        location = this->geometry();
        this->setGeometry(QGuiApplication::screens().at(0)->availableGeometry());
        util.SetIcon(ui->btnMenu_Max, QChar(0xf079), 10);
        ui->btnMenu_Max->setToolTip("还原");
    }
    max = !max;
}

void GuiMain::on_btnMenu_Min_clicked()
{
    this->showMinimized();
}

void GuiMain::on_pushButton_clicked()
{
    auto& util = CUtils::Inst();
    util.ShowMessageBoxInfo("恭喜你，选择老公成功!");
}

void GuiMain::on_pushButton_2_clicked()
{
    auto& util = CUtils::Inst();
    int result = util.ShowMessageBoxQuesion("确定真的不要我了吗?");
    if (result == 1)
    {
        util.ShowMessageBoxInfo("你好狠心啊!");
    }
    else
    {
        util.ShowMessageBoxInfo("亲爱的,我就知道你不会离开我的!");
    }
}

void GuiMain::on_pushButton_3_clicked()
{
    auto& util = CUtils::Inst();
    util.ShowMessageBoxError("老公在呢!");
}
