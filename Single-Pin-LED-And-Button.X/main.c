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
© [2022] Microchip Technology Inc. and its subsidiaries.

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
#include "single_pin_multiplexing.h"

void multiplexed_pin_output_handler(void);

/*
    Main application
*/

int main(void)
{
    uint8_t pin_value;
    
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();
    single_pins_init();
    
    /* Setting the TCA0 and TCB0 interrupt callbacks */
    TCA0_OverflowCallbackRegister(multiplexed_pin_output_handler);
    TCB0_CaptureCallbackRegister(multiplexed_pin_input_handler);


        while (1)
    {
        /* Reading the button connected to the common GPIO pin*/
        input_output_ret_t ret = multiplexed_pin_read(0, &pin_value);
        
        /* Handling the events triggered by the button */
        if(SUCCESS == ret)
        {
            if(pin_value)
            {
                LED_SetLow();
            }
            else
            {
                LED_SetHigh();
            }  
        }
    }
}

/* Handler for the common GPIO pin */
void multiplexed_pin_output_handler(void)
{
    multiplexed_pin_toggle(0);
}