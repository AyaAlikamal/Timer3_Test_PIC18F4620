/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"


volatile uint_32 timer3_flag = 0;
volatile uint_32 counter3_flag = 0;

void Timer3_Defualt_Interrupt_Hundeller(void);
timer3_config_t counter3_object;

led_t led1={
.Port_Name = PORTD_INDEX,
.pin = PIN0,
.led_statues = LED_OFF
};

void timer3_timer_init(){
timer3_config_t timer3_object;
timer3_object.TMR3_Interrupt_Hundeler = Timer3_Defualt_Interrupt_Hundeller;
timer3_object.Timer_priority = Interrupt_Periority_LOW,
timer3_object.timer3_mode = TIMER3_TIMER_MODE ;
timer3_object.timer3_prescaller = TIMER3_PRESCALLER_DIV_BY_8;
timer3_object.timer3_register_wr_mode = TIMER3_RW_REG_16BIT_MODE ;
Timer3_Init(&timer3_object);

}
void timer3_counter_init(){
counter3_object.TMR3_Interrupt_Hundeler = NULL;
counter3_object.timer3_mode = TIMER3_COUNTER_MODE_ENABLE();
counter3_object.timer3_prescaller = TIMER3_PRESCALLER_DIV_BY_1;
counter3_object.timer3_preload_value =0 ;
counter3_object.timer3_register_wr_mode = TIMER3_RW_REG_16BIT_MODE ;
counter3_object.timer3_counter_mode =  TIMER3_SYNC_COUNTER_MODE;
Timer3_Init(&counter3_object);
}


int main() {
   
Std_ReturnType ret = E_NOT_OK;
//application_initialize();
//ret = Timer2_Init(&timer2_obj);
timer3_counter_init();
timer3_timer_init();
//ret = led_initialize(&led1);
while(1){
    ret = Timer3_Read_Value(&counter3_object, &counter3_flag);
}
 return (EXIT_SUCCESS);
}
void application_initialize(void){
   Std_ReturnType ret = E_NOT_OK;

}
void Timer3_Defualt_Interrupt_Hundeller(void){
++timer3_flag;
//led_toggle(&led1);
}
