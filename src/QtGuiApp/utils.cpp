#include "utils.h"

CUtils::CUtils(QObject*): QObject(qApp)
{
    int fontId = QFontDatabase::addApplicationFont(":/image/fontawesome-webfont.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    iconFont = QFont(fontName);
}

void CUtils::SetIcon(QLabel* lab, QChar c, int size)
{
    iconFont.setPointSize(size);
    lab->setFont(iconFont);
    lab->setText(c);
}

void CUtils::SetIcon(QPushButton* btn, QChar c, int size)
{
    iconFont.setPointSize(size);
    btn->setFont(iconFont);
    btn->setText(c);
}

void CUtils::AutoRunWithSystem(bool IsAutoRun, const QString& AppName, const QString& AppPath)
{
    QSettings *reg = new QSettings(
        "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
        QSettings::NativeFormat);

    if (IsAutoRun) {
        reg->setValue(AppName, AppPath);
    } else {
        reg->setValue(AppName, "");
    }
}

void CUtils::SetUTF8Code()
{
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#endif
}

void CUtils::SetStyle(const QString &styleName)
{
    QFile file(QString(":/image/%1.css").arg(styleName));
    file.open(QFile::ReadOnly);
    QString qss = QLatin1String(file.readAll());
    qApp->setStyleSheet(qss);
    qApp->setPalette(QPalette(QColor("#F0F0F0")));
}

bool CUtils::SetChinese()
{
   QTranslator * translator=new QTranslator(qApp);
   return translator->load(":/image/qt_zh_CN.qm") && qApp->installTranslator(translator);
}

bool CUtils::IsIP(const QString& IP)
{
    QRegExp RegExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
    return RegExp.exactMatch(IP);
}

int CUtils::ShowMsgBoxInfo(const QString& info)
{
    GuiMsgBox *msg = new GuiMsgBox();
    msg->SetMessage(info, 0);
    return msg->exec();
}

int CUtils::ShowMsgBoxError(const QString& info)
{
    GuiMsgBox *msg = new GuiMsgBox();
    msg->SetMessage(info, 2);
    return msg->exec();
}

int CUtils::ShowMsgBoxQuesion(const QString& info)
{
    GuiMsgBox *msg = new GuiMsgBox();
    msg->SetMessage(info, 1);
    return msg->exec();
}

void CUtils::Sleep(int msecs)
{
    QTime dieTime = QTime::currentTime().addMSecs(msecs);
    while ( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void CUtils::FormInCenter(QWidget *w)
{
    QDesktopWidget dw;
    int nX = w->width();
    int nY = w->height();
    int deskWidth = dw.width();
    int deskHeight = dw.height();
    w->move(QPoint(deskWidth / 2 - nX / 2, deskHeight / 2 - nY / 2));
}
