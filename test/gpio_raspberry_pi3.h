#if !defined(__gpio_raspberry_pi3_h)
#define __gpio_raspberry_pi3_h

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
 
#include <linux/interrupt.h>
#include <linux/gpio.h>
 
 
#define DRIVER_AUTHOR "Kirill B."
#define DRIVER_DESC   "Blink test"
 
// we want GPIO_17 (pin 11 on P5 pinout raspberry pi rev. 2 board)
// to generate interrupt
#define GPIO_RPI3(x)		(x)
 
// text below will be seen in 'cat /proc/interrupt' command
#define GPIO_ANY_GPIO_DESC           "Some gpio pin description"
 
// below is optional, used in more complex code, in our case, this could be
// NULL
#define GPIO_ANY_GPIO_DEVICE_DESC    "some_device"

#endif /* __gpio_raspberry_pi3_h */
