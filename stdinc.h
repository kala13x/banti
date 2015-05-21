/*
 *  stdinc.h
 *  Copyright (C) 2015.05.12  Sun Dro (a.k.a. kala13x)
 *
 *  Standart includes and definations for banti project
 */

/* Linux includes */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/keyboard.h>
#include <linux/semaphore.h>
#include <linux/proc_fs.h>
#include <linux/kobject.h>
#include <linux/unistd.h>
#include <linux/syscalls.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/cred.h>
#include <linux/fs.h>

/* Driver info */
#define DRIVER_LICENSE "GPL"
#define DRIVER_VERSION "0.1.3"
#define DRIVER_BUILD 22