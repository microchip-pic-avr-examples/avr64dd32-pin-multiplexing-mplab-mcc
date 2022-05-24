 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
� [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "charlieplexing.h"
#include <util/delay.h>

#define LED_GAME_DELAY 100

static void LED_demo(void);

/*
    Main application
*/
       
int main(void)
{
    SYSTEM_Initialize();
    
    CharlieInit();
    TCB0_CaptureCallbackRegister(CharlieHandler);

    while (1)
    {
        LED_demo();
    }
}

static void LED_demo(void)
{
    bool led_game[LEDS_NUMBER] = {false, false, false, false, false, false};
    
    for(uint8_t index = 0; index < LEDS_NUMBER; index++)
    {
        CharlieAll(led_game);
        _delay_ms(LED_GAME_DELAY);
        led_game[index] = true;
    }
        
    for(uint8_t index = 0; index < LEDS_NUMBER; index++)
    {
        CharlieAll(led_game);
        _delay_ms(LED_GAME_DELAY);
        led_game[LEDS_NUMBER - index - 1] = false;
    }  
}