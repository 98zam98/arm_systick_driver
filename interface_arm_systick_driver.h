/******************************************************************************
 * Module: SYSTICK
 * File Name: Interface_arm_systick_driver.h
 * Version: 1
 * Date: 8/1/2022
 * Description: function prototypes and variables and macro functions that can be called by user 
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/

#ifndef __INTERFACE_ARM_SYSTICK_DRIVER_H__
#define __INTERFACE_ARM_SYSTICK_DRIVER_H__

/* function prototypes*/

void void_init_sysTick();
void void_delay_us_sysTick(u32 u32_copy_time);
void void_set_interval_sysTick(u32 u32_copy_time,void (*func_to_do)(void));
//--------------------------------------	


/* variables */

enum U1_VALUE_USER_CONFIG_CLKSOURCE_STK_CTRL
{
    DIV8_U1_VALUE_USER_CONFIG_CLKSOURCE_STK_CTRL,
    PROCESSOR_U1_VALUE_USER_CONFIG_CLKSOURCE_STK_CTRL
};


void ( * void_callback_sysTick ) ( void );


//--------------------------------------	


/* macro function*/

#define MACRO_ENABLE_STK_CTRL() SETBIT(STK_CTRL_REG,ENABLE_STK_CTRL)
#define MACRO_DISABLE_STK_CTRL() CLEARBIT(STK_CTRL_REG,ENABLE_STK_CTRL)
#define MACRO_ENABLE_EXCEPTION_TICKINT_STK_CTRL() SETBIT(STK_CTRL_REG,TICKINT_STK_CTRL)
//--------------------------------------	


#endif /* __INTERFACE_ARM_SYSTICK_DRIVER_H__ */