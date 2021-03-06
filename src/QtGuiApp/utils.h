#ifndef __UTILS_H
#define __UTILS_H

#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <QDesktopWidget>
#include <QObject>
#include <QFont>
#include <QFontDatabase>
#include <QPushButton>
#include <QApplication>
#include "guimsgbox.h"

class CUtils: public QObject
{
    explicit CUtils(QObject *parent = 0);
    QFont iconFont;
public:
    void SetIcon(QLabel* lab, QChar c, int size = 10);
    void SetIcon(QPushButton* btn, QChar c, int size = 10);
    void AutoRunWithSystem(bool IsAutoRun, const QString& AppName, const QString& AppPath);
    void SetUTF8Code();
    void SetStyle(const QString &styleName);
    bool SetChinese();
    bool IsIP(const QString& IP);
    int ShowMsgBoxInfo(const QString& info);
    int ShowMsgBoxError(const QString& info);
    int ShowMsgBoxQuesion(const QString& info);
    void Sleep(int msecs);
    void FormInCenter(QWidget *w);
public:
    static CUtils* Inst()
    {
        static CUtils *CUtilsInstance = new CUtils();
        return CUtilsInstance;
    }
};

#endif // __UTILS_H
