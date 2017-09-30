/* *File : header.h
 * *Author : Vishal Chopra
 * *Date : 9 jan 2017
 * *Brief : This file include all the header file used by USB driver4
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/usb.h>

#ifndef DEBUG

#define DEBUG
#define DEBUG_INFO KERN_INFO
#define DEBUG_ERR  KERN_ERR
#define DEBUG_WARN KERN_WARNING
#define driver_info(format, arg...)	do{DEBUG_INFO printk(format, ##arg);} while(0)
#define driver_err(format, arg...)	do{DEBUG_ERR printk(format, ##arg);} while(0)
#define driver_warn(format, arg...)	do{DEBUG_WARNING printk(format, ##arg);} while(0)

#endif

#define USB_VENDOR_ID 0x14cd
#define USB_PRODUCT_ID  0x121f

MODULE_LICENSE("Dual BSD/GPL");
//MODULE_LICENSE("BSD");
MODULE_AUTHOR("Vish Chopra");
MODULE_DESCRIPTION("USB driver");
