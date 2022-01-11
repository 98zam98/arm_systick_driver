/******************************************************************************
 * Module: SYSTICK
 * File Name: Hardware_arm_systick_driver.h
 * Version: 1
 * Date: 8/1/2022
 * Description: registers or connection with their macros and data types
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/
#ifndef __HARDWARE_ARM_SYSTICK_DRIVER_H__
#define __HARDWARE_ARM_SYSTICK_DRIVER_H__

/* SYSTICK*/

#define SYSTICK_BASE 0xE000E010

/* STK_CTRL start */
#define STK_CTRL_OFFSET 0x00
#define STK_CTRL_BASE (SYSTICK_BASE + STK_CTRL_OFFSET)
#define STK_CTRL_REG (*(volatile u32 *)STK_CTRL_BASE)
/*
Privileged
The SysTick CTRL register enables the SysTick features

Bits 31:17 Reserved, must be kept cleared.


Bit 16 COUNTFLAG:
Returns 1 if timer counted to 0 since last time this was read.

*/
#define COUNTFLAG_STK_CTRL 16
/*

Bits 15:3 Reserved, must be kept cleared.


Bit 2 CLKSOURCE: Clock source selection
Selects the clock source.
0: AHB/8
1: Processor clock (AHB)


*/
#define CLKSOURCE_STK_CTRL 2
/*

Bit 1 TICKINT: SysTick exception request enable
0: Counting down to zero does not assert the SysTick exception request
1: Counting down to zero to asserts the SysTick exception request.
Note: Software can use COUNTFLAG to determine if SysTick has ever counted to zero.


// */
#define TICKINT_STK_CTRL 1
/*

Bit 0 ENABLE: Counter enable
Enables the counter. When ENABLE is set to 1, the counter loads the RELOAD value from the
LOAD register and then counts down. On reaching 0, it sets the COUNTFLAG to 1 and
optionally asserts the SysTick depending on the value of TICKINT. It then loads the RELOAD
value again, and begins counting.
0: Counter disabled
1: Counter enabled
*/
#define ENABLE_STK_CTRL 0
/* STK_CTRL end */
//--------------------------------------

/* STK_LOAD start */
#define STK_LOAD_OFFSET 0x04
#define STK_LOAD_BASE (SYSTICK_BASE + STK_LOAD_OFFSET)
#define STK_LOAD_REG (*(volatile u32 *)STK_LOAD_BASE)


/* STK_LOAD end */
//--------------------------------------

/* STK_VAL start */
#define STK_VAL_OFFSET 0x08
#define STK_VAL_BASE (SYSTICK_BASE + STK_VAL_OFFSET)
#define STK_VAL_REG (*(volatile u32 *)STK_VAL_BASE)
/* STK_VAL end */
//--------------------------------------

/* STK_CALIB start */
#define STK_CALIB_OFFSET 0x0C
#define STK_CALIB_BASE (SYSTICK_BASE + STK_CALIB_OFFSET)
#define STK_CALIB_REG (*(volatile u32 *)STK_CALIB_BASE)
/* STK_CALIB end */
//--------------------------------------

//--------------------------------------

#endif /* __HARDWARE_ARM_SYSTICK_DRIVER_H__ */