/******************************************************************************
 * Module: SYSTICK
 * File Name: Private_arm_systick_driver.h
 * Version: 1
 * Date: 8/1/2022
 * Description: function prototypes and variables and macro functions that should not get called by user 
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/

#ifndef __PRIVATE_ARM_SYSTICK_DRIVER_H__
#define __PRIVATE_ARM_SYSTICK_DRIVER_H__

/* function prototypes*/

//--------------------------------------	


/* variables */

#define LIMIT_STK_LOAD 0x00FFFFFF

//--------------------------------------	


/* macro function*/
#define MACRO_READ_COUNTFLAG_STK_CTRL() GETBIT(STK_CTRL_REG,COUNTFLAG_STK_CTRL)

#define MACRO_CONFIG_PROCESSOR_CLK_CLKSOURCE_STK_CTRL() SETBIT(STK_CTRL_REG,CLKSOURCE_STK_CTRL)
#define MACRO_CONFIG_DIV8_CLKSOURCE_STK_CTRL() CLEARBIT(STK_CTRL_REG,CLKSOURCE_STK_CTRL)

#define MACRO_CALCULATE_VALUE_STK_LOAD(X) LIMIT_STK_LOAD&X
#define MACRO_LOAD_REG_STK_LOAD(X) STK_LOAD_REG=MACRO_CALCULATE_VALUE_STK_LOAD(X)
#define MACRO_VALUE_REG_STK_VAL(X) STK_VAL_REG=MACRO_CALCULATE_VALUE_STK_LOAD(X)

//--------------------------------------	


#endif /* __PRIVATE_ARM_SYSTICK_DRIVER_H__ */