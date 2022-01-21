#include "guimain.h"
#include <QApplication>
#include "utils.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto util = CUtils::Inst();
    util->SetUTF8Code();
    //util->SetStyle("black");//黑色风格
    util->SetStyle("blue");//蓝色风格
    //util->SetStyle("gray");//灰色风格
    //util->SetStyle("navy");//天蓝色风格
    util->SetChinese();

    GuiMain *w = new GuiMain();
    w->show();

    return a.exec();
}
