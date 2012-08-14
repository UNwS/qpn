/*****************************************************************************
* Product: DPP example
* Last Updated for Version: 4.5.00
* Date of the Last Update:  May 29, 2012
*
*                    Q u a n t u m     L e a P s
*                    ---------------------------
*                    innovating embedded systems
*
* Copyright (C) 2002-2012 Quantum Leaps, LLC. All rights reserved.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation, either version 2 of the License, or
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
* Quantum Leaps Web sites: http://www.quantum-leaps.com
*                          http://www.state-machine.com
* e-mail:                  info@quantum-leaps.com
*****************************************************************************/
#ifndef dpp_h
#define dpp_h

enum DPPSignals {
   EAT_SIG = Q_USER_SIG,     /* published by Table to let a philosopher eat */
   DONE_SIG,                   /* published by Philosopher when done eating */
   PAUSE_SIG,                  /* published by BSP to pause the application */
   TERMINATE_SIG,          /* published by BSP to terminate the application */
   HUNGRY_SIG                    /* posted from hungry Philosopher to Table */
};

enum { N_PHILO = 5 };                             /* number of philosophers */

/* active objects ..........................................................*/
#define PHILO_0_PRIO    1

extern struct PhiloTag  AO_Philo0;
extern struct PhiloTag  AO_Philo1;
extern struct PhiloTag  AO_Philo2;
extern struct PhiloTag  AO_Philo3;
extern struct PhiloTag  AO_Philo4;
extern struct TableTag  AO_Table;

void Philo_ctor(void);                           /* instantiates all Philos */
void Table_ctor(void);

#endif                                                             /* dpp_h */