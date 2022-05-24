/**
 * \file single_pin_multiplexing.c
 *
 * \brief Drive an LED and a button with one GPIO pin low level functionalities file.
 *
 (c) 2021 Microchip Technology Inc. and its subsidiaries.
    Subject to your compliance with these terms, you may use this software and
    any derivatives exclusively with Microchip products. It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

#include "single_pin_multiplexing.h"
#include "single_pin_multiplexing_config.h"

#define PIN_COUNT               (sizeof(multiplexed_pins) / sizeof(pin_t))

static input_output_pin_t input_output_pins[PIN_COUNT];

void single_pins_init(void)
{
    for(uint8_t i = 0; i < PIN_COUNT; i++)
    {
        input_output_pins[i].current_state = 0;
        input_output_pins[i].state = 0;
        input_output_pins[i].debounce_count = 0;
    }
}

void multiplexed_pin_input_handler(void)
{
    /* Set the pins as input */
    for(uint8_t pin = 0; pin < PIN_COUNT; pin++)
    {
        multiplexed_pins[pin].port->DIRCLR = multiplexed_pins[pin].mask;
    }
    
    _delay_us(PIN_STATE_DELAY);
      
    for(uint8_t pin = 0; pin < PIN_COUNT; pin++)
    {
        /* Read the pins current state */ 
        input_output_pins[pin].current_state = (multiplexed_pins[pin].port->IN & multiplexed_pins[pin].mask);
        /* Debounce mechanism */
        if(input_output_pins[pin].current_state == input_output_pins[pin].state)
        {
            input_output_pins[pin].debounce_count = 0;
        }
        else
        {
            input_output_pins[pin].debounce_count++;
        }   
        /* Set the pin state if the pin is debounced */
        if(input_output_pins[pin].debounce_count == DEBOUNCE_THRESHOLD)
        {
            input_output_pins[pin].state = input_output_pins[pin].current_state;
        }
    }
    /* Set the pins back as output */
    for(uint8_t pin = 0; pin < PIN_COUNT; pin++)
    {
        multiplexed_pins[pin].port->DIRSET = multiplexed_pins[pin].mask;
    }
}

input_output_ret_t pin_out_register(uint8_t index, uint8_t reg)
{
    if(index < PIN_COUNT)
    {   
        switch(reg) {
            case 0:
                multiplexed_pins[index].port->OUTCLR = multiplexed_pins[index].mask;
                break;
            case 1:
                multiplexed_pins[index].port->OUTSET = multiplexed_pins[index].mask;
                break;
            case 2:
                multiplexed_pins[index].port->OUTTGL = multiplexed_pins[index].mask;
                break;
            default:
                return FAIL;
        }
        return SUCCESS;
    }
    return PIN_INDEX_OUT_OF_RANGE;
}


input_output_ret_t multiplexed_pin_set_low(uint8_t index)
{
    return pin_out_register(index, 0);
}

input_output_ret_t multiplexed_pin_set_high(uint8_t index)
{
    return pin_out_register(index, 1);
}

input_output_ret_t multiplexed_pin_toggle(uint8_t index)
{
    return pin_out_register(index, 2);
}

input_output_ret_t multiplexed_pin_read(uint8_t index, uint8_t *out)
{
    if(index < PIN_COUNT)
    {  
     *out = input_output_pins[index].state;
     return SUCCESS;
    } 
    
    return PIN_INDEX_OUT_OF_RANGE;
}