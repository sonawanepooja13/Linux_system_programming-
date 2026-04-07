#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

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



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x3c98aa3c, "__register_chrdev" },
	{ 0xfb3de43c, "class_create" },
	{ 0x773c4019, "device_create" },
	{ 0x52b15b3b, "__unregister_chrdev" },
	{ 0x7c77f2d5, "class_destroy" },
	{ 0x89258034, "device_destroy" },
	{ 0x092a35a2, "_copy_to_user" },
	{ 0xf64ac983, "__copy_overflow" },
	{ 0xd272d446, "__fentry__" },
	{ 0xe8213e80, "_printk" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xa61fd7aa, "__check_object_size" },
	{ 0x092a35a2, "_copy_from_user" },
	{ 0x90a48d82, "__ubsan_handle_out_of_bounds" },
	{ 0xab006604, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x3c98aa3c,
	0xfb3de43c,
	0x773c4019,
	0x52b15b3b,
	0x7c77f2d5,
	0x89258034,
	0x092a35a2,
	0xf64ac983,
	0xd272d446,
	0xe8213e80,
	0xd272d446,
	0xa61fd7aa,
	0x092a35a2,
	0x90a48d82,
	0xab006604,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"__register_chrdev\0"
	"class_create\0"
	"device_create\0"
	"__unregister_chrdev\0"
	"class_destroy\0"
	"device_destroy\0"
	"_copy_to_user\0"
	"__copy_overflow\0"
	"__fentry__\0"
	"_printk\0"
	"__x86_return_thunk\0"
	"__check_object_size\0"
	"_copy_from_user\0"
	"__ubsan_handle_out_of_bounds\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B7E7B5F4E1CA07922250A18");
