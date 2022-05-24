/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

#ifndef SINGLE_PIN_MULTIPLEXING_H
#define	SINGLE_PIN_MULTIPLEXING_H

#include "mcc_generated_files/system/system.h"
#include <stdio.h>
#include <stdint.h>
#include <util/delay.h>

#define DEBOUNCE_THRESHOLD      10
#define PIN_STATE_DELAY         10

/*--------- DATA TYPES ---------*/
typedef struct {
    PORT_t *port;
    uint8_t mask;
} pin_t;

typedef struct {
    uint8_t current_state;
    uint8_t state;
    uint8_t debounce_count;
} input_output_pin_t;

typedef enum {
    SUCCESS,
    PIN_INDEX_OUT_OF_RANGE,
    FAIL
} input_output_ret_t;

/*--------- FUNCTION PROTOTYPES ---------*/
void single_pins_init(void);
void multiplexed_pin_input_handler(void);
input_output_ret_t multiplexed_pin_set_low(uint8_t index);
input_output_ret_t multiplexed_pin_set_high(uint8_t index);
input_output_ret_t multiplexed_pin_toggle(uint8_t index);
input_output_ret_t multiplexed_pin_read(uint8_t index, uint8_t *out);

#endif	/* SINGLE_PIN_MULTIPLEXING_H */