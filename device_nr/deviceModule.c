/**
 * @description - so an inode is a Data structure that basically contains metadata about the files. It is short for index node. Required to keep track of the files. Each file gets a unique inode num. Among many other things, the inode also stores the physical address of the file on the disk.
 */

#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>

#define BLOCK_NUM 90

static int driver_open(struct inode *device_file, struct file *instance){
	printk("dev_nr - open called\n");
	return 0;
}

static int driver_close(struct inode *device_file, struct file *instance){
	printk("dev_nr - close called\n");
	return 0;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close
};

/**
 * @brief This function gets called when the module is loaded into the kernel
 */

static int __init ModuleInit(void){
	int retval;
	printk("Hello, Linux Kernel!\n");
	/* register the device number */
	retval = register_chrdev(BLOCK_NUM, "my_dev_nr_driver", &fops);
	if(retval == 0){
		printk("Registered dev_nr at Major - %d, Minor - %d\n", BLOCK_NUM,0);
	}
	else if(retval > 0){
		printk("Registered dev_nr at Major - %d, Minor - %d/n", retval>>20, retval&0xfffff);
	}
	// some error 
	else{
		printk("ERROR Could not register device number - return value %d",retval);
		return -1;
	}
	return 0;
}

static void __exit ModuleExit(void){
	unregister_chrdev(BLOCK_NUM, "my_dev_nr_driver");
	printk("Goodbye, World!\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kailash Subramanian");
