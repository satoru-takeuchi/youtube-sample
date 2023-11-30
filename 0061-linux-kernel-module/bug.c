#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/bug.h>

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Satoru Takeuchi <satoru.takeuchi@gmail.com>");
MODULE_DESCRIPTION("Hello world kernel module");

static int mymodule_init(void) {
	int* i = NULL;
	*i = 1;
        return 0;
}

static void mymodule_exit(void) {
        /* Do nothing */
}

module_init(mymodule_init);
module_exit(mymodule_exit);
