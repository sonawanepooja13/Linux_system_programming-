#include<linux/module.h>  // used  author,license etc 
#include<linux/init.h>  //__int exit 
#include<linux/kernel.h> //prink and kern_info 


static int __init marvellous_init(void)
{
     printk(KERN_INFO "Marvellous Module get inserted :  Gay Ganesh...\n"); 
     return 0; 
     
}
static void __exit marvellous_exit(void)
{
     printk(KERN_INFO "Marvellous Module gets Removed\n"); 
}
module_init(marvellous_init);

module_exit(marvellous_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Marvellous Infosystems"); 
MODULE_DESCRIPTION("Demo Kernel Module"); 
