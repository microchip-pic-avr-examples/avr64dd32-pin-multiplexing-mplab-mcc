/**
 * \file charliepexing.c
 *
 * \brief Charlie Multiplexing low level functionalities file.
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

#include "charlieplexing.h"
#include "charlieplexing_config.h"

static bool   leds_data[LEDS_NUMBER];

void CharlieInit(void)
{
    uint8_t i;
    for(i = 0; i < LEDS_NUMBER; i++)
    {
        leds_data[i] = false;
    }
}

void CharlieOn(uint8_t id)
{
    if(id < LEDS_NUMBER)
    {
        leds_data[id] = true;
    }
}

void CharlieOff(uint8_t id)
{
    if(id < LEDS_NUMBER)
    {
        leds_data[id] = false;
    }
}

void CharlieToggle(uint8_t id)
{
    if(id < LEDS_NUMBER)
    {
        leds_data[id] = !leds_data[id];
    }
}

void CharlieHandler(void)
{
    static uint8_t id = 0;
    uint8_t pin, anode, cathode;
    anode = charlie_data[id].anode;
    cathode = charlie_data[id].cathode;
    for(pin = 0; pin < PINS_NUMBER; pin++)
    {
        if(leds_data[id] == true)
        {
            if(pin == anode)
            {
                pins_data[pin].port->DIRSET = pins_data[pin].mask;
                pins_data[pin].port->OUTSET = pins_data[pin].mask;
            }
            else if(pin == cathode)
            {
                pins_data[pin].port->DIRSET = pins_data[pin].mask;
                pins_data[pin].port->OUTCLR = pins_data[pin].mask;
            }
            else
            {
                pins_data[pin].port->DIRCLR = pins_data[pin].mask;
            }
        }
        else
        {
            pins_data[pin].port->DIRSET = pins_data[pin].mask;
            pins_data[pin].port->OUTCLR = pins_data[pin].mask;
        }
    }
    id++; 
    if(id == LEDS_NUMBER) 
    {
        id = 0;
    }
}

void CharlieAll(bool *pData)
{
    uint8_t i;
    if(pData != NULL)
    {
        for(i = 0; i < LEDS_NUMBER; i++)
        {
            leds_data[i] = pData[i];
        }
    }
}