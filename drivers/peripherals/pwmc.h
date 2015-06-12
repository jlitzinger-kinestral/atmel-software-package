/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2015, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 *
 * \par Purpose
 *
 * Interface for configuration the Pulse Width Modulation Controller (PWM) peripheral.
 *
 * \par Usage
 *
 *    -# Configures PWM clocks A & B to run at the given frequencies using
 *       pwmc_configure_clocks().
 *    -# Configure PWMC channel using pwmc_configure_channel(), pwmc_set_period()
 *       and pwmc_set_duty_cycle().
 *    -# Enable & disable channel using pwmc_enable_channel() and pwmc_disable_channel().
 *    -# Enable & disable the period interrupt for the given PWM channel using
 *       pwmc_enable_channel_it() and pwmc_disable_channel_it().
 *
 */

#ifndef _PWMC_
#define _PWMC_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "chip.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
extern void pwmc_configure_clocks(Pwm * pPwm, uint32_t mode);
extern void pwmc_enable_channel(Pwm * pPwm, uint8_t channel);
extern void pwmc_disable_channel(Pwm * pPwm, uint8_t channel);
extern void pwmc_enable_channel_it(Pwm * pPwm, uint8_t channel);
extern void pwmc_disable_channel_it(Pwm * pPwm, uint8_t channel);
extern void pwmc_configure_channel(Pwm * pPwm, uint8_t channel, uint32_t mode);
extern void pwmc_set_period(Pwm * pPwm, uint8_t channel,  uint16_t period);
extern void pwmc_set_duty_cycle(Pwm * pPwm, uint8_t channel, uint16_t duty);

#ifdef __cplusplus
}
#endif
#endif				/* #ifndef _PWMC_ */