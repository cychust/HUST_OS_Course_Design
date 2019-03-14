#include "util.h"

Util::Util()
{

}
const QString Util::HOST_NAME_PATH="";
const QString Util::CPU_INFO_PATH="";
const QString Util::SYSTEM_VERSION_PATH="";
const QString Util::SYSTEM_TIME_PATH="";
const QString Util::RUNTIME_PATH="";
const QString Util::CPU_FREQUENCY_PATH="";

QString secondToDay(long seconds){
    long day,hour,minute,second;
    long tmp=seconds;
    day=tmp/(60*60*24);
    tmp%=(60*60*24);
    hour=tmp/(60*60);
    tmp%=tmp%(60*60);
    minute=tmp/60;
    second=tmp%60;
    return QString("").sprintf("%ld days %ld hours %ld minutes %ld seconds",day,hour,minute,second);
}

QString NoNULL_content(QString content){
    if(content==nullptr) return "";
    return content;
}

QString Util::sys_time(){

}
/**
 * (3) run time /proc/uptime
 * @brief Util::run_time
 * @return
 */
QString Util::run_time(){
    QString content = file_content(SYSTEM_TIME_PATH);
    if(content==nullptr) return nullptr;

    QStringList times = content.split (" ");
    if(times.length ()>0){
        return secondToDay((long)times[0].toFloat());
    }
    return nullptr;
}
/**
 * (1)host info  /proc/host
 * @brief Util::host_info
 * @return
 */
QString Util::host_info(){    //(1)host info
    return file_content(HOST_NAME_PATH);
}
/**
 * (4) system version /proc/version
 * @brief Util::sys_version
 * @return
 */
QString Util::sys_version(){
    QString fileContent=file_content (SYSTEM_VERSION_PATH);
    if(fileContent==nullptr) return nullptr;
    QStringList elems=fileContent.split (" ");
    if(elems.length ()<3)return nullptr;
    return elems[2];
}

/**
 * (5) cpu model
 * @brief Util::CPU
 * @return
 */
QString Util::CPU_model(){
    QString fileContent=file_content (CPU_INFO_PATH,"cpu model");
    return fileContent;
}
/**
 * cpu frequence
 * @brief Util::CPU_frequence
 * @return
 */
QString Util::CPU_frequence(){
    return file_content(CPU_FREQUENCY_PATH,"cpu MHZ");
}

/**
 * get all content of file
 * @brief Util::file_content
 * @param filePath
 * @return
 */
QString Util::file_content(QString filePath){
    QFile file(filePath);
    QString result;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Can't open the file"<<endl;
        return nullptr;
    }
    while (!file.atEnd ()) {
        QByteArray line=file.readLine ();
        result.append (line);
    }
    if(file.isOpen ())
        file.close ();
    return result;
}
/**
 * get the lines of file which contain the specific content
 * @brief Util::file_content
 * @param filePath
 * @param lineContained
 * @return
 */
QString  Util::file_content(QString filePath,QString lineContained){
    QFile file(filePath);
    QString result="";
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Can't open the file"<<endl;
        return nullptr;
    }
    while (!file.atEnd ()) {
        QString line=file.readLine ();
        if(line.contains (lineContained)){
            result.append(line).append("\n");
            break;
        }
    }
    if(file.isOpen ())
        file.close ();
    return result;
}
/**
 * file is exist or not
 * @brief Util::IsExist
 * @param pid
 * @return
 */
bool Util::IsExistByPid(QString pid){
    QFile file("/proc/"+pid);
    if(!file.exists ()){
        return false;
    }
    return true;
}

/**
 * Judge a file Name is number or not
 * @brief Util::IsNumberByString
 * @param name
 * @return
 */
bool Util::isNumberByString(QString name){
 QString pattern("[0-9]+");
 QRegExp rx(pattern);
 return rx.exactMatch (name);
}
/**
 * (7)get the list of processes
 * @brief Util::process_stat
 * @return
 */
QList<QMap<QString,QString>> Util::process_stat(){
    QDir dir("/proc");
    dir.setFilter (QDir::Dirs);
    QStringList list = dir.entryList();
    QList<QMap<QString,QString>> mapList;
    for (int var = 0; var < list.size (); ++var) {
        if(isNumberByString (list.at(var))){             //is number
            QMap<QString,QString> map;
            QString statusFilePath="/proc/"+list.at (var)+"/status";
            QString statFilePath="/proc/"+list.at (var)+"/stat";
//            map.insert ("Name",NoNULL_content (file_content (statusFilePath,"Name")));
//            map.insert("pid",NoNULL_content(file_content (statusFilePath,"pid")));
//            map.insert ("ppid",NoNULL_content(file_content (statusFilePath,"ppid")));
            QString content=file_content (statFilePath);
            if(content==nullptr) continue;
            QStringList elems=content.split (" ");
            map.insert ("pid",elems[0]);   //pid
            map.insert ("comm",elems[1]);  //pid
            map.insert ("task_state",elems[2]);//comm
            map.insert ("ppid",elems[3]);  //ppid
            map.insert ("priority",elems[16]); //priority
            map.insert ("vsize",elems[21]); //vsize
            mapList.push_back (map);
        }
    }
    return mapList;
}

QString Util::currentTime(){

}

/**
 * cpu rate
 * @brief Util::CPU_Utilization_Rate
 * @return
 */
QString Util::CPU_Utilization_Rate(){
   QString content = file_content ("/proc/stat","cpu");
   QStringList elems=content.split (" ");
   float usage=0;
   long idle2;
   long total2;
   long user=elems[1].toLong ();
   long nice=elems[2].toLong ();
   long system=elems[3].toLong ();
   long idle=elems[4].toLong ();
   long iowait=elems[5].toLong ();
   long irq=elems[6].toLong ();
   long softirq=elems[7].toLong ();
   long total = user+nice+system+idle+iowait+irq+softirq;
   QThread::sleep(3);
   content=file_content ("/proc/stat","cpu");
   elems=content.split (" ");
   user=elems[1].toLong ();
   nice=elems[2].toLong ();
   system=elems[3].toLong ();
   idle2=elems[4].toLong ();
   iowait=elems[5].toLong ();
   irq=elems[6].toLong ();
   softirq=elems[7].toLong ();
   total2 = user+nice+system+idle2+iowait+irq+softirq;
   usage=(idle2-idle)/(total2-total)*100;
   if(usage<0) usage-=usage;
   return QString("").arg(usage).append("%");
}
/**
 * label set text
 * @brief Util::setText
 * @param o
 * @param text
 */
void Util::setText(QLabel o,QString text){
    o.setText(text==nullptr?"":text);
}


