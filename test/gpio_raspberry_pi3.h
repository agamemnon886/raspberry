#if !defined(__gpio_raspberry_pi3_h)
#define __gpio_raspberry_pi3_h

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/cdev.h>
#include <linux/fs.h>

#define DRIVER_AUTHOR "Kirill B."
#define DRIVER_DESC   "Blink test"

/* GPIO number */
#define GPIO_RPI3(x)		(x)

/* GPIO text */
#define GPIO_DESC	"Some gpio pin description"

#define MY_MAJOR  200
#define MY_MINOR  0
#define DEV_COUNT 1

#endif /* __gpio_raspberry_pi3_h */

