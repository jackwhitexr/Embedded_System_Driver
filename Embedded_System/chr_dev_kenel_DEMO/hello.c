#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/fs.h>

#define TEST_MAJOR      233    		//定义主设备号
static char drv_name[] = "test";       //定义主设备名   

//自己实现的打开函数
static int test_chardev_open(struct inode *inode,struct file *file) 
{
    printk("open major=%d, minor=%d\n", imajor(inode), iminor(inode));
	return 0;
}

//自己实现的释放函数
static int test_chardev_release(struct inode *inode,struct file *file )
{
   printk("close major=%d, minor=%d\n", imajor(inode), iminor(inode));
	return 0;
}

//标记化结构体初始化
static struct file_operations chardev_fops={
	.owner = THIS_MODULE,
	.open = test_chardev_open,
	.release = test_chardev_release,
};

//初始化注册设备
static int  __init  test_init(void)
{
        printk("Hello Mr.Bubbles\n");
	 if(register_chrdev(TEST_MAJOR,drv_name,&chardev_fops))
	 {
		printk("fail to register device \n");
		return -1;
	 }
        return 0;
}

//注销设备
static void  __exit  test_exit(void)
{
        printk("Goodbye，Mr.Bubbles!\n");
        unregister_chrdev(TEST_MAJOR,drv_name);
        
}

//进行关联
module_init(test_init);
module_exit(test_exit);

//声明许可证
MODULE_LICENSE("GPL");  


