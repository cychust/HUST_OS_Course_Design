#ifndef UTIL_H
#define UTIL_H

#include "QString"
#include"qfile.h"
#include"qdebug.h"
#include"qlabel.h"
#include"qdir.h"
#include"qmap.h"
#include"qthread.h"
class Util
{
public:
    Util();

    static const QString HOST_NAME_PATH;
    static const QString CPU_INFO_PATH;
    static const QString SYSTEM_VERSION_PATH;
    static const QString SYSTEM_TIME_PATH;
    static const QString RUNTIME_PATH;
    static const QString CPU_FREQUENCY_PATH;

    QString sys_time();
    QString run_time();
    QString host_info();
    QString sys_version();
    QString CPU_model();
    QString CPU_frequence();
    void setText(QLabel o,QString text);

private:
    QString file_content(QString filePath);
    QString file_content(QString filePath,QString lineContained);
};


#endif // UTIL_H
