/**
 * TCB0 Generated Driver API Header File
 *
 * @file tcb0.h
 *
 * defgroup tcb0 TCB0
 *
 * @brief This header file provides APIs for the TCB0 driver.
 *
 * @version TCB0 Driver Version 1.1.2
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

#ifndef TCB0_H_INCLUDED
#define TCB0_H_INCLUDED

#include <stdint.h>
#include "../system/utils/compiler.h"
#include "./timer_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const struct TMR_INTERFACE TCB0_Interface;

/**
 * @ingroup tcb0
 * @typedef void *TCB0_cb_t
 * @brief Function pointer to callback function called by TCB. NULL=default value: No callback function is to be used.
 */
typedef void (*TCB0_cb_t)(void);
/**
 * @ingroup tcb0
 * @brief Register a callback function to be called for check the overflow 
 * @param TCB0_cb_t cb - call back value for capture
 * @return none
 */
void TCB0_CaptureCallbackRegister(TCB0_cb_t cb);
/**
 * @ingroup tcb0
 * @brief Initialize tcb interface 
 * @param none
 * @return none
 */
void TCB0_Initialize(void);
/**
 * @ingroup tcb0
 * @brief start tcb interface 
 * @param none
 * @return none
 */
void TCB0_Start(void);
/**
 * @ingroup tcb0
 * @brief stop tcb interface 
 * @param none
 * @return none
 */
void TCB0_Stop(void);
/**
 * @ingroup tcb0
 * @brief Enable the capture interrupt for tcb interface 
 * @param none
 * @return none
 */
void TCB0_EnableCaptInterrupt(void);
/**
 * @ingroup tcb0
 * @brief Disable the capture interrupt for tcb interface 
 * @param none
 * @return none
 */
void TCB0_DisableCaptInterrupt(void);
/**
 * @ingroup tcb0
 * @brief Enable the overflow interrupt for tcb interface 
 * @param none
 * @return none
 */
void TCB0_EnableOvfInterrupt(void);
/**
 * @ingroup tcb0
 * @brief Disable the overflow interrupt for tcb interface 
 * @param none
 * @return none
 */
void TCB0_DisableOvfInterrupt(void);
/**
 * @ingroup tcb0
 * @brief Read the 16bit timer value for tcb 
 * @param none
 * @return uint16_t
 */
uint16_t TCB0_Read(void);
/**
 * @ingroup tcb0
 * @brief Write the 16bit timer value for tcb 
 * @param uint16_t timerVal - 16-bit Timer value to write for tcb interface
 * @return none
 */
void TCB0_Write(uint16_t timerVal);
/**
 * @ingroup tcb0
 * @brief Clearing the capture interrupt flag after the capture overflow flag set.
 * @param none
 * @return none
 */
void TCB0_ClearCaptInterruptFlag(void);
/**
 * @ingroup tcb0
 * @brief Enable the capture interrupt to set the capture interrupt flag, when interrupt occur.
 * @param none
 * @return none
 */
bool TCB0_IsCaptInterruptEnabled(void);
/**
 * @ingroup tcb0
 * @brief Clearing the Overflow interrupt flag after the overflow flag set.
 * @param none
 * @return none
 */
void TCB0_ClearOvfInterruptFlag(void);
/**
 * @ingroup tcb0
 * @brief Enable the Overflow interrupt to set overflow flag, when overflow occur.
 * @param none
 * @return none
 */
bool TCB0_IsOvfInterruptEnabled(void);



#ifdef __cplusplus
}
#endif

#endif /* TCB0_H_INCLUDED */