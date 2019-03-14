
#include "linux/kernel.h"
#include "linux/module.h"
#include "linux/fs.h"
#include "linux/init.h" // dd init and exit
#include "linux/types.h"
#include "linux/errno.h"
#include "linux/uaccess.h"
#include <linux/kdev_t.h>

#include <linux/types.h>

const char * devName="cycDevDriver";

int devNum;

char buf[1024] = "---cyc---";

int myOpen(struct inode *inode, struct file* file);
int myRelease(struct inode*inode, struct file* file);
ssize_t myRead(struct file *file, char __user* user,size_t t, loff_t*f);
ssize_t myWrite(struct file *file, const char __user* user,size_t t, loff_t*f);

struct file_operations structfileOperations={
    owner:THIS_MODULE,
    open: myOpen,
    release:myRelease,
    read: myRead,
    write:myWrite,
};

int init_module(){
    int ret=register_chrdev(0,devName,&structfileOperations);
    if(ret<0){
       printk("regist fail");
	return -1;
    }
	printk("myDevDrive has been registered!\n");
        devNum = ret;
        // debug information
        printk("myDevDrive's id: %d\n",ret);
        printk("usage: mknod /dev/myDevDrive c %d 0\n",devNum);
        printk("delete device\n\t usage: rm /dev/%s ",devName);
        printk("delete module\n\t usage: rmmode device ");
        return 0;
}

void unregister_module(void)
{
    unregister_chrdev(devNum,devName);
    printk("unregister success !\n");
}

int myOpen(struct inode * inode,struct file * file){
    printk("open myDrive OK ! \n");
    try_module_get(THIS_MODULE);
    return 0;
}

int myRelease(struct inode*inode,struct file*file){
    printk("Device  release !\n");
    module_put(THIS_MODULE);
    return 0;
}

ssize_t myRead(struct file *file, char __user *user, size_t t, loff_t *f){
  if (copy_to_user(user ,buf,sizeof(buf)))
    {
        return -2;
    }
    return sizeof(buf);
}

ssize_t myWrite(struct file *file, const char __user *user, size_t t, loff_t *f)
{
    if(copy_from_user(buf,user,sizeof(buf)))
    {
        return -3;
    }
    return sizeof(buf);
}

