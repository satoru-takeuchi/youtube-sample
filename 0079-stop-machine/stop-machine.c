#include <linux/module.h>
#include <linux/stop_machine.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Satoru Takeuchi <satoru.takeuchi@gmail.com>");
MODULE_DESCRIPTION("stop machine temporarily");

#define STOP_MSECS 10000

static int stop_func(void *arg) {
	mdelay(STOP_MSECS);
	return 0;
}

static int mymodule_init(void) {
	int ret = 0;
	ret = stop_machine(stop_func, NULL, NULL);
        return ret;
}

static void mymodule_exit(void) {
        /* Do nothing */
}

module_init(mymodule_init);
module_exit(mymodule_exit);
