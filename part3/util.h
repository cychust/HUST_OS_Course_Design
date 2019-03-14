#ifndef UTIL_H
#define UTIL_H

#include "QString"
#include"qfile.h"

#include"qlabel.h"
#include"qdir.h"
#include"qmap.h"
#include"qthread.h"

#include"QtDebug"
#include"qtextstream.h"
#include"istream"
#include"QDateTime"
#include"QTime"
#include"qabstractitemview.h"
#include <sys/types.h>
#include <signal.h>

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
    void setText(QLabel* o,QString text);
    QList<QMap<QString,QString>> process_stat();
    QString CPU_Utilization_Rate();
    QStringList cpu_rates();
    bool isNumberByString(QString name);
    double mem_rate();
private:

    QString file_content(QString filePath);
    QString file_content(QString filePath,QString lineContained);
    QString file_content(QString filePath,QStringList argv);
    bool IsExistByPid(QString pid);
};


#endif // UTIL_H
