#include "gpio_raspberry_pi3.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);

/****************************************************************************/
/* Module init / cleanup block.                                             */
/****************************************************************************/
int gpio_init(void) {
	int ret = 0;

	printk(KERN_NOTICE "Hello !\n");

	/* Allocate GPIO 17 before use */
	if(gpio_request_one(GPIO_RPI3(17), GPIOF_DIR_OUT | GPIOF_INIT_HIGH |
		GPIOF_EXPORT_DIR_CHANGEABLE, GPIO_DESC)) {
		printk("GPIO request faiure: %s\n", GPIO_DESC);
		return -ENODEV;
	}

	/* Get GPIO 17 value */
	ret = gpio_get_value(GPIO_RPI3(17));
	printk(KERN_NOTICE "gpio_get_value = %d\n", ret);

	return 0;
}

void gpio_cleanup(void) {
	printk(KERN_NOTICE "Goodbye\n");

	/* Free GPIO 17 */
	gpio_free(GPIO_RPI3(17));

	return;
}

module_init(gpio_init);
module_exit(gpio_cleanup);

