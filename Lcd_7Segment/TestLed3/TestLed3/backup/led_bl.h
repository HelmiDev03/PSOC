//*****************************************************************************
//*****************************************************************************
//  FILENAME: LED_BL.h
//   Version: 2.00, Updated on 2015/3/4 at 22:26:37                                          
//  Generated by PSoC Designer 5.4.3191
//
//  DESCRIPTION: LED_BL User Module C Language interface file
//-----------------------------------------------------------------------------
//  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef LED_BL_INCLUDE
#define LED_BL_INCLUDE

#include <m8c.h>


/* Create pragmas to support proper argument and return value passing */
#pragma fastcall16  LED_BL_Stop
#pragma fastcall16  LED_BL_Start
#pragma fastcall16  LED_BL_On
#pragma fastcall16  LED_BL_Off
#pragma fastcall16  LED_BL_Switch
#pragma fastcall16  LED_BL_Invert
#pragma fastcall16  LED_BL_GetState


//-------------------------------------------------
// Constants for LED_BL API's.
//-------------------------------------------------
//
#define  LED_BL_ON   1
#define  LED_BL_OFF  0

//-------------------------------------------------
// Prototypes of the LED_BL API.
//-------------------------------------------------
extern void  LED_BL_Start(void);                                     
extern void  LED_BL_Stop(void);                                      
extern void  LED_BL_On(void);                                      
extern void  LED_BL_Off(void);                                      
extern void  LED_BL_Switch(BYTE bSwitch);
extern void  LED_BL_Invert(void);                                         
extern BYTE  LED_BL_GetState(void);                                         

//-------------------------------------------------
// Define global variables.                 
//-------------------------------------------------



#endif
