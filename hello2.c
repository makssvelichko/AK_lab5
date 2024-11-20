#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

MODULE_AUTHOR("Velichko Maksim <maksimvelichko16@gmail.com>");
MODULE_DESCRIPTION("Hello, world - Part 2");
MODULE_LICENSE("Dual BSD/GPL");

static uint hello_count = 1;
module_param(hello_count, uint, 0444);
MODULE_PARM_DESC(hello_count, "The number of times to print 'Hello, world!'");

extern void print_hello(void);

static int __init hello2_init(void)
{
	int i;

	if (hello_count == 0 || (hello_count >= 5 && hello_count <= 10)) {
		pr_warn("Warning: hello_count is %u\n", hello_count);
	} else if (hello_count > 10) {
		pr_err("Error: hello_count is greater than 10\n");
		return -EINVAL;
	}

	for (i = 0; i < hello_count; i++) {
		print_hello();
	}
	return 0;
}

static void __exit hello2_exit(void)
{
	pr_info("Goodbye from hello2 module\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
