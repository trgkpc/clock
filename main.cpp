#define F_CPU 1000000
#include "avr_lib/led.hpp"
#include "avr_lib/switch.hpp"
#include "avr_lib/callback.hpp"
#include <avr/io.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// Transistor
auto T0 = LED_D5();
auto T1 = LED_D6();
auto T2 = LED_D7();
auto T3 = LED_D2();
auto T4 = LED_D3();

// LED
auto LED0 = LED_D0();
auto LED1 = LED_C0();
auto LED2 = LED_C1();
auto LED3 = LED_C2();
auto LED4 = LED_C3();
auto LED5 = LED_C4();
auto LED6 = LED_C5();

// Swtich
auto S0 = SWITCH_B1();
auto S1 = SWITCH_B5();
auto S2 = SWITCH_B3();
auto S3 = SWITCH_B4();

int main(void)
{
    Callback::init();
    T0.on();
    T1.on();
    T2.on();

    while(1){
    }
}

void Callback::SensorCallback()
{
    S0.update();
    S1.update();
    S2.update();
    S3.update();
}

void Callback::MainCallback()
{
    if(S0()){
        LED0.on();
    }else{
        LED0.off();
    }
}
