/**
* @file
* @brief QF-nano port AVR ATmega, cooperative QV-nano kernel, GNU-AVR toolset
* @cond
******************************************************************************
* Last Updated for Version: 5.4.0
* Date of the Last Update:  2015-05-28
*
*                    Q u a n t u m     L e a P s
*                    ---------------------------
*                    innovating embedded systems
*
* Copyright (C) Quantum Leaps, LLC. All rights reserved.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Alternatively, this program may be distributed and modified under the
* terms of Quantum Leaps commercial licenses, which expressly supersede
* the GNU General Public License and are specifically designed for
* licensees interested in retaining the proprietary status of their code.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
* Contact information:
* Web:   www.state-machine.com
* Email: info@state-machine.com
******************************************************************************
* @endcond
*/
#ifndef qfn_port_h
#define qfn_port_h

#define Q_ROM                PROGMEM
#define Q_ROM_BYTE(rom_var_) pgm_read_byte_near(&(rom_var_))
#define Q_ROM_PTR(rom_var_)  pgm_read_word_near(&(rom_var_))

/* QF-nano interrupt disable/enable... */
#define QF_INT_DISABLE() __asm__ __volatile__ ("cli" ::)
#define QF_INT_ENABLE()  __asm__ __volatile__ ("sei" ::)

/* QF-nano interrupt disabling policy for interrupt level */
/*#define QF_ISR_NEST*/  /* nesting of ISRs not allowed */

/* QV sleep mode, see NOTE1... */
#define QV_CPU_SLEEP()          do { \
    __asm__ __volatile__ ("sei" ::); \
    __asm__ __volatile__ ("sleep" ::); \
    SMCR = 0U; \
} while (0)

/* QF CPU reset for AVR */
#define QF_RESET()       __asm__ __volatile__ ("jmp 0x0000" ::)

#include <avr/pgmspace.h>    /* accessing data in program memory (PROGMEM) */
#include <avr/interrupt.h>   /* AVR interrupt support */
#include <avr/io.h>          /* SREG/SMCR definitions */

#include <stdint.h>      /* Exact-width types. WG14/N843 C99 Standard */
#include <stdbool.h>     /* Boolean type.      WG14/N843 C99 Standard */

#include "qepn.h"        /* QEP-nano platform-independent public interface */
#include "qfn.h"         /* QF-nano  platform-independent public interface */
#include "qvn.h"         /* QV-nano  platform-independent public interface */

/*****************************************************************************
* NOTE1:
* As described in the "AVR Datasheet" in Section "Reset and Interrupt
* Handling", when using the SEI instruction to enable interrupts, the
* instruction following SEI will be executed before any pending interrupts.
* As the Datasheet shows in the assembly example, the pair of instructions
*     SEI       ; enable interrupts
*     SLEEP     ; go to the sleep mode
* executes ATOMICALLY, and so no interrupt can be serviced between these
* instructins. You should NEVER separate these two lines.
*/

#endif /* qfn_port_h */
