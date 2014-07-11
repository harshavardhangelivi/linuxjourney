#include <linux/module.h>
#include <linux/init.h>
#include<linux/kernel.h>
#include<linux/slab.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include<linux/errno.h>
#include<linux/cdev.h>
#include<linux/string.h>
#include<linux/buffer_head.h>
#include "decls.h"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A Simple File System");
MODULE_AUTHOR("Gelivi Harsha Vardhan");

#include "prototypes.h"
struct file_system_type tfs_type={
	.owner = THIS_MODULE,
	.name = "tagfs",
	.mount = tagfs_mount,
	.kill_sb = tagfs_kill_sb,
};
struct inode_operations tfs_iops = {
	.lookup = tfs_iops_lookup,
};
struct file_operations tfs_fops = {
	.owner = THIS_MODULE,
	.iterate = tfs_fops_iterate,
};
#include "fstype_fun.h"
#include "fops.h"
#include "iops.h"

static int tagfs_init(void){
	int ret;
	ret = register_filesystem(&tfs_type);
	if(unlikely(ret<0)){
		printk(KERN_INFO"Error registering the filesystem %s. Error- %d\n", tfs_type.name, ret);
	}else{	
		printk(KERN_INFO "filesystem %s registered successfully\n", tfs_type.name);
	}
	return 0;
}

static void tagfs_exit(void){
	int ret;
	ret = unregister_filesystem(&tfs_type);
	if(unlikely(ret<0)){
		printk(KERN_INFO"Error unregistering the filesystem %s. Error- %d\n", tfs_type.name, ret);
	}else{	
		printk(KERN_INFO "filesystem %s unregistered successfully\n", tfs_type.name);
	}
}
module_init(tagfs_init);
module_exit(tagfs_exit);