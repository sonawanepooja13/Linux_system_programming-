#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

MODULE_LICENSE("GPL"); 
static int __init Marvellous_Init(void)
{
     printk(KERN_INFO"Marvellous module loaded :Jay Ganesh\n"); 
     return 0; 

}
static void __exit Marvellous_Cleanup(void)
{
    printk(KERN_INFO "Marvellous module unloaded : Gay Ganesh\n"); 

} 
module_init(Marvellous_Init);
module_exit(Marvellous_Cleanup); 
