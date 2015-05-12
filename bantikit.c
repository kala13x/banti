/*----------------------------------------------------
Name:   bantikit.c
Date:   2015.05.12
Auth:   Sun Dro (a.k.a. 7th Ghost / kala13x)
Desc:   Kernel Based RootKit Module
----------------------------------------------------*/


#include "stdinc.h"


/*---------------------------------------------
| Initialise rootkit module
---------------------------------------------*/
static int __init banti_kit_init(void)
{
    printk(KERN_INFO "Starting banti module!\n");
    return 0;
}


/*---------------------------------------------
| Clean rootkit module
---------------------------------------------*/
static void __exit banti_kit_clean(void)
{
	printk(KERN_INFO "Cleaning up banti module.\n");
}


/*---------------------------------------------
| Module initialisations
---------------------------------------------*/
module_init(banti_kit_init);
module_exit(banti_kit_clean);
MODULE_LICENSE(DRIVER_LICENSE);