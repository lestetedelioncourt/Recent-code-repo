==> LinuxCharacterDeviceDrivers/sec1/0_majorminor/majorminor.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>

MODULE_LICENSE("GPL");
static int test_device_init(void)
{
	dev_t devicenumber = 10;

	printk(KERN_INFO"Device Number :%u\n", devicenumber);
	printk(KERN_INFO"Major Number :%d\n", MAJOR(devicenumber));
	printk(KERN_INFO"Minor Number :%d\n", MINOR(devicenumber));

	devicenumber = MKDEV(120,30);
	printk(KERN_INFO"Device Number :%u\n", devicenumber);
	printk(KERN_INFO"Major Number :%d\n", MAJOR(devicenumber));
	printk(KERN_INFO"Minor Number :%d\n", MINOR(devicenumber));
	return 0;
}

static void test_device_exit(void)
{
}

module_init(test_device_init);
module_exit(test_device_exit);

==> LinuxCharacterDeviceDrivers/sec1/1_register_dev/registerdev.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

int major_number = 120;
int minor_number = 0;
int count = 1;
dev_t devicenumber;
char* device_name = "mychardev";

module_param(major_number, int, 0);
module_param(minor_number, int, 0);
module_param(count, int, 0);
module_param(device_name, charp, 0);

MODULE_LICENSE("GPL");
static int test_device_init(void)
{
	devicenumber = MKDEV(major_number, minor_number);
	printk(KERN_INFO"Device Number :%u\n", devicenumber);
	printk(KERN_INFO"Major Number :%d\n", MAJOR(devicenumber));
	printk(KERN_INFO"Minor Number :%d\n", MINOR(devicenumber));
	printk(KERN_INFO"Count :%d\n", count);

	if (!register_chrdev_region(devicenumber, count, device_name))
		printk(KERN_INFO"Device number registered\n");
	else
		printk(KERN_INFO"Device number registration failed\n");

	return 0;
}

static void test_device_exit(void)
{
	unregister_chrdev_region(devicenumber, count);
		printk(KERN_INFO"Device number unregistered\n");
}

module_init(test_device_init);
module_exit(test_device_exit);

==> LinuxCharacterDeviceDrivers/sec1/2_dynamic_registration/dynamicregistration.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

int minor_number = 0;
int count = 1;
dev_t devicenumber;
char* device_name = "mychardev";

module_param(minor_number, int, 0);
module_param(count, int, 0);
module_param(device_name, charp, 0);

MODULE_LICENSE("GPL");
static int test_device_init(void)
{
	printk(KERN_INFO"Count :%d\n", count);
	printk(KERN_INFO"Minor Number :%d\n", minor_number);
	printk(KERN_INFO"Device Name :%s\n", device_name);

	if (!alloc_chrdev_region(&devicenumber, minor_number, count, device_name))
	{
		printk(KERN_INFO"Device number registered\n");
		printk(KERN_INFO"Major Number :%d\n", MAJOR(devicenumber));
	}
	else
		printk(KERN_INFO"Device number registration failed\n");

	return 0;
}

static void test_device_exit(void)
{
	unregister_chrdev_region(devicenumber, count);
	printk(KERN_INFO"Device number unregistered\n");
}

module_init(test_device_init);
module_exit(test_device_exit);

==> LinuxCharacterDeviceDrivers/sec1/3_class_create/class_create.c <==
       > #include <linux/kernel.h>
       > #include <linux/module.h>
       > #include <linux/delay.h>
       > #include <linux/device.h>
       > 
       > MODULE_LICENSE("GPL");
       > static struct class *class;
       > 
       > static int test_device_init(void)
       > {
       > 	class = class_create(THIS_MODULE, "myclass");
       > 	return 0;
       > }
       > 
       > static void test_device_exit(void)
       > {
       > 	class_destroy(class);
       > }
       > 
       > module_init(test_device_init);
       > module_exit(test_device_exit);

==> LinuxCharacterDeviceDrivers/sec1/4_device_create/device_create.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/cdev.h>

MODULE_LICENSE("GPL");
static struct class *class;
static struct device *device1, *device2;
dev_t dev1, dev2;

static int test_device_init(void)
{
	dev1 = MKDEV(250, 1);
	dev2 = MKDEV(250, 2);
	class = class_create(THIS_MODULE, "myclass");
	device1 = device_create(class, NULL, dev1, NULL, "mydevice%d", 1);
	device2 = device_create(class, NULL, dev2, NULL, "mydevice%d", 2);
	return 0;
}

static void test_device_exit(void)
{
	device_destroy(class, dev1);
	device_destroy(class, dev2);
	class_destroy(class);
}

module_init(test_device_init);
module_exit(test_device_exit);

==> LinuxCharacterDeviceDrivers/sec1/5_automatic_device_creation/auto_alloc_device_create.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
static struct class *class;
static struct device *device;
dev_t dev1;
int minor = 0;
int count = 1;
const char* name = "newdevice";

static int test_device_init(void)
{
	class = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&dev1, minor, count, name)) {
		printk("Device number registered\n");
		printk("Major number received%d\n", MAJOR(dev1));
		device = device_create(class, NULL, dev1, NULL, "newdevice");
	}
	else
		printk("Device number registration failed\n");
	return 0;
}

static void test_device_exit(void)
{
 	unregister_chrdev_region(dev1, count);
	device_destroy(class, dev1);
	class_destroy(class);
}

module_init(test_device_init);
module_exit(test_device_exit);

==> LinuxCharacterDeviceDrivers/sec1/5_automatic_device_creation/auto_alloc_device_create.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0xf595d267, "device_destroy" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xd9da0486, "device_create" },
	{ 0xc5850110, "printk" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F081FA6923B189CFB30771B");

==> LinuxCharacterDeviceDrivers/sec2/00_struct_cdev/cdev.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>

int base_minor = 0;
char *device_name = "newchardev";
int count = 1;
dev_t devicenumber;

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode *inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file* file, char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
	return count;
}

static ssize_t device_write(struct file* file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
	return count;
}

struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_device_init(void)
{
	myclass = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		pr_info("Device number registered\n");
		pr_info("Major number received:%d\n", MAJOR(devicenumber));

		mydevice = device_create(myclass, NULL, devicenumber, NULL, "mydevice");
		mycdev = cdev_alloc();
		if (mycdev) 
		{
			mycdev->ops = &device_fops;
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else 
	{
		pr_info("Device registration failed\n");
	}
	return 0;
}


static void test_device_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_device_init);
module_exit(test_device_exit);

==> LinuxCharacterDeviceDrivers/sec2/00_struct_cdev/cdev.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xfe5cf5ad, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0xf595d267, "device_destroy" },
	{ 0xc0fdf3d5, "cdev_add" },
	{ 0x82046fe4, "cdev_alloc" },
	{ 0xd9da0486, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A3CD4D12737161B6D7A34F1");

==> LinuxCharacterDeviceDrivers/sec2/00_struct_cdev/hello.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>

int base_minor = 0;
char *device_name = "mychardev";
int count = 1;
dev_t devicenumber;

static struct class *class = NULL;
static struct device *device = NULL;
static struct cdev *mycdev = NULL;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
        return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
        return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
        return count;
}

struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};


static int test_hello_init(void)
{
	class = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		printk("Device number registered\n");
		printk("Major number received:%d\n", MAJOR(devicenumber));

		device = device_create(class, NULL, devicenumber, NULL, "mydevice");
		mycdev = cdev_alloc();
		if (mycdev) {
			mycdev->ops = &device_fops;
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}

	}
	else
		printk("Device number registration Failed\n");

	return 0;
}

static void test_hello_exit(void)
{
	device_destroy(class, devicenumber);
    class_destroy(class);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxCharacterDeviceDrivers/sec2/01_fops/userapp1.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE		"/dev/mydevice"

int main()
{
	int fd;
	int retval;
	char buffer[10];
	pid_t pid;

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0){
		perror("Open failed");
		exit(1);
	}

	getchar();
	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/01_fops/userapp2.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE		"/dev/mydevice"

int main()
{
	int fd;
	int retval;
	char buffer[10];
	pid_t pid;

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0){
		perror("Open failed");
		exit(1);
	}

	getchar();
	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/02_fops/userapp1.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE		"/dev/mydevice"

int main()
{
	int fd;
	int retval;
	char buffer[10];
	pid_t pid;

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0){
		perror("Open failed");
		exit(1);
	}

	getchar();
	pid = fork();
	if (pid == 0) {
		printf("Child Process Executing and writing hello world:%ld\n", write(fd, "hello world", sizeof("hello world")));
	}
	else {
		printf("Parent process executing and writing hello embedded:%ld\n", write(fd, "hello embedded", sizeof("hello embedded")));
	}

	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/03_fops/struct_file.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>

int base_minor = 0;
char *device_name = "mynewdevice";
int count = 1;
dev_t devicenumber;

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev mycdev;

MODULE_LICENSE("GPL");

static int device_open(struct inode* inode, struct file* file)
{
	pr_info("%s\n", __func__);

	if ((file->f_flags & O_ACCMODE) == O_RDONLY) {
		pr_info("opened File in Read only mode\n");
	} else if ((file->f_flags & O_ACCMODE) == O_WRONLY) {
		pr_info("opened File in Write only mode\n");
	}  else if ((file->f_flags & O_ACCMODE) == O_RDWR) {
		pr_info("opened File in Read/Write mode\n");
	} 

	if (file->f_flags & O_CREAT) {
		pr_info("Create if it does not exist\n");
	}
	if (file->f_flags & O_EXCL) {
		pr_info("Provide exclusive access\n");
	}
	if (file->f_flags & O_TRUNC) {
		pr_info("Truncat the file to zero size first\n");
	}
	if (file->f_flags & O_APPEND) {
		pr_info("Append to the file (don't overwrite)\n");
	}
	if (file->f_flags & O_NONBLOCK) {
		pr_info("Access methods are non-blocking\n");
	}
	if (file->f_flags & O_SYNC) {
		pr_info("O_SYNC\n");
	}

	pr_info("File Offset:%llu\n", file->f_pos);
	return 0;
}

static int device_release(struct inode *inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_write(struct file* file, const char __user *user_buffer, size_t count, loff_t* offset)
{
	pr_info("%s\n", __func__);
	return count;
}

static ssize_t device_read(struct file* file, char __user *user_buffer, size_t count, loff_t* offset)
{
	pr_info("%s\n", __func__);
	return count;
}

struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_device_init(void)
{
	myclass = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) { 
		pr_info("Device number registered\n");
		pr_info("Major number received%d\n", MAJOR(devicenumber));

		mydevice = device_create(myclass, NULL, devicenumber, NULL, "newdevice");
		cdev_init(&mycdev, &device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev, devicenumber, count);
	}
	else
		pr_info("Device number registration failed\n");

	return 0;
}

static void test_device_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(&mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_device_init);
module_exit(test_device_exit);


==> LinuxCharacterDeviceDrivers/sec2/03_fops/struct_file.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xfe5cf5ad, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0xf595d267, "device_destroy" },
	{ 0xc0fdf3d5, "cdev_add" },
	{ 0xf4161c9f, "cdev_init" },
	{ 0xd9da0486, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "177C0563458F9BB7286F298");

==> LinuxCharacterDeviceDrivers/sec2/03_fops/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE		"/dev/newdevice"

int main()
{
	int fd;
	int retval;
	char buffer[10];

	printf("Opening file:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);
	if (fd < 0) {
		perror("Open failed");
		exit(1);
	}

	close(fd);
	getchar();
	fd = open(DEVICE_FILE, O_RDONLY);
	if (fd < 0) {
		perror("Open failed");
		exit(1);
	}

	close(fd);
	getchar();
	fd = open(DEVICE_FILE, O_WRONLY);
	if (fd < 0) {
		perror("Open failed");
		exit(1);
	}

	close(fd);
	getchar();
	fd = open(DEVICE_FILE, O_WRONLY | O_NONBLOCK);
	if (fd < 0) {
		perror("Open failed");
		exit(1);
	}

	close(fd);
	getchar();
	fd = open(DEVICE_FILE, O_WRONLY | O_NONBLOCK | O_APPEND);
	if (fd < 0) {
		perror("Open failed");
		exit(1);
	}

	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/04_fops/comp.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>


int base_minor = 0;
char *device_name = "mychardev";
int count = 1;
dev_t devicenumber;

static struct class *class = NULL;
static struct device *device = NULL;
static struct cdev mycdev;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);

	//struct file
	if ((file->f_flags & O_ACCMODE) == O_RDONLY) {
		pr_info("Opened File in Read only mode\n");
	}else if ((file->f_flags & O_ACCMODE) == O_WRONLY) {
		pr_info("Opened File in Write only mode");
	}
	else if ((file->f_flags & O_ACCMODE) == O_RDWR) {
		pr_info("Opened File in Read/Write mode");
	}

	if (file->f_flags & O_CREAT) {
		pr_info( "Create if it does not exist");
	}

	if (file->f_flags & O_EXCL) {
		pr_info( "Provide exclusive access");
	}

	if (file->f_flags & O_TRUNC) {
		pr_info( "Truncate the file to zero size first");
	}

	if (file->f_flags & O_APPEND) {
		pr_info( "Append to the file (don't overwrite)");
	}

	if (file->f_flags & O_NONBLOCK) {
		pr_info( "Access methods are non-blocking");
	}
	if (file->f_flags & O_SYNC) {
		pr_info( "O_SYNC");
	}

	pr_info("File Offset:%llu\n", file->f_pos);

	//struct inode
	pr_info("Mode: %ho\n", inode->i_mode);
	pr_info("User Id: %d\n", inode->i_uid.val);
	pr_info("Group Id: %d\n", inode->i_gid.val);
	pr_info("Inode number:%lu\n", inode->i_ino);
	pr_info("Major number:%d\t Minor Number:%d\n", imajor(inode), iminor(inode));
	pr_info("Major number:%d\t Minor Number:%d\n", MAJOR(inode->i_rdev), MINOR(inode->i_rdev));

	//Accessing struct inode from struct file
	pr_info("Inode number through file structure:%lu\n", file->f_inode->i_ino);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
	return count;
}



struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};


static int test_hello_init(void)
{
	class = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		printk("Device number registered\n");
		printk("Major number received:%d\n", MAJOR(devicenumber));

		device = device_create(class, NULL, devicenumber, NULL, "mydevice");
		cdev_init(&mycdev, &device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev, devicenumber, count);

	}
	else
		printk("Device number registration Failed\n");

	return 0;
}

static void test_hello_exit(void)
{
	device_destroy(class, devicenumber);
	class_destroy(class);
	cdev_del(&mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxCharacterDeviceDrivers/sec2/04_fops/struct_inode.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>

int base_minor = 0;
int count = 1;
char* device_name = "mynewdev";
dev_t devicenumber;

static struct class* myclass = NULL;
static struct device* mydevice = NULL;
static struct cdev* mycdev;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file* file)
{
	pr_info("%s\n", __func__);

	// struct file
	if ((file->f_flags & O_ACCMODE) == O_RDONLY) {
		pr_info("Opened File in Read only mode\n");
	} else if ((file->f_flags & O_ACCMODE) == O_WRONLY) {
		pr_info("Opened File in Write only mode\n");
	} else if ((file->f_flags & O_ACCMODE) == O_RDWR) {
		pr_info("Opened File in ReadWrite mode\n");
	}

	if (file->f_flags & O_CREAT) {
		pr_info("Create if it does not exist\n");
	}

	if (file->f_flags & O_EXCL) {
		pr_info("Provide exclusive access\n");
	}

	if (file->f_flags & O_TRUNC) {
		pr_info("Truncate the file to zero size first\n");
	}

	if (file->f_flags & O_APPEND) {
		pr_info("Append to the file (don't overwrite)\n");
	}

	if (file->f_flags & O_NONBLOCK) {
		pr_info("Access methods are non-blocking\n");
	}

	if (file->f_flags & O_SYNC) {
		pr_info("O_SYNC\n");
	}

	pr_info("File Offset:%llu\n", file->f_pos);

	//struct inode
	pr_info("Mode: %ho\n", inode->i_mode);
	pr_info("User Id: %d\n", inode->i_uid.val);
	pr_info("Group Id: %d\n", inode->i_gid.val);
	pr_info("Inode number:%lu\n", inode->i_ino);
	pr_info("Major number:%d\tMinor number:%d\n", imajor(inode), iminor(inode));
	pr_info("Major number:%d\tMinor number:%d\n", MAJOR(inode->i_rdev), MINOR(inode->i_rdev));

	pr_info("Inode number through file structure:%lu\n", file->f_inode->i_ino);
	return 0;
}

static int device_release(struct inode *inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file* file, char __user *user_buffer, size_t count, loff_t* offset)
{
	pr_info("%s\n", __func__);
	return count;
}

static ssize_t device_write(struct file* file, const char __user *user_buffer, size_t count, loff_t* offset)
{
	pr_info("%s\n", __func__);
	return count;
}

struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_device_init(void)
{
	myclass = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		pr_info("Device number registered\n");
		pr_info("Major number received:%d\n", MAJOR(devicenumber));
		
		mydevice = device_create(myclass, NULL, devicenumber, NULL, "mynewdev");
		mycdev = cdev_alloc();
		if (mycdev) 
		{
			cdev_init(mycdev, &device_fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_info("Device number registration failed\n");
		
	return 0;
}

static void test_device_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_device_init);
module_exit(test_device_exit);

==> LinuxCharacterDeviceDrivers/sec2/04_fops/struct_inode.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B52AF4BF1227827BF32254C");

==> LinuxCharacterDeviceDrivers/sec2/04_fops/userapp1.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE 	"/dev/mynewdev"

int main()
{
	int fd;
	int retval;
	char buffer[10];

	printf("Opening File:%s\n", DEVICE_FILE); 
	fd = open(DEVICE_FILE, O_RDWR);
	
	if (fd < 0) {
		perror("Open failed\n");
		exit(1);
	}

	getchar();

	retval = write(fd, "hello", 5);
	printf("Write retval:%d\n", retval);
	getchar();

	retval = read(fd, buffer, 10);
	printf("Read retval:%d\n", retval);
	getchar();

	printf("Closing file\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/05_fops/structfile_structinode.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>

int base_minor = 0;
int count = 1;
char *device_name = "mychardev";
dev_t devicenumber;

static struct device* mydevice = NULL;
static struct class* myclass = NULL;
static struct cdev* mycdev;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s File:%p inode:%p\n", __func__, file, inode);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_write(struct file* file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file* file, char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
	return 0;
}

struct file_operations fops = {
	.open = device_open,
	.read = device_read,
	.write = device_write,
	.release = device_release
};

static int test_device_init(void)
{
	myclass = class_create(THIS_MODULE, "myclass");

 	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		pr_info("Device number registered\n");
		pr_info("Major number received%d\n", MAJOR(devicenumber));
		
		mydevice = device_create(myclass, NULL, devicenumber, NULL, "newdev");
	    mycdev = cdev_alloc();
		if (mycdev) {
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_info("Device number registration failed\n");

	return 0;
}

static void test_device_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_device_init);
module_exit(test_device_exit);

==> LinuxCharacterDeviceDrivers/sec2/05_fops/structfile_structinode.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5BC6E379C2399D3FD8D078F");

==> LinuxCharacterDeviceDrivers/sec2/05_fops/userapp1.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/newdev"

int main()
{
	int fd;
	int retval;
	char buffer[10];

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open failed");
		exit(1);
	}

	getchar();

	retval = write(fd, "hello", 5);
	printf("Write retval:%d\n", retval);
	getchar();

	retval = read(fd, buffer, 10);
	printf("Write retval:%d\n", retval);
	getchar();

	printf("Closing file\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/06_fops/printuserbuffer.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>

int base_minor = 0;
int count = 1;
char* device_name = "mychardev";
dev_t devicenumber;

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev mycdev;

MODULE_LICENSE("GPL");

static int device_open(struct inode* inode, struct file* file) 
{
	pr_info("%s File:%p Inode:%p\n", __func__, file, inode);
	return 0;
}

static int device_release(struct inode* inode, struct file* file) 
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file* file, char __user *user_buffer, size_t count, loff_t* offset) 
{
	pr_info("%s:Count:%lu\toffset:%llu\n", __func__, count, *offset);
	return count;
}

static ssize_t device_write(struct file* file, const char __user *user_buffer, size_t count, loff_t* offset) 
{
	pr_info("%s:User buffer:%s\t Count:%lu\toffset:%llu\n", __func__, user_buffer, count, *offset);
	return count;
}

struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_dev_init(void)
{
	myclass = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered\n");
		pr_info("Major number received:%d\n", MAJOR(devicenumber));

		mydevice = device_create(myclass, NULL, devicenumber, NULL, "mychardev");
		cdev_init(&mycdev, &device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev, devicenumber, count);
	}
	else
		pr_info("Device number registration failed\n");
	return 0;
}

static void test_dev_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(&mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_dev_init);
module_exit(test_dev_exit);

==> LinuxCharacterDeviceDrivers/sec2/06_fops/printuserbuffer.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "FC9FDFDB487467F74861FB4");

==> LinuxCharacterDeviceDrivers/sec2/06_fops/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/mychardev"

int main()
{
	int fd;
	int retval;
	char buffer[10];

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open Failed");
		exit(1);
	}

	getchar();

	retval = write(fd, "hello", 5);
	printf("Write retval:%d\n", retval);
	getchar();

	retval = read(fd, buffer, 10);
	printf("Read retval:%d\n", retval);
	getchar();

	printf("Closing file\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/07_copy_from_user/comp.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>


int base_minor = 0;
char *device_name = "mychardev";
int count = 1;
dev_t devicenumber;

static struct class *class = NULL;
static struct device *device = NULL;
static struct cdev mycdev;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
        return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer,
                      size_t count, loff_t *offset)
{
	pr_info("%s:Count:%lu \t offset:%llu\n", __func__,
			count, *offset);
        return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer,
                       size_t count, loff_t *offset)
{
	char kernel_buffer[100] = {0};
	int retval;

	pr_info("%s: Kernel Buffer:%p\t User Buffer:%p\n", __func__, kernel_buffer, user_buffer);
	retval = copy_from_user(kernel_buffer, user_buffer, count);
	pr_info("%s: Copy from user returned:%d\n", __func__, retval);
	pr_info("%s:Kernel Buffer:%s\t Count:%lu \t offset:%llu\n", __func__, kernel_buffer, count, *offset);
        return count;
}

struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};


static int test_hello_init(void)
{
	class = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		printk("Device number registered\n");
		printk("Major number received:%d\n", MAJOR(devicenumber));

		device = device_create(class, NULL, devicenumber, NULL, "mydevice");
		cdev_init(&mycdev, &device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev, devicenumber, count);

	}
	else
		printk("Device number registration Failed\n");

	return 0;
}

static void test_hello_exit(void)
{
	device_destroy(class, devicenumber);
        class_destroy(class);
	cdev_del(&mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxCharacterDeviceDrivers/sec2/07_copy_from_user/copy_from_user.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

int base_minor = 0;
int count = 1;
char *device_name = "newestdev";
dev_t devicenumber;

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev mycdev;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s:Count:%lu\toffset:%llu\n", __func__, count, *offset);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	char kernel_buffer[100] = {0};
	int retval;

	pr_info("%s: Kernel Buffer:%p\tUser Buffer:%p\n", __func__, kernel_buffer, user_buffer);
	retval = copy_from_user(kernel_buffer, user_buffer, count);
	pr_info("%s: copy from user has returned:%d\n", __func__, retval);
	pr_info("%s:Kernel Buffer:%s\tCount:%lu\toffset:%llu\n\n", __func__, kernel_buffer, count, *offset);
	return count;
}

struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_dev_init(void)
{
	myclass = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		pr_info("Device number registered\n");
		pr_info("Major number received:%d\n", MAJOR(devicenumber));
	
		mydevice = device_create(myclass, NULL, devicenumber, NULL, "newestdev");
		cdev_init(&mycdev, &device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev, devicenumber, count);
	}
	else
		pr_info("Device number registration Failed\n");

	return 0;
}

static void test_dev_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(&mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_dev_init);
module_exit(test_dev_exit);

==> LinuxCharacterDeviceDrivers/sec2/07_copy_from_user/copy_from_user.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "873D39417ED5BBDD934AD4A");

==> LinuxCharacterDeviceDrivers/sec2/07_copy_from_user/userapp1.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE  "/dev/newestdev"

int main()
{
	int fd;
	int retval;
	char buffer[10];
	char *ptr = NULL;

	printf("Opening File:%s\n", DEVICE_FILE);

	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open Failed");
		exit(1);
	}

	getchar();

	retval = write(fd, ptr, 5);
	printf("Write retval:%d\n", retval);
	getchar();

	retval = read(fd, buffer, 10);
	printf("Read retval:%d\n", retval);
	getchar();

	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/07_copy_from_user/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/newestdev"

int main()
{
	int fd;
	int retval;
	char buffer[10];

	printf("Opening File:%s\n", DEVICE_FILE);

	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open Failed");
		exit(1);
	}

	getchar();

	retval = write(fd, "hello", 5);
	printf("Write retval:%d\n", retval);
	getchar();

	retval = read(fd, buffer, 10);
	printf("Read retval:%d\n", retval);
	getchar();

	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/08_copy_to_user/copy_to_user.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

int base_minor = 0;
char* device_name = "mychardev";
int count =  1;
dev_t devicenumber;

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

MODULE_LICENSE("GPL");

static int device_open(struct inode* inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}


static int device_release(struct inode* inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file* file, char __user *user_buffer, size_t count, loff_t *offset)
{
	char kernel_buffer[10] = "kernel";

	int retval;

	retval = copy_to_user(user_buffer, kernel_buffer, 7);
	pr_info("%s Copy to user returned:%d\n", __func__, retval);

	pr_info("%s:Kernel buffer:5s \t Count:%lu \t offset:%llu\n", kernel_buffer, count, *offset);
	return 0;
}

static ssize_t device_write(struct file* file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	char kernel_buffer[100] = {0};

	int retval;

	retval = copy_from_user(kernel_buffer, user_buffer, count);
	pr_info("%s Copy from user returned:%d\n", __func__, retval);

	pr_info("%s:Kernel buffer:5s \t Count:%lu \t offset:%llu\n", kernel_buffer, count, *offset);
	return 0;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_dev_init(void)
{
	myclass = class_create(THIS_MODULE, "newclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		pr_info("Device number registered\n");
		pr_info("Major number received:%d\n", MAJOR(devicenumber));

		mydevice = device_create(myclass, NULL, devicenumber, NULL, "mychardevice");
		mycdev = cdev_alloc();
		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	} else
		pr_info("Device number registration failed\n");

	return 0;
}


static void test_dev_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_dev_init);
module_exit(test_dev_exit);

==> LinuxCharacterDeviceDrivers/sec2/08_copy_to_user/copy_to_user.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x56470118, "__warn_printk" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C048443A2A42F719410AC69");

==> LinuxCharacterDeviceDrivers/sec2/08_copy_to_user/userapp1.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/mychardevice"

int main()
{
	int fd;
	int retval;
	char *buffer = NULL;

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open failed");
		exit(1);
	}

	getchar();

	retval = write(fd, "hello", 5);
	printf("Write retval:%d\n", retval);
	getchar();

	retval = read(fd, buffer, 10);
	printf("Read retval:%d\n", retval);
	getchar();

	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/08_copy_to_user/userapp2.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/mychardevice"

int main()
{
	int fd;
	int retval;
	char buffer[4];

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open failed");
		exit(1);
	}

	getchar();

	retval = write(fd, "hello", 5);
	printf("Write retval:%d\n", retval);
	getchar();

	retval = read(fd, buffer, 10);
	printf("Read retval:%d\n", retval);
	getchar();

	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/08_copy_to_user/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/mychardevice"

int main()
{
	int fd;
	int retval;
	char buffer[10];

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open failed");
		exit(1);
	}

	getchar();

	retval = write(fd, "hello", 5);
	printf("Write retval:%d\n", retval);
	getchar();

	retval = read(fd, buffer, 10);
	printf("Read retval:%d\n", retval);
	getchar();

	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/09_put_user/comp.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>


int base_minor = 0;
char *device_name = "jiffies";
int count = 1;
dev_t devicenumber;

static struct class *class = NULL;
static struct device *device = NULL;
static struct cdev mycdev;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
        return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer,
                      size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
	if (count < sizeof(jiffies))
                return -EINVAL;
        if (!put_user(jiffies, (u64 *)user_buffer))
            return sizeof(jiffies);
        else
            return -EFAULT;

        return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer,
                       size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
        return count;
}



struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};


static int test_hello_init(void)
{
	class = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		printk("Device number registered\n");
		printk("Major number received:%d\n", MAJOR(devicenumber));

		device = device_create(class, NULL, devicenumber, NULL, device_name);
		cdev_init(&mycdev, &device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev, devicenumber, count);

	}
	else
		printk("Device number registration Failed\n");

	return 0;
}

static void test_hello_exit(void)
{
	device_destroy(class, devicenumber);
        class_destroy(class);
	cdev_del(&mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxCharacterDeviceDrivers/sec2/09_put_user/put_user.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

int base_minor = 0;
char* device_name = "jiffies";
int count = 1;
dev_t devicenumber;

static struct class* myclass = NULL;
static struct device* mydevice = NULL;
static struct cdev* mycdev = NULL;

MODULE_LICENSE("GPL");

static int device_open(struct inode* inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode* inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file* file, char* __user user_buffer, size_t count, loff_t* offset)
{
	pr_info("%s\n", __func__);
	if (count < sizeof(jiffies))
		return -EINVAL;
	if (!put_user(jiffies, (u64*)user_buffer))
		return sizeof(jiffies);
	else
		return -EFAULT;

	return 0;
}

static ssize_t device_write(struct file* file, const char* __user user_buffer, size_t count, loff_t* offset)
{
	pr_info("%s\n", __func__);
	return count;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int __init test_dev_init(void)
{
	myclass = class_create(THIS_MODULE, "thisclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		pr_info("Device number registered\n");
		pr_info("Major number receieved:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();
		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
		else
			pr_info("Device registration failed\n");
	}
		
	return 0;
}

static void test_dev_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_dev_init);
module_exit(test_dev_exit);

==> LinuxCharacterDeviceDrivers/sec2/09_put_user/put_user.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0xb8e7ce2c, "__put_user_8" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9381F31696F6BF901B28FC7");

==> LinuxCharacterDeviceDrivers/sec2/09_put_user/testapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fd;
	unsigned long long old_jiffies;
	unsigned long long new_jiffies;

	fd = open("/dev/jiffies", O_RDWR);
	if (fd < 0) {
		perror("fd failed");
		exit(2);
	}
	if (read(fd, &old_jiffies, sizeof(old_jiffies)) != sizeof(old_jiffies))
	{
		printf("Failed in reading first jiffies\n");
		exit(3);
	} 
	else
		printf("First read:%lld\n", old_jiffies);
	sleep(1);
	if (read(fd, &new_jiffies, sizeof(new_jiffies)) != sizeof(new_jiffies))
	{
		printf("Failed in reading second jiffies\n");
		exit(4);
	} 
	else
		printf("Second read:%lld\n", new_jiffies);
	printf("Difference:%lld\n", (new_jiffies - old_jiffies));
	close(fd);
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/10_get_user/get_user.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

int base_minor = 0;
char *device_name = "myint";
int count = 1;
dev_t devicenumber;

int value = 0;

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

MODULE_LICENSE("GPL");

static int device_open(struct inode* inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode* inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file* file, char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
	if (count < sizeof(value))
		return -EINVAL;
	if (!put_user(value, (int*)user_buffer))
		return sizeof(value);
	else
		return -EFAULT;
}

static ssize_t device_write(struct file* file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
	get_user(value, (int*)user_buffer);
	return count;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_dev_init(void)
{
	myclass = class_create(THIS_MODULE, "myint");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		pr_info("Device number registered\n");
		pr_info("Major number received:%d\n", MAJOR(devicenumber));

		mydevice = device_create(myclass, NULL, devicenumber, NULL, "myintdev");
		mycdev = cdev_alloc();
		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_info("Device number registration failed\n");

	return 0;
}

static void test_dev_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_dev_init);
module_exit(test_dev_exit);

==> LinuxCharacterDeviceDrivers/sec2/10_get_user/get_user.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6267342F8145E8B11D463C7");

==> LinuxCharacterDeviceDrivers/sec2/10_get_user/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/myintdev"

int main()
{
	int fd;
	int retval;
	int value = 10;

	printf("opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("open failed");
		exit(1);
	}

	getchar();

	retval = write(fd, &value, sizeof(value));
	printf("read retval:%d\n", retval);
	getchar();

	value = 2;

	retval = read(fd, &value, sizeof(value));
	printf("read retval:%d\t value:%d\n", retval, value);
	getchar();

	printf("Closing file\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/11_copy_user_struct/copy_user_struct.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "mystruct.h"

int base_minor = 0;
char *device_name = "mystruct";
int count = 1;
dev_t devicenumber;
abc kernel_struct;

static struct class *myclass = NULL;
static struct device *mycdevice = NULL;
static struct cdev *mycdev = NULL;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file* file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int retval;
	retval = copy_to_user(user_buffer, &kernel_struct, sizeof(kernel_struct));
	pr_info("%s: Copy to user returned:%d\n", __func__, retval);
	pr_info("%s: int:%d\tchar:%c\tCount:%lu\toffset:%llu\n\n", __func__, kernel_struct.i, kernel_struct.c, count, *offset);

	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int retval;
	retval = copy_from_user(&kernel_struct, user_buffer, count);
	pr_info("%s: Copy from user returned:%d\n", __func__, retval);
	pr_info("%s: int:%d\tchar:%c\tCount:%lu\toffset:%llu\n", __func__, kernel_struct.i, kernel_struct.c, count, *offset);
	return count;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_device_init(void)
{
	myclass = class_create(THIS_MODULE, "newstructclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		pr_info("Printing major number:%d\n", MAJOR(devicenumber));
		mycdevice = device_create(myclass, NULL, devicenumber, NULL, "newstructdev"); 
		mycdev = cdev_alloc();
		if (mycdev) {
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_info("Device number registration failed\n");

	return 0;
}

static void test_device_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_device_init);
module_exit(test_device_exit);

==> LinuxCharacterDeviceDrivers/sec2/11_copy_user_struct/copy_user_struct.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x56470118, "__warn_printk" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "4692378D8EF79CD8CD46E53");

==> LinuxCharacterDeviceDrivers/sec2/11_copy_user_struct/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "mystruct.h"

#define DEVICE_FILE "/dev/newstructdev"

int main()
{
	int fd;
	int retval;
	abc user_struct = {5, 'a'};

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open failed");
		exit(1);
	}

	getchar();

	retval = write(fd, &user_struct, sizeof(user_struct));
	printf("Write retval:%d\n", retval);
	getchar();

	user_struct.i = 4;
	user_struct.c = 'b';

	retval = read(fd, &user_struct, sizeof(user_struct));
	printf("Read retval:%d\tint:%d\tchar:%c\n", retval, user_struct.i, user_struct.c);
	getchar();

	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/12_copy_from_userheap/copy_from_heap.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "myheapdevice";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s:Count:%lu\toffset%llu\n", __func__, count, *offset);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	char kernel_buffer[100] = {0};
	int retval;

	pr_info("%s: Kernel Buffer:%p\tUser Buffer:%p\n", __func__, kernel_buffer, user_buffer);
	retval = copy_from_user(kernel_buffer, user_buffer, count);
	pr_info("%s: Copy from user returned:%d\n", __func__, retval);
	pr_info("%s: Kernel buffer:%s\tCount:%lu\tOffset%llu\n", __func__, kernel_buffer, count, *offset);
	return count;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_init(void)
{
	myclass = class_create(THIS_MODULE, "myheapclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		pr_info("Device number registered\n");
		pr_info("Major number received:%d\n", MAJOR(devicenumber));

		mydevice = device_create(myclass, NULL, devicenumber, NULL, "myheapdev");
		mycdev = cdev_alloc();
		if(mycdev) {
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
		else
			pr_info("Device number registration failed\n");

	}

	return 0;
}

static void test_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxCharacterDeviceDrivers/sec2/12_copy_from_userheap/copy_from_heap.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C6D54D98934359C6D2822DD");

==> LinuxCharacterDeviceDrivers/sec2/12_copy_from_userheap/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_FILE "/dev/myheapdev"

int main()
{
	int fd;
	int retval;
	char *buffer = malloc(sizeof(char)*10);

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open Failed");
		exit(1);
	}

	getchar();

	strcpy(buffer, "hello");

	retval = write(fd, buffer, strlen(buffer));
	printf("Write retval:%d\n", retval);
	getchar();

	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/13_heapstack_kernel_break/copy_heapstackstruct.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "heapstackstruct.h"

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char* device_name = "stackheapdev";
abc kernel_struct;

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

MODULE_LICENSE("GPL");

static int device_open(struct inode* inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}


static int device_release(struct inode* inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int retval;

	retval = copy_to_user(user_buffer, &kernel_struct, sizeof(kernel_struct));
	pr_info("%s: Copy to user returned:%d\n", __func__, retval);
	pr_info("%s:int:%d\tstr: %s\tcount:%lu\toffset:%llu\n", __func__, kernel_struct.i, kernel_struct.str, count, *offset);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int retval;

	retval = copy_from_user(&kernel_struct, user_buffer, count);
	pr_info("%s: Copy from user returned:%d\n", __func__, retval);
	pr_info("%s: int:%d\tstr%s\tCount:%lu\toffset:%llu\n", __func__, kernel_struct.i, kernel_struct.str, count, *offset);
	return count;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_kernel_init(void)
{
	myclass = class_create(THIS_MODULE, "stackheapclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		pr_info("Major number :%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, "stackheapdev");

		mycdev = cdev_alloc();
		if (mycdev) 
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_info("Failed to register device");
		
	return 0;
}

static void test_kernel_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_kernel_init);
module_exit(test_kernel_exit);

==> LinuxCharacterDeviceDrivers/sec2/13_heapstack_kernel_break/copy_heapstackstruct.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x56470118, "__warn_printk" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C6294F6BDA227BD7BBC19BD");

==> LinuxCharacterDeviceDrivers/sec2/13_heapstack_kernel_break/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "heapstackstruct.h"

#define DEVICE_FILE  "/dev/stackheapdev"

int main()
{
	int fd;
	int retval;
	abc user_struct;

	user_struct.str = malloc(sizeof(char)*10);
	strcpy(user_struct.str, "hello");
	user_struct.i = 10;

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open failed");
		exit(1);
	}

	getchar();

	retval = write(fd, &user_struct, sizeof(user_struct));
	printf("Write retval:%d\n", retval);
	getchar();

	printf("Closing file\n");
	close(fd);
	getchar();
	
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/14_print_dev_t/comp.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
	dev_t devicenumber;
	char buffer[20];

	devicenumber = MKDEV(120, 30);
	printk("Device Number :%s\n", format_dev_t(buffer, devicenumber));
	buffer[0] = '\0';
	printk("print_dev_t returned:%d\t Device Number:%s\n", print_dev_t(buffer, devicenumber), buffer);

	return -1;
}

static void test_hello_exit(void)
{
}

module_init(test_hello_init);
module_exit(test_hello_exit);

==> LinuxCharacterDeviceDrivers/sec2/14_print_dev_t/print_dev_t.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>

MODULE_LICENSE("GPL");

static int test_init(void)
{
	dev_t devicenumber;
	char buffer[20];

	devicenumber = MKDEV(120, 30);
	printk("Device Number :%s\n", format_dev_t(buffer, devicenumber));
	buffer[0] = '\0';
	printk("print_dev_t returned:%d\tdevice Number:%s\n", print_dev_t(buffer, devicenumber), buffer);

	return -1;
}

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxCharacterDeviceDrivers/sec2/14_print_dev_t/print_dev_t.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0xc5850110, "printk" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "55A99A66187865C0BE40F1B");

==> LinuxCharacterDeviceDrivers/sec2/15_strlen/strlen_kernel.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char* device_name = "mychardev";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

MODULE_LICENSE("GPL");

static int device_open(struct inode* inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode* inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file* file, char __user *user_buffer, size_t count, loff_t *offset)
{
	char kernel_buffer[10] = "kernel";
	int retval;

	retval = copy_to_user(user_buffer, kernel_buffer, 7);
	pr_info("%s: strlen:%lu\n", __func__, strlen(kernel_buffer));
	pr_info("%s: Copy to user returned:%d\n", __func__, retval);
	pr_info("%s: Kernel buffer:%s\tCount:%lu\toffset:%llu\n", __func__, kernel_buffer, count, *offset);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	char kernel_buffer[100] = {0};
	int retval;
	
	pr_info("%s: Kernel Buffer:%p\tUser Buffer:%p\n", __func__, kernel_buffer, user_buffer);
	pr_info("%s: strlen user Buffer:%lu\n", __func__, strlen(user_buffer));
	retval = copy_from_user(kernel_buffer, user_buffer, count);
	pr_info("%s: Copy from user returned:%d\n", __func__, retval);
	pr_info("%s: Kernel Buffer:%s\tUser Count:%lu\toffset:%llu\n", __func__, kernel_buffer, count, *offset);
	return count;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_dev_init(void)
{
	myclass = class_create(THIS_MODULE, "mydevclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		pr_info("Device major number:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, "mydev");
		mycdev = cdev_alloc();
		if (mycdev) {
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_info("Device number no registered\n");

	return 0;
}

static void test_dev_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_dev_init);
module_exit(test_dev_exit);

==> LinuxCharacterDeviceDrivers/sec2/15_strlen/strlen_kernel.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xa916b694, "strnlen" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BF7C99AD2092CAD5FBF2C16");

==> LinuxCharacterDeviceDrivers/sec2/15_strlen/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/mydev"

int main()
{
	int fd;
	int retval;
	char buffer[10];

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open failed");
		exit(1);
	}

	getchar();

	retval = read(fd, buffer, 10);
	printf("Read retval:%d\n", retval);
	getchar();

	retval = write(fd, buffer, 10);
	printf("Write retval:%d\n", retval);
	getchar();

	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/16_strnlen_user/strnlen_dev.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char* device_name = "strnlenuserdev";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t* offset)
{
	char kernel_buffer[100] = {0};
	int retval;

	pr_info("%s: Kernel Buffer:%p\tUser Buffer:%p\n", __func__, kernel_buffer, user_buffer);
	pr_info("%s: strlen kerne_buffer:%lu\n", __func__, strlen(kernel_buffer));
	retval = copy_from_user(kernel_buffer, user_buffer, count); 
	pr_info("%s: Copy from user returned:%d\n", __func__, retval);
	pr_info("%s:Kernel Buffer:%s\tCount:%lu\toffset:%llu\n", __func__, kernel_buffer, count, offset);
	
	return count;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t* offset)
{
	char kernel_buffer[10] = "kernel";
	int retval;

	retval = copy_to_user(user_buffer, kernel_buffer, 7); 
	pr_info("%s: Kernel Buffer:%p\tUser Buffer:%p\n", __func__, kernel_buffer, user_buffer);
	pr_info("%s strlen user_buffer:%lu\n", __func__, strnlen_user(user_buffer, 100));
	pr_info("%s: Copy to user returned:%d\n", __func__, retval);
	pr_info("%s:Kernel Buffer:%s\tCount:%lu\toffset:%llu\n", __func__, kernel_buffer, count, offset);
	return 0;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_strnlen_init(void)
{
	myclass = class_create(THIS_MODULE, "strnlenclass");

	if(!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		pr_info("Device number registered:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, "strlendev");
		mycdev = cdev_alloc();

		if (mycdev) {
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	return 0;
}

static void test_strnlen_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_strnlen_init);
module_exit(test_strnlen_exit);

==> LinuxCharacterDeviceDrivers/sec2/16_strnlen_user/strnlen_dev.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xa916b694, "strnlen" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0xd91f6ab6, "strnlen_user" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "09A757EEE28ECFEAB150B27");

==> LinuxCharacterDeviceDrivers/sec2/16_strnlen_user/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/strlendev"

int main() {
	int fd;
	int retval;
	char buffer[10];

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0){
		perror("Open failed");
		exit(1);
	}

	getchar();

	retval = read(fd, buffer, 10);
	printf("Read retval:%d\n", retval);
	getchar();

	retval = write(fd, buffer, 10);
	printf("Write retval:%d\n", retval);
	getchar();

	printf("Read retval\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/17_stackheapsolution/stackheapwrite.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "shstruct.h"

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char* device_name = "stackheapwritedev";
abc kernel_struct;
char kernel_buffer[100];

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int retval;
	int string_length = 0;
	
	retval = copy_from_user(&kernel_struct, user_buffer, count);
	pr_info("%s Copy from user returned:%d\n", __func__, retval);
	string_length = strnlen_user(kernel_struct.str, 100);
	retval = copy_from_user(&kernel_buffer, kernel_struct.str, string_length);
	pr_info("%s: Length:%d\n", __func__, string_length);
	pr_info("%s:int:%d\tstr:%s\tCount:%lu\toffset:%llu\n", __func__, kernel_struct.i, kernel_buffer, count, *offset);

	return count;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int retval;
	int string_length = 0;

	retval = copy_to_user(&((abc *)user_buffer)->i, &kernel_struct.i, sizeof(kernel_struct.i));
	pr_info("%s: Copy to user returned:%d\n", __func__, retval);

	retval = copy_to_user(((abc *)user_buffer)->str, kernel_buffer, strlen(kernel_buffer)+1);
	pr_info("%s: Copy to user returned:%d\n", __func__, retval);
	pr_info("%s:int:%d\tstr:%s\tCount:%lu\tOffset:%llu\n", __func__, kernel_struct.i, kernel_struct.str, count, *offset);

	return count;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_shdev_init(void) 
{
	myclass = class_create(THIS_MODULE, "myshclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		pr_info("Device Number registered:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, "myshdev");
		mycdev = cdev_alloc();

		if (mycdev) {
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_info("Device Number failed to register\n");

	return 0;
}

static void test_shdev_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_shdev_init);
module_exit(test_shdev_exit);


==> LinuxCharacterDeviceDrivers/sec2/17_stackheapsolution/stackheapwrite.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd91f6ab6, "strnlen_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xa916b694, "strnlen" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9E2487B7BCC436CC22659F4");

==> LinuxCharacterDeviceDrivers/sec2/17_stackheapsolution/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shstruct.h"

#define DEVICE_FILE "/dev/myshdev"

int main() 
{
	int fd;
	int retval;
	abc user_struct;

	user_struct.str = malloc(sizeof(char)*10);
	strcpy(user_struct.str, "hello");
	user_struct.i = 10;

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open failed");
		exit(1);
	}

	getchar();

	retval = write(fd, &user_struct, sizeof(user_struct));
	printf("Write retval:%d\n", retval);
	getchar();

	memset(&user_struct, 0, sizeof(user_struct));

	user_struct.str = malloc(sizeof(char)*10);
	retval = read(fd, &user_struct, sizeof(user_struct));
	printf("Read retval:%d\n", retval);
	printf("Int:%d\tStr:%s\n", user_struct.i, user_struct.str);
	getchar();

	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/18_read_ch_problem/read_ch_problem.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "mystruct.h"

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char* device_name = "newchardev";

struct class *myclass = NULL;
struct device *mydevice = NULL;
struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];

MODULE_LICENSE("GPL");

static int device_open(struct inode* inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode* inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int retval;

	retval = copy_from_user(kernel_buffer, user_buffer, count);
	pr_info("%s: Copy from user returned:%d\n", __func__, retval);
	pr_info("%s: kernel_buffer:%s\n", __func__, kernel_buffer);
	return count;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int retval;

	retval = copy_to_user(user_buffer, kernel_buffer, sizeof(kernel_buffer));
	pr_info("%s: Copy to user returned:%d\n", __func__, retval);
	return count;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_dev_init(void) {
	myclass = class_create(THIS_MODULE, "mynewclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered\n");
		pr_info("Major number: %d\n", MAJOR(devicenumber));

		mydevice = device_create(myclass, NULL, devicenumber, NULL, "newchardev");
		mycdev = cdev_alloc();
		if (mycdev) {
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}

	}
	else 
	{
		pr_info("Device number not registered\n");
	}
	
	return 0;
}

static void test_dev_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_dev_init);
module_exit(test_dev_exit);

==> LinuxCharacterDeviceDrivers/sec2/18_read_ch_problem/read_ch_problem.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x56470118, "__warn_printk" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D74F89F6ECA856433D37059");

==> LinuxCharacterDeviceDrivers/sec2/18_read_ch_problem/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "mystruct.h"

#define DEVICE_FILE "/dev/newchardev"

int main() 
{
	int fd;
	int retval;
	char buffer[10];
	int i;

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open Failed");
		exit(1);
	}

	getchar();

	retval = write(fd, "hello", 5);
	printf("Write retval:%d\n", retval);
	getchar();

	for (i = 0; i < 10; i++) {
		retval = read(fd, buffer + i, 1);
		printf("Read retval:%d", retval);
		printf("Read buffer:%c", buffer[i]);
		getchar();
	}

	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/19_offsetupdatesolution/comp.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

int base_minor = 0;
char *device_name = "msg";
int count = 1;
dev_t devicenumber;

static struct class *class = NULL;
static struct device *device = NULL;
static struct cdev mycdev;

#define MAX_SIZE        1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
        return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer,
                       size_t write_count, loff_t *offset)
{
	int retval;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	if (buffer_index + write_count > MAX_SIZE) {
		pr_err("%s: buffer_index:%d\t write_count:%lu\t Max Size:%d\n",__func__,
				buffer_index, write_count, MAX_SIZE);
		return -ENOSPC;
	}

	retval = copy_from_user(kernel_buffer+buffer_index, user_buffer, write_count);
	pr_info("%s: Copy from user returned:%d\n", __func__, retval);
	pr_info("%s: kernel_buffer:%s\n", __func__, kernel_buffer);

	buffer_index += write_count;
	//update file offset
	*offset += write_count;
        return write_count;
}

static ssize_t device_read(struct file *file, char __user *user_buffer,
                      size_t read_count, loff_t *offset)
{
	int retval;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	if (buffer_index + read_count > MAX_SIZE) {
		pr_err("%s: buffer_index:%d\t read_count:%lu\t Max Size:%d\n",__func__,
				buffer_index, read_count, MAX_SIZE);
		return -ENOSPC;
	}

	retval = copy_to_user(user_buffer, kernel_buffer+*offset, read_count);
	pr_info("%s: Copy to user returned:%d\n", __func__, retval);
	//update file offset
	*offset += read_count;

        return read_count;
}

struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_hello_init(void)
{
	class = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		printk("Device number registered\n");
		printk("Major number received:%d\n", MAJOR(devicenumber));

		device = device_create(class, NULL, devicenumber, NULL, device_name);
		cdev_init(&mycdev, &device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev, devicenumber, count);

	}
	else
		printk("Device number registration Failed\n");

	return 0;
}

static void test_hello_exit(void)
{
	device_destroy(class, devicenumber);
        class_destroy(class);
	cdev_del(&mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

==> LinuxCharacterDeviceDrivers/sec2/19_offsetupdatesolution/offset_update.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "msg";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t write_count, loff_t *offset)
{
	int retval;

	pr_info("%s: Copy_from_user retval:%lld", __func__, *offset);
	if (buffer_index + write_count > MAX_SIZE) {
		pr_err("%s: buffer_index:%d\twrite_count:%lu\tMax_size:%d\n", __func__, buffer_index, write_count, MAX_SIZE);
		return -ENOSPC;
	}
	retval = copy_from_user(kernel_buffer+buffer_index, user_buffer, write_count);
	pr_info("%s: Copy_from_user retval:%d\n", __func__, retval); 
	pr_info("%s: kernel_buffer:%s\n", __func__, kernel_buffer); 

	buffer_index += write_count;
	//update file offset
	*offset += write_count;
	return write_count;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t read_count, loff_t *offset)
{
	int retval;

	pr_info("%s read offset:%lld", __func__, *offset);
	if (buffer_index + read_count > MAX_SIZE) {
		pr_err("%s: bufer_index:%d\tread_count:%lu\tMax size:%d\n", __func__, buffer_index, read_count, MAX_SIZE);
		return -ENOSPC;
	}
	retval = copy_to_user(user_buffer, kernel_buffer+*offset, read_count);
	pr_info("%s: Copy_to_user retval:%d", __func__, retval);
	*offset += read_count;

	return read_count;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_new_init(void)
{
	myclass = class_create(THIS_MODULE, "newclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered\n");
		pr_info("Major number:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, "mynewdevice");
		mycdev = cdev_alloc();
		
		if (mycdev) {
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
	{
		pr_info("Device number registration failed\n");
	}

	return 0;
}

static void test_new_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_new_init);
module_exit(test_new_exit);

==> LinuxCharacterDeviceDrivers/sec2/19_offsetupdatesolution/offset_update.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1CD6BD8CB8D32DF3396C2B8");

==> LinuxCharacterDeviceDrivers/sec2/19_offsetupdatesolution/userapp1.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/mynewdevice"

int main() {
	int i;
	int fd;
	int retval;
	char buffer[10];

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);
	
	if (fd < 0) {
		perror("Open Failed");
		exit(1);
	}

	getchar();

	retval = write(fd, "hello", 5);
	printf("Write retval:%d\n", retval);
	getchar();

	retval = write(fd, "world", 5);
	printf("Write retval:%d\n", retval);
	getchar();

	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/19_offsetupdatesolution/userapp2.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/mynewdevice"

int main() {
	int fd;
	int retval;
	int i;
	char buffer[10];

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("Open Failed");
		exit(1);
	}

	getchar();

	for (i = 0; i < 250; i++) {
		retval = write(fd, "hello", 5);
		printf("Write retval:%d\n", retval);
		if (retval != 5) break;
	}

	printf("Closing File\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/19_offsetupdatesolution/userapp3.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/mynewdevice"

int main() {
	int i;
	int fd;
	int retval;
	char buffer[10];

	printf("Opening File:%s\n", DEVICE_FILE);
	fd = open(DEVICE_FILE, O_RDWR);

	if (fd < 0) {
		perror("open Failed");
		exit(1);
	}

	getchar();

	retval = read(fd, buffer, 5);
	buffer[retval] = '\0';
	printf("Read retval:%d\n", retval);
	printf("Read buffer:%s\n", buffer);
	getchar();

	retval = read(fd, buffer, 5);
	buffer[retval] = '\0';
	printf("Read retval:%d\n", retval);
	printf("Read buffer:%s\n", buffer);
	getchar();

	printf("Closing file\n");
	close(fd);
	getchar();

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/20_readwrite_position/readwrite_position.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "rwdev";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);

	if (count < available_space)
		bytes_to_write = count;
	else
		bytes_to_write = available_space;
		
	if (bytes_to_write == 0) {
		pr_err("%s: No available space in the buffer for writing\n", __func__);
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);
	pr_info("%s: Bytes written: %d\n", __func__, bytes_written);
	pr_info("%s: kernel_buffer: %s\n", __func__, kernel_buffer);

	//update file offset
	*offset += bytes_written;
	buffer_index += bytes_written;
	return bytes_written;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t* offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);
	
	if (count < available_space)
		bytes_to_read = count;
	else
		bytes_to_read = available_space;
	
	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading\n", __func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
		bytes_to_read = buffer_index - *offset;
	else
		return 0;

	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer+*offset, bytes_to_read);
	pr_info("%s: Copy to user returned: %d\n", __func__, bytes_to_read);

	*offset += bytes_read;
	return bytes_read;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_init(void)
{
	myclass = class_create(THIS_MODULE, "newclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered MAJOR: %d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();
		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}

	} 
	else
	{
		pr_info("Device number failed to register\n");
	}

	return 0;
}

static void test_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_init);
module_exit(test_exit);


==> LinuxCharacterDeviceDrivers/sec2/20_readwrite_position/readwrite_position.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C4C9BDC15558BBEA3DA3F15");

==> LinuxCharacterDeviceDrivers/sec2/20_readwrite_position/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char buffer[50];
	int fd;
	int length;
	int i = 0;

	fd = open("/dev/rwdev", O_RDWR);
	if (fd < 0) {
		perror("fd failed");
		exit(2);
	}
	printf("write retval : %d\n", write(fd, "hello world", sizeof("hello world")));
	printf("write retval : %d\n", write(fd, "bye world", sizeof("bye world")));
	//set the file position to 0
	lseek(fd, 0, SEEK_SET);
	perror("lseek");
	memset(buffer, 0, sizeof(buffer));
	length = read(fd, buffer, sizeof(buffer));
	buffer[length] = '\0';
	printf("Read: %s\tlength: %d\n", buffer, length);
	close(fd);
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/21_lseek/lseek.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char* device_name = "newdev";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);

	if (count < available_space)
		bytes_to_read = count;
	else
		bytes_to_read = available_space;

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading\n", __func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
		bytes_to_read = buffer_index - *offset;
	else
		return 0;

	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer+*offset, bytes_to_read);
	pr_info("%s: Copy to user returned:%d\n", __func__, bytes_to_read);

	//update file offset 
	*offset += bytes_read;

	return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);

	if (count < available_space)
		bytes_to_write = count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0) {
		pr_err("%s: No available space in the buffer for writing\n", __func__);
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer+*offset, user_buffer, bytes_to_write);
	pr_info("%s: Bytes written:%d\n", __func__, bytes_written);
	pr_info("%s: kernel_buffer:%s\n", __func__, kernel_buffer);

	*offset += bytes_written;
	buffer_index += bytes_written;
	return bytes_written;
}

static loff_t device_lseek(struct file *file, loff_t offset, int orig)
{
	loff_t new_pos = 0;

	switch(orig) {
		case 0: //seek set 
			new_pos = offset;
			break;
		case 1: //seek curr 
			new_pos = file->f_pos + offset;
			break;
		case 2: //seek end 
			new_pos = MAX_SIZE - offset;
			break;
	}
	if (new_pos > MAX_SIZE)
		new_pos = MAX_SIZE;
	if (new_pos < 0)
		new_pos = 0;
	file->f_pos = new_pos;
	return new_pos;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek
};

static int test_new_init(void)
{
	myclass = class_create(THIS_MODULE, "newerclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered: %d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();

		if (mycdev) {
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}

	}
	else {
		pr_info("Device number not successfully registered\n");
	}
	return 0;
}

static void test_new_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_new_init);
module_exit(test_new_exit);

==> LinuxCharacterDeviceDrivers/sec2/21_lseek/lseek.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E5BCCA8DBF4363ED9FE778D");

==> LinuxCharacterDeviceDrivers/sec2/21_lseek/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char buffer[50];
	int fd;
	int length;
	int i = 0;

	fd = open("/dev/newdev", O_RDWR);
	if (fd < 0){
		perror("fd failed");
		exit(2);
	}
 
	printf("Write : %d\n", write(fd, "hello world", sizeof("hello world")));
	printf("Write : %d\n", write(fd, "bye world", sizeof("bye world")));

	lseek(fd, 0, SEEK_SET);
	perror("lseek");
	memset(buffer, 0, sizeof(buffer));
	length = read(fd, buffer, sizeof(buffer));
	buffer[length] = '\0';
	printf("Read: %s\tlength: %d\n", buffer, length);
	for (i = 0; i < length; i++)
		printf("buffer[%d] :\t%c\n", i, buffer[i]);
	memset(buffer, 0, sizeof(buffer));
	length = read(fd, buffer, sizeof(buffer));
	buffer[length] = '\0';
	printf("Read: %s\tlength: %d\n", buffer, length);
	close(fd);

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/22_multipledevicenodes/multipledevicenodes.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define MAX_DEVICES 5

dev_t devicenumber;
int base_minor = 0;
int count = MAX_DEVICES;
char* device_name = "msg";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev mycdev[MAX_DEVICES];

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t* offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);

	if (count < available_space)
		bytes_to_read = count;
	else
		bytes_to_read = available_space;

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading.\n", __func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
		bytes_to_read = buffer_index - *offset;
	else
		return 0;

	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);
	pr_info("%s: Copy to user returned:%d\n", __func__, bytes_to_read);

	*offset += bytes_read;

	return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);

	if (count < available_space)
		bytes_to_write = count;
	else 
		bytes_to_write = available_space;

	if (bytes_to_write == 0) {
		pr_err("%s: No available space in the buffer for writing\n", __func__);
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);
	pr_info("%s: Bytes written: %d\n", __func__, bytes_written);
	pr_info("%s: kernel_buffer: %s\n", __func__, kernel_buffer);

	*offset += bytes_written;
	buffer_index += bytes_written;
	return bytes_written;
}

static loff_t device_lseek(struct file *file, loff_t offset, int orig)
{
	loff_t new_pos = 0;

	switch(orig) {
		case 0: //seek set
				new_pos = offset;
				break;
		case 1: //seek curr
				new_pos = file->f_pos +  offset;
				break;
		case 2: //seek end
				new_pos = MAX_SIZE - offset;
				break;
	}
	if (new_pos > MAX_SIZE) new_pos = MAX_SIZE;
	if (new_pos < 0) new_pos = 0;
	file->f_pos = new_pos;
	return new_pos;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek
};

static int new_dev_init(void) 
{
	int i = 0;
	myclass = class_create(THIS_MODULE, "newclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) 
	{
		int major = MAJOR(devicenumber);
		pr_info("Device number registered\n");
		pr_info("Major number received:%d\n", major);
		for(i = 0; i < MAX_DEVICES; i++) {
			dev_t tmp_device = MKDEV(major, i);
			mydevice = device_create(myclass, NULL, tmp_device, NULL, "%s%d", device_name, i);
			cdev_init(&mycdev[i], &fops);
			mycdev[i].owner = THIS_MODULE;
			cdev_add(&mycdev[i], tmp_device, 1);
		}
	}
	else 
		pr_info("Device number registration failed\n");

	return 0;
}

static void new_dev_exit(void) 
{
	int major = MAJOR(devicenumber);
	int i = 0;
	dev_t tmp_device;
	for (i = 0; i < MAX_DEVICES; i++) {
		tmp_device = MKDEV(major, i);
		device_destroy(myclass, tmp_device);
		cdev_del(&mycdev[i]);
	}
	class_destroy(myclass);
	unregister_chrdev_region(devicenumber, count);
}

module_init(new_dev_init);
module_exit(new_dev_exit);

==> LinuxCharacterDeviceDrivers/sec2/22_multipledevicenodes/multipledevicenodes.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A9C95F3A970E9A2A835B381");

==> LinuxCharacterDeviceDrivers/sec2/22_multipledevicenodes/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	char buffer[50];
	int fd1, fd2;
	int length;
	int i = 0;

	fd1 = open("/dev/msg1", O_RDWR);
	if (fd1 < 0) {
		perror("fd1 failed");
		exit(2);
	}

	fd2 = open("/dev/msg2", O_RDWR);
	if (fd2 < 0) {
		perror("fd2 failed");
		exit(2);
	}

	printf("write : %d\n", write(fd1, "hello world", sizeof("hello world")));
	lseek(fd2, 0, SEEK_SET);
	perror("lseek");
	memset(buffer, 0, sizeof(buffer));
	length = read(fd2, 0, sizeof(buffer));
	buffer[length] = '\0';
	printf("Read: %s\tLength %d\n", buffer, length);
	close(fd1);
	close(fd2);

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/23_container_of/container_of_test.c <==
#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({ \
	const typeof ( ((type *)0)->member) *__mptr = (ptr); \
	(type *)( (char *)__mptr - offsetof(type, member));})

struct test {
	int member1;
	float member2;
};

int main()
{
	struct test t1;
	float *ptr = &t1.member2;
	printf("Address of t1:\t%p\n", &t1);
	printf("Address of t1 container_method:\t%p\n", container_of(ptr, struct test, member2));
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec2/24_private_data/comp.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>


#define MAX_DEVICES     5

int base_minor = 0;
char *device_name = "msg";
int count = MAX_DEVICES;
dev_t devicenumber;

static struct class *class = NULL;
static struct device *device = NULL;
#define MAX_SIZE        1024
struct msg_device
{
	struct cdev mycdev;
	char kernel_buffer[MAX_SIZE];
};

static struct msg_device msg_devices[MAX_DEVICES];

int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	struct msg_device *my_device = container_of(inode->i_cdev, struct msg_device, mycdev);
	file->private_data = my_device;

	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
        return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer,
                      size_t read_count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	struct msg_device *my_device = (struct msg_device *)file->private_data;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	 available_space = MAX_SIZE - *(offset);

	if (read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading\n",
				__func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
                bytes_to_read = buffer_index - *offset;
        else
                return 0;


	bytes_read = bytes_to_read - copy_to_user(user_buffer, my_device->kernel_buffer+*offset, bytes_to_read);
	pr_info("%s: Copy to user returned:%d\n", __func__, bytes_to_read);

	//update file offset
	*offset += bytes_read;

        return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer,
                       size_t write_count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;
	struct msg_device *my_device = (struct msg_device *)file->private_data;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);

	if (write_count < available_space)
		bytes_to_write = write_count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0) {
		pr_err("%s: No available space in the buffer for writing\n",
				__func__);
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(my_device->kernel_buffer+*offset,  
				user_buffer, bytes_to_write);
	pr_info("%s: Bytes written:%d\n", __func__, bytes_written);
	pr_info("%s: kernel_buffer:%s\n", __func__, my_device->kernel_buffer);

	//update file offset
	*offset += bytes_written;
	buffer_index += bytes_written;
        return bytes_written;
}

static loff_t device_lseek(struct file *file, loff_t offset, int orig)
{
        loff_t new_pos = 0;

        switch(orig) {
                case 0 : /*seek set*/
                        new_pos = offset;
                        break;
                case 1 : /*seek cur*/
                        new_pos = file->f_pos + offset;
                        break;
                case 2 : /*seek end*/
                        new_pos = MAX_SIZE - offset;
                        break;
        }
        if(new_pos > MAX_SIZE)
                new_pos = MAX_SIZE;
        if(new_pos < 0)
                new_pos = 0;
        file->f_pos = new_pos;
        return new_pos;
}



struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek
};


static int test_hello_init(void)
{
	int i = 0;
	class = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		int major = MAJOR(devicenumber);
		printk("Device number registered\n");
		printk("Major number received:%d\n", major);
		for (i = 0; i < MAX_DEVICES; i++) {
			dev_t tmp_device = MKDEV(major, i);
			device = device_create(class, NULL, tmp_device, NULL, "%s%d", device_name, i);
			cdev_init(&msg_devices[i].mycdev, &device_fops);
			msg_devices[i].mycdev.owner = THIS_MODULE;
			cdev_add(&msg_devices[i].mycdev, tmp_device, 1);
		}

	}
	else
		printk("Device number registration Failed\n");

	return 0;
}

static void test_hello_exit(void)
{
	int major = MAJOR(devicenumber);
	int i = 0;
	dev_t tmp_device;
	for (i = 0; i < MAX_DEVICES; i++) {
		tmp_device = MKDEV(major, i);
		device_destroy(class, tmp_device);
		cdev_del(&msg_devices[i].mycdev);
	}
	
	class_destroy(class);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxCharacterDeviceDrivers/sec2/24_private_data/private_data_support.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define MAX_DEVICES 5

dev_t devicenumber;
int base_minor = 0;
int count = MAX_DEVICES;
char *device_name = "privdata";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
#define MAX_SIZE 1024

struct msg_device {
	struct cdev mycdev;
	char kernel_buffer[MAX_SIZE];
};

static struct msg_device msg_device[MAX_DEVICES];

int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file* file)
{
	pr_info("%s\n", __func__);
	struct msg_device *my_device = container_of(inode->i_cdev, struct msg_device, mycdev);
	file->private_data = my_device;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t read_count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	struct msg_device *my_device = (struct msg_device*)file->private_data;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *offset;

	if (read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading\n", __func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
		bytes_to_read = buffer_index - *offset;
	else
		return 0;

	bytes_read = bytes_to_read - copy_to_user(user_buffer, my_device->kernel_buffer + *offset, bytes_to_read);
	pr_info("%s: Copy to user returned:%d\n", __func__, bytes_to_read);

	*offset += bytes_read;

	return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t write_count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;
	struct msg_device *my_device = (struct msg_device*)file->private_data;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *offset;

	if (write_count < available_space)
		bytes_to_write = write_count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0)
	{
		pr_err("%s: No available space in the buffer for writing\n", __func__);
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(my_device->kernel_buffer + *offset, user_buffer, bytes_to_write);
	pr_info("%s: Bytes written:%d\n", __func__, bytes_written);
	pr_info("%s: kernel_buffer:%s\n", __func__, my_device->kernel_buffer);

	*offset += bytes_written;
	buffer_index += bytes_written;
	return bytes_written;
}

static loff_t device_lseek(struct file *file, loff_t offset, int orig)
{
	loff_t new_pos = 0;

	switch(orig) 
	{
		case 0: //seek set
			new_pos = offset;
			break;
		case 1: //seek curr
			new_pos = file->f_pos + offset;
			break;
		case 2: //seek end
			new_pos = MAX_SIZE - offset;
			break;
	}
	if (new_pos > MAX_SIZE)
		new_pos = MAX_SIZE;
	if (new_pos < 0)
		new_pos = 0;
	file->f_pos = new_pos;
	return new_pos;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek
};

static int test_newdev_init(void)
{
	int i = 0;
	myclass = class_create(THIS_MODULE, "thisclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		int major = MAJOR(devicenumber);
		pr_info("Device number registered, Major:%d\n", major);
		for (i = 0; i < MAX_DEVICES; i++)
		{
			dev_t tmp_device = MKDEV(major, i);
			mydevice = device_create(myclass, NULL, tmp_device, NULL, "%s%d", device_name, i);
			cdev_init(&msg_device[i].mycdev, &fops);
			msg_device[i].mycdev.owner = THIS_MODULE;
			cdev_add(&msg_device[i].mycdev, tmp_device, 1);
		}
	}
	else
		printk("Device number registration failed\n");
	return 0;
}

static void test_newdev_exit(void)
{
	int major = MAJOR(devicenumber);
	int i = 0;
	dev_t tmp_device;
	for (i = 0; i < MAX_DEVICES; i++)
	{
		tmp_device = MKDEV(major, i);
		device_destroy(myclass, tmp_device);
		cdev_del(&msg_device[i].mycdev);
	}
	class_destroy(myclass);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_newdev_init);
module_exit(test_newdev_exit);


==> LinuxCharacterDeviceDrivers/sec2/24_private_data/private_data_support.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "47855435053D5050BC5ACEA");

==> LinuxCharacterDeviceDrivers/sec2/24_private_data/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char buffer[50];
	int fd1, fd2;
	int length;
	int i = 0;

	fd1 = open("/dev/privdata1", O_RDWR);
	if (fd1 < 0)
	{
		perror("fd1 failed");
		exit(2);
	}

	fd2 = open("/dev/privdata2", O_RDWR);
	if (fd2 < 0)
	{
		perror("fd2 failed");
		exit(2);
	}

	printf("write : %\n", write(fd1, "hello world", sizeof("hello world")));
	lseek(fd2, 0, SEEK_SET);
	perror("lseek");
	memset(buffer, 0, sizeof(buffer));
	length = read(fd2, buffer, sizeof(buffer));
	buffer[length] = '\0';
	printf("Read:%s\tlength:%d\n", buffer, length);
	close(fd1);
	close(fd2);
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/00_ioctl_BLKGETSIZE/ioctl_BLKGETSIZE.c <==
#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>

int main()
{
	int fd;
	unsigned long num_blocks;

	fd = open("/dev/sda1", O_RDONLY);
	perror("fd");

	//0x00001260, BLKGETSIZE	unsigned long*
	ioctl(fd, 0x00001260, &num_blocks);
	perror("ioctl");
	printf("NUmber of blocks: %lu, this makes %.3f GB\n", num_blocks, (double)num_blocks * 512.0 / (1024 * 1024 * 1024));
	close(fd);
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/01_ioctl_BLKGETSIZE64/ioctl_BLKGETSIZE64.c <==
#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/fs.h>
#include <stdint.h>

int main()
{
	int fd;
	float size;

	fd = open("/dev/sda1", O_RDONLY);
	perror("fd");

	ioctl(fd, BLKGETSIZE64, &size);
	perror("ioctl");
	printf("Size %.3f GB\n", (size)/(1024 *1024 * 1024));
	close(fd);
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/02_unlocked_ioctl/unlocked_ioctl.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "msg";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t read_count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *offset;

	if (read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading\n", __func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
		bytes_to_read = buffer_index - *offset;
	else
		return 0;

	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);
	pr_info("%s: Copy to user returned:%d\n", __func__, bytes_to_read);

	*offset += bytes_read;
	return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t write_count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *offset;

	if (write_count < available_space)
		bytes_to_write = write_count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0){
		pr_err("%s: No available space in the buffer for writing\n");
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);
	pr_info("%s: Bytes written:%d\n", __func__, bytes_written);
	pr_info("%s: kernel_bufer:%s\n", __func__, kernel_buffer);

	*offset += bytes_written;
	buffer_index += bytes_written;
	return bytes_written;
}

long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	pr_info("%s: Cmd:%u\tArg:%lu\n", __func__, cmd, arg);
	return 0;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.unlocked_ioctl = device_ioctl
};

static int test_hello_init(void)
{
	myclass = class_create(THIS_MODULE, "myclass");
	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Major number registered:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);

		mycdev = cdev_alloc();

		if (mycdev) 
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else 
		pr_info("Device registration failed\n");

	return 0;
}

static void test_hello_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

==> LinuxCharacterDeviceDrivers/sec3/02_unlocked_ioctl/unlocked_ioctl.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "AA9890E6C5612637DFAE185");

==> LinuxCharacterDeviceDrivers/sec3/02_unlocked_ioctl/userapp.c <==
#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>

int main()
{
	int fd;

	fd = open("/dev/msg", O_RDWR);
	perror("fd");

	ioctl(fd, 0x01, 10);
	perror("ioctl");
	getchar();

	ioctl(fd, 0x01);
	perror("ioctl");
	getchar();
	close(fd);
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/03_three_ioctls/comp.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

int base_minor = 0;
char *device_name = "msg";
int count = 1;
dev_t devicenumber;

static struct class *class = NULL;
static struct device *device = NULL;
static struct cdev mycdev;

#define MAX_SIZE        1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
        return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer,
                      size_t read_count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	 available_space = MAX_SIZE - *(offset);

	if (read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;
	
	pr_info("bytes_to_read:%d\n", bytes_to_read);

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading\n",
				__func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
                bytes_to_read = buffer_index - *offset;
        else
                return 0;


	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer+*offset, bytes_to_read);
	pr_info("%s: Copy to user returned:%d\n", __func__, bytes_to_read);

	//update file offset
	*offset += bytes_read;

        return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer,
                       size_t write_count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);

	if (write_count < available_space)
		bytes_to_write = write_count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0) {
		pr_err("%s: No available space in the buffer for writing\n",
				__func__);
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer+*offset,  user_buffer, bytes_to_write);
	pr_info("%s: Bytes written:%d\n", __func__, bytes_written);
	pr_info("%s: kernel_buffer:%s\n", __func__, kernel_buffer);

	//update file offset
	*offset += bytes_written;
	buffer_index += bytes_written;
        return bytes_written;
}

static loff_t device_lseek(struct file *file, loff_t offset, int orig)
{
        loff_t new_pos = 0;

        switch(orig) {
                case 0 : /*seek set*/
                        new_pos = offset;
                        break;
                case 1 : /*seek cur*/
                        new_pos = file->f_pos + offset;
                        break;
                case 2 : /*seek end*/
                        new_pos = MAX_SIZE - offset;
                        break;
        }
        if(new_pos > MAX_SIZE)
                new_pos = MAX_SIZE;
        if(new_pos < 0)
                new_pos = 0;
        file->f_pos = new_pos;
        return new_pos;
}


long device_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	pr_info("%s: Cmd:%u\t Arg:%lu\n", __func__, cmd, arg);

	switch(cmd)
	{
		//Get Length of buffer
		case 0x01:
			pr_info("Get Buffer Length\n");
			put_user(MAX_SIZE, (unsigned int *)arg);
			break;
		//clear buffer
		case 0x02:
			pr_info("Clear buffer\n");
			memset(kernel_buffer, 0, sizeof(kernel_buffer));
			break;
		//fill character
		case 0x03:
			get_user(ch, (unsigned char *)arg);
			pr_info("Fill Character:%c\n", ch);
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			buffer_index = sizeof(kernel_buffer);
			break;
		default:
			pr_info("Unknown Command:%u\n", cmd);
			return -EINVAL;
	}
	return 0;
}

struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
	.unlocked_ioctl = device_ioctl	
};

static int test_hello_init(void)
{
	class = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		printk("Device number registered\n");
		printk("Major number received:%d\n", MAJOR(devicenumber));

		device = device_create(class, NULL, devicenumber, NULL, device_name);
		cdev_init(&mycdev, &device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev, devicenumber, count);

	}
	else
		printk("Device number registration Failed\n");

	return 0;
}

static void test_hello_exit(void)
{
	device_destroy(class, devicenumber);
        class_destroy(class);
	cdev_del(&mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxCharacterDeviceDrivers/sec3/03_three_ioctls/three_ioctls.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char* device_name = "msg";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t read_count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;
	int retval;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *offset;

	if (read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;

	pr_info("bytes to read:%d\n", bytes_to_read);

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading", __func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
		bytes_to_read = buffer_index - *offset;
	else
		return 0;

	pr_info("bytes to read:%d\n", bytes_to_read);
    retval = copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);
	bytes_read = bytes_to_read - retval;
	pr_info("%s: Copy to user returned:%d\n", __func__, retval);

	*offset += bytes_read;
	return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t write_count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;
	int retval;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *offset;

	if (write_count < available_space)
		bytes_to_write = write_count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0) {
		pr_err("%s: No available space in the buffer for writing\n", __func__);
		return -ENOSPC;
	}

    retval = copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);

	pr_info("%s: Copy from user returned:%d\n", __func__, retval);
	bytes_written = bytes_to_write - retval;
	pr_info("%s: Bytes written:%d\n", __func__, bytes_written);
	pr_info("%s: Kernel buffer:%s\n", __func__, kernel_buffer);

	*offset += bytes_written;
	buffer_index += bytes_written;
	return bytes_written;
}

static loff_t device_lseek(struct file *file, loff_t offset, int orig)
{
	loff_t new_pos = 0;

	switch(orig) {
		case 0: //seek set
			new_pos = offset;
			break;
		case 1: //seek curr
			new_pos = file->f_pos + offset;
			break;
		case 2: //seek end
			new_pos = MAX_SIZE - offset;
			break;
	}
	if (new_pos > MAX_SIZE)
		new_pos = MAX_SIZE;
	if (new_pos < 0)
		new_pos = 0;
	file->f_pos = new_pos;
	return new_pos;
}

long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	pr_info("%s: Cmd:%u\tArg:%lu\n", __func__, cmd, arg);

	switch(cmd)
	{
		//Get length of buffer
		case 0x01:
			pr_info("Get buffer Length\n");
			put_user(MAX_SIZE, (unsigned int*) arg);
			break;
		//clear buffer
		case 0x02:
			pr_info("Clear buffer\n");
			memset(kernel_buffer, 0, sizeof(kernel_buffer));
			break;
		case 0x03:
			get_user(ch, (unsigned char *)arg);
			pr_info("Fill character:%c\n", ch);
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			buffer_index = sizeof(kernel_buffer);
			break;
		default:
			pr_info("Unknown command:%u\n", cmd);
			return -EINVAL;
	}	
	return 0;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
	.unlocked_ioctl = device_ioctl
};

static int test_hello_init(void)
{
	myclass = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered, major:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);

		mycdev = cdev_alloc();
		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_info("Device number registartion Failed\n");

	return 0;
}

static void test_hello_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

==> LinuxCharacterDeviceDrivers/sec3/03_three_ioctls/three_ioctls.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0x46dce43, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0xb7ad68f3, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0x167e7f9d, "__get_user_1" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2A7885BB636931AB36B93FC");

==> LinuxCharacterDeviceDrivers/sec3/03_three_ioctls/userapp1.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char buffer[50];
	int fd;
	int length;
	int i = 0;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0){
		perror("fd failed");
		exit(2);
	}
 
	printf("Write : %d\n", write(fd, "hello world", sizeof("hello world")));
	printf("Write : %d\n", write(fd, "bye world", sizeof("bye world")));

	lseek(fd, 0, SEEK_SET);
	perror("lseek");
	memset(buffer, 0, sizeof(buffer));
	length = read(fd, buffer, sizeof(buffer));
	buffer[length] = '\0';
	printf("Read: %s\tlength: %d\n", buffer, length);
	for (i = 0; i < length; i++)
		printf("buffer[%d] :\t%c\n", i, buffer[i]);
	memset(buffer, 0, sizeof(buffer));
	length = read(fd, buffer, sizeof(buffer));
	buffer[length] = '\0';
	printf("Read: %s\tlength: %d\n", buffer, length);
	close(fd);

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/03_three_ioctls/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>

int main(int argc, char **argv)
{
	char buffer[1024];
	int fd;
	unsigned int length;
	unsigned char ch = 'A';

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0) {
		perror("fd failed");
		exit(2);
	}
	//Get Length - 0x01
	ioctl(fd, 0x01, &length);
	printf("Length:%u\n", length);
	//Set character - 0x03
	ioctl(fd, 0x03, &ch);
	perror("ioctl");
	length = read(fd, buffer, 1024);
	perror("Read");
	printf("length:%d\n", length);
	buffer[1023] = '\0';
	printf("Buffer:%s\n", buffer);
	close(fd);
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/04_symbolic_names_ioctl/comp.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "ioctl_cmd.h"

int base_minor = 0;
char *device_name = "msg";
int count = 1;
dev_t devicenumber;

static struct class *class = NULL;
static struct device *device = NULL;
static struct cdev mycdev;

#define MAX_SIZE        1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
        return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer,
                      size_t read_count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	 available_space = MAX_SIZE - *(offset);

	if (read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;
	
	pr_info("bytes_to_read:%d\n", bytes_to_read);

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading\n",
				__func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
                bytes_to_read = buffer_index - *offset;
        else
                return 0;


	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer+*offset, bytes_to_read);
	pr_info("%s: Copy to user returned:%d\n", __func__, bytes_to_read);

	//update file offset
	*offset += bytes_read;

        return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer,
                       size_t write_count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);

	if (write_count < available_space)
		bytes_to_write = write_count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0) {
		pr_err("%s: No available space in the buffer for writing\n",
				__func__);
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer+*offset,  user_buffer, bytes_to_write);
	pr_info("%s: Bytes written:%d\n", __func__, bytes_written);
	pr_info("%s: kernel_buffer:%s\n", __func__, kernel_buffer);

	//update file offset
	*offset += bytes_written;
	buffer_index += bytes_written;
        return bytes_written;
}

static loff_t device_lseek(struct file *file, loff_t offset, int orig)
{
        loff_t new_pos = 0;

        switch(orig) {
                case 0 : /*seek set*/
                        new_pos = offset;
                        break;
                case 1 : /*seek cur*/
                        new_pos = file->f_pos + offset;
                        break;
                case 2 : /*seek end*/
                        new_pos = MAX_SIZE - offset;
                        break;
        }
        if(new_pos > MAX_SIZE)
                new_pos = MAX_SIZE;
        if(new_pos < 0)
                new_pos = 0;
        file->f_pos = new_pos;
        return new_pos;
}

long device_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	pr_info("%s: Cmd:%u\t Arg:%lu\n", __func__, cmd, arg);

	switch(cmd)
	{
		//Get Length of buffer
		case MSG_IOCTL_GET_LENGTH:
			pr_info("Get Buffer Length\n");
			put_user(MAX_SIZE, (unsigned int *)arg);
			break;
		//clear buffer
		case MSG_IOCTL_CLEAR_BUFFER:
			pr_info("Clear buffer\n");
			memset(kernel_buffer, 0, sizeof(kernel_buffer));
			break;
		//fill character
		case MSG_IOCTL_FILL_BUFFER:
			get_user(ch, (unsigned char *)arg);
			pr_info("Fill Character:%c\n", ch);
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			buffer_index = sizeof(kernel_buffer);
			break;
		default:
			pr_info("Unknown Command:%u\n", cmd);
			return -EINVAL;
	}
	return 0;
}

struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
	.unlocked_ioctl = device_ioctl	
};

static int test_hello_init(void)
{
	class = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		printk("Device number registered\n");
		printk("Major number received:%d\n", MAJOR(devicenumber));

		device = device_create(class, NULL, devicenumber, NULL, device_name);
		cdev_init(&mycdev, &device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev, devicenumber, count);

	}
	else
		printk("Device number registration Failed\n");

	return 0;
}

static void test_hello_exit(void)
{
	device_destroy(class, devicenumber);
        class_destroy(class);
	cdev_del(&mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxCharacterDeviceDrivers/sec3/04_symbolic_names_ioctl/symbolicnamesioctl.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "ioctl_cmd.h"

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "msg";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode* inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	available_space = MAX_SIZE - *offset;

	if (count < available_space)
		bytes_to_read = count;
	else
		bytes_to_read = available_space;

	if (bytes_to_read == 0) {
		pr_err("Not enough space in buffer for reading\n");
		return -ENOSPC;
	}

	if (buffer_index > *offset)
		bytes_to_read =  buffer_index - *offset;
	else
		return 0;

	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);

	pr_info("%s: Bytes read into user buffer:%d\n", __func__, bytes_read);

	*offset += bytes_read;
	return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_to_write;
	int available_space;
	int bytes_written;

	available_space = MAX_SIZE - *offset;

	if (count < available_space)
		bytes_to_write = count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0) {
		pr_err("Not enough space in the buffer for writing\n");
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);
	pr_info("%s: Bytes written:%d\n", __func__, bytes_written);
	pr_info("%s: Kernel buffer:%s\n", __func__, kernel_buffer);

	return bytes_written;
}

loff_t lseek(struct file *file, loff_t offset, int cmd)
{
	loff_t new_pos = 0;

	switch(cmd) {
		case 0: //seek set
			new_pos = offset;
			break;
		case 1: //seek curr
			new_pos = file->f_pos + offset;
			break;
		case 2: //seek end
			new_pos = MAX_SIZE - offset;
			break;
	}
	if (new_pos > MAX_SIZE)
		new_pos = MAX_SIZE;
	if (new_pos < 0)
		new_pos = 0;
	file->f_pos = new_pos;
	return new_pos;
}

long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	pr_info("%s: Cmd:%u\tArg:%lu\n", __func__, cmd, arg);

	switch(cmd)
	{
		// Get length of Buffer
		case MSG_IOCTL_GET_LENGTH:
			pr_info("Get Buffer Length\n");
			put_user(MAX_SIZE, (unsigned int *) arg);
			break;
		//Clear buffer
		case MSG_IOCTL_CLEAR_BUFFER:
			pr_info("Clear buffer\n");
			memset(kernel_buffer, 0, sizeof(kernel_buffer));
			break;
		//Fill character
		case MSG_IOCTL_FILL_BUFFER:
			get_user(ch, (unsigned char*)arg);
			pr_info("Fill character:%c\n", ch);
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			buffer_index = sizeof(kernel_buffer);
			break;
		default:
			pr_info("Unknown command:%u\n", cmd);
			return -EINVAL;
	}
	return 0;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = lseek,
	.unlocked_ioctl = device_ioctl
};

static int test_dev_init(void)
{
	myclass = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered, Major:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();
		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_err("Device Registration failed\n");

	return 0;
}

static void test_dev_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_dev_init);
module_exit(test_dev_exit);

==> LinuxCharacterDeviceDrivers/sec3/04_symbolic_names_ioctl/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ioctl_cmd.h"

int main(int argc, char **argv)
{
	char buffer[1024];
	int fd;
	unsigned int length;
	unsigned char ch = 'A';
	int i = 0;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0) {
		perror("fd  failed");
		exit(2);
	}
	//Get length - 0x01
	ioctl(fd, MSG_IOCTL_GET_LENGTH, &length);
	printf("Length:%u\n", length);
	//Set character - 0x03
	ioctl(fd, MSG_IOCTL_FILL_BUFFER, &ch);
	perror("ioctl");
	lseek(fd, 0, SEEK_SET);
	perror("lseek");
	length = read(fd, buffer, 1024);
	perror("Read");
	printf("length:%d\n", length);
	buffer[1023] = '\0';
	printf("Buffer:%s\n", buffer);
	close(fd);
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/05_example_ioctl_macros/example_ioctl_macros.c <==
#include <stdio.h>
#include <linux/ioctl.h>

#define MAGIC_NUMBER1 'l'
#define MAGIC_NUMBER2 'i'

int main() 
{
	//prints 16-bit hex value for ioctl command
	printf("IO(MAGIC_NUMBER1, 1):%x\n", _IO(MAGIC_NUMBER1, 1));
	printf("IO(MAGIC_NUMBER2, 1):%x\n", _IO(MAGIC_NUMBER2, 1));

	getchar();
	printf("IO(MAGIC_NUMBER1, 2):%x\n", _IO(MAGIC_NUMBER1, 2));
	printf("IO(MAGIC_NUMBER2, 2):%x\n", _IO(MAGIC_NUMBER2, 2));

	//prints 32-bit hex value for ioctl command
	getchar();
	printf("IOR(MAGIC_NUMBER1, 2, int):%lx\n", _IOR(MAGIC_NUMBER1, 2, int));
	printf("IOR(MAGIC_NUMBER2, 2, int):%lx\n", _IOR(MAGIC_NUMBER2, 2, int));

	getchar();
	printf("IOR(MAGIC_NUMBER1, 3, int):%lx\n", _IOR(MAGIC_NUMBER1, 3, int));
	printf("IOR(MAGIC_NUMBER2, 3, int):%lx\n", _IOR(MAGIC_NUMBER2, 3, int));

	getchar();
	printf("IOWR(MAGIC_NUMBER2, 4, int):%lx\n", _IOWR(MAGIC_NUMBER2, 4, int));
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/06_decode_ioctl/decode_ioctl.c <==
#include <stdio.h>
#include <linux/ioctl.h>

#define MAGIC_NUMBER1 'l'

#define CMD1 _IO(MAGIC_NUMBER1, 1)
#define CMD2 _IOW(MAGIC_NUMBER1, 2, int)
#define CMD3 _IOWR(MAGIC_NUMBER1, 3, char)

void printDirection(unsigned int cmd)
{
	switch(_IOC_DIR(cmd))
	{
		case _IOC_NONE:
			printf("IOC_NONE\n");
			break;
		case _IOC_READ:
			printf("_IOC_READ\n");
			break;
		case _IOC_WRITE:
			printf("_IOC_WRITE\n");
			break;
		case _IOC_READ | _IOC_WRITE:
			printf(" _IOC_READ | _IOC_WRITE");
			break;
		default:
			break;
	}
}

int main()
{
	printf("Number:0x%.2x\n", _IOC_NR(CMD1));
	printf("Number:0x%.2lx\n", _IOC_NR(CMD2));
	printf("Number:0x%.2lx\n", _IOC_NR(CMD3));
	
	printf("Magic Number:0x%.2x\n", _IOC_TYPE(CMD1));
	printf("Magic Number:0x%.2lx\n", _IOC_TYPE(CMD2));
	printf("Magic Number:0x%.2lx\n", _IOC_TYPE(CMD3));
	
	printf("Size:0x%.2x\n", _IOC_SIZE(CMD1));
	printf("Size:0x%.2lx\n", _IOC_SIZE(CMD2));
	printf("Size:0x%.2lx\n", _IOC_SIZE(CMD3));
	
	printDirection(CMD1);
	printDirection(CMD2);
	printDirection(CMD3);
	
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/07_updated_driver_ioctl_macros/comp.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "ioctl_cmd.h"


int base_minor = 0;
char *device_name = "msg";
int count = 1;
dev_t devicenumber;

static struct class *class = NULL;
static struct device *device = NULL;
static struct cdev mycdev;

#define MAX_SIZE        1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
        return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer,
                      size_t read_count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	 available_space = MAX_SIZE - *(offset);

	if (read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;
	
	pr_info("bytes_to_read:%d\n", bytes_to_read);

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading\n",
				__func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
                bytes_to_read = buffer_index - *offset;
        else
                return 0;


	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer+*offset, bytes_to_read);
	pr_info("%s: Copy to user returned:%d\n", __func__, bytes_to_read);

	//update file offset
	*offset += bytes_read;

        return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer,
                       size_t write_count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);

	if (write_count < available_space)
		bytes_to_write = write_count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0) {
		pr_err("%s: No available space in the buffer for writing\n",
				__func__);
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer+*offset,  user_buffer, bytes_to_write);
	pr_info("%s: Bytes written:%d\n", __func__, bytes_written);
	pr_info("%s: kernel_buffer:%s\n", __func__, kernel_buffer);

	//update file offset
	*offset += bytes_written;
	buffer_index += bytes_written;
        return bytes_written;
}

static loff_t device_lseek(struct file *file, loff_t offset, int orig)
{
        loff_t new_pos = 0;

        switch(orig) {
                case 0 : /*seek set*/
                        new_pos = offset;
                        break;
                case 1 : /*seek cur*/
                        new_pos = file->f_pos + offset;
                        break;
                case 2 : /*seek end*/
                        new_pos = MAX_SIZE - offset;
                        break;
        }
        if(new_pos > MAX_SIZE)
                new_pos = MAX_SIZE;
        if(new_pos < 0)
                new_pos = 0;
        file->f_pos = new_pos;
        return new_pos;
}



long device_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	pr_info("%s: Cmd:%u\t Arg:%lu\n", __func__, cmd, arg);

	switch(cmd)
	{
		//Get Length of buffer
		case MSG_IOCTL_GET_LENGTH:
			pr_info("Get Buffer Length\n");
			put_user(MAX_SIZE, (unsigned int *)arg);
			break;
		//clear buffer
		case MSG_IOCTL_CLEAR_BUFFER:
			pr_info("Clear buffer\n");
			memset(kernel_buffer, 0, sizeof(kernel_buffer));
			break;
		//fill character
		case MSG_IOCTL_FILL_BUFFER:
			get_user(ch, (unsigned char *)arg);
			pr_info("Fill Character:%c\n", ch);
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			buffer_index = sizeof(kernel_buffer);
			break;
		default:
			pr_info("Unknown Command:%u\n", cmd);
			return -EINVAL;
	}
	return 0;
}


struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
	.unlocked_ioctl = device_ioctl	
};


static int test_hello_init(void)
{
	class = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		printk("Device number registered\n");
		printk("Major number received:%d\n", MAJOR(devicenumber));

		device = device_create(class, NULL, devicenumber, NULL, device_name);
		cdev_init(&mycdev, &device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev, devicenumber, count);

	}
	else
		printk("Device number registration Failed\n");

	return 0;
}

static void test_hello_exit(void)
{
	device_destroy(class, devicenumber);
        class_destroy(class);
	cdev_del(&mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxCharacterDeviceDrivers/sec3/07_updated_driver_ioctl_macros/updated_driver_device_macros.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "ioctl_cmd.h"

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "msg";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	buffer_index = 0;
	file->f_pos = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	buffer_index = 0;
	file->f_pos = 0;
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_to_write;
	int available_space;
	int bytes_written;

	available_space = MAX_SIZE - *offset;
	if (count > available_space) 
		bytes_to_write = available_space;
	else
		bytes_to_write = count;

	if (bytes_to_write == 0) {
		pr_err("No available space\n");
		return -ENOSPC;
	}

	int retval;

	retval = copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);

	bytes_written = bytes_to_write - retval;
	pr_info("Bytes written:%d\n", bytes_written);
	pr_info("Kernel Buffer:%s\n", kernel_buffer);

	return bytes_written;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_read;
	int bytes_to_read;
	
	if (buffer_index > *offset)
		bytes_to_read = buffer_index - *offset;
	else {
		pr_err("No space available");
		return -ENOSPC;
	}

	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);
	pr_info("Bytes read:%d\n", bytes_read);

	return bytes_read;
}

static loff_t device_lseek(struct file *file, loff_t offset, int cmd)
{
	loff_t new_pos = 0;

	switch(cmd)
	{
		case 0: //seek set
			new_pos = offset;
			break;
		case 1: //seek curr
			new_pos = file->f_pos;
			break;
		case 2: //seek end
			new_pos = MAX_SIZE - offset;
			break;
	}
	if (new_pos > MAX_SIZE)
		new_pos = MAX_SIZE;
	if (new_pos < 0)
		new_pos = 0;
	file->f_pos = new_pos;
	return new_pos;
}

long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	pr_info("%s: cmd:%u\tArg:%lu\n", __func__, cmd, arg);

	switch(cmd)
	{
		//Get length of buffer
		case MSG_IOCTL_GET_LENGTH:
			pr_info("Get Buffer Length\n");
			put_user(MAX_SIZE, (unsigned int*)arg);
			break;
		//Clear buffer
		case MSG_IOCTL_CLEAR_BUFFER:
			pr_info("Clear buffer\n");
			memset(kernel_buffer, 0,  sizeof(kernel_buffer));
			break;
		//fill character
		case MSG_IOCTL_FILL_BUFFER:
			get_user(ch, (unsigned char*)arg);
			pr_info("Fill character: '%c'\n", ch);
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			buffer_index = sizeof(kernel_buffer);
			break;
		default:
			pr_info("Unknown Command:%u\n", cmd);
			return -EINVAL;
	}

	return 0;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
	.unlocked_ioctl = device_ioctl
};

static int test_dev_init(void) {
	myclass = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered, Major:%d", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();

		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}

	}
	else
		pr_info("Device number not registred\n");

	return 0;
}

static void test_dev_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_dev_init);
module_exit(test_dev_exit);


==> LinuxCharacterDeviceDrivers/sec3/07_updated_driver_ioctl_macros/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ioctl_cmd.h"

int main(int argc, char **argv)
{
	char buffer[1024];
	int fd;
	unsigned int length;
	unsigned char ch = 'A';
	int i = 0;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0) {
		perror("fd failed.");
		exit(2);
	}
	//Get length - 0x01

	ioctl(fd, MSG_IOCTL_GET_LENGTH, &length);
	printf("Length:%u\n", length);
	ioctl(fd, MSG_IOCTL_FILL_BUFFER, &ch);
	perror("ioctl");
	lseek(fd, 0, SEEK_SET);
	perror("lseek");
	length= read(fd, buffer, 1024);
	perror("Read");
	printf("Length:%u\n", length);
	buffer[1023] ='\0';
	printf("Buffer:%s\n", buffer);
	close(fd);

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/09_unsupported_command_ioctl/comp.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "ioctl_cmd.h"


int base_minor = 0;
char *device_name = "msg";
int count = 1;
dev_t devicenumber;

static struct class *class = NULL;
static struct device *device = NULL;
static struct cdev mycdev;

#define MAX_SIZE        1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
        return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer,
                      size_t read_count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	 available_space = MAX_SIZE - *(offset);

	if (read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;
	
	pr_info("bytes_to_read:%d\n", bytes_to_read);

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading\n",
				__func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
                bytes_to_read = buffer_index - *offset;
        else
                return 0;


	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer+*offset, bytes_to_read);
	pr_info("%s: Copy to user returned:%d\n", __func__, bytes_to_read);

	//update file offset
	*offset += bytes_read;

        return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer,
                       size_t write_count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);

	if (write_count < available_space)
		bytes_to_write = write_count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0) {
		pr_err("%s: No available space in the buffer for writing\n",
				__func__);
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer+*offset,  user_buffer, bytes_to_write);
	pr_info("%s: Bytes written:%d\n", __func__, bytes_written);
	pr_info("%s: kernel_buffer:%s\n", __func__, kernel_buffer);

	//update file offset
	*offset += bytes_written;
	buffer_index += bytes_written;
        return bytes_written;
}

static loff_t device_lseek(struct file *file, loff_t offset, int orig)
{
        loff_t new_pos = 0;

        switch(orig) {
                case 0 : /*seek set*/
                        new_pos = offset;
                        break;
                case 1 : /*seek cur*/
                        new_pos = file->f_pos + offset;
                        break;
                case 2 : /*seek end*/
                        new_pos = MAX_SIZE - offset;
                        break;
        }
        if(new_pos > MAX_SIZE)
                new_pos = MAX_SIZE;
        if(new_pos < 0)
                new_pos = 0;
        file->f_pos = new_pos;
        return new_pos;
}



long device_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	pr_info("%s: Cmd:%u\t Arg:%lu\n", __func__, cmd, arg);

	if (_IOC_TYPE(cmd) != MSG_MAGIC_NUMBER) return -ENOTTY;
	if (_IOC_NR(cmd) > MSG_IOCTL_MAX_CMDS) return -ENOTTY;

	switch(cmd)
	{
		//Get Length of buffer
		case MSG_IOCTL_GET_LENGTH:
			pr_info("Get Buffer Length\n");
			put_user(MAX_SIZE, (unsigned int *)arg);
			break;
		//clear buffer
		case MSG_IOCTL_CLEAR_BUFFER:
			pr_info("Clear buffer\n");
			memset(kernel_buffer, 0, sizeof(kernel_buffer));
			break;
		//fill character
		case MSG_IOCTL_FILL_BUFFER:
			get_user(ch, (unsigned char *)arg);
			pr_info("Fill Character:%c\n", ch);
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			buffer_index = sizeof(kernel_buffer);
			break;
		default:
			pr_info("Unknown Command:%u\n", cmd);
			return -ENOTTY;
	}
	return 0;
}


struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
	.unlocked_ioctl = device_ioctl	
};


static int test_hello_init(void)
{
	class = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		printk("Device number registered\n");
		printk("Major number received:%d\n", MAJOR(devicenumber));

		device = device_create(class, NULL, devicenumber, NULL, device_name);
		cdev_init(&mycdev, &device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev, devicenumber, count);

	}
	else
		printk("Device number registration Failed\n");

	return 0;
}

static void test_hello_exit(void)
{
	device_destroy(class, devicenumber);
        class_destroy(class);
	cdev_del(&mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxCharacterDeviceDrivers/sec3/09_unsupported_command_ioctl/unsupportedioctlcmdrepsonse.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "ioctl_cmd.h"

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "msg";

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}


static ssize_t device_read(struct file *file, char __user *user_buffer,
                      size_t read_count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	 available_space = MAX_SIZE - *(offset);

	if (read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;
	
	pr_info("bytes_to_read:%d\n", bytes_to_read);

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading\n",
				__func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
                bytes_to_read = buffer_index - *offset;
        else
                return 0;


	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer+*offset, bytes_to_read);
	pr_info("%s: Copy to user returned:%d\n", __func__, bytes_to_read);

	//update file offset
	*offset += bytes_read;

        return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer,
                       size_t write_count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);

	if (write_count < available_space)
		bytes_to_write = write_count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0) {
		pr_err("%s: No available space in the buffer for writing\n",
				__func__);
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer+*offset,  user_buffer, bytes_to_write);
	pr_info("%s: Bytes written:%d\n", __func__, bytes_written);
	pr_info("%s: kernel_buffer:%s\n", __func__, kernel_buffer);

	//update file offset
	*offset += bytes_written;
	buffer_index += bytes_written;
        return bytes_written;
}

//static ssize_t device_write(struct file *file , const char __user *user_buffer, size_t count, loff_t *offset)
//{
//	pr_info("%s\n", __func__);
//	int bytes_to_write;
//	int available_space;
//	int bytes_written;
//
//	available_space = MAX_SIZE - *offset;
//	if (count > available_space)
//		bytes_to_write = available_space;
//	else
//		bytes_to_write = count;
//
//	if (bytes_to_write == 0) {
//		pr_err("Not enough available space\n");
//		return -ENOSPC;
//	}
//
//	int retval;
//
//	retval = copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);
//	bytes_written = bytes_to_write - retval;
//
//	pr_info("Bytes written:%d\n", bytes_written);
//	pr_info("Kernel buffer:%s\n", kernel_buffer);
//
//	return bytes_written;
//}
//
//static ssize_t device_read(struct file *file, char __user *user_buffer, size_t read_count, loff_t *offset)
//{
//	int bytes_to_read;
//	int bytes_read;
//
//	bytes_to_read = buffer_index - *offset;
//	if (bytes_to_read <= 0)
//	{
//		pr_err("Not enough space for reading\n");
//		return -ENOSPC;
//	}
//
//	int retval;
//	retval = copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);
//	
//	bytes_read = bytes_to_read - retval;
//
//	pr_info("Bytes read: %d\n", bytes_read);
//
//	return bytes_read;
//}

static loff_t device_lseek(struct file *file, loff_t offset, int cmd)
{
	pr_info("%s\n", __func__);
	loff_t new_pos = 0;

	switch(cmd) {
		case 0: //seek set
			new_pos = offset;
			break;
		case 1: //seek curr
			new_pos = file->f_pos + offset;
			break;
		case 2: //seek end
			new_pos = MAX_SIZE - offset;
			break;
	}
	if (new_pos > MAX_SIZE)
		new_pos = MAX_SIZE;
	if (new_pos < 0)
		new_pos = 0;
	file->f_pos = new_pos;
	return new_pos;
}

long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;

	pr_info("%s: Cmd:%u\tArg:%lu\n\n", __func__, cmd, arg);

	if (_IOC_TYPE(cmd) !=  MSG_MAGIC_NUMBER)
		return -ENOTTY;
	if (_IOC_NR(cmd) >  MSG_IOCTL_MAX_CMDS)
		return -ENOTTY;

	switch(cmd)
	{
		//Get length of buffer
		case MSG_IOCTL_GET_LENGTH:
			pr_info("Get Buffer Length\n");
			put_user(MAX_SIZE, (unsigned int*)arg);
			break;
		//clear buffer
		case MSG_IOCTL_CLEAR_BUFFER:
			pr_info("Clear Buffer\n");
			memset(kernel_buffer, 0, sizeof(kernel_buffer));
			break;
		//fill buffer
		case MSG_IOCTL_FILL_BUFFER:
			get_user(ch, (unsigned char*)arg);
			pr_info("Fill Buffer, char:%c\n", ch);
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			buffer_index = sizeof(kernel_buffer);
			break;
		default:
			pr_info("Unknown command:%u\n", cmd);
			return -ENOTTY;			
	}

	return 0;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
	.unlocked_ioctl = device_ioctl
};

static int test_dev_init(void)
{
	myclass = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registere, Major:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();

		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_info("Device number not registered\n");

	return 0;
}

static void test_dev_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_dev_init);
module_exit(test_dev_exit);

==> LinuxCharacterDeviceDrivers/sec3/09_unsupported_command_ioctl/unsupportedioctlcmdrepsonse.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0xe340d421, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0x9f4f34bc, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x167e7f9d, "__get_user_1" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A10C6C9091B4F2166E9CBE9");

==> LinuxCharacterDeviceDrivers/sec3/09_unsupported_command_ioctl/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ioctl_cmd.h"

int main(int argc, char **argv)
{
	char buffer[1024];
	int fd;
	unsigned int length;
	unsigned char ch = 'A';
	int i = 0;

	fd = open("/dev/msg",  O_RDWR);
	if (fd < 0)
	{
		perror("fd failed");
		exit(2);
	}

	//Get Length - 0x01
	ioctl(fd, MSG_IOCTL_GET_LENGTH, &length);
	printf("Length;%u\n", length);
	ioctl(fd, MSG_IOCTL_FILL_BUFFER, &ch);
	perror("ioctl");
	lseek(fd, 0, SEEK_SET);
	perror("lseek");
	length = read(fd, buffer, 1024);
	perror("Read");
	printf("Length:%d\n", length);
	buffer[1023] = '\0';
	printf("Buffer:%s\n", buffer);
	ioctl(fd, 4); //Unsupported command
	perror("ioctl");
	close(fd);

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/10_driver_access_ok/access_ok_macro.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <asm/uaccess.h>
#include "ioctl_cmd.h"

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char* device_name = "msg";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_written;
	int bytes_to_write;
	int available_space;

	available_space = MAX_SIZE - *offset;
	if (count > available_space)
		bytes_to_write = available_space;
	else
		bytes_to_write = count;

	if (bytes_to_write == 0)
	{
		pr_err("No available space\n");
		return -ENOSPC;
	}

	int retval;
	retval = copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);
	bytes_written = bytes_to_write - retval;

	pr_info("Bytes written:%d\n", bytes_written);
	pr_info("Kernel Buffer:%s\n", kernel_buffer);

	return bytes_written;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_to_read;
	int bytes_read;

	bytes_to_read = buffer_index - *offset;

	if (bytes_to_read == 0){
		pr_err("No available soace for reading");
		return -ENOSPC;
	}

	int retval;
	retval = copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);

	bytes_read = bytes_to_read - retval;

	pr_info("Bytes read:%d\n", bytes_read);

	return bytes_read;
}

static loff_t device_lseek(struct file *file, loff_t offset, int cmd)
{
	loff_t new_pos = 0;
	switch(cmd)
	{
		case 0: //seek set
			new_pos = offset;
			break;
		case 1: //seek curr
			new_pos = file->f_pos + offset;
			break;
		case 2: //seek end
			new_pos = MAX_SIZE - offset;
			break;
	}
	file->f_pos = offset;
	return new_pos;
}

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	long size = _IOC_SIZE(cmd);
	int retval = 0;
	
	pr_info("%s: Cmd:%u\tArg:%lu Size:%lu address:%p\n", __func__, cmd, arg, size, &ch);

    if (_IOC_TYPE(cmd) != MSG_MAGIC_NUMBER)
		return -ENOTTY;
    if (_IOC_NR(cmd) > MSG_IOCTL_MAX_CMDS)
		return -ENOTTY;

	//access_ok is kernel-oriented, so the concept of read and write is reversed
	retval = access_ok((void __user *) arg, size);
	pr_info("access_ok returned:%d\n", retval);

	switch (cmd)
	{
		case MSG_IOCTL_GET_LENGTH:
			pr_info("Get Buffer length\n");
			put_user(MAX_SIZE, (unsigned int*) arg);
			break;
		case MSG_IOCTL_CLEAR_BUFFER:
			pr_info("Clear Buffer\n");
			memset(kernel_buffer, 0, sizeof(kernel_buffer));
			break;
		case MSG_IOCTL_FILL_BUFFER:
			get_user(ch, (unsigned char*)arg);
			pr_info("Fill Buffer, char:%c\n", ch);
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			buffer_index = sizeof(kernel_buffer);
			break;
		case MSG_IOCTL_GET_ADDRESS:
			put_user(&kernel_buffer, (unsigned long long*) arg);
			pr_info("Get Address - IOCTL\n");
			break;
		default:
			pr_info("Unknown Command:%u\n", cmd);
			return -ENOTTY;
	}
	return 0;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
	.unlocked_ioctl = device_ioctl
};

static int test_init(void)
{
	myclass = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered, Major:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();

		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_info("Device number failed to register\n");

	return 0;
}

static void test_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxCharacterDeviceDrivers/sec3/10_driver_access_ok/userapp1.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ioctl_cmd.h"

int main(int argc, char **argv)
{
	char buffer[1024];
	int fd;
	unsigned int length;
	unsigned char ch = 'A';
	int i = 0;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0) {
		perror("fd failed");
		exit(2);
	}

	ioctl(fd, MSG_IOCTL_GET_ADDRESS, NULL);
	perror("ioctl");
	getchar();
	//Get Length - 0x01
	ioctl(fd, MSG_IOCTL_GET_LENGTH, &length);
	printf("Length:%u\n", length);
	ioctl(fd, MSG_IOCTL_FILL_BUFFER, &ch);
	perror("ioctl");
	lseek(fd, 0, SEEK_SET);
	perror("lseek");
	length = read(fd, buffer, 1024);
	perror("Read");
	printf("Length:%u\n", length);
	buffer[1023] = '\0';
	printf("Buffer:%s\n", buffer);
	ioctl(fd, 4);
	perror("ioctl");
	close(fd);
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/10_driver_access_ok/userapp2.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ioctl_cmd.h"

int main(int argc, char **argv)
{
	char buffer[1024];
	int fd;
	unsigned int length;
	unsigned char ch = 'A';
	int i = 0;
	unsigned long long ptr;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0)
	{
		perror("fd failed");
		exit(2);
	}

	ioctl(fd, MSG_IOCTL_GET_ADDRESS, &ptr);
	printf("%llx\n", ptr);
	perror("ioctl");
	getchar();

	ioctl(fd, MSG_IOCTL_GET_ADDRESS, ptr);
	perror("ioctl");
	getchar();

	//Get Length - 0x01
	ioctl(fd, MSG_IOCTL_GET_LENGTH, &length);
	printf("Length:%u\n", length);
	//Set character - 0x03
	ioctl(fd, MSG_IOCTL_FILL_BUFFER, &ch);
	perror("ioctl");
	lseek(fd, 0, SEEK_SET);
	perror("lseek");
	length = read(fd, buffer, 1024);
	perror("Read");
	printf("Length:%u\n", length);
	buffer[1023] = '\0';
	printf("Buffer:%s\n", buffer);
	ioctl(fd, 4);
	perror("ioctl");
	close(fd);

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/11_differentsizeioctl/passdiffsizeioctl.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "ioctl_cmd.h"

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "msg";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	buffer_index = 0;
	file->f_pos = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_to_write;
	int available_space;
	int bytes_written;

	available_space = MAX_SIZE - *offset;

	if (count > available_space)
		bytes_to_write = available_space;
	else
		bytes_to_write = count;

	if (bytes_to_write == 0) 
	{
		pr_err("Not enough availabble space\n");
		return -ENOSPC;
	}

	int retval;
	retval = copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);

	bytes_written = bytes_to_write - retval;

	pr_info("Bytes written:%d\n", bytes_written);
	pr_info("Kernel Buffer:%s\n", kernel_buffer);
	return bytes_written;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_read;
	int bytes_to_read;

	bytes_to_read = buffer_index - *offset;

	if (bytes_to_read == 0) {
		pr_err("No available space for reading");
		return -ENOSPC;
	}

	int retval;
	retval = copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);

	bytes_read = bytes_to_read - retval;

	pr_info("Bytes read:%d\n", bytes_read);
	return bytes_read;
}

static loff_t device_lseek(struct file *file, loff_t offset, int cmd)
{
	loff_t new_pos;

	switch(cmd)
	{
		case 0: //seek set
			new_pos = offset;
			break;
		case 1: //seek curr 
			new_pos = file->f_pos + offset;
			break;
		case 2: //seek end
			new_pos = MAX_SIZE - offset;
			break;
	}
	file->f_pos = new_pos;
	return new_pos;
}

long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	int retval = 0;
	long size = _IOC_SIZE(cmd);

	pr_info("%s: Cmd:%u\tArg:%lu Size:%lu add:%p\n", __func__, cmd, arg, size, &ch);

	if (_IOC_TYPE(cmd)!= MSG_MAGIC_NUMBER)
		return -ENOTTY;
	if (_IOC_NR(cmd) > MSG_IOCTL_MAX_CMDS)
		return -ENOTTY;

	//access_ok is kernel-riented so the concept of read and write is reversed

	retval = access_ok((void __user *)arg, size);
	if (!retval)
		return -EFAULT;

	switch(cmd)
	{
		case MSG_IOCTL_GET_LENGTH:
			pr_info("Get length\n");
			put_user(MAX_SIZE, (unsigned int*)arg);
			break;
		case MSG_IOCTL_CLEAR_BUFFER:
			pr_info("Clear buffer\n");
			memset(kernel_buffer, 0, sizeof(kernel_buffer)); 
			buffer_index = 0;
			break;
		case MSG_IOCTL_FILL_BUFFER:
			pr_info("Fill buffer\n");
			get_user(ch, (unsigned char *)arg);
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			kernel_buffer[1023] = '\0';
			buffer_index = sizeof(kernel_buffer);
			break;
		case MSG_IOCTL_GET_ADDRESS:
			pr_info("Get Address\n");
			put_user( 0x12345678, (unsigned long*)arg);
			break;
		default:
			pr_info("Unknown command\n");
			break;
	}

	return 0;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
	.unlocked_ioctl = device_ioctl
};

static int test_init(void)
{
	myclass = class_create(THIS_MODULE, "Myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{	
		pr_info("device number registered, Major number:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();

		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_info("Device number failed registration.\n");

	return 0;
}

static void test_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxCharacterDeviceDrivers/sec3/11_differentsizeioctl/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ioctl_cmd.h"

int main(int argc, char **argv)
{
	char buffer[1024];
	int fd;
	unsigned int length;
	unsigned char ch = 'A';
	int i = 0;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0)
	{
		perror("fd failed");
		exit(2);
	}

	ioctl(fd, MSG_IOCTL_GET_ADDRESS, &ch);
	perror("ioctl");
	getchar();
	close(fd);

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/12_signal_module_process/ioctl_signal.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <asm/uaccess.h>
#include <linux/sched/signal.h>
#include "ioctl_cmd.h"

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char * device_name = "sig";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
static int sig_pid = 0;
static struct task_struct *sig_tsk = NULL;
static int sig_to_send = SIGKILL;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	int retval = 0;
	long size = _IOC_SIZE(cmd);

	pr_info("%s: Cmd:%u\t Arg:%lu Size:%lu add:%p", __func__, cmd , arg, size, &ch);

	if (_IOC_TYPE(cmd) != SIG_MAGIC_NUMBER)
		return -ENOTTY;
	if (_IOC_NR(cmd) > SIG_IOCTL_MAX_CMDS)
		return -ENOTTY;

	//access_ok is kernel-oriented, so the concept of read and write is reversed
	retval = access_ok((void __user *)arg, size);

	pr_info("access_ok returned:%d\n", retval);
	if (!retval)
		return -EFAULT;
	
	switch(cmd)
	{
		case SIG_IOCTL_SET_PID:
			pr_info("SIG_IOCTL_SET_PID\n");
			get_user(sig_pid, (unsigned int *)arg);
			pr_info("PID:%d\n", sig_pid);
			sig_tsk = pid_task(find_vpid(sig_pid), PIDTYPE_PID);
			break;
		case SIG_IOCTL_SET_SIGNAL:
			pr_info("SIG_IOCTL_SET_SIGNAL\n");
			get_user(sig_to_send, (unsigned int *)arg);
			pr_info("Signal:%d\n", sig_to_send);
			break;
		case SIG_IOCTL_SEND_SIGNAL:
			if (!sig_tsk){
				pr_info("You haven't set the pid; using current\n");
				sig_tsk = current;
				sig_pid = (int)current->pid;
			}
			retval = send_sig(sig_to_send, sig_tsk, 0);
			pr_info("retval = %d\n", retval);
			break;
		default:
			pr_info("Unknown command:%u\n", cmd);
			return -ENOTTY;
	}

	return 0;
}

struct file_operations fops = {
	.open = device_open,
	.release = device_release,
	.unlocked_ioctl = device_ioctl
};

static int test_dev_init(void)
{
	myclass = class_create(THIS_MODULE, "newclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number register, major:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();
		if (mycdev){
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_info("Device number not registered\n");

	return 0;
}

static void test_dev_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_dev_init);
module_exit(test_dev_exit);

==> LinuxCharacterDeviceDrivers/sec3/12_signal_module_process/ioctl_signal.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0xe340d421, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0x9f4f34bc, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0xa758a7e6, "send_sig" },
	{ 0x69af1880, "current_task" },
	{ 0x53377cb8, "pid_task" },
	{ 0x5f3da946, "find_vpid" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BA58019B667BF59212DAB54");

==> LinuxCharacterDeviceDrivers/sec3/12_signal_module_process/userapp1.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ioctl_cmd.h"

int main(int argc, char **argv)
{
	int fd;

	fd = open("/dev/sig", O_RDWR);
	if (fd < 0) 
	{
		perror("fd failed");
		exit(2);
	}

	ioctl(fd, SIG_IOCTL_SEND_SIGNAL);
	perror("ioctl");
	getchar();

	close(fd);

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec3/12_signal_module_process/userapp2.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <unistd.h>
#include "ioctl_cmd.h"

void signal_handler(int sig)
{
	printf("Signal received\n");
}

int main(int argc, char **argv)
{
	int fd;
	pid_t pid = getpid();
	int snd_signal = SIGUSR1;

	printf("PROCESS PID:%d\n", pid);

	signal(SIGUSR1, signal_handler);
	fd = open("/dev/sig", O_RDWR);
	if (fd < 0) {
		perror("fd failed");
		exit(2);
	}

	
	ioctl(fd, SIG_IOCTL_SET_PID, &pid);

	ioctl(fd, SIG_IOCTL_SET_SIGNAL, &snd_signal);

	ioctl(fd, SIG_IOCTL_SEND_SIGNAL);
	perror("ioctl");
	getchar();

	close(fd);

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec4/00_driver_usage_count/driver_usage_count.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "mychardev";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;
MODULE_LICENSE("GPL");

static int device_open(struct inode* inode, struct file* file)
{
	static unsigned int driver_counter = 0;
	driver_counter++;
	pr_info("%s\n", __func__);
	pr_info("%s been used %d times since loaded\n", device_name, driver_counter);

	return 0;
}

static int device_release(struct inode* inode, struct file* file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
	return count;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
	return count;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_init(void)
{
	myclass = class_create(THIS_MODULE, "myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered, Major: %d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();
		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_info("Device number failed to register");

	return 0;
}

static void test_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxCharacterDeviceDrivers/sec4/00_driver_usage_count/driver_usage_count.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0xe340d421, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0x9f4f34bc, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "FDD3291DEA6322043EE0A24");

==> LinuxCharacterDeviceDrivers/sec4/01_access_control_proc/access_control_single_proc.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "asm/atomic.h"

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "msg";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
static atomic_t device_available = ATOMIC_INIT(1);
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	//Returns 1 if the result is zero, else 0
	if (!atomic_dec_and_test(&device_available)) {
		atomic_inc(&device_available);
		return -EBUSY;
	}

	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	atomic_inc(&device_available);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_to_read;
	int bytes_read;

	bytes_to_read = buffer_index - *offset;
	if (bytes_to_read == 0){
		pr_err("No available space\n");
		return -ENOSPC;
	}

	int retval;
	retval = copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);
	bytes_read = bytes_to_read - retval;

	pr_info("Bytes read:%d\n", retval);
	return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int available_space;
	int bytes_to_write;
	int bytes_written;

	available_space = MAX_SIZE - *offset;
	if (count > available_space)
		bytes_to_write = available_space;
	else
		bytes_to_write = count;

	if (bytes_to_write == 0){
		pr_err("No available space\n");
		return -ENOSPC;
	}

	int retval;
	retval = copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);
	bytes_written = bytes_to_write - retval;

	pr_info("Bytes written: %d\n", bytes_written);
	pr_info("Kernel Buffer: %s\n", kernel_buffer);

	return bytes_written;
}

struct file_operations fops = {
	.read = device_read,
	.open = device_open,
	.write = device_write,
	.release = device_release
};

static int dev_init(void)
{
	myclass = class_create(THIS_MODULE, "Myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered: %d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();

		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);

		}
	}
	else
		pr_err("Device number not registered\n");

	return 0;
}

static void dev_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(dev_init);
module_exit(dev_exit);

==> LinuxCharacterDeviceDrivers/sec4/01_access_control_proc/testapp.c <==
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>

void *func(void *arg)
{
	int fd;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0){
		printf("Thread id:%ld failed to open file\n", (long)pthread_self());
		return NULL;
	}
	else 
		printf("Thread id %ld succesfuly opened file\n", (long)pthread_self());
	
	sleep(5);
	write(fd, "hello", sizeof("hello"));
	close(fd);
	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, func, NULL);
	pthread_create(&thread2, NULL, func, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec4/02_user_access_control/user_access_control.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <asm/atomic.h>
#include <linux/cred.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char* device_name = "msg";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");
int usage_count = 0;
static kuid_t device_owner;

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s uid:%d\n", __func__, __kuid_val(current_uid()));

	if (usage_count && !(uid_eq(device_owner, current_uid())))
		return -EBUSY;

	if (usage_count == 0) {
		device_owner = current_uid();
		pr_info("Setting device owner to %d\n", __kuid_val(current_uid()));
	}

	usage_count++;
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	usage_count--;
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_to_read;
	int bytes_read;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	bytes_to_read = buffer_index - *offset;

	if (bytes_to_read <= 0){
		pr_err("No available space for reading\n");
		return -ENOSPC;
	}

	int retval;
	retval = copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);

	bytes_read = bytes_to_read - retval;

	*offset += bytes_read;
	buffer_index += bytes_read;
	pr_info("Bytes read:%d\n", bytes_read);

	return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_to_write;
	int available_space;
	int bytes_written;

	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *offset;
	if (count > available_space)
		bytes_to_write = available_space;
	else
		bytes_to_write = count;
		
	if (bytes_to_write == 0) {
		pr_err("No available space\n");
		return -ENOSPC;
	}

	int retval;
	retval = copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);

	bytes_written = bytes_to_write - retval;

	*offset += bytes_written;
	buffer_index += bytes_written;
	pr_info("Bytes written: %d\n", bytes_written);
	pr_info("Kernel buffer: %s\n", kernel_buffer);

	return bytes_written;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_init(void)
{
	myclass = class_create(THIS_MODULE, "thisclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered: %d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();
		
		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_err("Device number not registered\n");

	return 0;
}

static void test_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxCharacterDeviceDrivers/sec4/02_user_access_control/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char buffer[50];
	int fd;
	int length;
	int i = 0;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0) {
		perror("fd failed");
		exit(2);
	}
	printf("Open successful\n");
	write(fd, "hello", sizeof("hello"));
	getchar();
	close(fd);
}

==> LinuxCharacterDeviceDrivers/sec4/03_using_capabilities/init_module.c <==
#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// init_module is called by the insmod function. this bypasses the wrapped and calls the systemcall directly using a hash define
#define init_module(module_image, len, param_values) syscall(__NR_init_module, module_image, len, param_values)

int main(int argc, char **argv) {
	const char *params = "";
	int fd, use_finit;
	size_t image_size;
	struct stat st;
	void *image;

	fd = open(argv[1], O_RDONLY);
	fstat(fd, &st);
	image_size = st.st_size;
	image = malloc(image_size);
	read(fd, image, image_size);
	close(fd);
	if (init_module(image, image_size, params) != 0) {
		perror("init_module");
		return EXIT_FAILURE;
	}
	free(image);
	return EXIT_SUCCESS;
}

==> LinuxCharacterDeviceDrivers/sec4/03_using_capabilities/userapp.c <==
#include <stdio.h>
#include <sys/fcntl.h>

int main()
{
	int fd;

	fd = open("/etc/shadow", O_RDONLY);
	perror("fd"); //returns sucess when cap_dac_override set, permission denied when cap_dac_ovverride removed
	return 0;
}

==> LinuxCharacterDeviceDrivers/sec4/04_using_capabilities/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ioctl_cmd.h"

int main(int argc, char **argv)
{
	int fd;

	fd = open("/dev/sig", O_RDWR);
	if (fd < 0){
		perror("fd failed");
		exit(2);
	}

	ioctl(fd, SIG_IOCTL_SEND_SIGNAL);
	perror("ioctl");
	getchar();

	close(fd);
}

==> LinuxCharacterDeviceDrivers/sec4/04_using_capabilities/using_capabilities.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <asm/uaccess.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>
#include "ioctl_cmd.h"

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "sig";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

static int sig_pid = 0;
static struct task_struct *sig_tsk = NULL;
static int sig_tosend = SIGKILL;

#define MAX_SIZE 1024
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	int retval = 0;
	long size = _IOC_SIZE(cmd);
	
	pr_info("%s: Cmd:%u\tArg:%luSize:%lu add:%p\n", __func__, cmd, arg, size, &ch);

	if (_IOC_TYPE(cmd) != SIG_MAGIC_NUMBER) return -ENOTTY;
	if (_IOC_NR(cmd) > SIG_IOCTL_MAX_CMDS) return -ENOTTY;

	//access_ok is kernel-oriented, so the concept fo read and write is reversed

	retval = access_ok((void __user*)  arg, size);

	pr_info("access_ok returned:%d\n", retval);
	if (!retval)
		return -EFAULT;
	
	switch(cmd)
	{
		case SIG_IOCTL_SET_PID:
			pr_info("SIG_IOCTL_SET_PID\n");
			get_user(sig_pid, (unsigned int*)arg);
			pr_info("PID:%d\n", sig_pid);
			sig_tsk = pid_task(find_vpid(sig_pid), PIDTYPE_PID);
			break;
		case SIG_IOCTL_SET_SIGNAL:
			pr_info("SIG_IOCTL_SET_SIGNAL\n");
			get_user(sig_tosend, (unsigned int*)arg);
			pr_info("signal:%d\n", sig_tosend);
			break;
		case SIG_IOCTL_SEND_SIGNAL:
			pr_info("SIG_IOCTL_SEND_SIGNAL\n");
			if (!capable(CAP_SYS_ADMIN))
				return -EPERM;
			if (!sig_tsk) {
				pr_info("You haven't set the pid; using current\n");
				sig_tsk = current;
				sig_pid = (int)current->pid;
			}
			retval = send_sig(sig_tosend, sig_tsk, 0);
			pr_info("retval = %d\n", retval);
			break;
		default:
			pr_info("Unknown Command:%u\n", cmd);
			return -ENOTTY;
	}
	return 0;
}

struct file_operations fops = {
	.open = device_open,
	.release = device_release,
	.unlocked_ioctl = device_ioctl
};

static int dev_init(void) {
	myclass = class_create(THIS_MODULE, "thisclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) 
	{
		pr_info("Device number registered, Major:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();

		if (mycdev){
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_err("device number not registered\n");

	return 0;
}

static void dev_exit(void) {
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(dev_init);
module_exit(dev_exit);

==> LinuxCharacterDeviceDrivers/sec4/05_open_flags/open_flags.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <asm/atomic.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char* device_name = "msg";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
static atomic_t device_available = ATOMIC_INIT(1);
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	
	pr_info("MODE:%x\n", (file->f_flags & O_ACCMODE));
	if ((file->f_flags & O_ACCMODE) == O_WRONLY) 
		pr_info("O_WRONLY MODE\n");
	else if ((file->f_flags & O_ACCMODE) == O_RDONLY)
		pr_info("O_RDONLY MODE\n");
	else
		pr_info("MODE:%x\n", (file->f_flags & O_ACCMODE));

	atomic_dec(&device_available);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	atomic_inc(&device_available);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_read = 0;
	int bytes_to_read = 0;

	bytes_to_read = buffer_index - *offset;

	if (bytes_to_read <= 0){
		pr_err("No available space for reading\n");
		return -ENOSPC;
	}

	if (count < bytes_to_read)
		bytes_to_read = count;

	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);
	pr_info("Bytes Read: %d\n", bytes_read);
	*offset += bytes_read;

	return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_to_write = 0;
	int bytes_written = 0;
	int available = 0;

	available = MAX_SIZE - *offset;

	if (count > available)
		bytes_to_write = available;
	else
		bytes_to_write = count;

	if (bytes_to_write <= 0){
		pr_err("no available space for writing\n");
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);
	
	pr_info("Bytes written: %d\n", bytes_written);
	pr_info("Kernel Buffer: %s\n", kernel_buffer);

	*offset += bytes_written;
	buffer_index += bytes_written;

	return bytes_written;
}

static loff_t device_lseek(struct file *file, loff_t offset, int cmd)
{	
	loff_t new_pos = 0;

	switch(cmd) {
		case 0: //seek set
			new_pos = offset;
			break;
		case 1: //seek curr
			new_pos = file->f_pos + offset;
			break;
		case 2: //seek end
			new_pos = MAX_SIZE - offset;
			break;
	}

	if (new_pos > MAX_SIZE)
		new_pos = MAX_SIZE;
	if (new_pos < 0)
		new_pos = 0;
	file->f_pos = new_pos;
	return new_pos;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
};

static int init_dev(void)
{
	myclass = class_create (THIS_MODULE, "meyahnclass");
	 if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	 {
		pr_info("registered Device number: %d", MAJOR(devicenumber)); 
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();

		if (mycdev) {
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);;
		}
	 }
	 else
	 	pr_err("device registration failed\n");

	return 0;
}

static void exit_dev(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(init_dev);
module_exit(exit_dev);

==> LinuxCharacterDeviceDrivers/sec4/06_no_close_by_user/userapp.c <==
#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>

void *func(void *arg)
{
	int fd;

	fd = open("/dev/msg", O_RDWR);
	sleep(5);
	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, func, NULL);
	pthread_create(&thread2, NULL, func, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}

==> LinuxCharacterDeviceDrivers/sec4/06_no_close_by_user/user_doesnt_close.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <asm/atomic.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "msg";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
static atomic_t device_available = ATOMIC_INIT(1);
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);

	pr_info("MODE:%x\n", (file->f_flags & O_ACCMODE));
	if ((file->f_flags & O_ACCMODE) == O_WRONLY)
		pr_info("O_WRONLY MODE\n");
	else if ((file->f_flags & O_ACCMODE) == O_RDONLY)
		pr_info("O_RDONLY MODE\n");
	else
		pr_info("MODE:%x\n", (file->f_flags & O_ACCMODE));

	atomic_dec(&device_available);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s", __func__);
	atomic_inc(&device_available);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_read;
	int available;
	int bytes_to_read;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	available = buffer_index - *offset;

	if (available <= 0) {
		pr_err("Not enough space for reading\n");
		return -ENOSPC;
	}

	if (count > available)
		bytes_to_read = available;
	else
		bytes_to_read = count;

	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);

	pr_info("Bytes read: %d", bytes_read);
	
	return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int bytes_written;
	int available;
	int bytes_to_write;

	pr_info("%s write offset:%lld\n", __func__, *offset);

	available = MAX_SIZE - *offset;

	if (count > available)
		bytes_to_write = available;
	else
		bytes_to_write = count;
	
	if (bytes_to_write <= 0){
		pr_err("Not enough space for writing\n");
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);

	pr_info("Bytes written: %d\n", bytes_written);
	pr_info("Kernel buffer: %s\n", kernel_buffer);

	return bytes_written;
}

static loff_t device_lseek(struct file *file, loff_t offset, int cmd)
{
	loff_t new_pos = 0;

	switch(cmd) {
		case 0: //seek set
			new_pos = offset;
			break;
		case 1: //seek curr
			new_pos = file->f_pos + offset;
			break;
		case 2:	//seek end
			new_pos = MAX_SIZE - offset;
			break;
	}

	if (new_pos > MAX_SIZE)
		new_pos = MAX_SIZE;
	if (new_pos < 0)
		new_pos = 0;
	file->f_pos = new_pos;
	return new_pos;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
};


static int init_dev(void) 
{
	myclass = class_create(THIS_MODULE, "meynclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered, Major", MAJOR(devicenumber));

		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();

		if (mycdev) 
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_err("Device number not registered\n");

	return 0;
}

static void exit_dev(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(init_dev);
module_exit(exit_dev);

==> LinuxCharacterDeviceDrivers/sec4/06_no_close_by_user/user_doesnt_close.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0xe340d421, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0x9f4f34bc, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "68657623FEB4C8119CEC31E");

==> LinuxCharacterDeviceDrivers/sec4/07_misc_driver/misc_driver.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <asm/uaccess.h>
#include <linux/miscdevice.h>
#include "ioctl_cmd.h"

#define DEVICE_NAME "msg"
#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	int available = 0;
	int bytes_written = 0;
	int bytes_to_write = 0;

	pr_info("%s, offset: %lld", __func__, *offset);

	available = MAX_SIZE - *offset;

	if (count > available)
		bytes_to_write = available;
	else
		bytes_to_write = count;

	if (bytes_to_write <= 0){
		pr_err("Not enough space for writing\n");
		return -ENOSPC;
	}

	bytes_written = copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);

	pr_info("Bytes written: %d", bytes_written);
	pr_info("Kernel Buffer: %s", kernel_buffer);

	return bytes_written;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	int available = 0;
	int bytes_read = 0;
	int bytes_to_read = 0;

	pr_info("%s, offset: %lld", __func__, *offset);

	available = buffer_index - *offset;

	if (count > available)
		bytes_to_read = available;
	else
		bytes_to_read = count;

	if (bytes_to_read <= 0){
		pr_err("Not enough space for reading\n");
		return -ENOSPC;
	}

	bytes_read = copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);

	pr_info("Bytes read: %d", bytes_read);

	return bytes_read;
}

static loff_t device_lseek(struct file *file, loff_t offset, int cmd)
{
	loff_t new_pos;

	switch(cmd){
		case 0: //seek set
			new_pos = offset;
			break;
		case 1: //seek curr
			new_pos = file->f_pos + offset;
			break;
		case 2: //see end
			new_pos = MAX_SIZE - offset;
			break;
	}

	if (new_pos > MAX_SIZE)
		new_pos = MAX_SIZE;
	if (new_pos <= 0)
		new_pos = 0;
	file->f_pos = new_pos;
	return new_pos;
}

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	int retval = 0;
	long size = _IOC_SIZE(cmd);

	pr_info("%s: Cmd:%u\tArg:%lu Size:%lu add:%p\n", __func__, cmd, arg, size, &ch);

	if (_IOC_TYPE(cmd) != MSG_MAGIC_NUMBER) return -ENOTTY;
	if (_IOC_NR(cmd) > MSG_IOCTL_MAX_CMDS) return -ENOTTY;
	
	//access_ok is kernel oriented so the concept of read and write is reversed

	retval = access_ok((void __user *)arg, size);

	pr_info("access_ok returned:%d\n", retval);
	if (!retval)
		return -EFAULT;

	switch(cmd){
		case MSG_IOCTL_GET_LENGTH:
			pr_info("Get Buffer Length\n");
			put_user(MAX_SIZE, (unsigned int*) arg);
			break;
		case MSG_IOCTL_CLEAR_BUFFER:
			pr_info("MSG_IOCTL_CLEAR_BUFFER\n");
			memset(kernel_buffer, 0, sizeof(kernel_buffer));
			break;
		case MSG_IOCTL_FILL_BUFFER:
			pr_info("MSG_IOCTL_FILL_BUFFER\n");
			get_user(ch, (unsigned long*) arg);
			pr_info("Fill character is %s\n");
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			buffer_index = sizeof(kernel_buffer);
			break;
		case MSG_IOCTL_GET_ADDRESS:
			put_user(0x12345678, (unsigned int*) arg);
			pr_info("MSG_IOCTL_GET_ADDRESS\n");
			break;

		default:
			pr_info("Unknown Command:%u\n", cmd);
			return -ENOTTY;
	}
	return 0;
}

struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
	.unlocked_ioctl = device_ioctl,
};

static struct miscdevice my_misc_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVICE_NAME,
	.fops = &fops
};


static int test_hello_init(void)
{
	if(misc_register(&my_misc_device)) {
		pr_err("Couldnt register_device");
		return -EBUSY;
	}
	
	pr_info("Succeeded in registering char device %s\n", DEVICE_NAME);
	return 0;
}

static void test_hello_exit(void)
{
	misc_deregister(&my_misc_device);
	pr_info("device unregistered\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);

==> LinuxCharacterDeviceDrivers/sec4/07_misc_driver/misc_driver.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6e2db325, "misc_deregister" },
	{ 0x761c978, "misc_register" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6d334118, "__get_user_8" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9030BF155910D523F3CFE2C");

==> LinuxCharacterDeviceDrivers/sec4/07_misc_driver/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ioctl_cmd.h"

int main(int argc, char **argv)
{
	char buffer[1024];
	int fd;
	unsigned int length;
	int i = 0;
	unsigned long addr;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0) {
		perror("fd failed");
		exit(2);
	}

	printf("Size:%d\n", _IOC_SIZE(MSG_IOCTL_GET_ADDRESS));
	printf("cmd:%u\n", MSG_IOCTL_GET_ADDRESS);

	ioctl(fd, MSG_IOCTL_GET_ADDRESS, &addr); 
	perror("ioctl");
	getchar();
	printf("address:%x\n", addr);

	close(fd);
}

==> LinuxCommunicatingWithHardware/00_Requesting_IO_Ports/RequestingIOPorts.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>

#define MY_BASEPORT 0x0062
#define NUMBER_PORTS 2

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	if (!request_region(MY_BASEPORT, NUMBER_PORTS, "myports")) {
		pr_info("request region failed for myports\n");
		return -1;
	}
	else 
		pr_info("request region succcess for myports\n");
	

	return 0;
}

static void mod_exit(void)
{
	release_region(MY_BASEPORT, NUMBER_PORTS);
}

module_init(mod_init);
module_exit(mod_exit);

==> LinuxCommunicatingWithHardware/01_Read_Differs_From_Write_Value/ReadDiffersFromWriteValue.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/io.h>

#define MY_BASEPORT 0x0063
#define NUMBER_PORTS 1

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	if (!request_region(MY_BASEPORT, NUMBER_PORTS, "myport")) 
	{
		pr_info("Request region failed for myport\n");
		return -1;
	} 
	else 
	{
		pr_info("request region success for myport\n");
		outb(0xb1, MY_BASEPORT);
	}

	return 0;
}

//The value read is not the same as the value being written. Request_region is only
//a book keeping routine, which keeps track of which drivers are using which port
//addresses. A port is not necessarily readable and writable, it could be read-only
//or write-only
static void mod_exit(void)
{
	unsigned int a;
	a = inb(MY_BASEPORT);
	pr_info("value at %02x is %02x\n", MY_BASEPORT, a);
	release_region(MY_BASEPORT, NUMBER_PORTS);
}

module_init(mod_init);
module_exit(mod_exit);

==> LinuxKernelProgramming/array_arguments_init/array_arguments.c <==
       > #include <linux/kernel.h>
       > #include <linux/module.h>
       > #include <linux/moduleparam.h>
       > 
       > /*	We can add multiple parameters using module_param_array macro declared in moduleparam.h file
       > 	#define module_param_array(name, type, nump, perm)
       > 		 module_param_named(name, name, type, perm)
       > 
       > 	name: Name of the variable, type: Type of the variable: charp(char *), bool, 
       > 	type: Type of the variable: charp, bool, invbool, int, long, short, uint, ulong, ushort
       > 	nump: optional pointer filled in with the number written
       > 	perm: Permissions for the sysfs entry e.g. S_IRUGO: Only read by all users
       > 	You can also use numeric values like 0644 for permission entry
       > */
       > 
       > MODULE_LICENSE("GPL");
       > int param_array[4];
       > static int argc_count = 0;
       > module_param_array(param_array, int, &argc_count, S_IWUSR|S_IRUSR);
       > 
       > static int test_arguments_init(void)
       > {
       >     int i = 0;
       > 	printk(KERN_INFO"%s\n", __func__);
       > 	printk(KERN_INFO"%s: argc Count:%d\n", __func__, argc_count);
       > 	for (i = 0; i < sizeof(param_array)/sizeof(param_array[i]); i++)
       > 		printk(KERN_INFO"%d: %d\n", i, param_array[i]);
       > 	return 0;
       > }
       > 
       > static void test_arguments_exit(void)
       > {
       > 	printk(KERN_INFO"%s: In exit\n", __func__);
       > }
       > 
       > module_init(test_arguments_init);
       > module_exit(test_arguments_exit);
       > MODULE_AUTHOR("LESLIE");
       > MODULE_DESCRIPTION("Argument Passing Example");

==> LinuxKernelProgramming/array_arguments_init/array_arguments.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x19fdd0c3, "module_layout" },
	{ 0x69e052b6, "param_ops_int" },
	{ 0x39a5e323, "param_array_ops" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9CE02A6A18842E1F03D7F01");

==> LinuxKernelProgramming/exporting_variables/symbol1.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/jiffies.h>
#include "symbol_test.h"

MODULE_LICENSE("GPL");

static int test_symbol_init(void)
{
	pr_info("%s: In init\ta:%d\te:%c\n", __func__, foo.a, foo.e);
	return 0;
}

static void test_symbol_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(test_symbol_init);
module_exit(test_symbol_exit);

==> LinuxKernelProgramming/exporting_variables/symbol1.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x19fdd0c3, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0x5a4e81c8, "foo" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "symbol_export");


MODULE_INFO(srcversion, "BC581669B32525D6BA9A656");

==> LinuxKernelProgramming/exporting_variables/symbol_export.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/jiffies.h>
#include "symbol_test.h"

MODULE_LICENSE("GPL");

struct test foo;
EXPORT_SYMBOL(foo);

static int test_export_init(void)
{
	foo.a = 5;
	foo.b = 6;
	foo.c = 7;
	foo.d = 8;
	foo.e = '9';
	pr_info("%s: In init\n", __func__);
	return 0;
}

static void test_export_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(test_export_init);
module_exit(test_export_exit);

==> LinuxKernelProgramming/exporting_variables/symbol_export.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x19fdd0c3, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "FD1B0074D79B477E8269B99");

==> LinuxKernelProgramming/exportkernelsymbol/symbol_export.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/jiffies.h>

MODULE_LICENSE("GPL");

void print_jiffies(void)
{
	printk(KERN_INFO"%s: Jiffies:%ld\n", __func__, jiffies);
}

static int test_export_init(void)
{
	printk(KERN_INFO"%s: In init\n", __func__);
	return 0;
}

static void test_export_exit(void)
{
	printk(KERN_INFO"%s: In exit\n", __func__);
}

EXPORT_SYMBOL_GPL(print_jiffies);

module_init(test_export_init);
module_exit(test_export_exit);

==> LinuxKernelProgramming/exportkernelsymbol/symbol_export.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x19fdd0c3, "module_layout" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F2A63A7442D479898AAD45C");

==> LinuxKernelProgramming/module_metadata/hello.c <==
// 1. Include header files necessary
#include <linux/kernel.h>
#include <linux/module.h>

// 2. Module metadata
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello world");
MODULE_AUTHOR("Leslie");
MODULE_VERSION("1.1.1");
//MODULE_INFO can be used to define custom tags that can be accessed with modinfo
MODULE_INFO(OS, "Ubuntu-Linux");
// 3. Write initialization and exit functions 
static int test_hello_init(void) //return type of initialization function is int
{
	printk(KERN_INFO"%s: In init\n", __func__);
	return 0;
}

static void test_hello_exit(void) //return type of exit function is void
{
	printk(KERN_INFO"%s: In exit\n", __func__);
	/*INFO specifies kernel log level: EMERG, ALERT, CRIT, ERR, WARNING, NOTICE, INFO, DEBUG in order of decreasing priority
	defined in kernel.h. printk() writes to the kernel buffer, whereas printf() writes to the standard output*/
}

// 4. Specify functions as initialization and cleanup functions
module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxKernelProgramming/module_metadata/hello.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8B592141BAB4774FF02E2B6");

==> LinuxKernelProgramming/module_stacking/module1.c <==
//#include <linux/kernel.h>
//#include <linux/module.h>
//
//MODULE_LICENSE("GPL");
//
//int myadd(int a, int b)
//{
//	pr_info("%s: Adding: %d with %d\t Result:%d\n", __func__, a, b, a+b);
//	return a+b;
//}
//
//EXPORT_SYMBOL(myadd);
//static int module1_init(void)
//{
//	pr_info("%s: In init\n", __func__);
//	return 0;
//}
//
//static void module1_exit(void)
//{
//	pr_info("%s: In exit\n", __func__);
//}
//
//module_init(module1_init);
//module_exit(module1_exit);

#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

int myadd(int a, int b)
{
    pr_info("%s: Adding %d with %d\t Result:%d\n",
		    __func__, a, b, a+b);
    return a+b;
}

EXPORT_SYMBOL(myadd);

static int module1_init(void)
{
    pr_info("%s: In init\n", __func__);
    return 0;
}

static void module1_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(module1_init);
module_exit(module1_exit);

==> LinuxKernelProgramming/module_stacking/module1.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x19fdd0c3, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BB5CA390F5252C1F8332360");

==> LinuxKernelProgramming/module_stacking/module2.c <==
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

extern int myadd(int a, int b);

static int module2_init(void)
{
	pr_info("%s: In init\n", __func__);
	pr_info("%s: Add:%d\n", __func__, myadd(3, 5));
	return 0;
}

static void module2_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(module2_init);
module_exit(module2_exit);

==> LinuxKernelProgramming/module_stacking/module2.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x19fdd0c3, "module_layout" },
	{ 0xfc05b364, "myadd" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "module1");


MODULE_INFO(srcversion, "BC4718E129FAA4410AACED9");

==> LinuxKernelProgramming/Nolicense/fakelicense.c <==
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("abc");
//the module_init() and module_exit(0 functions simply alias their arguments to functions with these type definitions, thus they will
//still be called on module initialisation and cleanup
int moduleinit_(void)
{
	printk(KERN_INFO"%s: In init\n", __func__);
	return 0;
}

void modulecleanup_(void)
{
	printk(KERN_INFO"%s: In exit\n", __func__);
}

module_init(moduleinit_);
module_exit(modulecleanup_);

==> LinuxKernelProgramming/Nolicense/gpllicense.c <==
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

int myadd(int a, int b)
{
    pr_info("%s: Adding %d with %d\t Result:%d\n",
		    __func__, a, b, a+b);
    return a+b;
}

EXPORT_SYMBOL_GPL(myadd);

//the module_init() and module_exit(0 functions simply alias their arguments to functions with these type definitions, thus they will
//still be called on module initialisation and cleanup
int moduleinit_(void)
{
	printk(KERN_INFO"%s: In init\n", __func__);
	return 0;
}

void modulecleanup_(void)
{
	printk(KERN_INFO"%s: In exit\n", __func__);
}

module_init(moduleinit_);
module_exit(modulecleanup_);

==> LinuxKernelProgramming/Nolicense/nolicense.c <==
#include <linux/kernel.h>
#include <linux/module.h>

//the module_init() and module_exit(0 functions simply alias their arguments to functions with these type definitions, thus they will
//still be called on module initialisation and cleanup
int moduleinit_(void)
{
	printk(KERN_INFO"%s: In init\n", __func__);
	return 0;
}

void modulecleanup_(void)
{
	printk(KERN_INFO"%s: In exit\n", __func__);
}

module_init(moduleinit_);
module_exit(modulecleanup_);

==> LinuxKernelProgramming/Nolicense/nolicense.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6C5B4B450F9BE2B1FC97F6A");

==> LinuxKernelProgramming/nonGPL-GPLaccess/module1.c <==
//#include <linux/kernel.h>
//#include <linux/module.h>
//
//MODULE_LICENSE("GPL");
//
//int myadd(int a, int b)
//{
//	pr_info("%s: Adding: %d with %d\t Result:%d\n", __func__, a, b, a+b);
//	return a+b;
//}
//
//EXPORT_SYMBOL(myadd);
//static int module1_init(void)
//{
//	pr_info("%s: In init\n", __func__);
//	return 0;
//}
//
//static void module1_exit(void)
//{
//	pr_info("%s: In exit\n", __func__);
//}
//
//module_init(module1_init);
//module_exit(module1_exit);

#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

int myadd(int a, int b)
{
    pr_info("%s: Adding %d with %d\t Result:%d\n",
		    __func__, a, b, a+b);
    return a+b;
}

EXPORT_SYMBOL(myadd);

static int module1_init(void)
{
    pr_info("%s: In init\n", __func__);
    return 0;
}

static void module1_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(module1_init);
module_exit(module1_exit);

==> LinuxKernelProgramming/nonGPL-GPLaccess/module1.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BB5CA390F5252C1F8332360");

==> LinuxKernelProgramming/nonGPL-GPLaccess/module2.c <==
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("Proprietary");

extern int myadd(int a, int b);

static int module2_init(void)
{
	pr_info("%s: In init\n", __func__);
	pr_info("%s: Add:%d\n", __func__, myadd(3, 5));
	return 0;
}

static void module2_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(module2_init);
module_exit(module2_exit);

==> LinuxKernelProgramming/nonGPL-GPLaccess/module2.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xfc05b364, "myadd" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "module1");


MODULE_INFO(srcversion, "064BF9B17028E62812D55C5");

==> LinuxKernelProgramming/sec10/0_online_cpus/online_cpus.c <==
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/cpumask.h>

static int __init mod_init(void)
{
	pr_info("number of online cpus is %d\n", num_online_cpus());
	return 0;
}

static void __exit mod_exit(void)
{
}

module_init(mod_init);
module_exit(mod_exit);
MODULE_LICENSE("GPL");

==> LinuxKernelProgramming/sec10/1_print_tasks/tasks.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");

char buffer[256];
char* get_task_state(long state)
{
	switch(state) {
		case TASK_RUNNING:
			return "TASK_RUNNING";
		case TASK_INTERRUPTIBLE:
			return "TASK_INTERRUPTIBLE";
		case TASK_UNINTERRUPTIBLE:
			return "TASK_UNINTERRUPTIBLE";
		case __TASK_STOPPED:
			return "__TASK_STOPPED";
		case __TASK_TRACED:
			return "__TASK_TRACED";
		default:
		{
			sprintf(buffer, "Unknown Type:%ld\n", state);
			return buffer;
		}
	}
}

static int test_tasks_init(void)
{
	struct task_struct *task_list;
	unsigned int process_count = 0;
	pr_info("%s: In init\n", __func__);
	/*define for_each_process(p) \
		for (p = &init_task; (p = next_task(p)) != &init_task; )
	*/
	for_each_process(task_list) {
		pr_info("Process: %s\t PID:[%d]\t State:%s\n", task_list->comm, task_list->pid, get_task_state(task_list->state));
		process_count++;
	}
	pr_info("Number of processes:%u\n", process_count);
	return 0;
}

static void test_tasks_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}


module_init(test_tasks_init);
module_exit(test_tasks_exit);

==> LinuxKernelProgramming/sec10/1_print_tasks/tasks.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xce75c3fc, "init_task" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1CB0A0C423DAE414C22FF86");

==> LinuxKernelProgramming/sec10/2_current_task/current.c <==
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <asm/current.h>

MODULE_LICENSE("GPL");

static int current_init(void)
{
	printk("current pid: %d , current process: %s\n", current->pid, current->comm);
	return 0;
}

static void current_exit(void)
{
	printk("current pid: %d , current process: %s\n", current->pid, current->comm);
}

module_init(current_init);
module_exit(current_exit);

==> LinuxKernelProgramming/sec10/2_current_task/current_tasks.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");

char buffer[256];
char* get_task_state(long state)
{
	switch(state) {
		case TASK_RUNNING:
			return "TASK_RUNNING";
		case TASK_INTERRUPTIBLE:
			return "TASK_INTERRUPTIBLE";
		case TASK_UNINTERRUPTIBLE:
			return "TASK_UNINTERRUPTIBLE";
		case __TASK_STOPPED:
			return "__TASK_STOPPED";
		case __TASK_TRACED:
			return "__TASK_TRACED";
		default:
		{
			sprintf(buffer, "Unknown Type:%ld\n", state);
			return buffer;
		}
	}
}

static int test_tasks_init(void)
{
	struct task_struct *task;
	unsigned int process_count = 0;
	pr_info("%s: In init\n", __func__);
	/*define for_each_process(p) \
		for (p = &init_task; (p = next_task(p)) != &init_task; )
	*/
	for(task = current; task != &init_task; task = task->parent) {
		pr_info("Process: %s\t PID:[%d]\t State:%s\n", task->comm, task->pid, get_task_state(task->state));
		process_count++;
	}
	pr_info("Number of processes:%u\n", process_count);
	return 0;
}

static void test_tasks_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}


module_init(test_tasks_init);
module_exit(test_tasks_exit);

==> LinuxKernelProgramming/sec10/2_current_task/current_tasks.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xce75c3fc, "init_task" },
	{ 0xc5850110, "printk" },
	{ 0x69af1880, "current_task" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C45115DD7A6D15A5FCAE5C5");

==> LinuxKernelProgramming/sec10/3_find_tasks/find_tasks.c <==
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

#include <linux/sched.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
static unsigned int PID = 1;
module_param(PID, uint, 0400);

void print_task(struct task_struct *task)
{
	printk("process: %s, parent process: %s\n", task->comm, task->parent->comm);
}

static int init_find_task(void)
{
	struct task_struct *task = NULL;
	
	for_each_process(task) {
		if (task->pid == (pid_t)PID) {
			print_task(task);
		}
	}

	return 0;
}

static void exit_find_task(void)
{
	printk("GOOD BYE:find_task!!\n");
}

module_init(init_find_task);
module_exit(exit_find_task);

==> LinuxKernelProgramming/sec10/3_find_tasks/find_tasks.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0x3d58fb01, "param_ops_uint" },
	{ 0xce75c3fc, "init_task" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9DFC5FFEEBE92573A117E2F");

==> LinuxKernelProgramming/sec10/4_vmarea/vmarea.c <==
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/mm.h>
#include <linux/mm_types.h>
#include <linux/list.h>
#include <linux/proc_fs.h>
#include <linux/version.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
static unsigned int PID = 1;
module_param(PID, uint, 0400);

struct dentry* file_entry(struct file *pfile)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 19, 0)
	return pfile->f_path.dentry;
#else
	return pfile->f_dentry;
#endif
}

void print_vm_file(struct vm_area_struct *vmarea)
{
	struct file 		*vmfile = NULL;
	struct dentry 		*den = NULL;
	struct dentry 		*pPath = NULL;

	char				file[255];
	char 				*start = NULL, *end = NULL;

	if (vmarea->vm_file == NULL)
	{
		printk("\tIt's not a file map\n");
	}
	else // the vm_files
	{
		vmfile = vmarea->vm_file;
		den = file_entry(vmfile);
		// i find in linux-kernel-3.16
        //  http://lxr.free-electrons.com/source/include/linux/fs.h?v=3.16#L753
        //  struct path             f_path;
        //  #define f_dentry        f_path.dentry


		if (den != NULL)
		{
			printk(KERN_CONT"\t");
			memset(file, '\0', sizeof(file));
			for (pPath  = den; pPath != NULL; pPath = pPath->d_parent)
			{
				if(strcmp(pPath->d_name.name, "/") != 0)
				{
					strcpy(file + strlen(file),  pPath->d_name.name);
					strcpy(file + strlen(file), "/");
					continue;
				}
				else
				{
					break;
				}
			}
			do 
			{
				end = file + strlen(file) - 1;
				for (start = end - 1; *start != '/' && start > file; start --);

				if (*start == '/')
				{
					start++;
				}
				*end = '\0';

				printk(KERN_CONT"%s", start);
				*start = '\0';
			} while(start > file);
		}
		printk("\n");
	}
}

void print_vmarea_node(struct vm_area_struct *vmnode)
{
	printk("0x%lx - 0x%lx\t", vmnode->vm_start, vmnode->vm_end);
	if (vmnode->vm_flags & VM_READ)
		printk(KERN_CONT"r");
	else
		printk(KERN_CONT"-");

	if (vmnode->vm_flags & VM_WRITE)
		printk(KERN_CONT"w");
	else
		printk(KERN_CONT"-");

	if (vmnode->vm_flags & VM_EXEC)
		printk(KERN_CONT"x");
	else
		printk(KERN_CONT"-");

	if (vmnode->vm_flags & VM_SHARED)
		printk(KERN_CONT"s");
	else
		printk(KERN_CONT"p");

	print_vm_file(vmnode);
}

static void print_vm_list(struct vm_area_struct *vmlist)
{
	struct vm_area_struct		*vmnode = vmlist;

	while (vmnode != NULL)
	{
		print_vmarea_node(vmnode);

		vmnode = vmnode->vm_next;
	}
}

void print_mm_struct(struct mm_struct *mm)
{
	printk("code : [0x%lx, 0x%lx]\n", mm->start_code, mm->end_code);
	printk("data : [0x%lx, 0x%lx]\n", mm->start_data, mm->end_data);
	printk("heap : [0x%lx, 0x%lx]\n", mm->start_brk, mm->brk);
	printk("stack : [0x%lx]\n", mm->start_stack);

	print_vm_list(mm->mmap);
}

static int init_find_task(void)
{
	struct task_struct 		*task = NULL;
	
	for_each_process(task)
	{
		if (task->pid == (pid_t)PID)
		{
			print_mm_struct(task->mm);
		}
	}

	return 0;
}

static void exit_find_task(void)
{
	printk("GOOD BYE:find_task!!\n");
}

module_init(init_find_task);
module_exit(exit_find_task);

==> LinuxKernelProgramming/sec10/4_vmarea/vmarea.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0x3d58fb01, "param_ops_uint" },
	{ 0xce75c3fc, "init_task" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0xe914e41e, "strcpy" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xa916b694, "strnlen" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "155EE8E1A963FB9AF14946E");

==> LinuxKernelProgramming/sec11/0_kthread_create/kthread_create.c <==
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

static struct task_struct *my_thread;

int thread_function(void *pv)
{
	int i=0;
	while (!kthread_should_stop())
	{
		printk(KERN_INFO"In thread Function %d\n", i++);
		msleep(1000);
	}	
	return 0;
}

static int __init my_driver_init(void)
{
	my_thread = kthread_create(thread_function, NULL, "myThread");
	if(my_thread) 
	{
		wake_up_process(my_thread);
		return 0;
	}
	else
	{
		printk(KERN_ERR"cannot create thread\n");
		return -1;
	}
}

void __exit my_driver_exit(void)
{
	kthread_stop(my_thread);
	printk(KERN_INFO"Device Driver Remove.. Done!!\n");
}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_LICENSE("GPL");

==> LinuxKernelProgramming/sec11/1_kthread_run/kthread_run.c <==
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

struct task_struct *my_thread;
char buffer[256];
char* get_task_state(long state)
{
	switch(state) {
		case TASK_RUNNING:
			return "TASK_RUNNING";
		case TASK_INTERRUPTIBLE:
			return "TASK_INTERRUPTIBLE";
		case TASK_UNINTERRUPTIBLE:
			return "TASK_UNINTERRUPTIBLE";
		case __TASK_STOPPED:
			return "__TASK_STOPPED";
		case __TASK_TRACED:
			return "__TASK_TRACED";
		default:
		{
			sprintf(buffer, "Unknown Type:%ld\n", state);
			return buffer;
		}
	}
}

int print_running_thread(void *pv)
{
	while (!kthread_should_stop())
	{
		struct task_struct *task_list;
		for_each_process(task_list)
		{
			if (task_list->state == TASK_RUNNING)
				pr_info("Process: %s\tPID:[%d]\tState:%s\n", task_list->comm, task_list->pid, get_task_state(task_list->state));
		}
		msleep(500);
	}	
	return 0;
}

static int my_driver_init(void)
{
	pr_info("%s: In init\n", __func__);
	my_thread = kthread_create(print_running_thread, NULL, "print_running_cpu");
	return 0;
}

static void my_driver_exit(void)
{
	kthread_stop(my_thread);
	printk(KERN_INFO"Device Driver Remove.. Done!!\n");
}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_LICENSE("GPL");

==> LinuxKernelProgramming/sec11/1_kthread_run/run_new.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/kthread.h>
#include <linux/delay.h>

struct task_struct *print_thread;
char buffer[256];
char * get_task_state(long state)
{
    switch (state) {
        case TASK_RUNNING:
            return "TASK_RUNNING";
        case TASK_INTERRUPTIBLE:
            return "TASK_INTERRUPTIBLE";
        case TASK_UNINTERRUPTIBLE:
            return "TASK_UNINTERRUPTIBLE";
        case __TASK_STOPPED:
            return "__TASK_STOPPED";
        case __TASK_TRACED:
            return "__TASK_TRACED";
	case TASK_IDLE:
	    return "(TASK_UNINTERRUPTIBLE | TASK_NOLOAD)";
	case TASK_KILLABLE:
	    return "(TASK_WAKEKILL | TASK_UNINTERRUPTIBLE)";
	case TASK_STOPPED:
	    return "(TASK_WAKEKILL | __TASK_STOPPED)";
	case TASK_TRACED:
	    return "(TASK_WAKEKILL | __TASK_TRACED)";
        default:
        {
            sprintf(buffer, "Unknown Type:%ld", state);
            return buffer;
        }
    }
}

static int print_running_thread(void *data)
{
	 while(!kthread_should_stop()) {
		 struct task_struct *task_list;
		 for_each_process(task_list) {
			 if (task_list->state == TASK_RUNNING)
				 pr_info("Process: %s\t PID:[%d]\t State:%s\n", 
						 task_list->comm, task_list->pid,
						 get_task_state(task_list->state));
		 }
		 msleep(500);
	 }
	 return 0;
}

MODULE_LICENSE("GPL");
static int test_tasks_init(void)
{
    pr_info("%s: In init\n", __func__);
    print_thread = kthread_run(print_running_thread, NULL,
				"print_running_cpu");
    return 0;
}

static void test_tasks_exit(void)
{
    pr_info("%s: In exit\n", __func__);
    kthread_stop(print_thread);
}

module_init(test_tasks_init);
module_exit(test_tasks_exit);


==> LinuxKernelProgramming/sec11/2_two_threads/kthreads.c <==
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>

static struct task_struct *kthread1, *kthread2;

static int work_func1(void *data)
{
	int i = 0;
	while (!kthread_should_stop())
	{
		pr_info("1 %d\n", i);
		usleep_range(1000000, 1000001);
		i++;
		if (i == 10)
			i = 0;
	}
	return 0;
}

static int work_func2(void *data)
{
	int i = 0;
	while (!kthread_should_stop())
	{
		pr_info("2 %d\n", i);
		usleep_range(1000000, 1000001);
		i++;
		if (i == 10)
			i = 0;
	}
	return 0;
}

static int __init my_driver_init(void)
{
	kthread1 = kthread_create(work_func1, NULL, "mykthread1");
	kthread2 = kthread_create(work_func2, NULL, "mykthread2");
	wake_up_process(kthread1);
	wake_up_process(kthread2);
	return 0;
}

void __exit my_driver_exit(void)
{
	kthread_stop(kthread1);
	kthread_stop(kthread2);
	printk(KERN_INFO"Device Driver Remove.. Done!!\n");
}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_LICENSE("GPL");

==> LinuxKernelProgramming/sec11/2_two_threads/kthreads.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0x81b3a898, "kthread_stop" },
	{ 0x62767b5d, "wake_up_process" },
	{ 0x550b3716, "kthread_create_on_node" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xc5850110, "printk" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "389420354015A0546C51978");

==> LinuxKernelProgramming/sec11/3_processor_id/processor_id.c <==
#include <linux/init.h>
#include <linux/module.h>
#include <linux/smp.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

static struct task_struct *my_task = NULL;
MODULE_LICENSE("GPL");

int thread_function(void *data)
{
	char *str = (char*)data;

	pr_info("my kthread data: %s\n", str);
	pr_info("my kthread smp_processor_id: %d\n", smp_processor_id());
	while (!kthread_should_stop())
	{
		pr_info("my kthread: living. smp_processor_id: %d\n", smp_processor_id());
		pr_info("======================\n");
		msleep(1000);
	}	
		pr_info("my kthread: stop\n");
	return 0;
}

static int __init my_driver_init(void)
{
	pr_info("my init.\n");
	pr_info("smp_processor_id: %d\n", smp_processor_id());
	my_task = kthread_run(thread_function, "hello my kthread", "myThread-%s", "test");
	pr_info("my init finish.\n");
	pr_info("======================\n");

	return 0;
}

static void __exit my_driver_exit(void)
{
	pr_info("my exit.\n");
	pr_info("smp_processor_id: %d\n", smp_processor_id());
	if (my_task) 
	{
		pr_info("my exit.\n");
		kthread_stop(my_task);
	}
	pr_info("my exit finish.\n");
	pr_info("======================\n");
}

module_init(my_driver_init);
module_exit(my_driver_exit);

==> LinuxKernelProgramming/sec11/3_processor_id/processor_id.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0x81b3a898, "kthread_stop" },
	{ 0x62767b5d, "wake_up_process" },
	{ 0x550b3716, "kthread_create_on_node" },
	{ 0xf9a482f9, "msleep" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "ED40940AF60A4BB303830A2");

==> LinuxKernelProgramming/sec11/4_race_cond/kernel_race.c <==
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

static struct task_struct *thread1, *thread2;
unsigned long long counter = 0;
unsigned long loopcount = 10000;

module_param(loopcount, ulong, 0);

MODULE_LICENSE("GPL");

static int inc_thread(void *pv)
{
	int i=0;
	printk("Thread started\n");
	for (i = 0; i < loopcount; i++)
	{
		counter++;
	}	
	printk("Thread completed\n");
	return 0;
}

static int my_driver_init(void)
{
	pr_info("%s: In init loop count: %lu\n", __func__, loopcount);
	thread1 = kthread_run(inc_thread, NULL, "thread1");
	thread2 = kthread_run(inc_thread, NULL, "thread2");
	return 0;
}

static void my_driver_exit(void)
{
	kthread_stop(thread1);
	kthread_stop(thread2);
	printk(KERN_INFO"Device Driver Remove.. Done!!\n");
}

module_init(my_driver_init);
module_exit(my_driver_exit);

MODULE_LICENSE("GPL");

==> LinuxKernelProgramming/sec11/4_race_cond/kernel_race.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0x4083b059, "param_ops_ulong" },
	{ 0x81b3a898, "kthread_stop" },
	{ 0x62767b5d, "wake_up_process" },
	{ 0x550b3716, "kthread_create_on_node" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "051B0D495666A4CE1FFB4DB");

==> LinuxKernelProgramming/sec12/0_linux_version_code/version.c <==
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <asm/current.h>
#include <generated/utsrelease.h>

MODULE_LICENSE("GPL");

static int __init kernel_version_init(void)
{
	//Now depends on our Kernel version we could log a different comment in the Kernel log
	#if LINUX_VERSION_CODE <= KERNEL_VERSIOn(2, 6, 10)
		printk(KERN_INFO"KERNELVERSION: Hello OLD Kernel %s\n", UTS_RELEASE);
	#elif LINUX_VERSION_CODE >= KERNEL_VERSIOn(5, 0, 0)
		printk(KERN_INFO"KERNELVERSION: Hello NEW Kernel %s\n", UTS_RELEASE);
	#else LINUX_VERSION_CODE >= KERNEL_VERSIOn(5, 0, 0)
		printk(KERN_INFO"KERNELVERSION: Hello Moderate Kernel %s\n", UTS_RELEASE);
	#endif
	return 0;
}

static void __exit kernel_version_exit(void)
{
	printk(KERN_INFO"KERNELVERSION: Hello OLD Kernel\n");	
}

module_init(kernel_version_init);
module_exit(kernel_version_exit);


==> LinuxKernelProgramming/sec13/1_initdata/initdata.c <==
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static char buf[] __initdata = "LWL";

static int __init test_hello_init(void)
{
	pr_info("%s: In init:%s\n", __func__, buf);
	return 0;
}

static void test_hello_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

==> LinuxKernelProgramming/sec13/1_initdata/initdata.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "95DD68DCEE2826055EA3C4A");

==> LinuxKernelProgramming/sec1/day1/hello.c <==
// 1. Include header files necessary
#include <linux/kernel.h>
#include <linux/module.h>

// 2. Include license
MODULE_LICENSE("GPL");
// 3. Write initialization and exit functions 
static int test_hello_init(void) //return type of initialization function is int
{
	printk(KERN_INFO"%s: In init\n", __func__);
	return 0;
}

static void test_hello_exit(void) //return type of exit function is void
{
	printk(KERN_INFO"%s: In exit\n", __func__);
	/*INFO specifies kernel log level: EMERG, ALERT, CRIT, ERR, WARNING, NOTICE, INFO, DEBUG in order of decreasing priority
	defined in kernel.h. printk() writes to the kernel buffer, whereas printf() writes to the standard output*/
}

// 4. Specify functions as initialization and cleanup functions
module_init(test_hello_init);
module_exit(test_hello_exit);

==> LinuxKernelProgramming/sec1/day1/hello.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x19fdd0c3, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B91DCAAB223E733995C2F3F");

==> LinuxKernelProgramming/sec1/day2/hello1.c <==
// 1. Include header files necessary
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

// 2. Include license
MODULE_LICENSE("GPL");
// 3. Write initialization and exit functions 
static int test_hello_init(void) //return type of initialization function is int
{
	printk(KERN_INFO"%s: In init\n", __func__);
	return 0;
	// If function returns -1 the module will not be loaded into the kernel space upon invocation of insmod 
}

static void test_hello_exit(void) //return type of exit function is void
{
	printk(KERN_INFO"%s: In exit\n", __func__);
	/*INFO specifies kernel log level: EMERG, ALERT, CRIT, ERR, WARNING, NOTICE, INFO, DEBUG in order of decreasing priority
	defined in kernel.h. printk() writes to the kernel buffer, whereas printf() writes to the standard output*/
}

// 4. Specify functions as initialization and cleanup functions
module_init(test_hello_init);
module_exit(test_hello_exit);

==> LinuxKernelProgramming/sec1/day2/hello1.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x19fdd0c3, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "67BD7D43657BA691C8DD7AF");

==> LinuxKernelProgramming/sec1/day3/hello2.c <==
// 1. Include header files necessary
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

// 2. Include license
MODULE_LICENSE("GPL");
// 3. Write initialization and exit functions 
static int test_hello_init(void) //return type of initialization function is int
{
	printk(KERN_INFO"%s: In init\n", __func__);
	return 0;
	// If function returns -1 the module will not be loaded into the kernel space upon invocation of insmod 
}

static void test_hello_exit(void) //return type of exit function is void
{
	printk(KERN_INFO"%s: In exit\n", __func__);
	/*INFO specifies kernel log level: EMERG, ALERT, CRIT, ERR, WARNING, NOTICE, INFO, DEBUG in order of decreasing priority
	defined in kernel.h. printk() writes to the kernel buffer, whereas printf() writes to the standard output*/
}

// 4. Specify functions as initialization and cleanup functions
module_init(test_hello_init);
module_exit(test_hello_exit);

==> LinuxKernelProgramming/sec1/day3/newlinux.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x19fdd0c3, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2F81F444AC9E13F61EA4573");

==> LinuxKernelProgramming/sec1/day4/func.c <==
// 1. Include header files necessary
#include <linux/kernel.h>

void func(void)
{
	printk(KERN_INFO"Hello Linux\n");
}

==> LinuxKernelProgramming/sec1/day4/hello3.c <==
// 1. Include header files necessary
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

// 2. Include license
MODULE_LICENSE("GPL");

void func(void);
// 3. Write initialization and exit functions 
static int test_hello_init(void) //return type of initialization function is int
{
	printk(KERN_INFO"%s: In init\n", __func__);
	func();
	return 0;
	// If function returns -1 the module will not be loaded into the kernel space upon invocation of insmod 
}

static void test_hello_exit(void) //return type of exit function is void
{
	printk(KERN_INFO"%s: In exit\n", __func__);
	/*INFO specifies kernel log level: EMERG, ALERT, CRIT, ERR, WARNING, NOTICE, INFO, DEBUG in order of decreasing priority
	defined in kernel.h. printk() writes to the kernel buffer, whereas printf() writes to the standard output*/
}

// 4. Specify functions as initialization and cleanup functions
module_init(test_hello_init);
module_exit(test_hello_exit);

==> LinuxKernelProgramming/sec1/day5/func.c <==
// 1. Include header files necessary
#include <linux/kernel.h>

void func(void)
{
	printk(KERN_INFO"Hello Linux\n");
}

==> LinuxKernelProgramming/sec1/day5/hello4a.c <==
// 1. Include header files necessary
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

// 2. Include license
MODULE_LICENSE("GPL");

// 3. Write initialization and exit functions 
static int test_hello4a_init(void) //return type of initialization function is int
{
	printk(KERN_INFO"%s: In init\n", __func__);
	return 0;
	// If function returns -1 the module will not be loaded into the kernel space upon invocation of insmod 
}

static void test_hello4a_exit(void) //return type of exit function is void
{
	printk(KERN_INFO"%s: In exit\n", __func__);
	/*INFO specifies kernel log level: EMERG, ALERT, CRIT, ERR, WARNING, NOTICE, INFO, DEBUG in order of decreasing priority
	defined in kernel.h. printk() writes to the kernel buffer, whereas printf() writes to the standard output*/
}

// 4. Specify functions as initialization and cleanup functions
module_init(test_hello4a_init);
module_exit(test_hello4a_exit);

==> LinuxKernelProgramming/sec1/day5/hello4a.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x19fdd0c3, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5DF316C332F959E9A2EC562");

==> LinuxKernelProgramming/sec1/day5/hello4b.c <==
// 1. Include header files necessary
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

// 2. Include license
MODULE_LICENSE("GPL");

// 3. Write initialization and exit functions 
static int test_hello4b_init(void) //return type of initialization function is int
{
	printk(KERN_INFO"%s: In init\n", __func__);
	return 0;
	// If function returns -1 the module will not be loaded into the kernel space upon invocation of insmod 
}

static void test_hello4b_exit(void) //return type of exit function is void
{
	printk(KERN_INFO"%s: In exit\n", __func__);
	/*INFO specifies kernel log level: EMERG, ALERT, CRIT, ERR, WARNING, NOTICE, INFO, DEBUG in order of decreasing priority
	defined in kernel.h. printk() writes to the kernel buffer, whereas printf() writes to the standard output*/
}

// 4. Specify functions as initialization and cleanup functions
module_init(test_hello4b_init);
module_exit(test_hello4b_exit);

==> LinuxKernelProgramming/sec1/day5/hello4b.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x19fdd0c3, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "516465BCA86E694ED9C8E4F");

==> LinuxKernelProgramming/sec2/alias.c <==
#include <stdio.h>

static int myfunc(int a, int b)
{
	printf("%s: Adding %d with %d:\t Result:%d\n", __func__, a, b, a+b);
	return a+b;
}

static int add(int a, int b) __attribute__((alias("myfunc")));

int main()
{
	add(3, 6);
	myfunc(3, 5);
	return 0;
}

==> LinuxKernelProgramming/sec2/alias_variable.c <==
#include <stdio.h>

int oldname = 5;

extern int newname __attribute__((alias("oldname")));

int main()
{
	printf("Value of new name is: %d\n", newname);
	return 0;
}

==> LinuxKernelProgramming/sec2/module_init_exit.c <==
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

//the module_init() and module_exit(0 functions simply alias their arguments to functions with these type definitions, thus they will
//still be called on module initialisation and cleanup
int init_module(void)
{
	printk(KERN_INFO"%s: In init\n", __func__);
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO"%s: In exit\n", __func__);
}

==> LinuxKernelProgramming/sec2/module_init_exit.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x19fdd0c3, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A47623C54A3860B6D21805F");

==> LinuxKernelProgramming/sec7/0_printk/printk_rep.c <==
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

void func(void)
{
	int i;
	for (i = 0; i < 50000; i++)
		printk(KERN_INFO"Hello Linux User %d\n", i);
}

static int test_hello_init(void)
{	
	printk(KERN_INFO"%s: In init\n", __func__);
	func();
	return 0;
}

static void test_hello_exit(void)
{	
	printk(KERN_INFO"%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

==> LinuxKernelProgramming/sec7/0_printk/printk_rep.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "47F6B0340572B99F49806D4");

==> LinuxKernelProgramming/sec7/1_printk/printk_log_levels.c <==
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int test_hello_init(void)
{	
	printk("\001""4""%s: In init\n", __func__);
	return 0;
}

static void test_hello_exit(void)
{	
	printk("\001""2""%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

==> LinuxKernelProgramming/sec7/1_printk/printk_log_levels.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D04F0002735319543189333");

==> LinuxKernelProgramming/sec7/2_printk/printk_default_level.c <==
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int test_hello_init(void)
{	
	printk("%s: In init\n", __func__);
	return 0;
}

static void test_hello_exit(void)
{	
	printk("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

==> LinuxKernelProgramming/sec7/2_printk/printk_default_level.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "00B734E75E4144408D01CF0");

==> LinuxKernelProgramming/sec7/3_printk/pr_debug.c <==
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
    printk(KERN_DEBUG"%s: In Init 1\n", __func__);
    pr_debug("%s: In Init 2\n", __func__);
    return 0;
}

static void test_hello_exit(void)
{
    pr_warn("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxKernelProgramming/sec7/3_printk/pr_debug.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "32C40D659D0632746747E6B");

==> LinuxKernelProgramming/sec7/4_printk/printk_float.c <==
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
	float f = 2.56;
	printk("%s: In init, value of f is %f\n", __func__, f);
	return 0;
}

static void test_hello_exit(void)
{
	printk("%s In exit", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxKernelProgramming/sec7/4_printk/printk_float.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "EB19C85E8B015265C98AAC0");

==> LinuxKernelProgramming/sec7/5_printk/printk_limit.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
	int i;

	for (i = 0; i < 20; i++) {
		if (printk_ratelimit()) {
			pr_info("Printing %d\n", i+1);
		}
		else {
			pr_info("Sleeping for 5 seconds\n");
			msleep(5000);
			i--;
		}
	}
	return 0;
}

static void test_hello_exit(void)
{
	printk("%s In exit", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxKernelProgramming/sec7/5_printk/printk_limit.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc5850110, "printk" },
	{ 0x6128b5fc, "__printk_ratelimit" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "29F851FC216B762B8154959");

==> LinuxKernelProgramming/sec7/6_printk/printk_once.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
	int i;

	for (i = 0; i < 20; i++) {
		printk_once(KERN_INFO"Printing %d\n", i);
	}
	printk_once(KERN_INFO"Printing %d\n", i+1);
	return 0;
}

static void test_hello_exit(void)
{
	printk("Done\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxKernelProgramming/sec7/6_printk/printk_once.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0A9ABC4C70669B880441031");

==> LinuxKernelProgramming/sec7/7_printk/printk_defaultnline.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
	printk_once(KERN_INFO KERN_CONT"Hello ");
	printk_once(KERN_INFO KERN_CONT"World\n");
	return 0;
}

static void test_hello_exit(void)
{
	printk("Done\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxKernelProgramming/sec7/7_printk/printk_defaultnline.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F9189D14FF7711D83D8DCF0");

==> LinuxKernelProgramming/sec7/8_printk/printk_hexdump_bytes.c <==
#include <linux/kernel.h>
#include <linux/module.h>

/*
void print_hex_dump_bytes(const char *prefix_str, int prefix_type, const void *buf, size_t len)

Given a buffer print_hex_dump prints a hex + ASCII dump to the kernel log at the specified kernel log level, with an optional leading prefix.

prefix_str: 	string to prefix each line with;
prefix_type: 	controls whether prefix of an offset, address, or none is printed (%DUMP_PREFIX_OFFSET, \ ``DUMP_PREFIX_ADDRESS``\ , \ ``DUMP_PREFIX_NONE``\ )
buf: 			data blob to dump
len: 			number of bytes in buf
Defaults: 		log level of KERN_DEBUG, rowsize of 16, groupsize of 1, and ASCII output included
*/

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
	char buffer[] = "Hello World. Linux is the best OS.";
	print_hex_dump_bytes("buf: ", DUMP_PREFIX_OFFSET, buffer, sizeof(buffer));
	return 0;
}

static void test_hello_exit(void)
{
	printk("Done\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxKernelProgramming/sec7/8_printk/printk_hexdump.c <==
#include <linux/kernel.h>
#include <linux/module.h>

/*
void print_hex_dump(const char *level, const char *prefix_str, int prefix_type, int rowsize, int groupsize, const void *buf, size_t len, bool ascii);

Given a buffer print_hex_dump prints a hex + ASCII dump to the kernel log at the specified kernel log level, with an optional leading prefix.

level: 			kernel log level (e.g. KERN_DEBUG)
prefix_str: 	string to prefix each line with;
prefix_type: 	controls whether prefix of an offset, address, or none is printed (%DUMP_PREFIX_OFFSET, \ ``DUMP_PREFIX_ADDRESS``\ , \ ``DUMP_PREFIX_NONE``\ )
rowsize: 		number of bytes to print per line; must be 16 or 32
groupsize: 		number of bytes to print at a time (1, 2, 4, 8; default = 1)
buf: 			data blob to dump
len: 			number of bytes in buf
ascii: 			include ASCII after the hex output
*/

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
	char buffer[] = "Hello World. Linux is the best OS.";
	print_hex_dump(KERN_INFO, "buf: ", DUMP_PREFIX_OFFSET, 16, 1, buffer, sizeof(buffer), 0);
	return 0;
}

static void test_hello_exit(void)
{
	printk("Done\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxKernelProgramming/sec9/01_kernel_panic/panic_test.c <==
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
static int myinit(void)
{
	pr_info("%s: Kern_panic myinit\n", __func__);
	panic("Hello Kernel, I am causing the panic\n");
	return 0;
}

static void myexit(void)
{
	pr_info("myexit\n");
}

module_init(myinit);
module_exit(myexit);

==> LinuxKernelProgramming/sec9/02_oops/oops_test.c <==
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
static int myinit(void)
{
	pr_info("%s: We are attempting to access an invalid memory locationy\n", __func__);
	*(int *)0x12 = 'a';
	return 0;
}

static void myexit(void)
{
	pr_info("myexit\n");
}

module_init(myinit);
module_exit(myexit);

==> LinuxKernelProgramming/sec9/02_oops/oops_test.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "DC166300134832CF92C0756");

==> LinuxKernelProgramming/sec9/03_bug/bug_test.c <==
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
static int buginit(void)
{
	pr_info("%s: Kern_panic myinit\n", __func__);
	BUG();
	return 0;
}

static void bugexit(void)
{
	pr_info("bugexit\n");
}

module_init(buginit);
module_exit(bugexit);

==> LinuxKernelProgramming/sec9/03_bug/bug_test.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8e6402a9, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0CC58B972C666921217F3F4");

==> LinuxKernelProgramming/sec9/0_dumpstack/dump_stack.c <==
#include <linux/module.h>
#include <linux/kernel.h>

static int myinit(void)
{
	pr_info("dump_stack myinit\n");
	dump_stack();
	pr_info("dump_stack myinit\n");
	return 0;
}

static void myexit(void)
{
	pr_info("myexit\n");
}

module_init(myinit);
module_exit(myexit);
MODULE_LICENSE("GPL");

==> LinuxKernelProgramming/test_arguments_init/arguments.c <==
#include <linux/kernel.h>
#include <linux/module.h>

/*	We can add parameters using module_param macro declared in moduleparam.h file
	#define module_param(name, type, perm)
		 module_param_named(name, name, type, perm)

	name: Name of the variable, type: Type of the variable: charp(char *), bool, 
	type: Type of the variable: charp, bool, invbool, int, long, short, uint, ulong, ushort  
	perm: Permissions for the sysfs entry e.g. S_IRUGO: Only read by all users
	You can also use numeric values like 0644 for permission entry
*/

MODULE_LICENSE("GPL");
char *name = "Embedded";
int loop_count = 1;
module_param(name, charp, S_IRUGO);
module_param(loop_count, int, S_IRUGO);

static int test_arguments_init(void)
{
    int i;
	printk(KERN_INFO"%s: In init\n", __func__);
	printk(KERN_INFO"%s: Loop Count:%d\n", __func__, loop_count);
	for (i = 0; i < loop_count; i++)
		printk(KERN_INFO"%s: Hi %s\n", __func__, name);
	return 0;
}

static void test_arguments_exit(void)
{
	printk(KERN_INFO"%s: In exit\n", __func__);
}

module_init(test_arguments_init);
module_exit(test_arguments_exit);
MODULE_AUTHOR("LESLIE");
MODULE_DESCRIPTION("Argument Passing Example");

==> LinuxKernelProgramming/vermagic/vermagic1.c <==
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/vermagic.h>

static int vermagic_init(void)
{
	pr_info("VERMAGIC_STRING = " VERMAGIC_STRING "\n");
	return 0;
}

static void vermagic_exit(void) {}

module_init(vermagic_init)
module_exit(vermagic_exit)
MODULE_LICENSE("GPL");

==> LinuxKernelProgramming/vermagic/vermagic.c <==
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/vermagic.h>

static int vermagic_init(void)
{
	pr_info("VERMAGIC_STRING = " VERMAGIC_STRING "\n");
	return 0;
}

static void vermagic_exit(void) {}

module_init(vermagic_init)
module_exit(vermagic_exit)
MODULE_LICENSE("GPL");

==> LinuxMemoryManagement/00_virt_to_phys/virt_to_phys.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");
static int __init test_init(void)
{
	int i = 10;
	void *virtual_address = (void *)&i;
	phys_addr_t physical_address = virt_to_phys(virtual_address);

	//printk format needed for a specific data type is specified in the kernel source code
	//under Documentation/core-api/printk-formats.rst. %p will hash the address before printing
	//To protect the kernel. To use *real* address use %px
	pr_info("Virtual address of i (hashed) is %p\n", virtual_address);
	pr_info("Virtual address of i (unmodified) is %px\n", virtual_address);
	pr_info("Physical address of i is %pa\n", &physical_address);
	pr_info("Virtual address of i is %px\n", phys_to_virt(physical_address));
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/01_struct_page/struct_page.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mm_types.h>

MODULE_LICENSE("GPL");
static int __init test_init(void)
{
	pr_info("Size of page is %lu bytes\n", sizeof(struct page));
	return -1;
}

static void __exit test_exit(void)
{	
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/01_struct_page/struct_page.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F67C1485AB8C41FE7E0BB34");

==> LinuxMemoryManagement/02_page_fault/page_fault.c <==
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#define BUFFER_SIZE (1024 * 1024)

void print_pgfaults(void)
{
	int ret;
	struct rusage usage;
	ret = getrusage(RUSAGE_SELF, &usage); //can print page fault of a process using getrusage
	if (ret == -1) 
	{
		perror("getrusage");	
	}
	else
	{
		printf("Major page faults %ld\n", usage.ru_majflt);
		printf("Minor page faults %ld\n", usage.ru_minflt);
	}
}

int main(int argc, char **argv)
{
	unsigned char *p;
	printf("Initial state\n");
	print_pgfaults();
	p = malloc(BUFFER_SIZE);
	printf("After malloc\n");
	print_pgfaults();
	memset(p, 'a', BUFFER_SIZE);
	printf("After memset\n");
	print_pgfaults();
	memset(p, 'b', BUFFER_SIZE);
	printf("After 2nd memset\n");
	print_pgfaults();
	return 0;
}
// For every 1kb of memory allocated, it is returning 256 page faults.

==> LinuxMemoryManagement/03_kmalloc_kfree/kmalloc_kfree.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");

static void *ptr;
int alloc_size = 1024;

module_param(alloc_size, int, 0);

static int test_init(void)
{
	ptr = kmalloc(alloc_size, GFP_ATOMIC);
	if (!ptr) {
		// handle error
		pr_err("memory allocation failed\n");
		return -ENOMEM;
	}
	else {
		phys_addr_t physical_address = virt_to_phys(ptr);
		pr_info("Memory Allocated:%px\n", ptr);
		pr_info("Physical address of i is %pa\n", &physical_address);
		// sudo cat /proc/iomem - Physical address should be present in system RAM, a function address would be present in kernel code, kernel data is for data, and kernel bss is for uninitialized variables 
	}

	return 0;
}

static void test_exit(void)
{
	kfree(ptr);
	pr_info("Memory freed\n");
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/04_GFP_Flags_to_Kmalloc/GFP_Flags_KMalloc.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");

static void *ptr;
int alloc_size = 1024;

static int test_init(void)
{
	phys_addr_t physical_address;
	ptr = kmalloc(alloc_size, GFP_DMA);
	pr_info("Virtual address:%px\n", ptr);
	physical_address = virt_to_phys(ptr);
	pr_info("Physical address:%pa\n", &physical_address);
	kfree(ptr);
	ptr = kmalloc(alloc_size, GFP_DMA32);
	pr_info("Virtual address:%px\n", ptr);
	physical_address = virt_to_phys(ptr);
	pr_info("Physical address:%pa\n", &physical_address);
	kfree(ptr);
	return -1;
}

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/04_GFP_Flags_to_Kmalloc/GFP_Flags_KMalloc.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x37a0cba, "kfree" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xc5850110, "printk" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "CB865DFF1A1DF1AF9AD523A");

==> LinuxMemoryManagement/05_max_size_kmalloc/maxsize_kmalloc.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");

static void *ptr;
unsigned int alloc_size = 1024;
unsigned int loop = 8192;
module_param(loop, uint, 0);

static int test_init(void)
{
	int i;
	for (i = 1; i < loop; i++)
	{
		ptr = kmalloc(alloc_size * i, GFP_KERNEL);
		if (!ptr)
		{
			//handle error
			pr_err("Memory allocation failed\n");
			return -ENOMEM;
		}
		else
		{
			pr_info("Memory allocated of size:%uKB successfully:%px\n", i, ptr);
			kfree(ptr);
			pr_info("Memory freed\n");
		}
	}
	return -1;
}

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/06_kmalloc_memleak/kmalloc_memleak.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char* device_name = "mychardev";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;
unsigned int alloc_size = 2*1024*1024; //2MB

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	void *ptr;
	pr_info("%s\n", __func__);
	ptr = kmalloc(alloc_size, GFP_KERNEL);
	if (ptr)
		pr_info("Allocated %uKB size\n", alloc_size/(1024));
	else
		pr_info("failed in allocating memory\n");

	return 0;
}


static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
	pr_info("%s\n", __func__);
	return 0;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
};

static int test_init(void)
{
	myclass = class_create(THIS_MODULE, "Meinclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered, Major: %d", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();

		if (mycdev) {
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_err("failed to register device number");

	return 0;
}

static void test_exit(void)
{
	device_destroy(myclass, count);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/06_kmalloc_memleak/kmalloc_memleak.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0xe340d421, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0x9f4f34bc, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BB03221D9F4F1ADB512BCF8");

==> LinuxMemoryManagement/06_kmalloc_memleak/userapp.c <==
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("/dev/mychardev", O_RDWR);
	perror("fd");
}

==> LinuxMemoryManagement/07_kmalloc_ksize/ksize.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

static void *ptr;

static int test_init(void)
{
	ptr = kmalloc(1, GFP_KERNEL);
	printk("I got: %zu bytes of memory\n", ksize(ptr));
	kfree(ptr);
	ptr = kmalloc(8, GFP_KERNEL);
	printk("I got: %zu bytes of memory\n", ksize(ptr));
	kfree(ptr);
	ptr = kmalloc(8080, GFP_KERNEL);
	printk("I got: %zu bytes of memory\n", ksize(ptr));
	kfree(ptr);
	ptr = kmalloc(8192, GFP_KERNEL);
	printk("I got: %zu bytes of memory\n", ksize(ptr));
	kfree(ptr);
	return -1;
}

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/07_kmalloc_ksize/ksize.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0xc5850110, "printk" },
	{ 0x4ea5d10, "ksize" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B089A1888C7C76E023D160C");

==> LinuxMemoryManagement/08_kzalloc/kzalloc.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

static char *ptr;
int alloc_size = 1024;

module_param(alloc_size, int, 0);

static int test_init(void)
{
	ptr = kmalloc(alloc_size, GFP_ATOMIC);
	if (!ptr) 
	{
		//handle error
		pr_err("memory allocation failed\n");
		return -ENOMEM;
	}
	else
	{
		pr_info("Memory allocated successfully:%px\n", ptr);
		pr_info("Content of ptr+2 is %d\n", *(ptr+2));
		pr_info("Content of ptr+1022 is %d\n", *(ptr+102));
	}
	kfree(ptr);
	ptr = kzalloc(alloc_size, GFP_ATOMIC);
	if (!ptr)
	{
		//handle error
		pr_err("memory allocation failed\n");
		return -ENOMEM;
	}
	else
	{
		pr_info("Memory allocated successfully:%px\n", ptr);
		pr_info("Content of ptr+2 is %d\n", *(ptr+2));
		pr_info("Content of ptr+1022 is %d\n", *(ptr+102));
	}
	kfree(ptr);

	return -1;
}

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/08_kzalloc/kzalloc.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x4caf37f7, "param_ops_int" },
	{ 0x37a0cba, "kfree" },
	{ 0xc5850110, "printk" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "90CB14E49C2B812D9D97DE9");

==> LinuxMemoryManagement/09_krealloc/krealloc.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

static void *addr;

static int test_init(void)
{
	addr = kmalloc(4096, GFP_KERNEL);
	printk("I got: %zu bytes of memory\n", ksize(addr));
	addr = krealloc(addr, 8192, GFP_KERNEL);
	printk("I got: %zu bytes of memory\n", ksize(addr));
	kfree(addr);
	return -1;
}

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/09_krealloc/krealloc.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0xc8dcc62a, "krealloc" },
	{ 0xc5850110, "printk" },
	{ 0x4ea5d10, "ksize" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C66D6655798BEB262E638FD");

==> LinuxMemoryManagement/10_kmalloc_contiguous_demo/kmalloc_contiguous_demo.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");

static char *ptr;
int alloc_size = 1024;

module_param(alloc_size, int, 0);

static int test_init(void)
{
	ptr = kmalloc(alloc_size, GFP_ATOMIC);
	if (!ptr)
	{
		// handle error
		pr_err("memory allocation failed\n");
		return -ENOMEM;
	}
	else
	{
		pr_info("memory allocated successfully:%px\t%px\n", ptr, ptr+100);
		pr_info("Physical address:%llx\t%llx\n", virt_to_phys(ptr), virt_to_phys(ptr+100));
	}

	return 0;
}

static void test_exit(void)
{
	kfree(ptr);
	pr_info("Memory freed\n");
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/10_kmalloc_contiguous_demo/kmalloc_contiguous_demo.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x4caf37f7, "param_ops_int" },
	{ 0x37a0cba, "kfree" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xc5850110, "printk" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A945C6B39FF0C6ACD72E186");

==> LinuxMemoryManagement/11_vmalloc_maxsize/vmalloc_maxsize.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

static void *ptr;
unsigned int alloc_size = 1024*1024; //1MB
unsigned int loop = 8192;
module_param(loop, uint, 0);

static int test_init(void)
{
	int i;
	for (i = 1; i < loop; i++)
	{
		ptr = vmalloc(alloc_size*i);
		if(!ptr)
		{
			//handle error
			pr_err("memory allocation failed\n");
			return -ENOMEM;
		}
		else
		{
			pr_info("Memory allocated of size:%uMB successfully:%px\n", i, ptr);
			vfree(ptr);
			pr_info("Memory freed\n");
		}
	}	
	return -1;
}	

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/11_vmalloc_maxsize/vmalloc_maxsize.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x3d58fb01, "param_ops_uint" },
	{ 0x999e8297, "vfree" },
	{ 0xc5850110, "printk" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E99717C54BB8C666704ECE8");

==> LinuxMemoryManagement/12_vmalloc_ksizefail/vmalloc_ksizefail.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

static void *ptr;

static int test_init(void)
{
	ptr = vmalloc(1);
	pr_info("I got: %zu bytes of memory\n", ksize(ptr));
	vfree(ptr);
	ptr = vmalloc(8);
	pr_info("I got: %zu bytes of memory\n", ksize(ptr));
	vfree(ptr);
	ptr = vmalloc(8080);
	pr_info("I got: %zu bytes of memory\n", ksize(ptr));
	vfree(ptr);
	ptr = vmalloc(8192);
	pr_info("I got: %zu bytes of memory\n", ksize(ptr));
	vfree(ptr);
	return -1;
}

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/12_vmalloc_ksizefail/vmalloc_ksizefail.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x999e8297, "vfree" },
	{ 0xc5850110, "printk" },
	{ 0x4ea5d10, "ksize" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6AF9E03481F17481A6F2CE4");

==> LinuxMemoryManagement/13_Vmalloc_size/vmalloc_size.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <asm/pgtable.h>
#include <linux/mm.h>

MODULE_LICENSE("GPL");

static int test_init(void)
{
	pr_info("Vmalloc start:%lx\n", VMALLOC_START);
	pr_info("Vmalloc end:%lx\n", VMALLOC_END);
	pr_info("Vmalloc size:%d MB\n", (VMALLOC_END - VMALLOC_START)/(1024*1024));
	return -1;
}

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/13_Vmalloc_size/vmalloc_size.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xd304cfde, "boot_cpu_data" },
	{ 0xc5850110, "printk" },
	{ 0x9cb986f2, "vmalloc_base" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E1EB8EAAA6CE2091382039A");

==> LinuxMemoryManagement/14_kmalloc_zerobytes/kmalloc_zerobytes.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

static int *ptr;

static int test_init(void)
{
	ptr = kmalloc(0, GFP_KERNEL);
	if (ptr) {
		pr_info("memory Allocated:%px\n", ptr);
		kfree(ptr);
	}
	else
	{
		pr_info("Memory not allocated\n");
	}

	return -1;
}

static void test_exit(void) 
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/14_kmalloc_zerobytes/kmalloc_zerobytes.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0FC2084ECAC14DE2095E946");

==> LinuxMemoryManagement/15_vmalloc_zerobytes/vmalloc_zerobytes.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

static int *ptr;

static int test_init(void) {
	ptr= vmalloc(0);
	if (ptr) {
		pr_info("memory allocated:%px\n", ptr);
		vfree(ptr);
	}
	else
		pr_info("memory not allocated\n");

	return -1;
}

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/15_vmalloc_zerobytes/vmalloc_zerobytes.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x999e8297, "vfree" },
	{ 0xc5850110, "printk" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F5DD6D54A2E0D7007FB8E8B");

==> LinuxMemoryManagement/16_kernel_stack/kernel_stack.c <==
#include <linux/kernel.h>
#include <asm/io.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

static void *ptr;
int alloc_size = 1024;

int func(void)
{
	char buf[1024];
	static int i = 2;

	memset(buf, 'a', sizeof(buf));
	pr_info("func called\n");
	while (i--)
		func();
	return 10;
}

static int test_init(void)
{
	phys_addr_t physical_address;
	ptr = kmalloc(alloc_size, GFP_DMA);
	func();
	pr_info("Virtual Address:%px\n", ptr);
	physical_address = virt_to_phys(ptr);
	pr_info("Physical Address:%pa\n", &physical_address);
	func();
	kfree(ptr);
	func();
	return 0;
}

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxMemoryManagement/16_kernel_stack/kernel_stack.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc959d152, "__stack_chk_fail" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x37a0cba, "kfree" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "CD30C5DC53D31C5EC1A9963");

==> LinuxSynchronizationConcurrency/sec01/00_NR_CPUS/nr_cpus.c <==
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init test_init(void)
{
	pr_info("%s: In init NR_CPUS=%d\n", __func__, NR_CPUS);
	pr_info("Number of cpus available:%d\n", num_online_cpus());
	return -1;
}

static void __exit test_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec01/00_NR_CPUS/nr_cpus.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E400C2784047BCD1B72ED4C");

==> LinuxSynchronizationConcurrency/sec01/01_smp_processor_id/smp_processor_id.c <==
//smp_processor_id() gives the current processor number on which kernel is running
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

LIST_HEAD(listhead);

static int __init test_init(void)
{
	pr_info("Module is running on processor:%d\n", smp_processor_id());
	msleep(60000L);
	return -1;
}

static void __exit test_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec01/01_smp_processor_id/smp_processor_id.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "3DA2DD214A93384603CBE3F");

==> LinuxSynchronizationConcurrency/sec01/02_processor_id/processor_id.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/slab.h>

static struct task_struct *my_thread;

int thread_function(void *pv)
{
	int i = 0;
	while(!kthread_should_stop()) {
		pr_info("Processor id:%d\tIn Thread Function %d\n", smp_processor_id(), i++);
		msleep(1000);
	}
	return 0;
}

static int __init driv_init(void)
{
	pr_info("%s: pprocessor id:%d\n", __func__, smp_processor_id());
	my_thread = kthread_create(thread_function, NULL, "myThread");
	if (my_thread) {
		wake_up_process(my_thread);
		return 0;
	}
	else
	{
		pr_err("Cannot create kthread\n");
		return -1;
	}
}

static void __exit driv_exit(void)
{
	kthread_stop(my_thread);
	pr_info("%s: Device Driver Remove....Done\tProcessor Id:%d\n", __func__, smp_processor_id());
}

module_init(driv_init);
module_exit(driv_exit);

MODULE_LICENSE("GPL");

==> LinuxSynchronizationConcurrency/sec01/02_processor_id/processor_id.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x514011c4, "kthread_stop" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8CDDE11C5ECC67C6A244DA4");

==> LinuxSynchronizationConcurrency/sec02/00_Per_CPU_Variables/PerCPUVariables.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>

#define COMPANY_NAME "linux"

MODULE_LICENSE("GPL");
static struct proc_dir_entry *file_pde; //pde - proc directory entry
unsigned int percpu_data[NR_CPUS];

static int cpu_show(struct seq_file *m, void *v)
{
	int i;
	for (i = 0; i < num_online_cpus(); i++)
		seq_printf(m, "Processor %d:%u\n", i, percpu_data[i]);
	return 0;
}

static int my_open(struct inode *inode, struct file *file)
{
	return single_open(file, cpu_show, NULL);
}

static ssize_t proc_write_cpu(struct file *file, const char *buffer, size_t count, loff_t *data)
{
	unsigned char buf[10];
	unsigned int user_val;
	int cpu;

	pr_info("%s\n", __func__);
	if (copy_from_user(buf, buffer, count))
	{
		return -EFAULT;
	}
	else
	{
		buf[count] = '\0';
		user_val = simple_strtoul(buf, NULL, 10);

		cpu = get_cpu(); //get current processor and disable kernel preemption
		percpu_data[cpu] = user_val;
		pr_info("percpu_data on cpu=%d is %u\n", cpu, percpu_data[cpu]);
		put_cpu(); //enable kernel preemption
	}

	return count;
}

static struct proc_ops cpu_ops = {
  .proc_open  = my_open,
  .proc_read = seq_read,
  .proc_lseek= seq_lseek,
  .proc_write = proc_write_cpu
};

static int test_init(void)
{
	pr_info("%s: In init\n", __func__);

	file_pde = proc_create("percpu", 0644, NULL, &cpu_ops);
	if (!file_pde) {
		pr_err("%s: error creating proc file\n", __func__);
		return -1;
	}

	return 0;
}

static void test_exit(void)
{
	pr_info("%s: In exit\n", __func__);
	remove_proc_entry("percpu", NULL);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec02/01_Example_Interface_PerCPU_h/PerCPU_h.c <==
//To create a per-CPU variable at compile time the macro DEFINE_PER_CPU(type, name) i.e DEFINE_PER_CPU(int, i) DEFINE_PER_CPU(int[3], my_array), can manipulate the variables
//with get_cpu_var() and put_cpu_var() routines, get_cpu_var() returns an lvalue and disables preemption, put_cpu_var() reenables preemption

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/percpu.h>

MODULE_LICENSE("GPL");

static DEFINE_PER_CPU(long, percpuvar) = 5;

static int __init test_init(void)
{
	int cpu;
	pr_info("percpuvar=%ld\n", get_cpu_var(percpuvar)++);
	cpu = smp_processor_id();
	pr_info("current cpu=%d\n", cpu);
	put_cpu_var(percpuvar);
	pr_info("percpuvar=%ld\n", get_cpu_var(percpuvar));
	cpu = smp_processor_id();
	pr_info("current cpu=%d\n", cpu);
	put_cpu_var(percpuvar);
	
	return -1;
}

static void __exit test_exit(void)
{

}

module_init(test_init);
module_exit(test_exit);


==> LinuxSynchronizationConcurrency/sec02/01_Example_Interface_PerCPU_h/PerCPU_h.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xc5850110, "printk" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B3C55AF81C423B6A4C2C208");

==> LinuxSynchronizationConcurrency/sec02/02_access_another_processors_variable/per_cpu.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/percpu.h>

MODULE_LICENSE("GPL");

DEFINE_PER_CPU(int, counter);

static int __init test_init(void)
{
	int num_cpus = num_online_cpus();
	int i = 0;
	int val;

	pr_info("Number of cpus available:%d\n", num_cpus);
	for (i = 0; i < num_cpus; i++) {
		int value = per_cpu(counter, i);
		pr_info("Value of counter is %d at Processor:%d\n", value, i);
	}

	get_cpu_var(counter) = 10;
	pr_info("Printing counter value of all processor after updating current processor:%d\n", smp_processor_id());
	put_cpu_var(counter);

	for (i = 0; i < num_cpus; i++) {
		int value = per_cpu(counter, i);
		pr_info("Value of counter is %d at Processor:%d\n", value, i);
	}

	return -1;
}

static void __exit test_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec02/02_access_another_processors_variable/per_cpu.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xc5850110, "printk" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "49351CDD0103C0DB0C4A1E6");

==> LinuxSynchronizationConcurrency/sec02/03_for_each_online_cpu/for_each_online_cpu.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/percpu.h>

MODULE_LICENSE("GPL");

DEFINE_PER_CPU(int, counter);

static int __init test_init(void)
{
	int i = 0;

	for_each_online_cpu(i) 
	{
		int value = per_cpu(counter, i);
		pr_info("Value of counter is %d at Processor:%d\n", value, i);
	}

	get_cpu_var(counter) = 10;
	pr_info("Printing counter value of all processor after updating current processor:%d\n", smp_processor_id());
	put_cpu_var(counter);

	for_each_online_cpu(i) 
	{
		int value = per_cpu(counter, i);
		pr_info("Value of counter is %d at Processor:%d\n", value, i);
	}

	return -1;
}

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec02/03_for_each_online_cpu/for_each_online_cpu.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xc5850110, "printk" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B99D67EDA6596A007B234D2");

==> LinuxSynchronizationConcurrency/sec02/04_dynamic_alloc_per_cpu/alloc_percpu.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/percpu.h>

MODULE_LICENSE("GPL");

static int *dynamic_counter;

static int __init test_init(void)
{
	int cpu = get_cpu();
	int i;
	dynamic_counter = alloc_percpu(int);
	pr_info("cpu:%d\n", cpu);
	*per_cpu_ptr(dynamic_counter, cpu) = 1000;
	put_cpu();
	for_each_online_cpu(i) 
		pr_info("cpu:%d\tcounter:%d\n", i, *per_cpu_ptr(dynamic_counter, i));
	free_percpu(dynamic_counter);
	return 0;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec02/04_dynamic_alloc_per_cpu/alloc_percpu.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xc5850110, "printk" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "812AB6734ED742DD799C72B");

==> LinuxSynchronizationConcurrency/sec03/00_read-modify-write-problem/problem.c <==
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int glob = 0;

//a race condition occurs because when assembled into instructions, the modification
//of a variable usually follows read-modify-write, such that the translator reads the
//value into a new location attempts to modify it, then places it back in the original 
//register (see lines 41-43 of problem.s)
void *threadFunc(void * arg)
{
	int j;
	int loops = *((int *) arg);
	printf("\n %s: start, glob:%d\n", __func__, glob);
	for (j=0; j < loops; j++)
	{
		glob++;
	}
	printf("\n %s: end, glob:%d\n", __func__, glob);

	return NULL;
}

int main()
{
	pthread_t t1, t2;
	int loops=1000000, ret;

	ret = pthread_create(&t1, NULL, threadFunc, &loops);
	if (ret != 0)
		perror("Pthread Create : ");

	ret = pthread_create(&t2, NULL, threadFunc, &loops);
	if (ret != 0)
		perror("Pthread Create : ");

	ret = pthread_join(t1, NULL);
	if (ret != 0)
		perror("Pthread Join : ");

	ret = pthread_join(t2, NULL);
	if (ret != 0)
		perror("Pthread Join : ");

	printf("glob = %d\n", glob);
	return 0;
}

==> LinuxSynchronizationConcurrency/sec03/01_atomic_example/atomic_example.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>

atomic_t val = ATOMIC_INIT(0);
MODULE_LICENSE("GPL");
static int test_init(void)
{
	pr_info("%s: Value after initialization:%d\n", __func__, atomic_read(&val));
	atomic_set(&val, 4);
	pr_info("%s: Value after setting to 4:%d\n", __func__, atomic_read(&val));
	atomic_dec(&val);
	pr_info("%s: Value after decrementing:%d\n", __func__, atomic_read(&val));
	atomic_inc(&val);
	pr_info("%s: Value after incrementing:%d\n", __func__, atomic_read(&val));
	atomic_add(3, &val);
	pr_info("%s: Value after adding 3:%d\n", __func__, atomic_read(&val));
	atomic_sub(2, &val);
	pr_info("%s: Value after subtracting 2:%d\n", __func__, atomic_read(&val));
	return -1;
}

static void test_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec03/01_atomic_example/atomic_example.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "102558CCFFD3BED107A2103");

==> LinuxSynchronizationConcurrency/sec03/02_atomic_op_and_test/atomic_op_and_test.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>

//atomic_inc_and_test, atomic_dec_and_test, atomic sub and test  return 1 if the result
//is zero otherwise return 1

//atomic_add_negative return 1 if the result is negative otherwise return 0

atomic_t val = ATOMIC_INIT(0);
MODULE_LICENSE("GPL");
static int test_init(void)
{
	pr_info("%s: Value after initialization:%d\n", __func__, atomic_read(&val));
	atomic_set(&val, 4);
	pr_info("%s: Value after setting to 4:%d\n", __func__, atomic_read(&val));
	pr_info("%s: atomic_sub_and_test:%d\n", __func__, atomic_sub_and_test(4, &val));
	pr_info("%s: atomic_add_negative:%d\n", __func__, atomic_add_negative(-1, &val));
	pr_info("%s: atomic_inc_and_test:%d\n", __func__, atomic_inc_and_test(&val));
	pr_info("%s: atomic_inc_and_test:%d\n", __func__, atomic_inc_and_test(&val));
	pr_info("%s: atomic_dec_and_test:%d\n", __func__, atomic_dec_and_test(&val));
	pr_info("%s: atomic_dec_and_test:%d\n", __func__, atomic_dec_and_test(&val));

	return -1;
}

static void test_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec03/02_atomic_op_and_test/atomic_op_and_test.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0D33364A736F9F076123479");

==> LinuxSynchronizationConcurrency/sec03/03_atomic_op_nd_return/atomic_op_and_return.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>

atomic_t val = ATOMIC_INIT(0);
MODULE_LICENSE("GPL");
static int test_init(void)
{
	pr_info("%s: Value after initialization:%d\n", __func__, atomic_read(&val));
	atomic_set(&val, 4);
	pr_info("%s: Value after setting to 4:%d\n", __func__, atomic_read(&val));
	pr_info("%s: atomic_add_return(3):%d\n", __func__, atomic_add_return(3, &val));
	pr_info("%s: atomic_sub_return(2):%d\n", __func__, atomic_sub_return(2, &val));
	pr_info("%s: atomic_inc_return:%d\n", __func__, atomic_inc_return(&val));
	pr_info("%s: atomic_dec_return:%d\n", __func__, atomic_dec_return(&val));

	return -1;
}

static void test_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec03/03_atomic_op_nd_return/atomic_op_and_return.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "49C2703F85B0D7DD1F2DA81");

==> LinuxSynchronizationConcurrency/sec03/04_more_atomic_ops/more_atomic_ops.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>

//int atomic_fetch_add(int val, atomic_t *i) atomically adds val to i returns pre-add i
//int atomic_fetch_sub(int val, atomic_t *i) atomically subs val from i returns pre-sub i
//int atomic_cmpxchg(atomic_t *i, intold,int new) reads the value at location i and checks if it is equal to old; if true swaps value at i with new and returns value read at i
//int atomic_xchg(atomic_t *i, int new) swaps the oldvalue at location i with new, and returns old value i

MODULE_LICENSE("GPL");
atomic_t val = ATOMIC_INIT(0);
static int __init test_init(void)
{
	pr_info("%s: Value after initialization:%d\n", __func__, atomic_read(&val));
	atomic_set(&val, 4);
	pr_info("%s: Value after setting to 4:%d\n", __func__, atomic_read(&val));
	pr_info("%s: atomic_fetch_add(2):%d\n", __func__, atomic_fetch_add(2, &val));
	pr_info("%s: atomic_read:%d\n", __func__, atomic_read(&val));
	pr_info("%s: atomic_fetch_sub(1):%d\n", __func__, atomic_fetch_sub(1, &val));
	pr_info("%s: atomic_read:%d\n", __func__, atomic_read(&val));
	pr_info("%s: atomic_cmpxchg(2, 3):%d\n", __func__, atomic_cmpxchg(&val, 2, 3));
	pr_info("%s: atomic_cmpxchg(5, 3):%d\n", __func__, atomic_cmpxchg(&val, 5, 3));
	pr_info("%s: atomic_read:%d\n", __func__, atomic_read(&val));
	pr_info("%s: atomic_xchg(5):%d\n", __func__, atomic_xchg(&val, 5));
	pr_info("%s: atomic_read:%d\n", __func__, atomic_read(&val));
	
	return -1;
}


static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec03/04_more_atomic_ops/more_atomic_ops.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "38E0347F29F423192B09529");

==> LinuxSynchronizationConcurrency/sec03/05_atomic64/atomic64_example.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>

atomic64_t val = ATOMIC_INIT(0);
MODULE_LICENSE("GPL");
static int test_init(void)
{
	pr_info("%s: Value after initialization:%lld\n", __func__, atomic64_read(&val));
	atomic64_set(&val, 4);
	pr_info("%s: Value after setting to 4:%lld\n", __func__, atomic64_read(&val));
	atomic64_dec(&val);
	pr_info("%s: Value after decrementing:%lld\n", __func__, atomic64_read(&val));
	atomic64_inc(&val);
	pr_info("%s: Value after incrementing:%lld\n", __func__, atomic64_read(&val));
	atomic64_add(3, &val);
	pr_info("%s: Value after adding 3:%lld\n", __func__, atomic64_read(&val));
	atomic64_sub(2, &val);
	pr_info("%s: Value after subtracting 2:%lld\n", __func__, atomic64_read(&val));
	return -1;
}

static void test_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec03/05_atomic64/atomic64_example.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "20262A0265D021286D1F939");

==> LinuxSynchronizationConcurrency/sec03/06_atomic_bitwise_ops/atomic_bitwise_ops.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>

unsigned long addr = 0x50;
MODULE_LICENSE("GPL");
static int test_init(void)
{
	pr_info("Value before performing any atomic operations:%02lx\n", addr);
	set_bit(0, &addr);
	pr_info("Value after setting the 0th bit:%02lx\n", addr);
	clear_bit(4, &addr);
	pr_info("Value after setting clearing the 4th bit:%02lx\n", addr);
	change_bit(0, &addr);
	pr_info("Value after changing the 0th bit:%02lx\n", addr);
	return -1;
}

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec03/06_atomic_bitwise_ops/atomic_bitwise_ops.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "063F09E5F4A9CE6A68631FD");

==> LinuxSynchronizationConcurrency/sec03/07_atomic_bitwise_op_return/atomic_bitwise_op_return.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>

unsigned long addr = 0x50;
atomic64_t val = ATOMIC_INIT(0);
MODULE_LICENSE("GPL");
static int test_init(void)
{
	//these operations always return the old value at the nth bit, indexed from LSB
	pr_info("Value before performing any atomic operations:%02lx\n", addr);
	pr_info("test_and_set_bit(0, &addr):%d\n", test_and_set_bit(0, &addr));
	pr_info("Value after setting the 0th bit:%02lx\n", addr);
	pr_info("test_and_clear_bit(4, &addr):%d\n", test_and_clear_bit(4, &addr));
	pr_info("Value after setting clearing the 4th bit:%02lx\n", addr);
	pr_info("test_and_change_bit(0, &addr):%d", test_and_change_bit(0, &addr));
	pr_info("Value after changing the 0th bit:%02lx\n", addr);
	return -1;
}

static void test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec03/07_atomic_bitwise_op_return/atomic_bitwise_op_return.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E46BE5D4276EDE2E570C400");

==> LinuxSynchronizationConcurrency/sec04/00_spinlock_api/spinlock_api.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/spinlock.h>

MODULE_LICENSE("GPL");

DEFINE_SPINLOCK(my_lock); // => spinlock_t my_lock = __SPIN_LOCK_UNLOCKED(my_lock);

static int __init test_init(void)
{
	spin_lock(&my_lock); // => Locks the spin lock
	pr_info("Starting critical region\n");
	pr_info("Ending critical region\n");
	spin_unlock(&my_lock); // => Unlocks the spin lock
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec04/01_dynamic_spinlock/dynamic_spinlock.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/spinlock.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
spinlock_t *my_lock;

static int __init test_init(void)
{
	my_lock = kmalloc(sizeof(spinlock_t), GFP_KERNEL);
	spin_lock_init(my_lock); //inittializes the spin lock at run time
	spin_lock(my_lock);
	pr_info("Starting critical region\n");
	pr_info("Ending critical region\n");
	spin_unlock(my_lock);
	kfree(my_lock);

	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec04/01_dynamic_spinlock/dynamic_spinlock.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0x50d4de4, "pv_ops" },
	{ 0xc5850110, "printk" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BC5D321D9696DE613385442");

==> LinuxSynchronizationConcurrency/sec04/02_spinlock_kthreads/spinlock_kthreads.c <==
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/spinlock.h>
#include <linux/kthread.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
unsigned int counter; //shared data
DEFINE_SPINLOCK(counter_lock);
struct task_struct *read_thread, *write_thread;

static int writer_function(void *data)
{
	while(!kthread_should_stop()) 
	{
		spin_lock(&counter_lock);
		counter++;
		spin_unlock(&counter_lock);
		msleep(500);
	}
	do_exit(0);
}

static int read_function(void *data)
{
	while(!kthread_should_stop())
	{
		spin_lock(&counter_lock);
		pr_info("counter: %d\n", counter);
		spin_unlock(&counter_lock);
		msleep(500);
	}
	do_exit(0);
}

static int __init my_mod_init(void)
{
	pr_info("Entering module\n");
	counter = 0;

	read_thread = kthread_run(read_function, NULL, "read-thread");
	write_thread = kthread_run(writer_function, NULL, "write-thread");

	return 0;
}

static void __exit my_mod_exit(void)
{
	pr_info("%s: in exit\n", __func__);
	kthread_stop(read_thread);
	kthread_stop(write_thread);
}

module_init(my_mod_init);
module_exit(my_mod_exit);

==> LinuxSynchronizationConcurrency/sec04/02_spinlock_kthreads/spinlock_kthreads.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x514011c4, "kthread_stop" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0xf9a482f9, "msleep" },
	{ 0x50d4de4, "pv_ops" },
	{ 0xc5850110, "printk" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x952664c5, "do_exit" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "FF9D86F04244230E5145897");

==> LinuxSynchronizationConcurrency/sec04/03_deadlock_spinlock/deadlock_spinlock.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/spinlock.h>

MODULE_LICENSE("GPL");

DEFINE_SPINLOCK(my_lock);

static int __init test_init(void)
{
	spin_lock(&my_lock);
	pr_info("Starting critical region\n");
	spin_lock(&my_lock);
	pr_info("Ending critical region\n");
	spin_unlock(&my_lock);
	return -1;
}

static void test_exit(void)
{
	spin_unlock(&my_lock);
	spin_unlock(&my_lock);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec04/03_deadlock_spinlock/deadlock_spinlock.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x50d4de4, "pv_ops" },
	{ 0xc5850110, "printk" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1EDF1153E7C06D56DB019C7");

==> LinuxSynchronizationConcurrency/sec04/04_spinlock_chardriver/spinlock_chardriver.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/spinlock.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "msg";

static struct class *myclass = NULL;
static struct device *mydevice = NULL;
static struct cdev *mycdev = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

DEFINE_SPINLOCK(my_lock);

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s: Trying to acquire spinlock on processor:%d\n", __func__, smp_processor_id());
	spin_lock(&my_lock);
	pr_info("%s: Spinlock acquired on processor:%d\n", __func__, smp_processor_id());
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	spin_unlock(&my_lock);
	pr_info("%s: Spinlock released on processor:%d\n", __func__, smp_processor_id());
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t read_count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	pr_info("%s read offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);

	if (read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;

	if (bytes_to_read == 0){
		pr_err("%s: No available space in the buffer for reading\n", __func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
		bytes_to_read = buffer_index - *offset;
	else
		return 0;

	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);

	//update file offset
	*offset += bytes_read;

	return bytes_read;
}
		

	static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t write_count, loff_t *offset)
{		
	int bytes_written;
	int available_space;
	int bytes_to_write;

	pr_info("%s: write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *offset;

	if (write_count < available_space)
		bytes_to_write = write_count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0)
	{
		pr_err("%s: No available space in the buffer for writing\n", __func__);
		return -ENOSPC;
	}	

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);

	pr_info("%s:Bytes writtten:%d\n", __func__, bytes_written);
	pr_info("%s:Kernel Buffer:%s\n", __func__, kernel_buffer);

	*offset += bytes_written;
	buffer_index += bytes_written;
	return bytes_written;
}	


struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_init(void)
{
	myclass = class_create(THIS_MODULE, "winning_class");
	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered, Major:%d\n", MAJOR(devicenumber));
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();

		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_err("Device number not registered\n");

	return 0;
}

static void test_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec04/04_spinlock_chardriver/spinlock_chardriver.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0xe340d421, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0x9f4f34bc, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x50d4de4, "pv_ops" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B2AB0EAA0A759FE224962B8");

==> LinuxSynchronizationConcurrency/sec04/04_spinlock_chardriver/userapp.c <==
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv)
{
	int fd;
	unsigned int i = 0;

	fd = open("/dev/msg", O_RDWR);
	if (fd < 0) {
		perror("fd failed");
		exit(2);
	}
	for (i = 0; i < 2UL * INT_MAX; i++);
	close(fd);
}

==> LinuxSynchronizationConcurrency/sec04/05_spin_trylock/spin_trylock.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/spinlock.h>

dev_t devicenumber;
int base_minor = 0;
int count = 1;
char *device_name = "msg";

static struct class *myclass  = NULL;
static struct device *mydevice  = NULL;
static struct cdev *mycdev  = NULL;

#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");

DEFINE_SPINLOCK(my_lock);

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s Trying to acquire spinlock on processor: %d", __func__, smp_processor_id());
	if (!spin_trylock(&my_lock))
		return -EBUSY;
	pr_info("%s: Spinlock acquired on processor:%d\n", __func__, smp_processor_id());
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
} 

static int device_release(struct inode *inode, struct file *file)
{
	spin_unlock(&my_lock);
	pr_info("%s: Spinlock released on processor:%d\n", __func__, smp_processor_id());
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t read_count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	pr_info("%s: Read offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *offset;

	if (read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading\n", __func__);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
		bytes_to_read = buffer_index - *offset;
	else
		return 0;

	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);
	pr_info("%s: Copy to user returned: %d\n",  __func__, bytes_to_read);

	*offset += bytes_read;
		
	return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t write_count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;

	pr_info("%s: Write offset:%lld", __func__, *offset);
	available_space = MAX_SIZE - *offset;
	
	if (write_count < available_space)
		bytes_to_write = write_count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0) {
		pr_err("%s: No available space in the buffer for writing\n", __func__);
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);
	pr_info("Bytes written: %d", bytes_written);
	pr_info("Kernel buffer: %s", kernel_buffer);

	*offset += bytes_written;
	buffer_index += bytes_written;

	return bytes_written;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

static int test_init(void)
{
	myclass = class_create(THIS_MODULE, "winclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name))
	{
		pr_info("Device number registered, MAJOR" );
		mydevice = device_create(myclass, NULL, devicenumber, NULL, device_name);
		mycdev = cdev_alloc();

		if (mycdev)
		{
			cdev_init(mycdev, &fops);
			mycdev->owner = THIS_MODULE;
			cdev_add(mycdev, devicenumber, count);
		}
	}
	else
		pr_err("Print Device number not registerd.");


	return 0;
}

static void test_exit(void)
{
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
	cdev_del(mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_init);
module_exit(test_exit);


==> LinuxSynchronizationConcurrency/sec04/05_spin_trylock/spin_trylock.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0xe340d421, "device_destroy" },
	{ 0xd5f10699, "cdev_add" },
	{ 0x4240b5cb, "cdev_init" },
	{ 0x54dc6ab9, "cdev_alloc" },
	{ 0x9f4f34bc, "device_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa946dcde, "__class_create" },
	{ 0x50d4de4, "pv_ops" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x56470118, "__warn_printk" },
	{ 0xfef216eb, "_raw_spin_trylock" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2BB5DA6CFF29DF240FADEEE");

==> LinuxSynchronizationConcurrency/sec04/05_spin_trylock/userapp.c <==
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

int main(int argc, char **argv)
{
	int fd;
	unsigned int i = 0;

	fd = open("/dev/msg", O_RDWR);
	if (fd< 0) {
		perror("fd failed");
		exit(2);
	}
	for (i = 0; i < 2UL * INT_MAX; i++);
	close(fd);
}

==> LinuxSynchronizationConcurrency/sec04/06_msleep_criticalsction/msleep_critreg.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/spinlock.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
spinlock_t *my_lock;

static int __init test_init(void)
{
	my_lock = kmalloc(sizeof(spinlock_t), GFP_KERNEL);
	spin_lock_init(my_lock);
	spin_lock(my_lock);
	pr_info("Starting critical region\n");
	msleep(1000);
	pr_info("Ending critical region\n");
	spin_unlock(my_lock);
	kfree(my_lock);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec04/06_msleep_criticalsction/msleep_critreg.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0x50d4de4, "pv_ops" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc5850110, "printk" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B2E689FDC14C7BE3376EDF3");

==> LinuxSynchronizationConcurrency/sec05/00_semaphore_dynamic/semaphore_dynalloc.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/semaphore.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

struct semaphore *mysem;

static int __init test_init(void)
{
	mysem = kmalloc(sizeof(mysem), GFP_KERNEL);
	sema_init(mysem, 1);	//Counter is 1 so binary semaphore
	down(mysem);
	pr_info("Starting critical region\n");
	pr_info("Ending critical region\n");
	up(mysem);
	kfree(mysem);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec05/00_semaphore_dynamic/semaphore_dynalloc.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0xcf2a6966, "up" },
	{ 0xc5850110, "printk" },
	{ 0x6626afca, "down" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6038A16FC1ADB9A082CF0E6");

==> LinuxSynchronizationConcurrency/sec05/01_semaphore_down_up/semaphore_down_up.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/semaphore.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

struct semaphore *mysem;

static int __init test_init(void)
{
	mysem = kmalloc(sizeof(mysem), GFP_KERNEL);
	sema_init(mysem, 4);
	pr_info("semaphore count:%d\n", mysem->count);
	down(mysem);
	pr_info("semaphore count:%d\n", mysem->count);
	pr_info("Starting critical region\n");
	pr_info("Ending critical region\n");
	up(mysem);
	pr_info("semaphore count:%d\n", mysem->count);
	return -1;
}	

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);


==> LinuxSynchronizationConcurrency/sec05/01_semaphore_down_up/semaphore_down_up.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xcf2a6966, "up" },
	{ 0x6626afca, "down" },
	{ 0xc5850110, "printk" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D23440B3F42CFB16C006011");

==> LinuxSynchronizationConcurrency/sec05/02_TASK_UNINTERRUPTIBLE/TASK_UNINTERRUPTIBLE.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/semaphore.h>

MODULE_LICENSE("GPL");

struct semaphore mysem;

static int __init test_init(void)
{
	sema_init(&mysem, 2);
	pr_info("mysem.count:0x%x\n", mysem.count);
	down(&mysem);
	pr_info("mysem.count:0x%x\n", mysem.count);
	down(&mysem);
	pr_info("mysem.count:0x%x\n", mysem.count);
	down(&mysem);
	pr_info("mysem.count:0x%x\n", mysem.count);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec05/02_TASK_UNINTERRUPTIBLE/TASK_UNINTERRUPTIBLE.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6626afca, "down" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8A4D3F33E6EB5B5799B0F72");

==> LinuxSynchronizationConcurrency/sec05/03_producer_consumer/producer_consumer.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/semaphore.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

struct semaphore *mysem;
static struct task_struct *thread1, *thread2;
char buffer[10];

static int producer(void *arg)
{
	char ch = 'A';
	while (!kthread_should_stop())
	{
		pr_info("%s trying to acquire semaphore on processor: %d\n", __func__, smp_processor_id());
		down(mysem);
		pr_info("%s acquired semaphore on processor:%d\n", __func__, smp_processor_id());
		memset(buffer, ch, sizeof(buffer) -1);
		msleep(20*1000L);
		pr_info("%s releasing semaphore on processor:%d\n", __func__, smp_processor_id());
		up(mysem);
		ch++;
	}
	return 0;
}

static int consumer(void *arg)
{
	while (!kthread_should_stop())
	{
		pr_info("%s trying to acquire semaphore on processor: %d\n", __func__, smp_processor_id());
		down(mysem);
		pr_info("%s acquired semaphore on processor:%d\n", __func__, smp_processor_id());
		pr_info("%s Consumed Data:%s\n", __func__, buffer);
		pr_info("%s Cleared Data\n", __func__);
		memset(buffer, 0, sizeof(buffer));
		msleep(20*1000L);
		pr_info("%s releasing semaphore on processor:%d\n", __func__, smp_processor_id());
		up(mysem);
	}

	return 0;
}

static int __init test_init(void)
{
	mysem = kmalloc(sizeof(mysem), GFP_KERNEL);
	memset(buffer, 0, sizeof(buffer));
	sema_init(mysem, 1);
	thread1 = kthread_run(producer, NULL, "thread1");
	thread2 = kthread_run(consumer, NULL, "thread2");

	return 0;
}

static void __exit test_exit(void)
{
	kthread_stop(thread1);
	kthread_stop(thread2);
	kfree(mysem);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec05/03_producer_consumer/producer_consumer.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0x514011c4, "kthread_stop" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xcf2a6966, "up" },
	{ 0xf9a482f9, "msleep" },
	{ 0x6626afca, "down" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E36E48089123B11FDACC298");

==> LinuxSynchronizationConcurrency/sec05/04_down_interruptible/down_interruptible.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/semaphore.h>

MODULE_LICENSE("GPL");

struct semaphore mysem;

static int __init test_init(void)
{
	int ret;
	sema_init(&mysem, 1);
	pr_info("mysem.count:0x%x\n", mysem.count);
	down(&mysem);
	pr_info("mysem.count:0x%x\n", mysem.count);
	ret = down_interruptible(&mysem);
	pr_info("mysem.count:0x%x\t ret:%d\n", mysem.count, ret);
	up(&mysem);
	pr_info("mysem.count:0x%x\n", mysem.count);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec05/04_down_interruptible/down_interruptible.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xcf2a6966, "up" },
	{ 0x6bd0e573, "down_interruptible" },
	{ 0x6626afca, "down" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6C15FBBAF3DD49E2EE79006");

==> LinuxSynchronizationConcurrency/sec05/05_down_trylock/down_trylock.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/semaphore.h>

MODULE_LICENSE("GPL");

struct semaphore mysem;

static int __init test_init(void)
{
	int ret;
	sema_init(&mysem, 1);
	pr_info("mysem.count:0x%x\n", mysem.count);
	down(&mysem);
	pr_info("mysem.count:0x%x\n", mysem.count);
	ret = down_trylock(&mysem);
	pr_info("mysem.count:0x%x\t ret:%d\n", mysem.count, ret);
	up(&mysem);
	pr_info("mysem.count:0x%x\n", mysem.count);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec05/05_down_trylock/down_trylock.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xcf2a6966, "up" },
	{ 0xe9ffc063, "down_trylock" },
	{ 0x6626afca, "down" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "70B1DF7647A0AAC36704A21");

==> LinuxSynchronizationConcurrency/sec05/06_down_timeout/down_timeout.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/semaphore.h>

MODULE_LICENSE("GPL");

struct semaphore mysem;

static int __init test_init(void)
{
	int ret;
	sema_init(&mysem, 2);
	pr_info("mysem.count:0x%x\n", mysem.count);
	ret = down_timeout(&mysem,1000);
	pr_info("mysem.count:0x%x\t ret:%d\n", mysem.count, ret);
	ret = down_timeout(&mysem,1000);
	pr_info("mysem.count:0x%x\t ret:%d\n", mysem.count, ret);
	ret = down_timeout(&mysem,1000);
	pr_info("mysem.count:0x%x\t ret:%d\n", mysem.count, ret);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec05/06_down_timeout/down_timeout.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x92e683f5, "down_timeout" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7BF4B3EF47914AE90139BDD");

==> LinuxSynchronizationConcurrency/sec05/07_down_killable/down_killable.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/semaphore.h>

MODULE_LICENSE("GPL");

struct semaphore mysem;

static int __init test_init(void)
{
	int ret;
	sema_init(&mysem, 1);
	pr_info("mysem.count:0x%x\n", mysem.count);
	down(&mysem);
	pr_info("mysem.count:0x%x\n", mysem.count);
	ret = down_killable(&mysem);
	pr_info("mysem.count:0x%x\t ret:%d\n", mysem.count, ret);
	up(&mysem);
	pr_info("mysem.count:0x%x\n", mysem.count);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec05/07_down_killable/down_killable.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xcf2a6966, "up" },
	{ 0x36b6ebbf, "down_killable" },
	{ 0x6626afca, "down" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "67168D93CCE0D2F31324FCF");

==> LinuxSynchronizationConcurrency/sec06/00_mutex_dynamic/mutex_dynamic.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

struct mutex *mylock;

static int __init test_init(void)
{
	mylock = kmalloc(sizeof(mylock), GFP_KERNEL);
	mutex_init(mylock);
	mutex_lock(mylock);
	pr_info("Starting critical region\n");
	pr_info("Ending critical region\n");
	mutex_unlock(mylock);
	kfree(mylock);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec06/01_mutex_static/mutex_static.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

DEFINE_MUTEX(mylock);

static int __init test_init(void)
{
	mutex_lock(&mylock);
	pr_info("Starting critical region\n");
	pr_info("Ending critical region\n");
	mutex_unlock(&mylock);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec06/01_mutex_static/mutex_static.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x409bcb62, "mutex_unlock" },
	{ 0xc5850110, "printk" },
	{ 0x2ab7989d, "mutex_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "16CBA10E66E32CCAE59EF4A");

==> LinuxSynchronizationConcurrency/sec06/02_mutex_sleep/mutex_sleep.c <==
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/mutex.h>
#include <linux/delay.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
DEFINE_MUTEX(mylock); //dynamic declaration via macro
static struct task_struct *thread1, *thread2;

static int threadfn(void *arg)
{
	pr_info("Processor: %d, trying to acquire semaphore\n", smp_processor_id());
	mutex_lock(&mylock);
	pr_info("Starting critical region on processor: %d\n", smp_processor_id());
	msleep(2000);
	pr_info("Ending critical region\n");
	mutex_unlock(&mylock);
	pr_info("Processor: %d, releasing semaphore\n", smp_processor_id());
	return 0;
}

static int __init test_init(void)
{
	mutex_init(&mylock); //dynamic initialization
	thread1 = kthread_run(threadfn, NULL, "thread1");
	thread2 = kthread_run(threadfn, NULL, "thread2");

	return 0;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec06/02_mutex_sleep/mutex_sleep.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0x977f511b, "__mutex_init" },
	{ 0x409bcb62, "mutex_unlock" },
	{ 0xf9a482f9, "msleep" },
	{ 0x2ab7989d, "mutex_lock" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6B70203B14982DDDD701A3B");

==> LinuxSynchronizationConcurrency/sec06/03_mutex_trylock/mutex_trylock.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

DEFINE_MUTEX(mylock);
static struct task_struct *thread1, *thread2;

static int threadfn(void *arg)
{
	int ret;
	ret = mutex_trylock(&mylock);
	pr_info("Starting critical region on processor:%d with ret:%d\n", smp_processor_id(), ret);
	msleep(2000);
	pr_info("Ending critical region\n");
	if(!ret)
		mutex_unlock(&mylock);

	return 0;
}

static int __init test_init(void)
{
	mutex_init(&mylock);
	thread1 = kthread_run(threadfn, NULL, "thread1");
	thread2 = kthread_run(threadfn, NULL, "thread2");

	return 0;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec06/03_mutex_trylock/mutex_trylock.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0x977f511b, "__mutex_init" },
	{ 0x409bcb62, "mutex_unlock" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xf21017d9, "mutex_trylock" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8B53E2440AA3D952ED46ACF");

==> LinuxSynchronizationConcurrency/sec06/04_unlock_from_non_owner/unlock_from_non_owner.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/kthread.h>

MODULE_LICENSE("GPL");
DEFINE_MUTEX(my_lock);
struct task_struct *mythread;

static int threadfn(void *data)
{
	pr_info("Kernel thread running on processor:%d\n", smp_processor_id());
	pr_info("Kernel thread unlocking on processor:%d\n", smp_processor_id());
	mutex_unlock(&my_lock);
	pr_info("Kernel thread unlocked withou calling lock on processor:%d\n", smp_processor_id());
	return 0;
}

static int __init test_init(void)
{
	pr_info("Init function running on processor:%d\n", smp_processor_id());
	mutex_lock_interruptible(&my_lock);
	pr_info("Init function locked on processor:%d\n", smp_processor_id());
	mythread = kthread_run(threadfn, NULL, "mythread");
	msleep(8000);
	pr_info("Init function completed on processor:%d\n", smp_processor_id());
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec06/04_unlock_from_non_owner/unlock_from_non_owner.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xf9a482f9, "msleep" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0xb5136dc7, "mutex_lock_interruptible" },
	{ 0x409bcb62, "mutex_unlock" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6812386AD2F7BDA3DA46D18");

==> LinuxSynchronizationConcurrency/sec06/05_recursive_mutex_locks/recursive_lock.c <==
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

struct mutex *mylock;

static int __init test_init(void)
{
	mylock = kmalloc(sizeof(mylock), GFP_KERNEL);
	mutex_init(mylock);
	mutex_lock_interruptible(mylock);
	pr_info("Starting critical region\n");
	mutex_lock_interruptible(mylock);
	pr_info("Ending critical region\n");
	mutex_unlock(mylock);
	kfree(mylock);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec06/05_recursive_mutex_locks/recursive_lock.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0x409bcb62, "mutex_unlock" },
	{ 0xc5850110, "printk" },
	{ 0xb5136dc7, "mutex_lock_interruptible" },
	{ 0x977f511b, "__mutex_init" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "CE5006C712696D5D8C6D18C");

==> LinuxSynchronizationConcurrency/sec06/06_mutex_is_locked/mutex_is_locked.c <==
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

struct mutex *mylock;

static int __init test_init(void)
{
	mylock = kmalloc(sizeof(mylock), GFP_KERNEL);
	mutex_init(mylock);
	mutex_lock(mylock);
	pr_info("Starting critical region\n");
	if (mutex_is_locked(mylock))
		pr_info("mutex is locked\n");
	else
		pr_info("mutex is unlocked\n");
	pr_info("Ending critical region\n");
	mutex_unlock(mylock);
	if (mutex_is_locked(mylock))
		pr_info("mutex is locked\n");
	else
		pr_info("mutex is unlocked\n");
	kfree(mylock);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec06/06_mutex_is_locked/mutex_is_locked.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0x409bcb62, "mutex_unlock" },
	{ 0x318d6fec, "mutex_is_locked" },
	{ 0xc5850110, "printk" },
	{ 0x2ab7989d, "mutex_lock" },
	{ 0x977f511b, "__mutex_init" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7296D4D628087F49067B0FC");

==> LinuxSynchronizationConcurrency/sec07/00_read_write_lock_problem/rw_lock_problem.c <==
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

DEFINE_MUTEX(mylock);

static struct proc_dir_entry *dir_entry;
int counter = 0;

static ssize_t mywrite(struct file *file, const char __user *ubuf, size_t count, loff_t *ppos)
{
	mutex_lock(&mylock);
	pr_info("write handler\n");
	msleep(5000);
	counter++;
	mutex_unlock(&mylock);
	return count;
}

static ssize_t myread(struct file *file, char __user *ubuf, size_t count, loff_t *ppos)
{
	mutex_lock(&mylock);
	pr_info("read handler: %d\n", counter);
	msleep(10000);
	mutex_unlock(&mylock);
	return 0;
}

static struct proc_ops cpu_ops = {
  .proc_read = myread,
  .proc_write = mywrite
};

static int proc_init(void)
{
	dir_entry = proc_create("ldd", 0666, NULL, &cpu_ops);
	if (!dir_entry) {
		pr_err("%s: error creating proc-entry\n", __func__);
		return -1;
	}
	pr_info("ldd proc entry created\n");
	return 0;
}


static void proc_cleanup(void)
{
	remove_proc_entry("ldd", NULL);
}

module_init(proc_init);
module_exit(proc_cleanup);

==> LinuxSynchronizationConcurrency/sec07/00_read_write_lock_problem/rw_lock_problem.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xb75bc01, "remove_proc_entry" },
	{ 0xbe8b05f8, "proc_create" },
	{ 0x409bcb62, "mutex_unlock" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc5850110, "printk" },
	{ 0x2ab7989d, "mutex_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7FBCFE9E52E886AFEBBB764");

==> LinuxSynchronizationConcurrency/sec07/01_rw_spinlock_api/comp.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rwlock_types.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

DEFINE_RWLOCK(mylock);
static struct task_struct *thread1, *thread2, *thread3;

int counter = 0;

static int write_threadfn(void *arg)
{
	while(!kthread_should_stop())
	{
		pr_info("processor:%d trying to acquire write lock\n", smp_processor_id());
		write_lock(&mylock);
		pr_info("processor:%d acquired write lock\n", smp_processor_id());
		counter++;
		mdelay(3000);
		write_unlock(&mylock);
		pr_info("processor%d released write lock\n", smp_processor_id());
	}
	return 0;
}

static int read_threadfn(void *arg)
{
	while(!kthread_should_stop())
	{
		pr_info("processor:%d trying to acquire read lock\n", smp_processor_id());
		read_lock(&mylock);
		pr_info("processor:%d acquired read lock\n", smp_processor_id());
		pr_info("processor%d\t counter:%d\n", smp_processor_id(), counter);
		mdelay(2000);
		read_unlock(&mylock);
		pr_info("processor:%d releasing read lock\n", smp_processor_id());
	}
	return 0;
}

static int __init test_hello_init(void)
{
    thread1 = kthread_run(read_threadfn, NULL, "thread1");
    thread2 = kthread_run(read_threadfn, NULL, "thread2");
    thread3 = kthread_run(write_threadfn, NULL, "thread3");

    return 0;
}

static void __exit test_hello_exit(void)
{
	kthread_stop(thread1);
	kthread_stop(thread2);
	kthread_stop(thread3);
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxSynchronizationConcurrency/sec07/01_rw_spinlock_api/rw_spinlock_api.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rwlock_types.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

DEFINE_RWLOCK(mylock);
static struct task_struct *thread1, *thread2, *thread3;

int counter = 0;

static int write_threadfn(void *arg)
{
	while (!kthread_should_stop())
	{
		pr_info("processor:%d trying to acquire write lock\n", smp_processor_id());
		write_lock(&mylock);
		pr_info("processor:%d acquired write lock\n", smp_processor_id());
		counter++;
		msleep(3000);
		write_unlock(&mylock);
		pr_info("processor:%d released write lock\n", smp_processor_id());
	}

	return 0;
}

static int read_threadfn(void *arg)
{
	while(!kthread_should_stop())
	{
		pr_info("processor:%d trying to acquire read lock\n", smp_processor_id());
		read_lock(&mylock);
		pr_info("processor:%d acquired read lock\n", smp_processor_id());
		pr_info("processor:%d counter:%d\n", smp_processor_id(), counter);
		msleep(2000);
		read_unlock(&mylock);
		pr_info("processor:%d released read lock\n", smp_processor_id());
	}

	return 0;
}

static int __init test_init(void)
{
	thread1 = kthread_run(read_threadfn, NULL, "thread1");
	thread2 = kthread_run(read_threadfn, NULL, "thread2");
	thread3 = kthread_run(write_threadfn, NULL, "thread3");

	return 0;
}

static void __exit test_exit(void)
{
	kthread_stop(thread1);
	kthread_stop(thread2);
	kthread_stop(thread3);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec07/01_rw_spinlock_api/rw_spinlock_api.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x514011c4, "kthread_stop" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0xf9a482f9, "msleep" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "543331070F7EA66093481EB");

==> LinuxSynchronizationConcurrency/sec07/02_recursive_read_locks/recursive_read_locks.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rwlock_types.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

DEFINE_RWLOCK(mylock);

static int __init test_init(void)
{
	rwlock_init(&mylock);
	pr_info("trying to get the read lock once\n");
	read_lock(&mylock);
	pr_info("Acquired read lock once\n");
	msleep(2000);
	pr_info("trying to get the read lock twice\n");
	read_lock(&mylock);
	pr_info("Acquired read lock twice\n");
	msleep(2000);
	pr_info("Unlocking read lock once\n");
	read_unlock(&mylock);
	pr_info("Unlocking read lock twice\n");
	read_unlock(&mylock);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec07/02_recursive_read_locks/recursive_read_locks.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xf9a482f9, "msleep" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A337B045BA97E243343282F");

==> LinuxSynchronizationConcurrency/sec07/03_read_write_read_pref/comp.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <asm/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/rwlock_types.h>
#include <linux/delay.h>
#include "ioctl_cmd.h"



#define DEVICE_NAME	"msg"
#define MAX_SIZE        1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");
DEFINE_RWLOCK(mylock);

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
        return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer,
                      size_t read_count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	pr_info("processor :%d acquiring read lock\n", smp_processor_id());
	read_lock(&mylock);
	pr_info("processor :%d acquired read lock\n", smp_processor_id());
	pr_info("%s read offset:%lld\n", __func__, *offset);
	msleep(20000);
	 available_space = MAX_SIZE - *(offset);

	if (read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;
	
	pr_info("bytes_to_read:%d\n", bytes_to_read);

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading\n",
				__func__);
		read_unlock(&mylock);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
                bytes_to_read = buffer_index - *offset;
        else {

		read_unlock(&mylock);
                return 0;
	}


	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer+*offset, bytes_to_read);
	pr_info("%s: Copy to user returned:%d\n", __func__, bytes_to_read);

	//update file offset
	*offset += bytes_read;

	read_unlock(&mylock);
        return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer,
                       size_t write_count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;

	pr_info("processor :%d acquiring write lock\n", smp_processor_id());
	write_lock(&mylock);
	pr_info("processor :%d acquired write lock\n", smp_processor_id());
	pr_info("%s write offset:%lld\n", __func__, *offset);
	available_space = MAX_SIZE - *(offset);

	if (write_count < available_space)
		bytes_to_write = write_count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0) {
		pr_err("%s: No available space in the buffer for writing\n",
				__func__);
		write_unlock(&mylock);
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer+*offset,  user_buffer, bytes_to_write);
	pr_info("%s: Bytes written:%d\n", __func__, bytes_written);
	pr_info("%s: kernel_buffer:%s\n", __func__, kernel_buffer);

	//update file offset
	*offset += bytes_written;
	buffer_index += bytes_written;
	write_unlock(&mylock);
        return bytes_written;
}

static loff_t device_lseek(struct file *file, loff_t offset, int orig)
{
        loff_t new_pos = 0;

        switch(orig) {
                case 0 : /*seek set*/
                        new_pos = offset;
                        break;
                case 1 : /*seek cur*/
                        new_pos = file->f_pos + offset;
                        break;
                case 2 : /*seek end*/
                        new_pos = MAX_SIZE - offset;
                        break;
        }
        if(new_pos > MAX_SIZE)
                new_pos = MAX_SIZE;
        if(new_pos < 0)
                new_pos = 0;
        file->f_pos = new_pos;
        return new_pos;
}



long device_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	int retval = 0;
	long size = _IOC_SIZE(cmd);

	pr_info("%s: Cmd:%u\t Arg:%lu Size:%lu add:%p\n", __func__, cmd, arg, size, &ch);

	if (_IOC_TYPE(cmd) != MSG_MAGIC_NUMBER) return -ENOTTY;
	if (_IOC_NR(cmd) > MSG_IOCTL_MAX_CMDS) return -ENOTTY;

	//access_ok is kernel-oriented, so the concept of read and write is reversed
	
	retval = access_ok((void __user *)arg, size);

	pr_info("access_ok returned:%d\n", retval);
	if (!retval)
		return -EFAULT;

	switch(cmd)
	{
		//Get Length of buffer
		case MSG_IOCTL_GET_LENGTH:
			pr_info("Get Buffer Length\n");
			put_user(MAX_SIZE, (unsigned int *)arg);
			break;
		//clear buffer
		case MSG_IOCTL_CLEAR_BUFFER:
			pr_info("Clear buffer\n");
			memset(kernel_buffer, 0, sizeof(kernel_buffer));
			break;
		//fill character
		case MSG_IOCTL_FILL_BUFFER:
			get_user(ch, (unsigned char *)arg);
			pr_info("Fill Character:%c\n", ch);
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			buffer_index = sizeof(kernel_buffer);
			break;
		//address of kernel buffer
		case MSG_GET_ADDRESS:
			put_user(0x12345678, (unsigned long*)arg);
			pr_info("MSG_GET_ADDRESS\n");
			break;
		default:
			pr_info("Unknown Command:%u\n", cmd);
			return -ENOTTY;
	}
	return 0;
}


long device_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	int retval = 0;
	long size = _IOC_SIZE(cmd);
	unsigned int tmp_cmd = _IOR(MSG_MAGIC_NUMBER, 4, u32);

	pr_info("%s: Cmd:%u\t Arg:%lu Size:%lu tm_cmd:%u\n", __func__, cmd, arg, size, tmp_cmd);


	if (_IOC_TYPE(cmd) != MSG_MAGIC_NUMBER) return -ENOTTY;
	if (_IOC_NR(cmd) > MSG_IOCTL_MAX_CMDS) return -ENOTTY;

	if (cmd == tmp_cmd)
		cmd = MSG_GET_ADDRESS;

	//access_ok is kernel-oriented, so the concept of read and write is reversed
	
	retval = access_ok((void __user *)arg, size);

	pr_info("access_ok returned:%d\n", retval);
	if (!retval)
		return -EFAULT;

	switch(cmd)
	{
		//Get Length of buffer
		case MSG_IOCTL_GET_LENGTH:
			pr_info("Get Buffer Length\n");
			put_user(MAX_SIZE, (unsigned int *)arg);
			break;
		//clear buffer
		case MSG_IOCTL_CLEAR_BUFFER:
			pr_info("Clear buffer\n");
			memset(kernel_buffer, 0, sizeof(kernel_buffer));
			break;
		//fill character
		case MSG_IOCTL_FILL_BUFFER:
			get_user(ch, (unsigned char *)arg);
			pr_info("Fill Character:%c\n", ch);
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			buffer_index = sizeof(kernel_buffer);
			break;
		//address of kernel buffer
		case MSG_GET_ADDRESS:
			put_user(0x12345678, (unsigned long*)arg);
			pr_info("MSG_GET_ADDRESS\n");
			break;
		default:
			pr_info("Unknown Command:%u\n", cmd);
			return -ENOTTY;
	}
	return 0;
}




struct file_operations device_fops = {
	.owner = THIS_MODULE,
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
	.unlocked_ioctl = device_ioctl,
	.compat_ioctl = device_compat_ioctl
};

static struct miscdevice my_misc_device = {
    .minor = 121,
    .name = DEVICE_NAME,
    .fops = &device_fops
};



static int test_hello_init(void)
{
	if (misc_register(&my_misc_device)) {
		pr_err("Couldn't register device misc, "
				"%d.\n", my_misc_device.minor);
		return -EBUSY;
	}
	pr_info("Succeeded in registering character device %s\n", DEVICE_NAME);

	return 0;
}

static void test_hello_exit(void)
{
	misc_deregister(&my_misc_device);
	pr_info("device unregistered\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);


==> LinuxSynchronizationConcurrency/sec07/03_read_write_read_pref/read_write_read.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <asm/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/rwlock_types.h>
#include <linux/delay.h>
#include "ioctl_cmd.h"

#define DEVICE_NAME "msg"
#define MAX_SIZE 1024
char kernel_buffer[MAX_SIZE];
int buffer_index;
MODULE_LICENSE("GPL");
DEFINE_RWLOCK(mylock);

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	file->f_pos = 0;
	buffer_index = 0;
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer, size_t read_count, loff_t *offset)
{
	int bytes_read;
	int available_space;
	int bytes_to_read;

	pr_info("processor: %d acquiring read lock\n", smp_processor_id());
	read_lock(&mylock);
	pr_info("processor: %d acquired read lock\n", smp_processor_id());
	pr_info("%s read offset: %lld\n", __func__, *offset);
	msleep(20000);
	available_space = MAX_SIZE - *offset;

	if (read_count < available_space)
		bytes_to_read = read_count;
	else
		bytes_to_read = available_space;

	pr_info("bytes_to_read:%d\n", bytes_to_read);

	if (bytes_to_read == 0) {
		pr_err("%s: No available space in the buffer for reading\n", __func__);
		read_unlock(&mylock);
		return -ENOSPC;
	}

	if (buffer_index > *offset)
		bytes_to_read = buffer_index - *offset;
	else{
		read_unlock(&mylock);
		return 0;
	}

	bytes_read = bytes_to_read - copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);
	pr_info("%s: Copy to user returned:%d\n", __func__, bytes_to_read);

	*offset += bytes_read;
	read_unlock(&mylock);
	return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer, size_t write_count, loff_t *offset)
{
	int bytes_written;
	int available_space;
	int bytes_to_write;

	pr_info("processor: %d acquiring write lock\n", smp_processor_id());
	write_lock(&mylock);
	pr_info("processor: %d acquired write lock\n", smp_processor_id());
	pr_info("%s write offset: %lld\n", __func__, *offset);
	msleep(20000);
	available_space = MAX_SIZE - *offset;
	
	if (write_count < available_space)
		bytes_to_write = write_count;
	else
		bytes_to_write = available_space;

	if (bytes_to_write == 0) {
		pr_err("%s: No available space in the buffer for writing\n", __func__);
		write_unlock(&mylock);
		return -ENOSPC;
	}

	bytes_written = bytes_to_write - copy_from_user(kernel_buffer + *offset, user_buffer, bytes_to_write);
	pr_info("%s: Bytes written:%d\n", __func__, bytes_written);
	pr_info("%s: Kernel buffer:%s\n", __func__, kernel_buffer);

	offset += bytes_written;
	buffer_index += bytes_written;
	write_unlock(&mylock);
	return bytes_written;
}	

static loff_t device_lseek(struct file *file, loff_t offset, int cmd)
{
	loff_t new_pos = 0;

	switch(cmd) {
		case 0: //seek set
			new_pos = offset;
			break;
		case 1: //seek curr
			new_pos = file->f_pos + offset;
			break;
		case 2: //seek end
			new_pos = MAX_SIZE - offset;
			break;
	}
	if (new_pos > MAX_SIZE)
		new_pos = MAX_SIZE;
	if (new_pos < 0)
		new_pos = 0;
	file->f_pos = new_pos;
	return new_pos;
}

long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	unsigned char ch;
	int retval = 0;
	long size = _IOC_SIZE(cmd);

	pr_info("%s: Cmd:%u\tArg:%luSize;%lu add:%p\n", __func__, cmd, arg, size, &ch);
	
	if (_IOC_TYPE(cmd) != MSG_MAGIC_NUMBER) return -ENOTTY;
	if ((_IOC_NR(cmd)) > MSG_IOCTL_MAX_CMDS) return -ENOTTY;

	//access_ok is kernel oriented, so the concept of read and write is reversed.

	pr_info("access_ok returned:%d", retval);
	if (!retval)
		return -EFAULT;

	switch(cmd) 
	{
		case MSG_IOCTL_GET_LENGTH:
			pr_info("Get Buffer Length\n");
			put_user(MAX_SIZE, (unsigned int *) arg);
			break;
		case MSG_IOCTL_CLEAR_BUFFER:
			pr_info("Clear buffer\n");
			memset(kernel_buffer, 0, sizeof(kernel_buffer));
			break;
		case MSG_IOCTL_FILL_BUFFER:
			get_user(ch, (unsigned char *) arg);
			pr_info("Fill character:%c\n", ch);
			memset(kernel_buffer, ch, sizeof(kernel_buffer));
			buffer_index = sizeof(kernel_buffer);
			break;
		case MSG_IOCTL_GET_ADDRESS:
			put_user(0x12345678, (unsigned long *) arg);
			pr_info("MSG_IOCTL_GET_ADDRESS\n");
			break;  
		default:
			pr_info ("unknown Command:%u\n", cmd);
			return -ENOTTY;
	}

	return 0;
}

struct file_operations device_fops = {
	.owner = THIS_MODULE,
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
	.llseek = device_lseek,
	.unlocked_ioctl = device_ioctl
};

static struct miscdevice my_misc_device = {
	.minor = 128,
	.name = DEVICE_NAME,
	.fops = &device_fops
};

static int test_init(void)
{
	if (misc_register(&my_misc_device)) {
		pr_err("Couldn't register device misc %d.\n", my_misc_device.minor);
		return -EBUSY;
	}
	pr_info("Succeeded in registering character device %s\n", DEVICE_NAME);

	return 0;
}

static void test_exit(void)
{
	misc_deregister(&my_misc_device);
	pr_info("device unregistered\n");
}
	
module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec07/04_rw_kernelthreads/rw_kernelthreads.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rwlock_types.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

DEFINE_RWLOCK(mylock);
static struct task_struct *thread1, *thread2, *thread3;

int counter = 0;

static int write_threadfn(void *arg)
{
	pr_info("processor:%d trying to acquire write lock\n", smp_processor_id());
	write_lock(&mylock);
	pr_info("processor:%d acquired write lock\n", smp_processor_id());
	counter++;
	msleep(7000);
	write_unlock(&mylock);
	pr_info("processor:%d released write lock\n", smp_processor_id());
	return 0;
}

static int read_threadfn(void *arg)
{
	pr_info("processor:%d trying to acquire read lock\n", smp_processor_id());
	read_lock(&mylock);
	pr_info("processor:%d acquired read lock\n", smp_processor_id());
	counter++;
	msleep(5000);
	read_unlock(&mylock);
	pr_info("processor:%d released read lock\n", smp_processor_id());
	return 0;
}

static int __init test_init(void)
{
	thread1 = kthread_run(read_threadfn, NULL, "thread1");
	thread2 = kthread_run(write_threadfn, NULL, "thread2");
	thread3 = kthread_run(read_threadfn, NULL, "thread3");
	return 0;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec07/04_rw_kernelthreads/rw_kernelthreads.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0xf9a482f9, "msleep" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D729B4147BF550386242501");

==> LinuxSynchronizationConcurrency/sec07/05_rw_kernelthreads/kernelthreads_rw.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rwlock_types.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

DEFINE_RWLOCK(mylock);
static struct task_struct *thread1, *thread2, *thread3, *thread4;

int counter = 0;

static int write_threadfn(void *arg)
{
	pr_info("processor:%d trying to acquire write lock\n", smp_processor_id());
	write_lock(&mylock);
	pr_info("processor:%d acquired write lock\n", smp_processor_id());
	counter++;
	msleep(7000);
	write_unlock(&mylock);
	pr_info("processor:%d released write lock\n", smp_processor_id());
	return 0;
}

static int read_threadfn(void *arg)
{
	pr_info("processor:%d trying to acquire read lock\n", smp_processor_id());
	read_lock(&mylock);
	pr_info("processor:%d acquired read lock\n", smp_processor_id());
	counter++;
	msleep(5000);
	read_unlock(&mylock);
	pr_info("processor:%d released read lock\n", smp_processor_id());
	return 0;
}

static int __init test_init(void)
{
	thread1 = kthread_run(read_threadfn, NULL, "thread1");
	thread2 = kthread_run(write_threadfn, NULL, "thread2");
	thread3 = kthread_run(write_threadfn, NULL, "thread3");
	thread4 = kthread_run(read_threadfn, NULL, "thread3");
	return 0;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec07/05_rw_kernelthreads/kernelthreads_rw.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0xf9a482f9, "msleep" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D0B23B50CF8F17C1C2B113A");

==> LinuxSynchronizationConcurrency/sec08/00_rw_semaphores_dynalloc/rw_semaphores_dynalloc.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rwsem.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

struct rw_semaphore *mysem;

static int __init test_init(void)
{
	mysem = kmalloc(sizeof(mysem), GFP_KERNEL);
	init_rwsem(mysem);
	pr_info("count:%ld\n", atomic_long_read(&mysem->count));
	kfree(mysem);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec08/00_rw_semaphores_dynalloc/rw_semaphores_dynalloc.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0xc5850110, "printk" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2BE3BBB027C83422FA6BA47");

==> LinuxSynchronizationConcurrency/sec08/01_up_down/updown.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rwsem.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

DECLARE_RWSEM(mylock);
static struct task_struct *thread1, *thread2,  *thread3;

int counter = 0;

static int write_threadfn(void *arg)
{
	while(!kthread_should_stop())
	{
		pr_info("processor:%d trying to acquire write lock\n", smp_processor_id());
		down_write(&mylock);
		pr_info("processor:%d acquired write lock\n", smp_processor_id());
		counter++;
		msleep(5000);
		up_write(&mylock);
		pr_info("processor:%d released write lock\n", smp_processor_id());
	}
	return 0;
}

static int read_threadfn(void *arg)
{
	while(!kthread_should_stop())
	{
		pr_info("processor:%d trying to acquire read lock\n", smp_processor_id());
		down_read(&mylock);
		pr_info("processor:%d acquired read lock\n", smp_processor_id());
		counter++;
		msleep(2000);
		up_read(&mylock);
		pr_info("processor:%d released read lock\n", smp_processor_id());
	}
	return 0;
}

static int __init test_init(void)
{
	thread1 = kthread_run(read_threadfn, NULL, "thread1");
	thread2 = kthread_run(read_threadfn, NULL, "thread2");
	thread3 = kthread_run(write_threadfn, NULL, "thread3");

	return 0;
}

static void __exit test_exit(void)
{
	kthread_stop(thread1);
	kthread_stop(thread2);
	kthread_stop(thread3);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec08/01_up_down/updown.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x514011c4, "kthread_stop" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0x53b954a2, "up_read" },
	{ 0x668b19a1, "down_read" },
	{ 0xce807a25, "up_write" },
	{ 0xf9a482f9, "msleep" },
	{ 0x57bc19d2, "down_write" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0C24893F48CA289DD902C41");

==> LinuxSynchronizationConcurrency/sec08/02_downgrade_write/downgrade_write.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rwsem.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

struct rw_semaphore *mysem;

static int __init test_init(void)
{
	mysem = kmalloc(sizeof(mysem), GFP_KERNEL);
	init_rwsem(mysem);

//	pr_info("init_rwsem_count:%ld\n", atomic_long_read(&mysem->count));
//	down_write(mysem);
//	pr_info("down_write count:%ld\n", atomic_long_read(&mysem->count));
//	up_write(mysem);
//	pr_info("up_write count:%ld\n", atomic_long_read(&mysem->count));
//
//	down_read(mysem);
//	pr_info("down_read count:%ld\n", atomic_long_read(&mysem->count));
//	up_read(mysem);
//	pr_info("up_read count:%ld\n", atomic_long_read(&mysem->count));
//
	down_write(mysem);
	pr_info("down_write count:%ld\n", atomic_long_read(&mysem->count));
	downgrade_write(mysem);
	pr_info("downgrade_write count:%ld\n", atomic_long_read(&mysem->count));
	up_read(mysem);
	pr_info("up_read count:%ld\n", atomic_long_read(&mysem->count));

	kfree(mysem);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);


==> LinuxSynchronizationConcurrency/sec08/02_downgrade_write/downgrade_write.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0x53b954a2, "up_read" },
	{ 0x18888d00, "downgrade_write" },
	{ 0xc5850110, "printk" },
	{ 0x57bc19d2, "down_write" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "EB742C47706F688325A3536");

==> LinuxSynchronizationConcurrency/sec08/03_recursive_write_locks/recursive_write.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rwsem.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

struct rw_semaphore *mysem;

static int __init test_init(void)
{
	mysem = kmalloc(sizeof(mysem), GFP_KERNEL);
	init_rwsem(mysem);
	pr_info("init rwsem count: %ld\n", atomic_long_read(&mysem->count));
	down_write(mysem);
	pr_info("down write count: %lld\n", atomic_long_read(&mysem->count));
	down_write(mysem);
	pr_info("down write count:%ld\n", atomic_long_read(&mysem->count));
	kfree(mysem);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);


==> LinuxSynchronizationConcurrency/sec08/03_recursive_write_locks/recursive_write.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0x57bc19d2, "down_write" },
	{ 0xc5850110, "printk" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C0C7ACEA7FA4B944C1A8A4C");

==> LinuxSynchronizationConcurrency/sec08/04_multithread/multithread.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rwsem.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

DECLARE_RWSEM(mylock);
static struct task_struct *thread1, *thread2, *thread3,*thread4;

int counter = 0;

static int write_threadfn(void *arg)
{
	pr_info("processor:%d trying to acquire write lock\n", smp_processor_id());
	down_write(&mylock);
	pr_info("processor:%d trying to acquire write lock\n", smp_processor_id());
	counter++;
	msleep(7000);
	up_write(&mylock);
	pr_info("processor:%d trying to acquire write lock\n", smp_processor_id());
	return 0;
}

static int read_threadfn(void *arg)
{
	pr_info("processor:%d trying to acquire read lock\n", smp_processor_id());
	down_read(&mylock);
	pr_info("processor:%d trying to acquire read lock\n", smp_processor_id());
	pr_info("processor:%d counter:%d\n", smp_processor_id(), counter);
	msleep(7000);
	up_read(&mylock);
	pr_info("processor:%d trying to acquire read lock\n", smp_processor_id());
	return 0;
}

static int __init test_init(void)
{
	thread1 = kthread_run(read_threadfn, NULL, "thread1");
	thread2 = kthread_run(write_threadfn, NULL, "thread2");
	thread3 = kthread_run(read_threadfn, NULL, "thread3");
	thread4 = kthread_run(write_threadfn, NULL, "thread4");
	return 0;
}


static void __init test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec08/04_multithread/multithread.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0x53b954a2, "up_read" },
	{ 0x668b19a1, "down_read" },
	{ 0xce807a25, "up_write" },
	{ 0xf9a482f9, "msleep" },
	{ 0x57bc19d2, "down_write" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0CF9CC48809AD20871B097E");

==> LinuxSynchronizationConcurrency/sec09/00_seqlock_dynalloc/seqlock.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/seqlock.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

seqlock_t *seqlock;

static int __init test_init(void)
{
	seqlock = kmalloc(sizeof(seqlock), GFP_KERNEL);
	
	seqlock_init(seqlock);
	pr_info("Value of sequence after seqlock_init:%d\n", &seqlock->seqcount.seqcount.sequence);
	kfree(seqlock);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec09/00_seqlock_dynalloc/seqlock.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0xc5850110, "printk" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "CFBEE86EF4EFFB3C36D8493");

==> LinuxSynchronizationConcurrency/sec09/01_seqlock_write/seqlock_write.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/seqlock.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

seqlock_t *seqlock;

static int __init test_init(void)
{
	seqlock = kmalloc(sizeof(seqlock), GFP_KERNEL);

	seqlock_init(seqlock);
	pr_info("Value of sequence after seqlock_init:%d\n", seqlock->seqcount.seqcount.sequence);

	write_seqlock(seqlock);
	pr_info("Value of sequence after write_seqlock:%d\n", seqlock->seqcount.seqcount.sequence);
	write_sequnlock(seqlock);
	pr_info("Value of sequence after write_sequnlock:%d\n", seqlock->seqcount.seqcount.sequence);

	write_seqlock(seqlock);
	pr_info("Value of sequence after write_seqlock:%d\n", seqlock->seqcount.seqcount.sequence);
	write_sequnlock(seqlock);
	pr_info("Value of sequence after write_sequnlock:%d\n", seqlock->seqcount.seqcount.sequence);
	
	kfree(seqlock);
	return -1;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec09/01_seqlock_write/seqlock_write.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37a0cba, "kfree" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xc5850110, "printk" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x50d4de4, "pv_ops" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D56E8C11EB2D2CB86725EED");

==> LinuxSynchronizationConcurrency/sec09/02_seqlock_rw/seqlock_read.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/seqlock.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

DEFINE_SEQLOCK(lock);
static struct task_struct *thread1, *thread2, *thread3, *thread4;

int counter = 0;

static int write_threadfn(void *arg)
{
	pr_info("processor:%d trying to acquire write seq lock\n", smp_processor_id());
	write_seqlock(&lock);
	pr_info("processor:%d acquired seq lock\n", smp_processor_id());
	counter++;
	msleep(7000);
	write_sequnlock(&lock);
	pr_info("processor:%d released write lock\n", smp_processor_id());
	return 0;
}

static int read_threadfn(void *arg)
{
	unsigned int seq;
	int mycounter;
	pr_info("processor:%d starting sqread\n", smp_processor_id());
	do 
	{
		seq = read_seqbegin(&lock);
		mycounter = counter;
		pr_info("processor:%d read mycounter:%d\n", smp_processor_id(), mycounter);
	} while (read_seqretry(&lock, seq));

	pr_info("processor:%d completed sqread\n", smp_processor_id());
	pr_info("processor:%d mycounter:%d\n", smp_processor_id(), mycounter);

	return 0;
}

static int __init test_init(void)
{
	thread1 = kthread_run(read_threadfn, NULL, "thread1");
	thread2 = kthread_run(write_threadfn, NULL, "thread2");
	thread3 = kthread_run(read_threadfn, NULL, "thread3");
	thread4 = kthread_run(write_threadfn, NULL, "thread4");
	return 0;
}

static void __exit test_exit(void)
{
	pr_info("Exiting kernel module\n");
}

module_init(test_init);
module_exit(test_exit);


==> LinuxSynchronizationConcurrency/sec10/00_rcu_assign_pointer/rcu_assign_pointer.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/rcupdate.h>
#include <linux/kthread.h>

MODULE_LICENSE("GPL");

struct task_struct *thread;

typedef struct my_data
{
	int key;
	int val;
} my_data;

my_data *global_ptr = NULL;

static int write_thread_fn(void *arg)
{
	my_data *new_ptr = kmalloc(sizeof(my_data), GFP_KERNEL);
	new_ptr->key = 1;
	new_ptr->val = 1000;
	rcu_assign_pointer(global_ptr, new_ptr);
	pr_info("global pointer\tkey:%d\tval:%d\n", global_ptr->key, global_ptr->val);
	return 0;
}

static int __init test_init(void)
{
	thread = kthread_run(write_thread_fn, NULL, "write_thread");;
	return 0;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec10/00_rcu_assign_pointer/rcu_assign_pointer.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0xc5850110, "printk" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "3D2C618CBC91BE36390447F");

==> LinuxSynchronizationConcurrency/sec10/01_rcu_dereference/rcu_dereference.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/rcupdate.h>
#include <linux/kthread.h>

MODULE_LICENSE("GPL");

struct task_struct *thread;

typedef struct my_data
{
	int key;
	int val;
} my_data;

my_data *global_ptr = NULL;

static int read_thread_fn(void *arg)
{
	my_data *ptr = NULL;
	rcu_read_lock();
	ptr = rcu_dereference(global_ptr);
	pr_info("%s:key:%d\t val:%d\n", __func__, ptr->key, ptr->val);
	rcu_read_unlock();
	return 0;
}

static int __init test_init(void)
{
	global_ptr = kmalloc(sizeof(my_data), GFP_KERNEL);
	if (!global_ptr)
		return -ENOMEM;

	global_ptr->key = 1;
	global_ptr->val = 1000;

	thread = kthread_run(read_thread_fn, NULL, "read_thread1");
	return 0;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);


==> LinuxSynchronizationConcurrency/sec10/01_rcu_dereference/rcu_dereference.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0x2d5f69b3, "rcu_read_unlock_strict" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F19C2E63221C3FCAA3A5036");

==> LinuxSynchronizationConcurrency/sec10/02_rcu_read_write/rcu_read_write.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/rcupdate.h>
#include <linux/kthread.h>

MODULE_LICENSE("GPL");

struct task_struct *thread1, *thread2, *thread3;

typedef struct my_data
{
	int key;
	int val;
} my_data;

my_data *global_ptr = NULL;

static int write_thread_fn(void *arg)
{
	my_data *new_ptr = kmalloc(sizeof(my_data), GFP_KERNEL);
	new_ptr->key = 1;
	new_ptr->val = 1000;
	rcu_assign_pointer(global_ptr, new_ptr);
	pr_info("global pointer\tkey:%d\tval:%d\n", global_ptr->key, global_ptr->val);
	return 0;
}

static int read_thread_fn(void *arg)
{
	my_data *ptr = NULL;
	rcu_read_lock();
	ptr = rcu_dereference(global_ptr);
	if (ptr != NULL)
		pr_info("%s:key:%d\tval:%d\n", __func__, ptr->key, ptr->val);
	else
		pr_info("%s write thread did not yet start\n", __func__);
	rcu_read_unlock();

	return 0;
}

static int __init test_init(void)
{
	thread1 = kthread_run(read_thread_fn, NULL, "read_thread1");
	thread2 = kthread_run(write_thread_fn, NULL, "write_thread1");
	thread3 = kthread_run(read_thread_fn, NULL, "read_thread2");

	return 0;
}

static void __exit test_exit(void)
{
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec10/02_rcu_read_write/rcu_read_write.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0x2d5f69b3, "rcu_read_unlock_strict" },
	{ 0xc5850110, "printk" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "86EBCE179E9AE41CA51FBC0");

==> LinuxSynchronizationConcurrency/sec10/03_rcu_rw_problem/rcu_rw_driver.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/rcupdate.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

struct task_struct *thread1, *thread2, *thread3;

typedef struct my_data 
{
	int key;
	int val;
} my_data;

my_data *global_ptr = NULL;

static int write_thread_fn(void *arg)
{
	while (!kthread_should_stop())
	{
		my_data *new_ptr = kmalloc(sizeof(my_data), GFP_KERNEL);
		memcpy(new_ptr, global_ptr, sizeof(my_data));
		new_ptr->key++;
		new_ptr->val++;
		rcu_assign_pointer(global_ptr, new_ptr);
		//not freeing data that was previously stored in global_data, need kfree()
		//RCU should free after waiting for pre-existing RCU-Readers to complete
		//RCU should split updates/writes into two phases, removal & reclamation
		//Removal - replaces references to data items with the latest
		//Reclamation - fress the old reference
		pr_info("%s:processor:%d write complete\n", __func__, smp_processor_id());
		msleep(3000);

	}
	return 0;
}

static int read_thread_fn(void *arg)
{
	while(!kthread_should_stop())
	{
		my_data *ptr = NULL;
		rcu_read_lock();
		ptr = rcu_dereference(global_ptr);
		if (ptr != NULL)
			pr_info("%s:processor:%d\tkey:%d\tval:%d\n", __func__, smp_processor_id(), ptr->key, ptr->val);
		else
			pr_info("%s write thread has not yet started\n", __func__);
		rcu_read_unlock();
		msleep(3000);
	}
	return 0;
}

static int __init test_init(void)
{
	global_ptr = kmalloc(sizeof(my_data), GFP_KERNEL);
	global_ptr->key = 1;
	global_ptr->val = 1001;

	thread1 = kthread_run(read_thread_fn, NULL, "read_thread1");
	thread2 = kthread_run(write_thread_fn, NULL, "write_thread1");
	thread3 = kthread_run(read_thread_fn, NULL, "read_thread2");
	return 0;
}

static void __exit test_exit(void)
{
	kthread_stop(thread1);
	kthread_stop(thread2);
	kthread_stop(thread3);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec10/03_rcu_rw_problem/rcu_rw_driver.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x514011c4, "kthread_stop" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xf9a482f9, "msleep" },
	{ 0x2d5f69b3, "rcu_read_unlock_strict" },
	{ 0xc5850110, "printk" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F29EF96BFB92C6FAF422A02");

==> LinuxSynchronizationConcurrency/sec10/04_rcu_rw_solution/rcu_rw_solution.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/rcupdate.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

struct task_struct *thread1, *thread2, *thread3;

typedef struct my_data
{
	int key;
	int val;
} my_data;

my_data *global_ptr = NULL;

//RCU should free after waiting for pre-existing RCU-Readers to complete
//RCU should split updates/writes into two phases, removal & reclamation
//Removal - replaces references to data items with the latest
//Reclamation - fress the old reference
static int write_thread_fn(void *arg)
{
	while(!kthread_should_stop())
	{
		my_data *tmp_ptr = global_ptr;
		my_data *new_ptr = kmalloc(sizeof(my_data), GFP_KERNEL);
		memcpy(new_ptr, global_ptr, sizeof(my_data));
		new_ptr->key++;
		new_ptr->val++;
		rcu_assign_pointer(global_ptr, new_ptr);
		pr_info("%s: processor:%d write complete\n\n", __func__, smp_processor_id());
		pr_info("%s: processor:%d\tStarting synchronize_rcu\n", __func__, smp_processor_id());
		synchronize_rcu(); 	// this will block the kfree until all read calls accessing the old
							// global pointer have finished
		pr_info("%s: Processor:%d\t Ending synchronize_rcu\n", __func__, smp_processor_id());
		kfree(tmp_ptr);
		msleep(3000);
	}
	return 0;
}

static int read_thread_fn(void *arg)
{
	while(!kthread_should_stop())
	{
		my_data *ptr = NULL;
		rcu_read_lock();
		ptr = rcu_dereference(global_ptr);
		if (ptr != NULL)
			pr_info("%s:processor:%d\tkey:%d\tval:%d\n", __func__, smp_processor_id(), ptr->key, ptr->val);
		else
			pr_info("%s write thread did not yet start\n", __func__);
		rcu_read_unlock();
		msleep(3000);
	}
	return 0;
}

static int __init test_init(void)
{
	global_ptr = kmalloc(sizeof(my_data), GFP_KERNEL);
	global_ptr->key = 1;
	global_ptr->val = 1001;

	thread1 = kthread_run(read_thread_fn, NULL, "read_thread1");
	thread2 = kthread_run(write_thread_fn, NULL, "write_thread1");
	thread3 = kthread_run(read_thread_fn, NULL, "read_thread2");

	return 0;
}

static void __exit test_exit(void)
{
	kthread_stop(thread1);
	kthread_stop(thread2);
	kthread_stop(thread3);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec10/04_rcu_rw_solution/rcu_rw_solution.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x514011c4, "kthread_stop" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0x37a0cba, "kfree" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xf9a482f9, "msleep" },
	{ 0x2d5f69b3, "rcu_read_unlock_strict" },
	{ 0xc5850110, "printk" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "26D37C09AE118808D99C815");

==> LinuxSynchronizationConcurrency/sec10/05_rcu_head_callback/rcu_head_callback.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/rcupdate.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

struct task_struct *thread1, *thread2, *thread3;

typedef struct my_data
{
	int key;
	int val;
	struct rcu_head rhead;
} my_data;

my_data *global_ptr = NULL;

static void rcu_free(struct rcu_head *head)
{
	my_data *data = container_of(head, my_data, rhead);
	pr_info("%s:processor:%d\tfreeing existing data\n", __func__, smp_processor_id());
	kfree(data);
}

static int write_thread_fn(void *arg)
{
	while(!kthread_should_stop())
	{
		my_data *tmp_ptr = global_ptr;
		my_data *new_ptr = kmalloc(sizeof(my_data), GFP_KERNEL);
		memcpy(new_ptr, global_ptr, sizeof(my_data));
		new_ptr->key++;
		new_ptr->val++;
		rcu_assign_pointer(global_ptr, new_ptr);
		pr_info("%s: processor:%d write complete\n\n", __func__, smp_processor_id());
		call_rcu(&tmp_ptr->rhead, rcu_free);
		msleep(3000);
	}
	return 0;
}

static int read_thread_fn(void *arg)
{
	while(!kthread_should_stop())
	{
		my_data *ptr = NULL;
		rcu_read_lock();
		ptr = rcu_dereference(global_ptr);
		if (ptr != NULL)
			pr_info("%s:processor:%d\tkey:%d\tval:%d\n", __func__, smp_processor_id(), ptr->key, ptr->val);
		else
			pr_info("%s write thread did not yet start\n", __func__);
		rcu_read_unlock();
		msleep(3000);
	}
	return 0;
}

static int __init test_init(void)
{
	global_ptr = kmalloc(sizeof(my_data), GFP_KERNEL);
	global_ptr->key = 1;
	global_ptr->val = 1001;

	thread1 = kthread_run(read_thread_fn, NULL, "read_thread1");
	thread2 = kthread_run(write_thread_fn, NULL, "write_thread1");
	thread3 = kthread_run(read_thread_fn, NULL, "read_thread2");

	return 0;
}

static void __exit test_exit(void)
{
	kthread_stop(thread1);
	kthread_stop(thread2);
	kthread_stop(thread3);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec10/05_rcu_head_callback/rcu_head_callback.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x514011c4, "kthread_stop" },
	{ 0x37874eb8, "wake_up_process" },
	{ 0x40794748, "kthread_create_on_node" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xf9a482f9, "msleep" },
	{ 0x2d5f69b3, "rcu_read_unlock_strict" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x37a0cba, "kfree" },
	{ 0xc5850110, "printk" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5A0CB96586E970B9A4A7557");

==> LinuxSynchronizationConcurrency/sec10/06_nonsafe_linked_list/linked_list.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

typedef struct my_data
{
	struct list_head list;
	int key;
	int data;
} my_data;

LIST_HEAD(listhead);

void insert(int key, int data)
{
	my_data *ptr = kmalloc(sizeof(*ptr), GFP_KERNEL);
	ptr->key = key;
	ptr->data = data;
	list_add_tail(&(ptr->list), &listhead);
}

my_data *search(int key)
{
	my_data *ptr;

	list_for_each_entry(ptr, &listhead, list) {
		if (ptr->key == key)
			return ptr;
	}
	return NULL;
}

void delete(int key)
{
	my_data *ptr;

	ptr = search(key);
	if (ptr != NULL) {
		list_del(&(ptr->list));
		kfree(ptr);
	}
}

void print_list(void)
{
	my_data *ptr;

	list_for_each_entry(ptr, &listhead, list) {
		pr_info("key:%d\tvalue:%d\n", ptr->key, ptr->data);
	}
}

static int __init test_init(void)
{
	insert(1, 1000);
	insert(2, 1001);
	insert(3, 1002);

	pr_info("printing list\n");
	print_list();
	pr_info("deleting key 2\n");
	delete(2);
	pr_info("printing list\n");
	print_list();
	return 0;
}

static void __exit test_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec10/06_nonsafe_linked_list/linked_list.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0x37a0cba, "kfree" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "DE6563155AA277084FC16F9");

==> LinuxSynchronizationConcurrency/sec10/07_rcu_linked_list/rcu_linked_list.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rculist.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

DEFINE_SPINLOCK(mylock);

typedef struct my_data
{
	struct list_head list;
	int key;
	int data;
} my_data;

LIST_HEAD(listhead);

void insert(int key, int data)
{
	my_data *ptr;
	spin_lock(&mylock);
	ptr = kmalloc(sizeof(*ptr), GFP_KERNEL);
	ptr->key = key;
	ptr->data = data;
	list_add_tail_rcu(&(ptr->list), &listhead);
	spin_unlock(&mylock);
}

my_data *search(int key)
{
	my_data *ptr;

	list_for_each_entry_rcu(ptr, &listhead, list) {
		if (ptr->key == key)
			return ptr;
	}
	return NULL;
}

void delete(int key)
{
	my_data *ptr;

	spin_lock(&mylock);
	ptr = search(key);
	if (ptr != NULL) {
		list_del_rcu(&(ptr->list));
		kfree(ptr);
	}
	spin_unlock(&mylock);
}

void print_list(void)
{
	my_data *ptr;

	list_for_each_entry_rcu(ptr, &listhead, list) {
		pr_info("key:%d\tvalue:%d\n", ptr->key, ptr->data);
	}
}


static int __init test_init(void)
{
	insert(1, 1000);
	insert(2, 1001);
	insert(3, 1002);

	pr_info("printing list\n");
	print_list();
	pr_info("deleting key 2\n");
	delete(2);
	pr_info("printing list\n");
	print_list();
	return 0;
}

static void __exit test_exit(void)
{
	pr_info("%s: In exit\n", __func__);
}

module_init(test_init);
module_exit(test_exit);

==> LinuxSynchronizationConcurrency/sec10/07_rcu_linked_list/rcu_linked_list.mod.c <==
#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0xc5850110, "printk" },
	{ 0x37a0cba, "kfree" },
	{ 0x50d4de4, "pv_ops" },
	{ 0x69ecc112, "kmem_cache_alloc_trace" },
	{ 0x36c11c94, "kmalloc_caches" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "872A0DE35179EEF006EDE24");

==> LinuxUserSpaceDebugging/1/assembly.c <==
#include <stdio.h>

int main()
{
	int i = 10;
	int j = 20;

	i += j;
	i -= j;
	i *= j;
	i /= j;

	return 0;
}

==> LinuxUserSpaceDebugging/1/backtrace.c <==
#include <stdio.h>

void func1();
void func2();

int main()
{
	register int wye;
	int *ptr;
	int ex;
	int num=10;

	ptr = &ex;
	ex = 305441741;
	wye = -1;
	printf("Enter an integer: ");
	scanf("%i", ptr);
	wye += *ptr;
	printf("The result is %i\n", wye);

	func1();
	printf("In Main(): %d\n", num);
}

void func1()
{
	int num=20;
	func2();
	printf("In func1(): %d\n", num);
}

void func2()
{
	int num=30;
	printf("In func2(): %d\n", num);
}

==> LinuxUserSpaceDebugging/1/gdb_debug2.c <==
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *buf;

	buf = malloc(1<<31);

	fgets(buf, 1024, stdin);
	printf("%s\n", buf);

    return 0;
}


==> LinuxUserSpaceDebugging/1/gdb_debug3.c <==
#include <stdio.h>

int main(int argc, char *argv[])
{
	int c = 1337;
    return 0;
}


==> LinuxUserSpaceDebugging/1/gdb_debug4.c <==
#include <stdio.h>

int main(int argc, char *argv[])
{
	int a[] = {1,3,7};
    return 0;
}


==> LinuxUserSpaceDebugging/1/gdb_debug5.c <==

#include <stdio.h>

int main(int argc, char *argv[])
{
	char msg[] = "Hello world\n";
    return 0;
}


==> LinuxUserSpaceDebugging/1/gdb_debug6.c <==
#include <stdio.h>


void myFunction()
{
	// Initialize the counter to 0
	static int sFunctionCounter = 0;
	
	// Each time we enter the fucntion increment the counter
	sFunctionCounter++;
}

int main(int argc, char *argv[])
{
	int i;

	//call 10 times myFunction
	for (i = 0; i < 10; i++)
		myFunction();

    return 0;
}


==> LinuxUserSpaceDebugging/1/gdb_debug7.c <==
#include <stdio.h>

int main(int argc, char *argv[])
{
	int x = 30;
	int y = 10;

    x = y;

    printf("%d\n", x); 

    return 0;
}


==> LinuxUserSpaceDebugging/1/gdb_debugging.c <==
#include <stdio.h>

unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n-1);
}

int main(int argc, char *argv[])
{
    unsigned int loop = 50;
	if (argc == 2) {
		loop = atoi(argv[1]);
	}

    while(loop--)
    {
        printf("Factorial of number %d is %u\n", loop, factorial(loop));
    }

    return 0;
}


==> LinuxUserSpaceDebugging/1/source_code1.c <==
#include <stdio.h>
#include <stdlib.h>

unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n-1);
}

int main(int argc, char *argv[])
{
    unsigned int loop = 50;
    while(loop--)
    {
		sleep(2);
    }

    return 0;
}


==> LinuxUserSpaceDebugging/1/source_code2.c <==
#include <stdio.h>

int main(int argc, char *argv[])
{
    int *ptr = NULL;
	*ptr = 10;

	printf("%s", "SW-VERSION=0.1");

    return 0;
}


==> LinuxUserSpaceDebugging/1/source_code3.c <==

#include <stdio.h>

int main(int argc, char *argv[])
{
    return 1/0;
}

==> LinuxUserSpaceDebugging/1/source_code.c <==
#include <stdio.h>

unsigned int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n-1);
}

int main(int argc, char *argv[])
{
    unsigned int loop = 50;
    while(loop--)
    {
        printf("Factorial of number %d is %u\n", loop, factorial(loop));
    }

    return 0;
}


==> LinuxUserSpaceDebugging/1/step_vs_next.c <==
#include <stdio.h>

void printMessage(char *msg) {
    if(msg != NULL)
		printf("msg:%s\n", msg);
}

int main(){
	char buffer[] = "Hello world";
	int i = 10;
	printMessage(buffer);
	return 0;
}

==> LinuxUserSpaceDebugging/2/doublefree.c <==
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void doublefree(int cond)
{
	char *ptr, *bogus;

	char name[] = "Hands-on Linux Sys Prg";
	int n =512;

	printf("%s(): cond %d\n", __FUNCTION__, cond);
	ptr = malloc(n);
	if (!ptr)
		printf("malloc failed\n");
	strncpy(ptr, name, strlen(name)); 
	free(ptr);

	bogus = malloc(n);
	if (cond) {
		bogus = malloc(-1UL);
		if (!bogus) {
			fprintf(stderr, "%s:%s:%d: malloc failed\n", __FUNCTION__, __FUNCTION__, __LINE__);
			free(ptr);
			exit(-1);
		}
	}
}

int main()
{
    doublefree(0);
    doublefree(1);

	return 0;
}	

==> LinuxUserSpaceDebugging/2/leakagecase2.c <==
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const size_t BLK_1MB = 1024*1024;

static void amleaky(size_t mem)
{
	char *ptr, *next;

	ptr = malloc(mem);
	if (!ptr)
		printf("malloc failed\n");
	memset(ptr, 0, mem);
}

static void leakagecase2(size_t size, unsigned int reps)
{
	unsigned int  i, threshold = 3*BLK_1MB;
	double mem_leaked;

	if (reps == 0)
		reps = 1;
	mem_leaked = size * reps;

	printf("%s(): will now leak %.0f bytes (%.2f MB) [%zu bytes * %u loops]\n", __FUNCTION__, mem_leaked, mem_leaked/(1024*1024), size, reps);
    amleaky(size);

	if (mem_leaked >= threshold)
		system("free|grep \"^Mem:\"");

	printf("\n");
}

int main()
{
    amleaky(32);
    leakagecase2(32, 100000);
    leakagecase2(BLK_1MB, 12);

	return 0;
}	

==> LinuxUserSpaceDebugging/2/memoryleak.c <==
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const size_t BLK_1MB = 1024*1024;

static void amleaky(size_t mem)
{
	char *ptr, *next;

	ptr = malloc(mem);
	if (!ptr)
		printf("malloc failed\n");
	memset(ptr, 0, mem);
}

static void leakagecase1(size_t size)
{
	printf("%s(): will now leak %zu bytes (%ld MB)\n", __FUNCTION__, size, size/(1024*1024));
    amleaky(size);
}

int main()
{
    amleaky(32);
    leakagecase1(BLK_1MB);

	return 0;
}	

==> LinuxUserSpaceDebugging/2/overunderflow.c <==
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void write_overflow_compilemem(void)
{
	int i, arr[5];

	for (i = 0; i <= 50; i++) 
	{
		arr[i] = 1; //Overflows on i==5
	}
}

static void write_overflow_dynmem(void)
{
	char *dest, src[] = "abcd56789123456789";

	dest = malloc(8);
	if (!dest)
		printf("malloc failed\n");

	strcpy(dest, src); //write overflow
	//because memory is allocated on heap, does not fail, though is still bug
	free(dest);
}

static void write_underflow(void)
{
    char *p = malloc(8);

	if (!p)
		printf("malloc failed\n");

	p--; //p now pointing to alocation before the memory allocation 
	strncpy(p, "abcd5678", 8);  //write underflow
	free(++p);
}

int main()
{
    //write_overflow_compilemem();
    write_overflow_dynmem();
    //write_underflow();

	return 0;
}	

==> LinuxUserSpaceDebugging/2/readunderoverflow.c <==
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void read_overflow_compilemem(void)
{
	char arr[16], tmp[16];

	memset(arr, 'a', 16);
	memset(tmp, 't', 16);
    tmp[15] = '\0'; 

	printf("arr: %s\n", arr); //Read buffer overflo
}

static void read_overflow_dynmem(void)
{
	char *arr;

	arr = malloc(5);
	if (!arr)
		printf("malloc failed\n");
	memset(arr, 'a', 5);

    arr[5] = 'S'; arr[6] = 'e'; arr[7] = 'c'; 
    arr[8] = 'r'; arr[9] = 'e'; arr[10] = 't'; 

	printf("arr: %s\n", arr);
	printf("*(arr+100): %d\n", *(arr+100));
	printf("*(arr+10000): %d\n", *(arr+10000));
	free(arr);
}

static void read_underflow(int cond)
{
	char *dest, src[] = "abcd56789123456789", *orig;

	printf("%s(): cond %d\n", __FUNCTION__, cond);
	dest = malloc(25);
	if (!dest)
		printf("malloc failed\n");
	orig = dest;

	strncpy(dest, src, strlen(src)); 

	if (cond) 
	{
		*(orig -1) = 'x';
		dest--;
	}

	printf("dest: %s\n", dest);
	free(orig);
}

int main()
{
    read_overflow_compilemem();
    //read_overflow_dynmem();
    //read_underflow(0);
    //read_underflow(1);

	return 0;
}	

==> LinuxUserSpaceDebugging/2/uninitialized.c <==
#include <stdio.h>

/*A classic case, local variables are by definition uninitialized, unlike globals
which are by definition preset to zero.
In below code it's undefined what will occur at runtime as x is uninitialized and will thus have random content */

void uninit_var()
{
	int x;

	if (x)
		printf("true case: x=%d\n", x);
	else
		printf("false case");
}

//more training lolz....

int main()
{
	uninit_var();

	return 0;
}

==> LinuxUserSpaceDebugging/2/useafterfree.c <==
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void uaf(void)
{
	char *arr, *next;

	char name[] = "Hands-on Linux Sys Prg";
	int n =512;

	arr = malloc(n);
	if (!arr)
		printf("malloc failed\n");
	memset(arr, 'a', n);

    arr[n-1] = '\0'; 
	printf("%s():%d: arr = %p:%.*s\n", __FUNCTION__, __LINE__, arr, 32, arr);

	next = malloc(n);
	if (!next) {
		free(arr);
		fprintf(stderr, "Error log: arr = %p:val=%s\n", arr, arr);
		printf("malloc failed\n");
	}
	free(arr);
	strncpy(arr, name, strlen(name)); 

	printf("%s():%d: arr = %p:%.*s\n", __FUNCTION__, __LINE__, arr, 32, arr);
	free(next);
}

int main()
{
    uaf();

	return 0;
}	

==> LinuxUserSpaceDebugging/2/useafterreturn.c <==
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void* uar(void)
{
	char name[32];

	memset(name, 0, 32);
	strncpy(name, "Hands-on Linux Sys Prg", 22); 

	return name;
}

int main()
{
    void *res = uar();
    printf("res: %s\n", (char*)res);

	return 0;
}	

==> LinuxUserSpaceDebugging/3/double_free.c <==
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int *ptr, i;

	ptr = malloc(10*sizeof(int));

	for (i = 0; i < 10; i++)
		ptr[i] = i;

	free(ptr);
	free(ptr);

	return 0;
}


==> LinuxUserSpaceDebugging/3/memory_leak.c <==
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *ptr;

	ptr = (char*)malloc(19);

	ptr = (char*)malloc(12);
	free(ptr);

	ptr = (char*)malloc(16);

    return 0;
}


==> LinuxUserSpaceDebugging/3/read_overflow_dyn.c <==
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
	int arr[10];
	for (i = 0; i < 9; i++)
		arr[i] = i;
	
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	printf("\n");
    return 0;
}


==> LinuxUserSpaceDebugging/3/write_overflow2.c <==
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ptr;
	ptr = malloc(10);
	read(0, ptr, 100);
	free(ptr);
	return 0;
}

==> LinuxUserSpaceDebugging/3/write_overflow.c <==
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	int *a = malloc(sizeof(int) * 12);

	if (!a) return -1;

	for (i = 0; i < 15; i++) {
		a[i] = i;
	}

	free(a);

    return 0;
}


==> LinuxUserSpaceDebugging/4/1.c <==
int main(){ }

==> LinuxUserSpaceDebugging/4/2.c <==
int main(){
    printf("Hello\n");
}

==> LinuxUserSpaceDebugging/4/3.c <==
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/signal.h>

void alarm_handler(int signum) {
	printf("Buzz Buzz Buzz\n");

	//set a new alarm for 1 second
	alarm(1);
}

int main(){
	signal(SIGALRM, alarm_handler);

	alarm(10);

	alarm(1);

	while(1) {
		pause();
		alarm(1);
	}
}

==> LinuxUserSpaceDebugging/4/4.c <==
#include <stdio.h>

int main() {
	FILE *fd = NULL;

	if (fd = fopen("test", "rw")){
		printf("test file opened\n");
	}
	else {
		printf("Failed to open the file\n");
	}
}

==> LinuxUserSpaceDebugging/4/app.c <==
#include <stdio.h>

int main() {
	int i = 0;
	printf("hello world Learning Linux is very easy\n");
	while(1) {
		i++;
		printf("Hello %d time\n", i);
		sleep(2);
	}
}

==> LinuxUserSpaceDebugging/4/fork.c <==
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

#define CHILD 0

int main()
{
	pid_t pid;
	printf("My pid = %d\n", getpid());
	pid = fork();
	if (pid == CHILD){
		printf("child: pid = %d\n", getpid());
	} 
	else {
		printf("My pid = %d\n", getpid());
		printf("Newly created child pid = %d\n", pid);
	}
}

==> LinuxUserSpaceDebugging/4/ltrace.c <==
#include <stdio.h>
#include <unistd.h>

int main() {
	FILE *fp = fopen("rfile.txt", "w+");
	fprintf(fp+1, "Invalid Write\n");
	fclose(fp);
	return 0;
}


==> LinuxUserSpaceDebugging/4/newapp.c <==
#include <stdio.h>

/* Our structure */
struct rec
{
	int x, y, z;
	float value;
};

int main()
{
	int counter;
	struct rec my_record;
	int counter_limit;
	FILE *ptr_myfile;

	counter_limit = 1000;

	ptr_myfile=fopen("test.bin", "wb");
	if (!ptr_myfile)
	{
		printf("Unable to open file");
		return -1;
	}
	for (counter=1; counter <= counter_limit; counter++)
	{
		my_record.x = counter;
		my_record.y = counter;
		my_record.z = counter;
		my_record.value = (float) counter * 10.0;
		fwrite(&my_record, sizeof(struct rec), 1, ptr_myfile);
	}
	fclose(ptr_myfile);
}
==> LinuxCharacterDeviceDrivers/sec2/11_copy_user_struct/mystruct.h <==
#ifndef __MYSTRUCT_H
#define __MYSTRUCT_H

typedef struct abc
{
	int i;
	char c;
} abc;

#endif

==> LinuxCharacterDeviceDrivers/sec2/13_heapstack_kernel_break/heapstackstruct.h <==
#ifndef _HEAPSTACKSTRUCT_H
#define _HEAPSTACKSTRUCT_H

typedef struct abc {
	int i;
	char *str;
} abc;

#endif

==> LinuxCharacterDeviceDrivers/sec2/17_stackheapsolution/shstruct.h <==
#ifndef __SH_STRUCT_H
#define __SH_STRUCT_H

typedef struct abc
{
	int i;
	char *str;
} abc;

#endif

==> LinuxCharacterDeviceDrivers/sec2/18_read_ch_problem/mystruct.h <==
#ifndef _MY_STRUCT_H
#define _MY_STRUCT_H

typedef struct abc {
	int i;
	char c;
} abc;

#endif

==> LinuxCharacterDeviceDrivers/sec3/04_symbolic_names_ioctl/ioctl_cmd.h <==
#ifndef __IOCTL_CMD_H
#define __IOCTL_CMD_H

#define MSG_IOCTL_GET_LENGTH 0x01

#define MSG_IOCTL_CLEAR_BUFFER 0x02

#define MSG_IOCTL_FILL_BUFFER 0x03

#endif

==> LinuxCharacterDeviceDrivers/sec3/07_updated_driver_ioctl_macros/ioctl_cmd.h <==
#ifndef __IOCTL_CMD_H
#define __IOCTL_CMD_H

#define MSG_MAGIC_NUMBER 0x21

#define MSG_IOCTL_GET_LENGTH _IOR(MSG_MAGIC_NUMBER, 1, unsigned int)

#define MSG_IOCTL_CLEAR_BUFFER _IO(MSG_MAGIC_NUMBER, 2)

#define MSG_IOCTL_FILL_BUFFER _IOW(MSG_MAGIC_NUMBER, 3, unsigned char)

#define MSG_IOCTL_MAX_CMDS 3

#endif

==> LinuxCharacterDeviceDrivers/sec3/09_unsupported_command_ioctl/ioctl_cmd.h <==
#ifndef __IOCTL_CMD_H
#define __IOCTL_CMD_H

#define MSG_MAGIC_NUMBER 0x21

#define MSG_IOCTL_GET_LENGTH _IOR(MSG_MAGIC_NUMBER, 1, unsigned int)

#define MSG_IOCTL_CLEAR_BUFFER _IO(MSG_MAGIC_NUMBER, 2)

#define MSG_IOCTL_FILL_BUFFER _IOW(MSG_MAGIC_NUMBER, 3, unsigned char)

#define MSG_IOCTL_MAX_CMDS 3

#endif

==> LinuxCharacterDeviceDrivers/sec3/10_driver_access_ok/ioctl_cmd.h <==
#ifndef __IOCTL_CMD_H
#define __IOCTL_CMD_H

#define MSG_MAGIC_NUMBER 0x21

#define MSG_IOCTL_GET_LENGTH _IOR(MSG_MAGIC_NUMBER, 1, unsigned int)

#define MSG_IOCTL_CLEAR_BUFFER _IO(MSG_MAGIC_NUMBER, 2)

#define MSG_IOCTL_FILL_BUFFER _IOW(MSG_MAGIC_NUMBER, 3, unsigned char)

#define MSG_IOCTL_GET_ADDRESS _IOR(MSG_MAGIC_NUMBER, 4, unsigned long long)

#define MSG_IOCTL_MAX_CMDS 4

#endif

==> LinuxCharacterDeviceDrivers/sec3/11_differentsizeioctl/ioctl_cmd.h <==
#ifndef __IOCTL_CMD_H
#define __IOCTL_CMD_H

#define MSG_MAGIC_NUMBER 0x21

#define MSG_IOCTL_GET_LENGTH _IOR(MSG_MAGIC_NUMBER, 1, unsigned int)

#define MSG_IOCTL_CLEAR_BUFFER _IO(MSG_MAGIC_NUMBER, 2)

#define MSG_IOCTL_FILL_BUFFER _IOW(MSG_MAGIC_NUMBER, 3, unsigned char)

#define MSG_IOCTL_GET_ADDRESS _IOR(MSG_MAGIC_NUMBER, 4, unsigned long long) 

#define MSG_IOCTL_MAX_CMDS 4

#endif

==> LinuxCharacterDeviceDrivers/sec3/12_signal_module_process/ioctl_cmd.h <==
#ifndef __IOCTL_CMD_H
#define __IOCTL_CMD_H

#define SIG_MAGIC_NUMBER 0x21

#define SIG_IOCTL_SET_PID _IOW(SIG_MAGIC_NUMBER, 1, unsigned int)

#define SIG_IOCTL_SET_SIGNAL _IOW(SIG_MAGIC_NUMBER, 2, unsigned int)

#define SIG_IOCTL_SEND_SIGNAL _IO(SIG_MAGIC_NUMBER, 3)

#define SIG_IOCTL_MAX_CMDS 3

#endif

==> LinuxCharacterDeviceDrivers/sec4/04_using_capabilities/ioctl_cmd.h <==
#ifndef __IOCTL_CMD_H
#define __IOCTL_CMD_H

#define SIG_MAGIC_NUMBER 0x21

#define SIG_IOCTL_SET_PID _IOW(SIG_MAGIC_NUMBER, 1, unsigned int)

#define SIG_IOCTL_SET_SIGNAL _IOW(SIG_MAGIC_NUMBER, 2, unsigned int)

#define SIG_IOCTL_SEND_SIGNAL _IO(SIG_MAGIC_NUMBER, 3)

#define SIG_IOCTL_MAX_CMDS 3

#endif

==> LinuxCharacterDeviceDrivers/sec4/07_misc_driver/ioctl_cmd.h <==
#ifndef __IOCTL_CMD_H
#define __IOCTL_CMD_H

#define MSG_MAGIC_NUMBER 0x21

#define MSG_IOCTL_GET_LENGTH _IOR(MSG_MAGIC_NUMBER, 1, unsigned int)

#define MSG_IOCTL_CLEAR_BUFFER _IO(MSG_MAGIC_NUMBER, 2)

#define MSG_IOCTL_FILL_BUFFER _IOW(MSG_MAGIC_NUMBER, 3, unsigned char)

#define MSG_IOCTL_GET_ADDRESS _IOR(MSG_MAGIC_NUMBER, 4, unsigned long)

#define MSG_IOCTL_MAX_CMDS 4

#endif

==> LinuxKernelProgramming/exporting_variables/symbol_test.h <==
#ifndef _SYMBOL_H
#define _SYMBOL_H


struct test
{
	int a;
	int b;
	int c;
	int d;
	char e;
};

extern struct test foo;

#endif

==> LinuxSynchronizationConcurrency/sec07/03_read_write_read_pref/ioctl_cmd.h <==
#ifndef __IOCTL_CMD_H
#define __IOCTL_CMD_H

#define MSG_MAGIC_NUMBER 0x21

#define MSG_IOCTL_GET_LENGTH _IOR(MSG_MAGIC_NUMBER, 1, unsigned int)

#define MSG_IOCTL_CLEAR_BUFFER _IO(MSG_MAGIC_NUMBER, 2)

#define MSG_IOCTL_FILL_BUFFER _IOR(MSG_MAGIC_NUMBER, 3, unsigned char)

#define MSG_IOCTL_GET_ADDRESS _IOR(MSG_MAGIC_NUMBER, 4, unsigned long)

#define MSG_IOCTL_MAX_CMDS 4

#endif

==> ./LinuxCommunicatingWithHardware/00_RequestingIOPorts/RequestingIOPorts.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>

#define MY_BASEPORT 0x0062
#define NUMBER_PORTS 2

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	if (!request_region(MY_BASEPORT, NUMBER_PORTS, "myports")) 
	{
		pr_info("request region failed for myports\n");
	} 
	else 
	{
		pr_info("request region success for myports\n");
	}

	return 0;
}

static void mod_exit(void)
{
	release_region(MY_BASEPORT, NUMBER_PORTS);
}

module_init(mod_init);
module_exit(mod_exit);
		 

==> ./LinuxCommunicatingWithHardware/01_RequestingAllocatedRegion/RequestingAllocatedRegion.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>

#define MY_BASEPORT 0x0070
#define NUMBER_PORTS 2

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	if (!request_region(MY_BASEPORT, NUMBER_PORTS, "myports")) 
	{
		pr_info("request region failed for myports\n");
	} 
	else 
	{
		pr_info("request region success for myports\n");
	}

	return 0;
}

static void mod_exit(void)
{
	release_region(MY_BASEPORT, NUMBER_PORTS);
}

module_init(mod_init);
module_exit(mod_exit);
		 

==> ./LinuxCommunicatingWithHardware/02_ReadWriteFromIO/ReadWriteFromIO.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/io.h>

#define MY_BASEPORT 0x0063
#define NUMBER_PORTS 1

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	if (!request_region(MY_BASEPORT, NUMBER_PORTS, "myports")) 
	{
		pr_info("request region failed for myports\n");
	} 
	else 
	{
		pr_info("request region success for myports\n");
		outb(0xa, MY_BASEPORT);
	}

	return 0;
}

static void mod_exit(void)
{
	unsigned int a;
	a = inb(MY_BASEPORT);
	pr_info("Value at %02x is %02x\n", MY_BASEPORT, a);
	release_region(MY_BASEPORT, NUMBER_PORTS);
}

module_init(mod_init);
module_exit(mod_exit);
		 

==> ./LinuxCommunicatingWithHardware/03_EnablingSpeaker/EnablingSpeaker.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

//If speaker is available on port 61 as PNP (Plug and Play device) 

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	outb(0x03, 0x0061); //Enabling speaker
	ssleep(5);
	outb(0x00, 0x0061); //Disabling speaker
	return 0;
}

static void mod_exit(void)
{
}

module_init(mod_init);
module_exit(mod_exit);
		 

==> ./LinuxCommunicatingWithHardware/04_Communicating_with_RTC/Communicating_with_RTC.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define RTC_ADDRESS		0x70
#define RTC_DATA		0x71

#define SECONDS			0x00
#define MINUTES			0x02
#define HOURS			0x04
#define DAY_WEEK		0x06
#define DAY_MONTH		0x07
#define MONTH			0x08
#define YEAR			0x09

#define REGA			0x0A
#define REGB			0x0B
#define REGC			0x0C
#define REGD			0x0D

unsigned char rtc_read(int address)
{
	outb_p(address, RTC_ADDRESS);
	return inb_p(RTC_DATA);
}

int __init hello_init(void)
{
	unsigned char regb = rtc_read(REGB);

	pr_info("Register B:%02x\n", regb);

	if (regb & 0x01) 
	{
		pr_info("Daylight saving enabled\n");
	}
	else
	{
		pr_info("Daylight saving disabled\n");

	}

	if (regb & 0x02) 
	{
		pr_info("24 Hour Mode\n");
	}
	else
	{
		pr_info("12 Hour Mode\n");
	}

	if (regb & 0x04) 
	{
		pr_info("Data in Binary Format\n");
	}
	else
	{
		pr_info("Data in BCD Format\n");
	}

	return 0;
}

void __exit hello_exit(void)
{

}


MODULE_LICENSE("GPL");

module_init(hello_init);
module_exit(hello_exit);
		 

==> ./LinuxCommunicatingWithHardware/05_HW_AND_SW_CLOCK/HW_AND_SW_CLOCK.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define RTC_ADDRESS		0x70
#define RTC_DATA		0x71

#define SECONDS			0x00
#define MINUTES			0x02
#define HOURS			0x04
#define DAY_WEEK		0x06
#define DAY_MONTH		0x07
#define MONTH			0x08
#define YEAR			0x09

#define REGA			0x0A
#define REGB			0x0B
#define REGC			0x0C
#define REGD			0x0D

unsigned char rtc_read(int address)
{
	outb_p(address, RTC_ADDRESS);
	return inb_p(RTC_DATA);
}

int __init hello_init(void)
{
	pr_info("Hours:%02x\t Minutes:%02x\t Seconds:%02x\n", rtc_read(HOURS), rtc_read(MINUTES), rtc_read(SECONDS));
	ssleep(5);

	pr_info("Hours:%02x\t Minutes:%02x\t Seconds:%02x\n", rtc_read(HOURS), rtc_read(MINUTES), rtc_read(SECONDS));

	return 0;
}

void __exit hello_exit(void)
{

}


MODULE_LICENSE("GPL");

module_init(hello_init);
module_exit(hello_exit);
		 

==> ./LinuxCommunicatingWithHardware/06_Update_Time/Update_Time.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define RTC_ADDRESS		0x70
#define RTC_DATA		0x71

#define SECONDS			0x00
#define MINUTES			0x02
#define HOURS			0x04
#define DAY_WEEK		0x06
#define DAY_MONTH		0x07
#define MONTH			0x08
#define YEAR			0x09

#define REGA			0x0A
#define REGB			0x0B
#define REGC			0x0C
#define REGD			0x0D

unsigned char rtc_read(int address)
{
	outb_p(address, RTC_ADDRESS);
	return inb_p(RTC_DATA);
}

void rtc_write(unsigned char address, unsigned char value)
{
	outb_p(address, RTC_ADDRESS);
	outb_p(value, RTC_DATA);
}

int __init hello_init(void)
{
	pr_info("Hours:%02x\t Minutes:%02x\t Seconds:%02x\n", rtc_read(HOURS), rtc_read(MINUTES), rtc_read(SECONDS));
	ssleep(5);

	rtc_write(HOURS, 3);
	rtc_write(MINUTES, 33);
	rtc_write(SECONDS, 33);

	pr_info("Hours:%02x\t Minutes:%02x\t Seconds:%02x\n", rtc_read(HOURS), rtc_read(MINUTES), rtc_read(SECONDS));

	return 0;
}

void __exit hello_exit(void)
{

}


MODULE_LICENSE("GPL");

module_init(hello_init);
module_exit(hello_exit);
		 

==> ./LinuxCommunicatingWithHardware/07_Sending_Keyboard_Controller_Commands/Sending_Keyboard_Controller_Commands.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/io.h>

#define I8042_COMMAND_REG		0x64
#define I8042_STATUS_REG		0x64
#define I8042_DATA_REG			0x60

static inline int i8042_read_data(void)
{
	return inb(I8042_DATA_REG);
}

static inline int i8042_read_status(void)
{
	return inb(I8042_STATUS_REG);
}

//commands to be sent to the keyboard microprocessor
static inline void i8042_write_data(int val)
{
	outb(val, I8042_DATA_REG);
}

//commands to be sent to the keyboard controller
static inline void i8042_write_command(int val)
{
	outb(val, I8042_COMMAND_REG);
}

int __init hello_init(void)
{
	int cmd_byte;

	//read command byte
	i8042_write_command(0x20);
	cmd_byte = i8042_read_data();

	pr_info("cmd_byte:%02x\n", cmd_byte);
	if (cmd_byte & 0x01)
	{
		pr_info("Keyboard interrupt enabled\n");
	}
	else
	{
		pr_info("Keyboard interrupt disabled\n");
	}

	if (cmd_byte & 0x02)
	{
		pr_info("Mouse interrupt enabled\n");
	}
	else
	{
		pr_info("Mouse interrupt disabled\n");
	}

	if (cmd_byte & 0x04)
	{
		pr_info("System Flag self test passed\n");
	}
	else
	{
		pr_info("System Flag self test failed\n");
	}

	if (cmd_byte & 0x80)
	{
		pr_info("Inhibit switch enabled\n");
	}
	else
	{
		pr_info("Inhibit switch disabled\n");
	}

	if (cmd_byte & 0x10)
	{
		pr_info("Keyboard interface disabled\n");
	}
	else
	{
		pr_info("Keyboard communication enabled\n");
	}

	if (cmd_byte & 0x20)
	{
		pr_info("Auxiliary PS/2 device interface disabled\n");
	}
	else
	{
		pr_info("Auxiliary PS/2 device interface enabled\n");
	}

	return 0;
}

void __exit hello_exit(void)
{

}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);

==> ./LinuxCommunicatingWithHardware/08_Enabling_Disabling_Mouse/Enabling_Disabling_Mouse.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define I8042_COMMAND_REG		0x64
#define I8042_STATUS_REG		0x64
#define I8042_DATA_REG			0x60

static inline int i8042_read_data(void)
{
	return inb(I8042_DATA_REG);
}

static inline int i8042_read_status(void)
{
	return inb(I8042_STATUS_REG);
}

//commands to be sent to the keyboard microprocessor
static inline void i8042_write_data(int val)
{
	outb(val, I8042_DATA_REG);
}

//commands to be sent to the keyboard controller
static inline void i8042_write_command(int val)
{
	outb(val, I8042_COMMAND_REG);
}

void print_cmd_byte(unsigned char cmd_byte)
{
	if (cmd_byte & 0x01)
	{
		pr_info("Keyboard interrupt enabled\n");
	}
	else
	{
		pr_info("Keyboard interrupt disabled\n");
	}

	if (cmd_byte & 0x02)
	{
		pr_info("Mouse interrupt enabled\n");
	}
	else
	{
		pr_info("Mouse interrupt disabled\n");
	}

	if (cmd_byte & 0x04)
	{
		pr_info("System Flag self test passed\n");
	}
	else
	{
		pr_info("System Flag self test failed\n");
	}

	if (cmd_byte & 0x80)
	{
		pr_info("Inhibit switch enabled\n");
	}
	else
	{
		pr_info("Inhibit switch disabled\n");
	}

	if (cmd_byte & 0x10)
	{
		pr_info("Keyboard interface disabled\n");
	}
	else
	{
		pr_info("Keyboard communication enabled\n");
	}

	if (cmd_byte & 0x20)
	{
		pr_info("Auxiliary PS/2 device interface disabled\n");
	}
	else
	{
		pr_info("Auxiliary PS/2 device interface enabled\n");
	}
}

int __init hello_init(void)
{
	unsigned char cmd_byte;

	//read command byte
	i8042_write_command(0x20);
	cmd_byte = i8042_read_data();

	pr_info("cmd_byte:%02x\n", cmd_byte);
	print_cmd_byte(cmd_byte);

	//Disabling Mouse
	cmd_byte |= (1 << 5);
	pr_info("updating cmd byte:%02x\n", cmd_byte);
	i8042_write_command(0x60);
	i8042_write_data(cmd_byte);

	i8042_write_command(0x20);
	cmd_byte = i8042_read_data();
	print_cmd_byte(cmd_byte);
	ssleep(5);

	//Enabling Mouse
	cmd_byte &= ~(1 << 5);
	pr_info("updating cmd byte:%02x\n", cmd_byte);
	i8042_write_command(0x60);
	i8042_write_data(cmd_byte);
	i8042_write_command(0x20);
	cmd_byte = i8042_read_data();
	print_cmd_byte(cmd_byte);

	pr_info("cmd_byte:%02x\n", cmd_byte);
	return 0;
}

void __exit hello_exit(void)
{

}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);

==> ./LinuxCommunicatingWithHardware/09_Enabling_Disabling_Keyboard/Enabling_Disabling_Keyboard.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define I8042_COMMAND_REG		0x64
#define I8042_STATUS_REG		0x64
#define I8042_DATA_REG			0x60

static inline int i8042_read_data(void)
{
	return inb(I8042_DATA_REG);
}

static inline int i8042_read_status(void)
{
	return inb(I8042_STATUS_REG);
}

//commands to be sent to the keyboard microprocessor
static inline void i8042_write_data(int val)
{
	outb(val, I8042_DATA_REG);
}

//commands to be sent to the keyboard controller
static inline void i8042_write_command(int val)
{
	outb(val, I8042_COMMAND_REG);
}

void print_cmd_byte(unsigned char cmd_byte)
{
	if (cmd_byte & 0x01)
	{
		pr_info("Keyboard interrupt enabled\n");
	}
	else
	{
		pr_info("Keyboard interrupt disabled\n");
	}

	if (cmd_byte & 0x02)
	{
		pr_info("Mouse interrupt enabled\n");
	}
	else
	{
		pr_info("Mouse interrupt disabled\n");
	}

	if (cmd_byte & 0x04)
	{
		pr_info("System Flag self test passed\n");
	}
	else
	{
		pr_info("System Flag self test failed\n");
	}

	if (cmd_byte & 0x80)
	{
		pr_info("Inhibit switch enabled\n");
	}
	else
	{
		pr_info("Inhibit switch disabled\n");
	}

	if (cmd_byte & 0x10)
	{
		pr_info("Keyboard interface disabled\n");
	}
	else
	{
		pr_info("Keyboard communication enabled\n");
	}

	if (cmd_byte & 0x20)
	{
		pr_info("Auxiliary PS/2 device interface disabled\n");
	}
	else
	{
		pr_info("Auxiliary PS/2 device interface enabled\n");
	}
}

int __init hello_init(void)
{
	//0xAD (Disable keyboard interface) - Sets bit 4 of command byte and disables all communication with keyboard
	i8042_write_command(0xAD);

	ssleep(5);

	//0xAE (Enable keyboard interface) - Clears bit 4 of command byte and re-enables communication with keyboard
	i8042_write_command(0xAE);

	return 0;
}

void __exit hello_exit(void)
{

}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);

==> ./LinuxCommunicatingWithHardware/10_Read_Command_Byte_Post_Keyboard_Disable/Read_Cmd_Byte_Post_Keyboard_Disable.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define I8042_COMMAND_REG		0x64
#define I8042_STATUS_REG		0x64
#define I8042_DATA_REG			0x60

static inline int i8042_read_data(void)
{
	return inb(I8042_DATA_REG);
}

static inline int i8042_read_status(void)
{
	return inb(I8042_STATUS_REG);
}

//commands to be sent to the keyboard microprocessor
static inline void i8042_write_data(int val)
{
	outb(val, I8042_DATA_REG);
}

//commands to be sent to the keyboard controller
static inline void i8042_write_command(int val)
{
	outb(val, I8042_COMMAND_REG);
}

void print_cmd_byte(unsigned char cmd_byte)
{
	if (cmd_byte & 0x01)
	{
		pr_info("Keyboard interrupt enabled\n");
	}
	else
	{
		pr_info("Keyboard interrupt disabled\n");
	}

	if (cmd_byte & 0x02)
	{
		pr_info("Mouse interrupt enabled\n");
	}
	else
	{
		pr_info("Mouse interrupt disabled\n");
	}

	if (cmd_byte & 0x04)
	{
		pr_info("System Flag self test passed\n");
	}
	else
	{
		pr_info("System Flag self test failed\n");
	}

	if (cmd_byte & 0x80)
	{
		pr_info("Inhibit switch enabled\n");
	}
	else
	{
		pr_info("Inhibit switch disabled\n");
	}

	if (cmd_byte & 0x10)
	{
		pr_info("Keyboard interface disabled\n");
	}
	else
	{
		pr_info("Keyboard communication enabled\n");
	}

	if (cmd_byte & 0x20)
	{
		pr_info("Auxiliary PS/2 device interface disabled\n");
	}
	else
	{
		pr_info("Auxiliary PS/2 device interface enabled\n");
	}
}

int __init hello_init(void)
{
	unsigned char cmd_byte;

	//0xAD (Disable keyboard interface) - Sets bit 4 of command byte and disables all communication
	i8042_write_command(0xAD);

	//read command byte
	i8042_write_command(0x20);
	cmd_byte = i8042_read_data();

	pr_info("cmd_byte:%02x\n", cmd_byte);
	print_cmd_byte(cmd_byte);

	ssleep(5);

	//0xAE (Enable keyboard interface) - Clears bit 4 of command byte and re-enables communication with keyboard
	i8042_write_command(0xAE);

	i8042_write_command(0x20);
	cmd_byte = i8042_read_data();
	pr_info("cmd_byte:%02x\n", cmd_byte);
	print_cmd_byte(cmd_byte);
	return 0;
}

void __exit hello_exit(void)
{

}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);

==> ./LinuxCommunicatingWithHardware/11_status_register/Status_Register.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define I8042_COMMAND_REG		0x64
#define I8042_STATUS_REG		0x64
#define I8042_DATA_REG			0x60

static inline int i8042_read_data(void)
{
	return inb(I8042_DATA_REG);
}

static inline int i8042_read_status(void)
{
	return inb(I8042_STATUS_REG);
}

//commands to be sent to the keyboard microprocessor
static inline void i8042_write_data(int val)
{
	outb(val, I8042_DATA_REG);
}

//commands to be sent to the keyboard controller
static inline void i8042_write_command(int val)
{
	outb(val, I8042_COMMAND_REG);
}

void print_cmd_byte(unsigned char cmd_byte)
{
	if (cmd_byte & 0x01)
	{
		pr_info("Keyboard interrupt enabled\n");
	}
	else
	{
		pr_info("Keyboard interrupt disabled\n");
	}

	if (cmd_byte & 0x02)
	{
		pr_info("Mouse interrupt enabled\n");
	}
	else
	{
		pr_info("Mouse interrupt disabled\n");
	}

	if (cmd_byte & 0x04)
	{
		pr_info("System Flag self test passed\n");
	}
	else
	{
		pr_info("System Flag self test failed\n");
	}

	if (cmd_byte & 0x80)
	{
		pr_info("Inhibit switch enabled\n");
	}
	else
	{
		pr_info("Inhibit switch disabled\n");
	}

	if (cmd_byte & 0x10)
	{
		pr_info("Keyboard interface disabled\n");
	}
	else
	{
		pr_info("Keyboard communication enabled\n");
	}

	if (cmd_byte & 0x20)
	{
		pr_info("Auxiliary PS/2 device interface disabled\n");
	}
	else
	{
		pr_info("Auxiliary PS/2 device interface enabled\n");
	}
}

int __init hello_init(void)
{
	int status = i8042_read_status();

	if (status & 0x01)
	{
		pr_info("Output buffer status full\n");
	}
	else
	{
		pr_info("Output buffer status empty\n");
	}

	if (status & 0x02)
	{
		pr_info("Input buffer status full\n");
	}
	else
	{
		pr_info("Input buffer status empty\n");
	}

	if (status & 0x08)
	{
		pr_info("Command Byte\n");
	}
	else
	{
		pr_info("Data Byte\n");
	}

	if (status & 0x10)
	{
		pr_info("Keyboard enabled\n");
	}
	else
	{
		pr_info("Keyboard disabled\n");
	}

	return 0;
}

void __exit hello_exit(void)
{

}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);

==> ./LinuxCommunicatingWithHardware/12_Print_Keys_Typed/Print_Keys_Typed.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define I8042_COMMAND_REG		0x64
#define I8042_STATUS_REG		0x64
#define I8042_DATA_REG			0x60

static inline int i8042_read_data(void)
{
	return inb(I8042_DATA_REG);
}

static inline int i8042_read_status(void)
{
	return inb(I8042_STATUS_REG);
}

//commands to be sent to the keyboard microprocessor
static inline void i8042_write_data(int val)
{
	outb(val, I8042_DATA_REG);
}

//commands to be sent to the keyboard controller
static inline void i8042_write_command(int val)
{
	outb(val, I8042_COMMAND_REG);
}

void print_cmd_byte(unsigned char cmd_byte)
{
	if (cmd_byte & 0x01)
	{
		pr_info("Keyboard interrupt enabled\n");
	}
	else
	{
		pr_info("Keyboard interrupt disabled\n");
	}

	if (cmd_byte & 0x02)
	{
		pr_info("Mouse interrupt enabled\n");
	}
	else
	{
		pr_info("Mouse interrupt disabled\n");
	}

	if (cmd_byte & 0x04)
	{
		pr_info("System Flag self test passed\n");
	}
	else
	{
		pr_info("System Flag self test failed\n");
	}

	if (cmd_byte & 0x80)
	{
		pr_info("Inhibit switch enabled\n");
	}
	else
	{
		pr_info("Inhibit switch disabled\n");
	}

	if (cmd_byte & 0x10)
	{
		pr_info("Keyboard interface disabled\n");
	}
	else
	{
		pr_info("Keyboard communication enabled\n");
	}

	if (cmd_byte & 0x20)
	{
		pr_info("Auxiliary PS/2 device interface disabled\n");
	}
	else
	{
		pr_info("Auxiliary PS/2 device interface enabled\n");
	}
}

int __init hello_init(void)
{
	int status = i8042_read_status();
	int data;

	while (!(status & 0x01))
	{
		status = i8042_read_status();
	}

	data = i8042_read_data();
	pr_info("Data:%02x\n", data);

	return 0;
}

void __exit hello_exit(void)
{

}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);

==> ./LinuxCommunicatingWithHardware/13_Print_Keys_Typed_Two/Print_Keys_Typed.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define I8042_COMMAND_REG		0x64
#define I8042_STATUS_REG		0x64
#define I8042_DATA_REG			0x60


const unsigned char kbdus[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};


static inline int i8042_read_data(void)
{
	return inb(I8042_DATA_REG);
}

static inline int i8042_read_status(void)
{
	return inb(I8042_STATUS_REG);
}

//commands to be sent to the keyboard microprocessor
static inline void i8042_write_data(int val)
{
	outb(val, I8042_DATA_REG);
}

//commands to be sent to the keyboard controller
static inline void i8042_write_command(int val)
{
	outb(val, I8042_COMMAND_REG);
}

void print_cmd_byte(unsigned char cmd_byte)
{
	if (cmd_byte & 0x01)
	{
		pr_info("Keyboard interrupt enabled\n");
	}
	else
	{
		pr_info("Keyboard interrupt disabled\n");
	}

	if (cmd_byte & 0x02)
	{
		pr_info("Mouse interrupt enabled\n");
	}
	else
	{
		pr_info("Mouse interrupt disabled\n");
	}

	if (cmd_byte & 0x04)
	{
		pr_info("System Flag self test passed\n");
	}
	else
	{
		pr_info("System Flag self test failed\n");
	}

	if (cmd_byte & 0x80)
	{
		pr_info("Inhibit switch enabled\n");
	}
	else
	{
		pr_info("Inhibit switch disabled\n");
	}

	if (cmd_byte & 0x10)
	{
		pr_info("Keyboard interface disabled\n");
	}
	else
	{
		pr_info("Keyboard communication enabled\n");
	}

	if (cmd_byte & 0x20)
	{
		pr_info("Auxiliary PS/2 device interface disabled\n");
	}
	else
	{
		pr_info("Auxiliary PS/2 device interface enabled\n");
	}
}

int __init hello_init(void)
{
	int status = i8042_read_status();
	int data;

	while (!(status & 0x01))
	{
		status = i8042_read_status();
	}

	data = i8042_read_data();
	pr_info("ScanCode:%02x\n", data);
	pr_info("Data:%c\n", kbdus[data]);

	return 0;
}

void __exit hello_exit(void)
{

}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);

==> ./LinuxCommunicatingWithHardware/14_Turn_On_KB_LEDS/Turn_On_KB_LEDS.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define I8042_COMMAND_REG		0x64
#define I8042_STATUS_REG		0x64
#define I8042_DATA_REG			0x60

static inline int i8042_read_data(void)
{
	return inb(I8042_DATA_REG);
}

static inline int i8042_read_status(void)
{
	return inb(I8042_STATUS_REG);
}

//commands to be sent to the keyboard microprocessor
static inline void i8042_write_data(int val)
{
	outb(val, I8042_DATA_REG);
}

//commands to be sent to the keyboard controller
static inline void i8042_write_command(int val)
{
	outb(val, I8042_COMMAND_REG);
}

//LED followed by parameter bits
//bits 3-7: Must be zero.

//bit 2: Capslock LED (1 = on, 0 = off).

//bit 1: Numlock LED (1 = on, 0 = off).

//bit 0: Scroll lock LED (1 = on, 0 = off).

static void set_kbd_led_on(void)
{
	//wait till the input buffer is empty
	while ((i8042_read_status() & 0x02));

	//send 0xED as Data
	i8042_write_data(0xED);

	//wait till the input buffer is empty
	while ((i8042_read_status() & 0x02));

	//0x07 for all LEDS
	i8042_write_data(0x07);
}

static void set_kbd_led_off(void)
{
	//wait till the input buffer is empty
	while ((i8042_read_status() & 0x02));

	//send 0xED as Data
	i8042_write_data(0xED);

	//wait till the input buffer is empty
	while ((i8042_read_status() & 0x02));

	//0x00 for all LEDS off
	i8042_write_data(0x00);
}

void print_cmd_byte(unsigned char cmd_byte)
{
	if (cmd_byte & 0x01)
	{
		pr_info("Keyboard interrupt enabled\n");
	}
	else
	{
		pr_info("Keyboard interrupt disabled\n");
	}

	if (cmd_byte & 0x02)
	{
		pr_info("Mouse interrupt enabled\n");
	}
	else
	{
		pr_info("Mouse interrupt disabled\n");
	}

	if (cmd_byte & 0x04)
	{
		pr_info("System Flag self test passed\n");
	}
	else
	{
		pr_info("System Flag self test failed\n");
	}

	if (cmd_byte & 0x80)
	{
		pr_info("Inhibit switch enabled\n");
	}
	else
	{
		pr_info("Inhibit switch disabled\n");
	}

	if (cmd_byte & 0x10)
	{
		pr_info("Keyboard interface disabled\n");
	}
	else
	{
		pr_info("Keyboard communication enabled\n");
	}

	if (cmd_byte & 0x20)
	{
		pr_info("Auxiliary PS/2 device interface disabled\n");
	}
	else
	{
		pr_info("Auxiliary PS/2 device interface enabled\n");
	}
}

int __init hello_init(void)
{
	set_kbd_led_on();
	ssleep(5);
	set_kbd_led_off();

	return 0;
}

void __exit hello_exit(void)
{

}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);

==> ./LinuxCommunicatingWithHardware/15_ioperm_system_call/prog.c <==
#include <stdio.h>
#include <errno.h>
#include <sys/io.h>

int main(int argc, char *argv[])
{
	if (ioperm(0x70, 3, 1)) 
	{
		perror("ioperm failed");
	}
	else
	{
		printf("ioperm on 0x70 success\n");
	}
}

==> ./LinuxCommunicatingWithHardware/16_Error_Message_TO_Normal_User/Error_Message_To_Normal_User.c <==
#include <stdio.h>
#include <errno.h>
#include <sys/io.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	//Allow only root user user to run this program, uid of root is 0
	if (geteuid() != 0) 
	{
		fprintf(stderr, "Must be root to run %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (ioperm(0x70, 3, 1))
	{
		perror("ioperm failed");
	}
	else
	{
		printf("ioperm on 0x70 success\n");
	}

	return 0;
}

==> ./LinuxCommunicatingWithHardware/17_No_IOPerm_Call_From_Userspace/No_IOPerm_Call_From_Userspace.c <==
#include <stdio.h>
#include <sys/io.h>

int main()
{
	outb(0x70, 0x00);
	printf("%d\n", inb(0x71));
	return 0;
}

==> ./LinuxCommunicatingWithHardware/18_Access_RTC_Registers_From_User_Space/Access_RTC_Registers_From_User_Space.c <==
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define RTC_ADDRESS_PORT	0x70
#define RTC_DATA_PORT		0x71

unsigned char rtc_read(int offset)
{
	unsigned char value;

	ioperm(RTC_ADDRESS_PORT, 0x2, 1);

	outb(offset, RTC_ADDRESS_PORT);
	value = inb(RTC_DATA_PORT);

	ioperm(RTC_ADDRESS_PORT, 0x2, 0);
	return value;
}

int main(int argc, char **argv)
{
	int i;
	unsigned long tmp;

	unsigned char rtc_data[0x10];

	if (geteuid() != 0) 
	{
		fprintf(stderr, "Must be root to run %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < sizeof(rtc_data); i++)
		rtc_data[1] = rtc_read(i);

	printf("RTC Current Time: %2.2x:%2.2x:%2.2x %2.2x/%2.2x/%2.2x \n", 
					rtc_data[4],
					rtc_data[2],
					rtc_data[0],
					rtc_data[7],
					rtc_data[8],
					rtc_data[9]);

	exit(EXIT_SUCCESS);
}

==> ./LinuxCommunicatingWithHardware/19_iopl/iopl.c <==
#include <stdio.h>
#include <errno.h>
#include <sys/io.h>

int main(int argc, char *argv[])
{
	if (iopl(3)) 
	{
		perror("iopl failed");
	}	
	else 
	{
		printf("iopl success\n");
	}

	return 0;
}

==> ./LinuxCommunicatingWithHardware/20_Accessing_RTC_After_iopl/Accessing_RTC_After_iopl.c <==
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define RTC_ADDRESS_PORT	0x70
#define RTC_DATA_PORT		0x71

unsigned char rtc_read(int offset)
{
	unsigned char value;

	outb(offset, RTC_ADDRESS_PORT);
	value = inb(RTC_DATA_PORT);

	return value;
}

int main(int argc, char **argv)
{
	int i;
	unsigned long tmp;

	unsigned char rtc_data[0x10];

	if (geteuid() != 0)
	{
		fprintf(stderr, "Must be root to run %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	iopl(3);

	for (i=0; i < sizeof(rtc_data); i++)
		rtc_data[i] = rtc_read(i);

	printf("RTC Current Time: %2.2x:%2.2x:%2.2x %2.2x/%2.2x/%2.2x \n", 
					rtc_data[4],
					rtc_data[2],
					rtc_data[0],
					rtc_data[7],
					rtc_data[8],
					rtc_data[9]);

	exit(EXIT_SUCCESS);
}



==> ./LinuxCommunicatingWithHardware/21_Pushing_Keys_From_Userspace/Pushing_Keys_From_Userspace.c <==
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/io.h>

#define I8042_DATA_REG			0x60
#define I8042_STATUS_REG		0x64

void push_keycode(unsigned char code)
{
	while (inb(I8042_STATUS_REG) & 0x2);

	outb(0xd2, I8042_STATUS_REG);

	while (inb(I8042_STATUS_REG) & 0x2);

	outb(code, I8042_STATUS_REG);
}

/*  keycodes in http://www.win.tue.nl/~aeb/linux/kbd/scancodes-1.html */
unsigned char hello[] = { 
	0x23, 0x12, 0x26, 0x26, 0x18, 
	0x26, 0x17, 0x31, 0x16, 0x2d, 0
};


int main(int argc, char **argv)
{
	unsigned char *ptr = hello;

	iopl(3);

	for (ptr = hello; *ptr; ptr++)
	{
		printf("%02x\n", *ptr);
		push_keycode(*ptr);			/* Key down */
		sleep(1);
		push_keycode(*ptr | 0x80);	/* Key up */
		sleep(1);
	}

	exit(EXIT_SUCCESS);
}

==> ./LinuxCommunicatingWithHardware/22_Restart_Computer_With_Keyboard_Port/Restart_Computer_With_Keyboard_Port.c <==
#include <stdio.h>
#include <sys/io.h>

#define KEYBOARD_PORT 0x64

int main()
{
	ioperm(KEYBOARD_PORT, 0x01, 0x01);
	//The keyboard controller has a pin which goes to the reset pin of the CPU. 
	//A Command Byte of 0xFE means "pulse the reset line down for 6ms"
	outb(0xfe, KEYBOARD_PORT);
	return 0;
}

==> ./LinuxCommunicatingWithHardware/23_Enabling_Disabling_Speaker/Enabling_Disabling_Speaker.c <==
#include <stdio.h>
#include <sys/io.h>
#include <unistd.h>

#define SPEAKER_PORT 0x61

int main()
{
	ioperm(SPEAKER_PORT, 0x01, 0x01);
	outb(0x03, SPEAKER_PORT); // Turn ON Speaker
	sleep(3);
	outb(0x00, SPEAKER_PORT); // Turn OFF Speaker
	return 0;
}

==> ./LinuxCommunicatingWithHardware/24_Timers_And_Speakers/Timers_And_Speakers.c <==
#include <stdio.h>
#include <sys/io.h>
#include <unistd.h>

#define SPEAKER_PORT 0x61
#define TIMER2_PORT 0x42
#define PIT_SETTING_PORT 0x43
#define PIT_BASE_PORT 0x40

int main()
{
	int freq;
	ioperm(PIT_BASE_PORT, 4, 0x01);
	ioperm(SPEAKER_PORT, 0x01, 0x01);

	for (freq = 100; freq < 800; freq += 100)
	{
		unsigned short div = 1193181/freq; //frequency is 1.193 MHz

		outb(0xb6, PIT_SETTING_PORT);
		outb(div, TIMER2_PORT);
		outb(div>>8, TIMER2_PORT);
		outb(0x03, SPEAKER_PORT); //Turn ON Speaker
		sleep(1);
	}

	outb(0x00, SPEAKER_PORT); //Turn OFF Speaker
	return 0;
}

==> ./LinuxCommunicatingWithHardware/25_dev_port/dev_port.c <==
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char seconds = 0;
	char data = 0;
	int fd = open("/dev/port", O_RDWR);

	perror("open");

	lseek(fd, 0x70, SEEK_SET);
	write(fd, &data, 1);

	lseek(fd, 0x71, SEEK_SET);
	read(fd, &seconds, 1);
	printf("%02X ", seconds);

	close(fd);
	return 0;
}

==> ./LinuxCommunicatingWithHardware/26_Request_mem_region_fail/Request_mem_region_fail.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>

#define MY_BASEADDRESS 0x00000000
#define LENGTH 0xf

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	if (!request_mem_region(MY_BASEADDRESS, LENGTH, "myports"))
	{
		pr_info("request_mem_region failed for myports\n");
		return -1;
	}
	else
	{
		pr_info("request_mem_region success for myports\n");
	}

	return 0;
}

static void mod_exit(void)
{
	release_mem_region(MY_BASEADDRESS, LENGTH);
}

module_init(mod_init);
module_exit(mod_exit);


==> ./LinuxCommunicatingWithHardware/27_Request_mem_region_success/Request_mem_region_success.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>

#define MY_BASEADDRESS 0xf8000000
#define LENGTH 0xf

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	if (!request_mem_region(MY_BASEADDRESS, LENGTH, "myports"))
	{
		pr_info("request_mem_region failed for myports\n");
		return -1;
	}
	else
	{
		pr_info("request_mem_region success for myports\n");
	}
	return 0;
}

static void mod_exit(void)
{
	release_mem_region(MY_BASEADDRESS, LENGTH);
}

module_init(mod_init);
module_exit(mod_exit);

==> ./LinuxCommunicatingWithHardware/28_ioremap_iounmap/ioremap_iounmap.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/io.h>

#define MY_BASEADDRESS 0xf8000000
#define LENGTH 0xf

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	if (!request_mem_region(MY_BASEADDRESS, LENGTH, "myports"))
	{
		pr_info("request_mem_region() failed for myports\n");
	}
	else
	{
		void __iomem *p;

		pr_info("request_mem_region() success for myports\n");

		p = ioremap(MY_BASEADDRESS, LENGTH);
		pr_info("ioremap returned:%px\n", p); //return a virtual address
		iounmap(p);
	}

	return 0;
}

static void mod_exit(void)
{
	release_mem_region(MY_BASEADDRESS, LENGTH);
}

module_init(mod_init);
module_exit(mod_exit);

==> ./LinuxCommunicatingWithHardware/29_writing_to_memory/writing_to_memory.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/io.h>

#define MY_BASEADDRESS 0xf8000000
#define LENGTH 0xf

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	if (!request_mem_region(MY_BASEADDRESS, LENGTH, "myports"))
	{
		pr_info("request_mem_region failed for myports\n");
		return -1;
	}
	else
	{
		void __iomem *p;

		pr_info("request_mem_region() success for myports");

		p = ioremap(MY_BASEADDRESS, LENGTH);
		pr_info("ioremap returned:%px\n", p);
		*(unsigned int *)p = 0x12345678;
		pr_info("read:%04x\n", *(unsigned int *)p);
		iounmap(p);
	}

	return 0;
}

static void mod_exit(void)
{
	release_mem_region(MY_BASEADDRESS, LENGTH);
}

module_init(mod_init);
module_exit(mod_exit);

==> ./LinuxCommunicatingWithHardware/30_ioread_iowrite/ioread_iowrite.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/io.h>

#define MY_BASEADDRESS 0xf8000000
#define LENGTH 0xf

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	if (!request_mem_region(MY_BASEADDRESS, LENGTH, "myports"))
	{
		pr_info("request_mem_region failed for myports\n");
		return -1;
	}
	else
	{
		void __iomem *p;
		int value;
		pr_info("request_mem_region success for myports\n");
		
		p = ioremap(MY_BASEADDRESS, LENGTH);
		pr_info("ioremap returned:%px\n", p);
		iowrite32(0x1234, p);
		value = ioread32(p);
		pr_info("Value read:%02x\n", value);
		iounmap(p);
	}

	return 0;
}

static void mod_exit(void)
{
	release_mem_region(MY_BASEADDRESS, LENGTH);
}

module_init(mod_init);
module_exit(mod_exit);

==> ./LinuxCommunicatingWithHardware/31_HW_Random_Number_Generator/HW_Random_Number_Generator.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/io.h>

#define INTEL_RANDOM_GENERATOR_ADDR 0xFFBC015F
#define LENGTH 3

#define INTEL_RANDOM_GENERATOR_HW_STATUS 0
#define INTEL_RANDOM_GENERATOR_PRESENT 0x40
#define INTEL_RANDOM_GENERATOR_ENABLED 0x01

MODULE_LICENSE("GPL");

static inline unsigned char hwstatus_get(void __iomem *mem)
{
	return ioread8(mem + INTEL_RANDOM_GENERATOR_HW_STATUS);
}

static int mod_init(void)
{
	if (!request_mem_region(INTEL_RANDOM_GENERATOR_ADDR, LENGTH, "myports"))
	{
		pr_info("request_mem_region() failed for myports\n");
		return -1;
	}
	else 
	{
		void __iomem *mem;
		unsigned char hw_status;

		pr_info("request_mem_region() succcess for myports\n");

		mem = ioremap(INTEL_RANDOM_GENERATOR_ADDR, LENGTH);
		pr_info("ioremap returned:%px\n", mem);
		if (!mem)
		{
			pr_err("ioremap failed\n");
			return -1;
		}
		hw_status = hwstatus_get(mem);
		pr_info("Hardware status:%02x\n", hw_status);
		if ((hw_status & INTEL_RANDOM_GENERATOR_PRESENT) == 0)
		{
			pr_warn("Random number generator not present\n");
		}
		else
		{
			pr_warn("Random number generator present\n");
		}
		
		if ((hw_status & INTEL_RANDOM_GENERATOR_ENABLED) == 0)
		{
			pr_warn("Random number generator not enabled\n");
		}
		else
		{
			pr_warn("Random number generator enabled\n");
		}

		iounmap(mem);
	}

	return 0;
}

static void mod_exit(void)
{
	release_mem_region(INTEL_RANDOM_GENERATOR_ADDR, LENGTH);
}

module_init(mod_init);
module_exit(mod_exit);

==> ./LinuxCommunicatingWithHardware/32_Registers_in_HW_RNG/Registers_in_HW_RNG.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define INTEL_RANDOM_GENERATOR_ADDR 0xFFBC015F
#define LENGTH 3

#define INTEL_RANDOM_GENERATOR_HW_STATUS 0
#define INTEL_RANDOM_GENERATOR_PRESENT 0x40
#define INTEL_RANDOM_GENERATOR_ENABLED 0x01
#define INTEL_RANDOM_GENERATOR_STATUS 1
#define INTEL_RANDOM_GENERATOR_DATA_PRESENT 0x01
#define INTEL_RANDOM_GENERATOR_DATA 2

MODULE_LICENSE("GPL");

static inline unsigned char hwstatus_get(void __iomem *mem)
{
	return ioread8(mem + INTEL_RANDOM_GENERATOR_HW_STATUS);
}

static void read_random_data(void __iomem *mem)
{
	int data = 0x00;
	int i;

	for (i = 0; i < 20; i++)
	{
		data = !!(ioread8(mem + INTEL_RANDOM_GENERATOR_STATUS) & INTEL_RANDOM_GENERATOR_DATA_PRESENT);

		if (data) break;
		udelay(10);
	}

	pr_info("Data:%02x\n", data);

	if (data)
	{
		unsigned char random_data;
		random_data = ioread8(mem + INTEL_RANDOM_GENERATOR_DATA);
		pr_info("Random Data:%02x\n", random_data);
	}
}

static int mod_init(void)
{
	if (!request_mem_region(INTEL_RANDOM_GENERATOR_ADDR, LENGTH, "myports"))
	{
		pr_info("request_mem_region() failed for myports\n");
		return -1;
	}
	else 
	{
		void __iomem *mem;
		unsigned char hw_status;

		pr_info("request_mem_region() succcess for myports\n");

		mem = ioremap(INTEL_RANDOM_GENERATOR_ADDR, LENGTH);
		pr_info("ioremap returned:%px\n", mem);
		if (!mem)
		{
			pr_err("ioremap failed\n");
			return -1;
		}
		hw_status = hwstatus_get(mem);
		pr_info("Hardware status:%02x\n", hw_status);
		if ((hw_status & INTEL_RANDOM_GENERATOR_PRESENT) == 0)
		{
			pr_warn("Random number generator not present\n");
		}
		else
		{
			pr_warn("Random number generator present\n");
		}
		
		if ((hw_status & INTEL_RANDOM_GENERATOR_ENABLED) == 0)
		{
			pr_warn("Random number generator not enabled\n");
		}
		else
		{
			pr_warn("Random number generator enabled\n");
			read_random_data(mem);
		}

		iounmap(mem);
	}

	return 0;
}

static void mod_exit(void)
{
	release_mem_region(INTEL_RANDOM_GENERATOR_ADDR, LENGTH);
}

module_init(mod_init);
module_exit(mod_exit);

==> ./LinuxCommunicatingWithHardware/33_Ports_Access_As_IO_Memory/Ports_Access_As_IO_Memory.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

MODULE_LICENSE("GPL");

#define MY_BASEPORT 0x061
#define NUMBER_PORTS 1
static u8 __iomem *base_iomem;

static int mod_init(void)
{
	if (!request_region(MY_BASEPORT, NUMBER_PORTS, "myport"))
	{
		pr_info("request region failed for myport\n");
	}
	else
	{
		pr_info("request region success for myport\n");
		base_iomem = ioport_map(MY_BASEPORT, NUMBER_PORTS);
		iowrite8(0x03, base_iomem);
		ssleep(5);
		iowrite8(0x00, base_iomem);
	}

	return 0;
}

static void mod_exit(void)
{
	ioport_unmap(base_iomem);
	release_region(MY_BASEPORT, NUMBER_PORTS);
}

module_init(mod_init);
module_exit(mod_exit);

==> ./LinuxCommunicatingWithHardware/34_implementation_of_devmem/Implementation_of_devmem.c <==
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;
	char ch = 'a';
	void *mem;

	fd = open("/dev/mem", O_RDWR | O_SYNC);

	if (fd < 0)
	{
		perror("open failed\n");
		return -1;
	}

	mem = mmap(NULL, 0xfff, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0x101f1000);
	if (mem == (void*) -1)
	{
		perror("mmap failed\n");
		close(fd);
		return -2;
	}

	*(unsigned char*)mem = ch;

	munmap(mem, 0xfff);
	close(fd);
	return 0;
}

==> ./LinuxCommunicatingWithHardware/35_RTC_On_QEMU_ARM/RTC_On_QEMU_ARM.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <asm/io.h>

#define RTC_BASEADDRESS 0x101e8000
#define LENGTH 0xf 

MODULE_LICENSE("GPL");

static int mod_init(void)
{
	void __iomem *p;
	u32 seconds;

	p = ioremap(RTC_BASEADDRESS, LENGTH);
	pr_info("ioremap returned:%px\n", p);

	//read data register which increments every second
	seconds = ioread32(p);
	pr_info("seconds:%04x\n", seconds);
	ssleep(5);
	seconds = ioread32(p);
	pr_info("seconds:%04x\n", seconds);
	
	return 0;
}

static void mod_exit(void)
{
}

module_init(mod_init);
module_exit(mod_exit);

==> ./LinuxCommunicatingWithHardware/37_smbios_entry_point_table/smbios_entry_point_table.c <==
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/** SMBIOS entry point scan region start address */
#define SMBIOS_ENTRY_START 0xf0000

/** SMBIOS entry point scan region length */
#define SMBIOS_ENTRY_LEN 0x10000

void find_smbios_entry(u_int8_t *mem_mapped)
{
	size_t fp;

	/* Try to find SMBIOS */
	for (fp=0; fp<=0xFFF0; fp+=16)
	{
		if (memcmp(mem_mapped+fp, "_SM_", 4) == 0 && fp<=0xFFE0)
		{
			printf("smbios found at offset:%02lx\n", SMBIOS_ENTRY_START + fp);
		}
	}
}

int main(int argc, char *argv[])
{
	int fd;
	u_int8_t *entry_mem;

	fd = open("/dev/mem", O_RDWR);

	if (fd < 0)
	{
		perror("open failed:\n");
		return -1;
	}

	/* Map the region potentially containing the SMBIOS entry point */
	entry_mem = mmap(NULL, SMBIOS_ENTRY_LEN, PROT_READ, MAP_SHARED, fd, SMBIOS_ENTRY_START);

	if (entry_mem == MAP_FAILED)
	{
		perror("mmap failed\n");
		close(fd);
		return -2;
	}

	/* Scan for the SMBIOS entry point */
	find_smbios_entry(entry_mem);

	/* Unmap the entry point region (no longer required) */
	munmap(entry_mem, SMBIOS_ENTRY_LEN);

	close(fd);
	return 0;
}

==> ./LinuxCommunicatingWithHardware/38_parsing_entry_point_table/Parsing_Entry_Point_Table.c <==
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 *
 * SMBIOS entry point
 *
 * This is the single table which describes the list of SMBIOS
 * structures. It is located by scanning through the BIOS segment
 */
struct smbios_entry 
{
	/** Signature - Must be equal to SMBIOS_SIGNATURE */
	u_int32_t signature;
	/** Checksum */
	u_int8_t checksum;
	/** Length */
	u_int8_t len;
	/** Major version */
	u_int8_t major;
	/** Minor version */
	u_int8_t minor;
	/** Maximum structure size */
	u_int16_t max;
	/** Entry point revision */
	u_int8_t revision;
	/** Formatted area */
	u_int8_t formatted[5];
	/** DMI Signature */
	u_int8_t dmi_signature[5];
	/** DMI checksum */
	u_int8_t dmi_checksum;
	/** Structure table length */
	u_int16_t smbios_len;
	/** Structure table address */
	u_int32_t smbios_address;
	/** Number of SMBIOS structures */
	u_int16_t smbios_count;
	/** BCD revision */
	u_int8_t bcd_revision;
} __attribute__ (( packed ));

/** SMBIOS entry point scan region start address */
#define SMBIOS_ENTRY_START 0xf0000

/** SMBIOS entry point scan region length */
#define SMBIOS_ENTRY_LEN 0x10000

void print_smbios_table(u_int8_t *addr)
{
	struct smbios_entry *entry = (struct smbios_entry*)addr;
	printf("smbios address:%02x\n", entry->smbios_address);
}

void find_smbios_entry(u_int8_t *mem_mapped)
{
	size_t fp;

	/* Try to find SMBIOS */
	for (fp=0; fp<=0xFFF0; fp+=16)
	{
		if(memcmp(mem_mapped+fp, "_SM_", 4)==0 && fp<=0xFFE0)
		{
			printf("smbios found at offset:%02lx\n", SMBIOS_ENTRY_START + fp);
			print_smbios_table(mem_mapped+fp);
		}
	}
}

int main(int argc, char *argv[])
{
	int fd;
	u_int8_t *entry_mem;

	fd = open("/dev/mem", O_RDWR);

	if (fd < 0)
	{
		perror("open failed:\n");
		return -1;
	}

	/* Map the region potentially containing the SMBIOS entry point */
	entry_mem = mmap(NULL, SMBIOS_ENTRY_LEN, PROT_READ, MAP_SHARED, fd, SMBIOS_ENTRY_START);

	if (entry_mem == MAP_FAILED)
	{
		perror("mmap failed\n");
		close(fd);
		return -2;
	}

	/* Scan for the SMBIOS entry point */
	find_smbios_entry(entry_mem);

	/* Unmap the entry point region (no longer required) */
	munmap(entry_mem, SMBIOS_ENTRY_LEN);

	close(fd);
	return 0;
}

==> ./LinuxCommunicatingWithHardware/39_Access_Configuration_Address_Space/Access_Configuration_Address_Space.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define PCI_INDEX_PORT 0xcf8
#define PCI_DATA_PORT 0xcfc

unsigned short read_pci_config_short(unsigned char bus, unsigned char slot, unsigned char func, unsigned char offset)
{
	outl(0x80000000 | (bus<<16) | (slot<<11) | (func<<8) | offset, 0xcf8);
	return inw(0xcfc + (offset&2));
    //If the offset is even (LSB is 0), the operation reads from the register at 0xcfc.
    //If the offset is odd (LSB is 1), the operation reads from the register at 0xcfc + 2.
	//a simple way to switch between reading adjacent 16-bit registers without modifying the original offset value.
}

int __init hello_init(void)
{
	unsigned short vendor_id;
	unsigned short device_id;

	vendor_id = read_pci_config_short(0, 0, 0, 0);
	device_id = read_pci_config_short(0, 0, 0, 2);
	pr_info("Vendor id:%02x\t Device Id:%02x\n", vendor_id, device_id);

	vendor_id = read_pci_config_short(0, 1, 0, 0);
	device_id = read_pci_config_short(0, 1, 0, 2);
	pr_info("Vendor id:%02x\t Device Id:%02x\n", vendor_id, device_id);
	return 0;
}

void __exit hello_exit(void)
{

}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);

==> ./LinuxCommunicatingWithHardware/40_print_full_address_space/print_full_address_space.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/io.h>

#define PCI_INDEX_PORT 0xcf8
#define PCI_DATA_PORT 0xcfc

unsigned char bus_number = 0;
unsigned char slot_number = 1;
unsigned char function_number = 0;

module_param(bus_number, byte, 0);
module_param(slot_number, byte, 0);
module_param(function_number, byte, 0);

unsigned short read_pci_config_short(unsigned char bus, unsigned char slot, unsigned char func, unsigned char offset)
{
	outl(0x8000000 | (bus<<16) | (slot<<11) | (func<<8) | offset, 0xcf8);
	return inw(0xcfc + (offset&2));
}

unsigned char read_pci_config_byte(unsigned char bus, unsigned char slot, unsigned char func, unsigned char offset)
{
	unsigned char v;
	outl(0x80000000 | (bus<<16) | (slot<<11) | (func<<8) | offset, 0xcf8);
	v = inb(0xcfc + (offset&3));
	return v;
}

void print_configuration_space(unsigned char bus, unsigned char slot, unsigned char func)
{
	unsigned char pci_config_space[256];
	unsigned short i;
	
	for (i = 0; i < 256; i++)
		pci_config_space[i] = read_pci_config_byte(bus, slot, func, i);

	print_hex_dump_bytes("", DUMP_PREFIX_NONE, pci_config_space, 256);
}


int __init hello_init(void)
{
	pr_info("Printing Configuration space of :%d:%d:%d\n", bus_number, slot_number, function_number);
	print_configuration_space(bus_number, slot_number, function_number);

	return 0;
}

void __exit hello_exit(void)
{

}

MODULE_LICENSE("GPL");

module_init(hello_init);
module_exit(hello_exit);

==> ./LinuxCommunicatingWithHardware/41_read_device_doesnt_exist/read_device_doesnt_exist.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define PCI_INDEX_PORT 0xcf8
#define PCI_DATA_PORT 0xcfc

unsigned short read_pci_config_short(unsigned char bus, unsigned char slot, unsigned char func, unsigned char offset)
{
	outl(0x8000000 | (bus<<16) | (slot<<11) | (func<<8) | offset, 0xcf8);
	return inw(0xcfc + (offset&2));
}

int __init hello_init(void)
{
	unsigned short vendor_id;
	unsigned short device_id;

	vendor_id = read_pci_config_short(3, 1, 0, 0);
	device_id = read_pci_config_short(3, 1, 0, 2);
	pr_info("Vendor id:%02x\t Device id:%02x\n", vendor_id, device_id);

	return 0;
}	

void __init hello_exit(void)
{

}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);


==> ./LinuxCommunicatingWithHardware/42_Base_Address_Registers/Base_Address_Registers.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define PCI_INDEX_PORT 0xcf8
#define PCI_DATA_PORT 0xcfc

unsigned short read_pci_config_short(unsigned char bus, unsigned char slot, unsigned char func, unsigned char offset)
{
	outl(0x80000000 | (bus<<16) | (slot<<11) | (func<<8) | offset, 0xcf8);
	return inw(0xcfc + (offset&2));
}

unsigned int read_pci_config(unsigned char bus, unsigned char slot, unsigned char func, unsigned char offset)
{
	unsigned int v;
	outl(0x80000000 | (bus<<16) | (slot<<11) | (func<<8) | offset, 0xcf8);
	v = inl(0xcfc);
	return v;
}

int __init hello_init(void)
{
	//00:02.0 VMware SVGA II Adapter
	unsigned int bar_register = read_pci_config(0, 2, 0, 0x10);
	pr_info("bar register:%02x\n", bar_register);

	if (bar_register & 0x01)
		pr_info("I/O mapped I/O\n");
	else 
	{
		pr_info("Memory Mapped I/O\n");
		if (((bar_register >> 1) & 0x03) == 0x00)
			pr_info("32-bit address space\n");
		else
			pr_info("64-bit address space\n");
	}

	return 0;
}

void __exit hello_exit(void)
{

}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);

==> ./LinuxCommunicatingWithHardware/43_Base_Address_of_BAR/Base_Address_of_BAR.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define PCI_INDEX_PORT 0xcf8
#define PCI_DATA_PORT 0xcfc

unsigned short read_pci_config_short(unsigned char bus, unsigned char slot, unsigned char func, unsigned char offset)
{
	outl(0x80000000 | (bus << 16) | (slot << 11) | (func << 8) | offset, 0xcf8);
	return inw(0xcfc + (offset&2));
}

unsigned int read_pci_config(unsigned char bus, unsigned char slot, unsigned char func, unsigned char offset)
{	
	unsigned int v;
	outl(0x80000000 | (bus<<16) | (slot<<11) | (func<<8) | offset, 0xcf8);
	v = inl(0xcfc);
	return v;
}

int __init hello_init(void)
{
	u64 address;
	//00:02.0 VMware SVGA II Adapter
	unsigned int bar_register = read_pci_config(0, 2, 0, 0x10);
	pr_info("bar register:%02x\n", bar_register);

	if (bar_register & 0x01)
	{
		pr_info("I/O Mapped I/O\n");
		address = (bar_register & 0xFFFFFFFC);
	}
	else
	{
		pr_info("Memory Mapped I/O\n");
		if (((bar_register >> 1) & 0x03) == 0x00)
		{
			pr_info("32-bit Address space\n");
			address = (bar_register & 0xFFFFFFF0U);
		}
		else
		{
			unsigned long int bar_registerl = read_pci_config(0, 2, 0, 0x14);
			pr_info("64-bit address space\n");
			pr_info("bar register2:%02lx\n", bar_registerl);
			address = (bar_register & 0xFFFFFFF0U) + ((bar_registerl & 0xFFFFFFFFU) << 32);
		}
	}
	pr_info("BAR Address Register:%02llx\n", address);
	return 0;
}

void __exit hello_exit(void)
{

}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);

==> ./LinuxCommunicatingWithHardware/44_Find_Memory_Used_By_PCI_Device/Find_Memory_Used_BY_PCI_Device.c <==
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/io.h>

#define PCI_INDEX_PORT 0xcf8
#define PCI_DATA_PORT 0xcfc

unsigned short read_pci_config_short(unsigned char bus, unsigned char slot, unsigned char func, unsigned char offset)
{
	outl(0x80000000 | (bus<<16) | (slot<<11) | (func<<8) | offset, 0xcf8);
	return inw(0xcfc +(offset & 2));
}

unsigned int read_pci_config(unsigned char bus, unsigned char slot, unsigned char func, unsigned char offset)
{
	unsigned int v;
	outl(0x80000000 | (bus<<16) | (slot<<11) | (func<<8) | offset, 0xcf8);
	v = inl(0xcfc);
	return v;
}

void write_pci_config(unsigned char bus, unsigned char slot, unsigned char func, unsigned char offset, unsigned int val)
{
	outl(0x80000000 | (bus<<16) | (slot<<11) | (func<<8) | offset, 0xcf8);
	outl(val, 0xcfc);
}

int __init hello_init(void)
{
	u64 address;
	//02:01.0 Ethernet controller
	unsigned int bar_register = read_pci_config(2, 1, 0, 0x10);
	pr_info("bar register:%02x\n", bar_register);

	if (bar_register & 0x01)
	{
		pr_info("I/O Mapped I/O\n");
		address = (bar_register&0xfffffffc);
	}
	else
	{
		pr_info("Memory Mapped I/O\n");
		if (((bar_register >> 1) & 0x03) == 0x00)
		{		
			pr_info("32-BIT Address space\n");
			address = (bar_register & 0xFFFFFFF0U);
		}
		else
		{
			// To get the size of the device. 
			// 1. you must save the original value of the BAR
			// 2. write a value of all 1's to the register
			// 3. then read it back
			// 4. restore the original value
			// The amount of memory can then be determined by masking the information bits, 
			// performing a bitwise NOT ('~' in C) and incrementing the value by 1
			unsigned long int bar_register1 = read_pci_config(2, 1, 0, 0x14);
			unsigned int size, size_bar_register1, size_bar_register2;

			pr_info("64-bit address space\n");
			pr_info("bar register2:%02lx\n", bar_register1);
			address = (bar_register & 0xFFFFFFF0U) + ((bar_register1 & 0xFFFFFFFFU) << 32);

			//write all ones
			write_pci_config(0, 8, 0, 0x10, 0xffffffff);
			write_pci_config(0, 8, 0, 0x14, 0xffffffff);

			//read it
			size_bar_register1 = read_pci_config(0, 8, 0, 0x10);
			size_bar_register2 = read_pci_config(0, 8, 0, 0x14);

			//restore the original value
			write_pci_config(0, 8, 0, 0x10, bar_register);
			write_pci_config(0, 8, 0, 0x14, bar_register1);

			pr_info("size bar_register1:%02x\n", size_bar_register1);
			pr_info("size bar_register2:%02x\n", size_bar_register2);

			//Masking
			pr_info("size_bar_register1:%02x\n", ~size_bar_register1);
			pr_info("size_bar_register2:%02x\n", ~size_bar_register2);

			//clear the lowest 4 bits (prefetchable, address size, types)
			size_bar_register1 &= ~15;
			pr_info("size_bar_register1:%02x\n", ~size_bar_register1);
			size = ~size_bar_register1 + 1;
			pr_info("size:%02x\n", size);
		}
	}

	pr_info("Base Address Register:%02llx\n", address);
	return 0;
}

void __exit hello_exit(void)
{

}

MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);

