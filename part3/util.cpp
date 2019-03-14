#include "util.h"

Util::Util()
{

}
const QString Util::HOST_NAME_PATH="/proc/sys/kernel/hostname";
const QString Util::CPU_INFO_PATH="/proc/cpuinfo";
const QString Util::SYSTEM_VERSION_PATH="/proc/version";
const QString Util::SYSTEM_TIME_PATH="/proc/uptime";
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
    QString content=file_content (SYSTEM_TIME_PATH);
    if(content==nullptr) return nullptr;
    QStringList times = content.split (" ");
    QDateTime currentTime=QDateTime::currentDateTime();
    qint64 runtime=times[0].toDouble();
    currentTime = currentTime.addSecs(-runtime);
    QString result= currentTime.toString ("yyyy-MM-hh hh:mm:ss ddd");
    return result;
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
        QTime runtime(0,0);
        runtime=runtime.addSecs((long long)times[0].toDouble ());
        QString result=runtime.toString ("HH:mm:ss");
        return result;
    }
    return nullptr;
}
/**
 * (1)host info  /proc/host
 * @brief Util::host_info
 * @return
 */
QString Util::host_info(){    //(1)host info
   QString hostName=file_content(HOST_NAME_PATH);
   return  hostName;
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
    QString fileContent=file_content (CPU_INFO_PATH,"model name");
    QStringList cpus=fileContent.split ("\n");
    QString result;
    result.append (cpus[0].mid (cpus[0].lastIndexOf (":")+1,cpus[0].length ()));
    return result;
}
/**
 * cpu frequence
 * @brief Util::CPU_frequence
 * @return
 */
QString Util::CPU_frequence(){
    QString fileContent=file_content (CPU_INFO_PATH,"cpu MHz");
    QStringList cpus=fileContent.split ("\n");
    QString result;
    for (int i=0;i<cpus.size ();i++) {
        result.append (cpus[i].mid (cpus[i].lastIndexOf (":")+1,cpus[i].length ())).append ("\n");
    }
    return result;
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
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"Can't open the file"<<endl;
        return nullptr;
    }
    QTextStream in(&file);
    QString line;
    do{
        line=in.readLine ();
        if(!line.isNull ())
            result.append (line);
    }while(!line.isNull ());

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
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"Can't open the file"<<endl;
        return nullptr;
    }
    QTextStream in(&file);
    QString line;
    do{
        line=in.readLine();
        if(!line.isNull ()){
            if(line.contains(lineContained)){
                result.append(line).append("\n");
            }
        }
    }while(!line.isNull ());
//    qDebug()<<"*********************************";
    if(file.isOpen ())
        file.close ();
    return result;
}

QString Util::file_content(QString filePath,QStringList argv){
    QFile file(filePath);
    QString result;
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"Can't open the file"<<endl;
        return nullptr;
    }
    QTextStream in(&file);
    QString line;
    do{
        line=in.readLine();
        if(!line.isNull ()){
            for (int i=0;i<argv.size();i++) {
                if(line.contains(argv[i])){
                    result.append(line).append("\n");
                    break;
                }
            }
        }
    }while(!line.isNull ());
//    qDebug()<<"*********************************";
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
//            QString statusFilePath="/proc/"+list.at (var)+"/status";
            QString statFilePath="/proc/"+list.at (var)+"/stat";
            QString content=file_content (statFilePath);
            if(content==nullptr) continue;
            QStringList elems=content.split (" ");
            map.insert ("pid",elems[0]);   //pid
            map.insert ("comm",elems[1].mid(elems[1].lastIndexOf ("(")+1,elems[1].indexOf (")")-1));  //comm
            map.insert ("task_state",elems[2]);//task_state
            map.insert ("ppid",elems[3]);  //ppid
            map.insert ("priority",elems[17]); //priority
            map.insert ("vsize",elems[23]); //rss
//            qDebug()<<elems[0]<<" "<<elems[1]<<" "<<elems[2]<<" "<<elems[3]<<" "<<elems[16]<<" "<<elems[21];
            mapList.push_back (map);
        }
    }
    return mapList;
}


/**
 * cpu rate
 * @brief Util::CPU_Utilization_Rate
 * @return
 */
QString Util::CPU_Utilization_Rate(){
   QString content = file_content ("/proc/stat","cpu");
   QStringList elems=content.split (" ");
   double usage=0;
   double idle2;
   double total2;
   double user=elems[2].toDouble ();
   double nice=elems[3].toLong ();
   double system=elems[4].toLong ();
   double idle=elems[5].toLong ();
   double iowait=elems[6].toLong ();
   double irq=elems[7].toLong ();
   double softirq=elems[8].toLong ();
   double total = user+nice+system+idle+iowait+irq+softirq;
   QThread::msleep(30);
   content=file_content ("/proc/stat","cpu");
//   qDebug()<<content;
   elems=content.split (" ");
   user=elems[2].toLong ();
//   qDebug()<<elems[2];
   nice=elems[3].toLong ();
   system=elems[4].toLong ();
   idle2=elems[5].toLong ();
   iowait=elems[6].toLong ();
   irq=elems[7].toLong ();
   softirq=elems[8].toLong ();
   total2 = user+nice+system+idle2+iowait+irq+softirq;
   usage=(1-(idle2-idle)/(total2-total))*100.0;

//   qDebug()<<elems[2]<<" "<<elems[3]<<" "<<elems[4]<<" "<<elems[5]<<" "<<elems[6]<<" "<<elems[7]<<" "<<elems[8]<<" ";
//   qDebug()<<idle2-idle<<" "<<total2-total;
   if(usage<0) usage-=usage;
//   qDebug()<<usage;
   QString result=QString::number(usage,10,2);
   return result;
}

QStringList Util::cpu_rates(){
    QString content = file_content ("/proc/stat","cpu");
    QStringList elems=content.split (" ");
    double user=elems[2].toDouble ();
    double nice=elems[3].toLong ();
    double system=elems[4].toLong ();
    double idle=elems[5].toLong ();
    double iowait=elems[6].toLong ();
    double irq=elems[7].toLong ();
    double softirq=elems[8].toLong ();
    double total = user+nice+system+idle+iowait+irq+softirq;
    QStringList result;
    result.push_back (QString::number (total));
    result.push_back (QString::number (idle));
    return result;
}
/**
 * label set text
 * @brief Util::setText
 * @param o
 * @param text
 */
void Util::setText(QLabel* o,QString text){
    o->setText(text==nullptr?"":text);
}

/**
 * memory used rates;
 * @brief Util::mem_rate
 * @return
 */
double Util::mem_rate (){
    QStringList argv={"MemTotal","MemFree","Buffers","Cached"};
    QString content = file_content ("/proc/meminfo",argv);
    QStringList contents=content.split ("\n");
    double MemTotal = contents[0].split (":")[1].trimmed ().split (" ")[0].toDouble ();
    double MemFree  = contents[1].split (":")[1].trimmed ().split (" ")[0].toDouble ();
    double Buffers  = contents[2].split (":")[1].trimmed ().split (" ")[0].toDouble ();
    double Cached   = contents[3].split (":")[1].trimmed ().split (" ")[0].toDouble ();
    qDebug()<<MemTotal<<" "<<MemFree<<" "<<Buffers<<" "<<Cached<<" ";
    double result=0.0;
    result=(MemTotal-MemFree-Buffers-Cached)/MemTotal*100;
    qDebug()<<result;
    return result;
}
