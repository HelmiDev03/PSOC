//*****************************************************************************
//*****************************************************************************
//  FILENAME: DELSIG11_1.h
//   Version: 3.2, Updated on 2015/3/4 at 22:25:33
//
//  DESCRIPTION:  C declarations for the DELSIG11 User Module with
//                a 1st-order modulator.
//-----------------------------------------------------------------------------
//      Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef DELSIG11_1_INCLUDE
#define DELSIG11_1_INCLUDE

#include <m8c.h>

#define DELSIG11_1_POLL_ENABLE 1

#pragma fastcall16 DELSIG11_1_Start
#pragma fastcall16 DELSIG11_1_SetPower
#pragma fastcall16 DELSIG11_1_StartAD
#pragma fastcall16 DELSIG11_1_StopAD
#pragma fastcall16 DELSIG11_1_Stop

#if ( DELSIG11_1_POLL_ENABLE )
#pragma fastcall16 DELSIG11_1_fIsDataAvailable
#pragma fastcall16 DELSIG11_1_iGetData
#pragma fastcall16 DELSIG11_1_iGetDataClearFlag
#pragma fastcall16 DELSIG11_1_ClearFlag
#endif

//-------------------------------------------------
// Prototypes of the DELSIG11_1 API.
//-------------------------------------------------
extern void DELSIG11_1_Start(BYTE bPower);       // RAM use class 2
extern void DELSIG11_1_SetPower(BYTE bPower);    // RAM use class 2
extern void DELSIG11_1_StartAD(void);            // RAM use class 4
extern void DELSIG11_1_StopAD(void);             // RAM use class 1
extern void DELSIG11_1_Stop(void);               // RAM use class 1

#if ( DELSIG11_1_POLL_ENABLE )
extern BYTE DELSIG11_1_fIsDataAvailable(void);   // RAM use class 4
extern INT  DELSIG11_1_iGetData(void);           // RAM use class 4
extern INT  DELSIG11_1_iGetDataClearFlag(void);  // RAM use class 4
extern void DELSIG11_1_ClearFlag(void);          // RAM use class 4
#endif

//-------------------------------------------------
// Defines for DELSIG11_1 API's.
//-------------------------------------------------
#define DELSIG11_1_OFF         0
#define DELSIG11_1_LOWPOWER    1
#define DELSIG11_1_MEDPOWER    2
#define DELSIG11_1_HIGHPOWER   3

#define DELSIG11_1_DATA_READY_BIT  0x10
//-------------------------------------------------
// Hardware Register Definitions
//-------------------------------------------------
#pragma ioport  DELSIG11_1_TimerDR0:    0x020              //Time base Counter register
BYTE            DELSIG11_1_TimerDR0;
#pragma ioport  DELSIG11_1_TimerDR1:    0x021              //Time base Period value register
BYTE            DELSIG11_1_TimerDR1;
#pragma ioport  DELSIG11_1_TimerDR2:    0x022              //Time base CompareValue register
BYTE            DELSIG11_1_TimerDR2;
#pragma ioport  DELSIG11_1_TimerCR0:    0x023              //Time base Control register
BYTE            DELSIG11_1_TimerCR0;
#pragma ioport  DELSIG11_1_TimerFN: 0x120               //Time base Function register
BYTE            DELSIG11_1_TimerFN;
#pragma ioport  DELSIG11_1_TimerSL: 0x121               //Time base Input register
BYTE            DELSIG11_1_TimerSL;
#pragma ioport  DELSIG11_1_TimerOS: 0x122               //Time base Output register
BYTE            DELSIG11_1_TimerOS;

#pragma ioport  DELSIG11_1_AtoDcr0: 0x080               //Analog control register 0
BYTE            DELSIG11_1_AtoDcr0;
#pragma ioport  DELSIG11_1_AtoDcr1: 0x081               //Analog control register 1
BYTE            DELSIG11_1_AtoDcr1;
#pragma ioport  DELSIG11_1_AtoDcr2: 0x082               //Analog control register 2
BYTE            DELSIG11_1_AtoDcr2;
#pragma ioport  DELSIG11_1_AtoDcr3: 0x083               //Analog control register 3
BYTE            DELSIG11_1_AtoDcr3;

#endif
// end of file DELSIG11_1.h
