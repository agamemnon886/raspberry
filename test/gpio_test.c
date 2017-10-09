#include "gpio_raspberry_pi3.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);

dev_t devno;

struct cdev gpio_cdev;

int gpio_open(struct inode *inode, struct file *filp)
{
	printk("%s, line %d\n", __FUNCTION__, __LINE__);
	return 0;
}

ssize_t gpio_read(struct file *filp, char __user *user, size_t size, loff_t *offset) {
	printk("%s, line %d\n", __FUNCTION__, __LINE__);
	return 0;
}

ssize_t gpio_write(struct file *filp, const char __user *user, size_t size, loff_t *offset) {
	printk("%s, line %d\n", __FUNCTION__, __LINE__);
	return 0;
}

int gpio_close(struct inode *inode, struct file *filp) {
	printk("%s, line %d\n", __FUNCTION__, __LINE__);
	return 0;
}

static const struct file_operations fops = {
	.open = gpio_open,
	.owner = THIS_MODULE,
	.read = gpio_read,
	.write = gpio_write,
	.release = gpio_close,
};

/****************************************************************************/
/* Module init / cleanup block.                                             */
/****************************************************************************/
int gpio_init(void) {
	int ret = 0;

	printk(KERN_NOTICE "Hello !\n");

	if (alloc_chrdev_region(&devno, 0, 1, "gpio_test_led")) {
		printk("Can't allocate char device region\n");
		return -ENODEV;
	}

	cdev_init(&gpio_cdev, &fops);
	gpio_cdev.owner = THIS_MODULE;

	ret = cdev_add(&gpio_cdev, devno, 1);
	if (ret) {
		printk(KERN_NOTICE "Failed to add device\n");
		return -ENODEV;
	}

	/* Allocate GPIO 3 before use */
	if(gpio_request_one(GPIO_RPI3(3), GPIOF_DIR_OUT | GPIOF_INIT_LOW |
		GPIOF_EXPORT_DIR_CHANGEABLE, GPIO_DESC)) {
		printk("GPIO request faiure: %s\n", GPIO_DESC);
		return -ENODEV;
	}

	/* Get GPIO 3 value */
	ret = gpio_get_value(GPIO_RPI3(3));
	printk(KERN_NOTICE "gpio_get_value = %d\n", ret);


	

	return 0;
}

void gpio_cleanup(void) {
	printk(KERN_NOTICE "Goodbye\n");

	/* Free GPIO 3 */
	gpio_free(GPIO_RPI3(3));

	cdev_del(&gpio_cdev);

	unregister_chrdev_region(devno, 1);

	return;
}

module_init(gpio_init);
module_exit(gpio_cleanup);

