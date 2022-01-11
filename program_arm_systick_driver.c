/******************************************************************************
 * Module: SYSTICK
 * File Name: Program_arm_systick_driver.c
 * Version: 1
 * Date: 8/1/2022
 * Description: function prototypes and variables and macro functions that can be called by user 
 * Author: Zyad Ahmed Mackawy (ZAM)
 *******************************************************************************/

/* Private */

//--------------------------------------	


/* Interface*/

// 0x00FFFFFF
// FFFFFF = 16,777,215
void void_init_sysTick()
{
    MACRO_DISABLE_STK_CTRL();
    MACRO_LOAD_REG_STK_LOAD(0x00FFFFFF);
    MACRO_VALUE_REG_STK_VAL(0);
    #if USER_CONFIG_CLKSOURCE_STK_CTRL
    MACRO_CONFIG_PROCESSOR_CLK_CLKSOURCE_STK_CTRL();
    #else
    MACRO_CONFIG_DIV8_CLKSOURCE_STK_CTRL();
    #endif
    MACRO_ENABLE_STK_CTRL();
}


void void_delay_us_sysTick(u32 u32_copy_time)
{
    MACRO_LOAD_REG_STK_LOAD(u32_copy_time-1);
    MACRO_VALUE_REG_STK_VAL(0);
    MACRO_ENABLE_STK_CTRL();
    //while (MACRO_READ_COUNTFLAG_STK_CTRL()==0);
    while ((STK_CTRL_REG&0x00010000)==0);

}


void void_set_interval_sysTick(u32 u32_copy_time,void (*func_to_do)(void))
{
    //void_init_sysTick();
    MACRO_LOAD_REG_STK_LOAD(u32_copy_time-1);
    MACRO_VALUE_REG_STK_VAL(0);
    MACRO_ENABLE_EXCEPTION_TICKINT_STK_CTRL();
    MACRO_ENABLE_STK_CTRL();

    void_callback_sysTick = func_to_do;
}
//--------------------------------------	

