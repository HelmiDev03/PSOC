;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME:   LED_5.asm
;;  Version: 2.00, Updated on 2015/3/4 at 22:26:37
;;  Generated by PSoC Designer 5.4.3191
;;
;;  DESCRIPTION: LED user module.
;;
;;
;;  NOTE: User Module APIs conform to the fastcall16 convention for marshalling
;;        arguments and observe the associated "Registers are volatile" policy.
;;        This means it is the caller's responsibility to preserve any values
;;        in the X and A registers that are still needed after the API functions
;;        returns. For Large Memory Model devices it is also the caller's 
;;        responsibility to perserve any value in the CUR_PP, IDX_PP, MVR_PP and 
;;        MVW_PP registers. Even though some of these registers may not be modified
;;        now, there is no guarantee that will remain the case in future releases.
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "LED_5.inc"
include "memory.inc"

export _LED_5_Start
export  LED_5_Start

export _LED_5_Stop
export  LED_5_Stop

export _LED_5_On
export  LED_5_On

export _LED_5_Off
export  LED_5_Off

export _LED_5_Switch
export  LED_5_Switch

export _LED_5_Invert
export  LED_5_Invert

export _LED_5_GetState
export  LED_5_GetState


AREA UserModules (ROM, REL)


.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: LED_5_Start(void)
;  FUNCTION NAME: LED_5_Stop(void)
;
;  FUNCTION NAME: LED_5_Switch(void)
;
;  DESCRIPTION: ( Switch )
;     Turn LED on or off     
;
;  DESCRIPTION: ( Start, Stop )
;     Turn LED off                       
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:  ( Switch )
;     A => If 0, turn off LED, if > 0 turn on LED
;
;  ARGUMENTS:  ( Start, Stop )
;      None
;
;  RETURNS:  none
;
;  SIDE EFFECTS:
;    REGISTERS ARE VOLATILE: THE A AND X REGISTERS MAY BE MODIFIED!
;
;-----------------------------------------------------------------------------
_LED_5_On:
 LED_5_On:
   mov  A,0x01
   jmp  LED_5_Switch 

_LED_5_Start:
 LED_5_Start:
_LED_5_Stop:
 LED_5_Stop:
_LED_5_Off:
 LED_5_Off:
   mov  A,0x00

_LED_5_Switch:
 LED_5_Switch:
   RAM_PROLOGUE RAM_USE_CLASS_4
   RAM_PROLOGUE RAM_USE_CLASS_2
   RAM_SETPAGE_CUR >Port_0_Data_SHADE

   or   A,0x00                                   ; Check mode
   jz   .Turn_Off_LED

.Turn_On_LED:
IF(1)                                            ; Active High Digit Drive
   or   [Port_0_Data_SHADE],LED_5_PinMask
ELSE                                             ; Active Low Digit Drive
   and  [Port_0_Data_SHADE],~LED_5_PinMask
ENDIF
   jmp  .Switch_LED

.Turn_Off_LED:
IF(1)                      ; Active High Digit Drive
   and  [Port_0_Data_SHADE],~LED_5_PinMask
ELSE                              ; Active Low Digit Drive
   or   [Port_0_Data_SHADE],LED_5_PinMask
ENDIF

.Switch_LED:
   mov  A,[Port_0_Data_SHADE]
   mov  reg[LED_5_PortDR],A

   RAM_EPILOGUE RAM_USE_CLASS_2
   RAM_EPILOGUE RAM_USE_CLASS_4
   ret
.ENDSECTION



.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: LED_5_Invert(void)
;
;  DESCRIPTION:
;     Invert state of LED                               
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS: none
;
;  RETURNS:  none
;
;  SIDE EFFECTS:
;    REGISTERS ARE VOLATILE: THE A AND X REGISTERS MAY BE MODIFIED!
;
;-----------------------------------------------------------------------------
_LED_5_Invert:
 LED_5_Invert:
   RAM_PROLOGUE RAM_USE_CLASS_4
   RAM_PROLOGUE RAM_USE_CLASS_2
   RAM_SETPAGE_CUR >Port_0_Data_SHADE

   xor  [Port_0_Data_SHADE],LED_5_PinMask
   mov  A,[Port_0_Data_SHADE]
   mov  reg[LED_5_PortDR],A

   RAM_EPILOGUE RAM_USE_CLASS_2
   RAM_EPILOGUE RAM_USE_CLASS_4
   ret
.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: LED_5_GetState(void)
;
;  DESCRIPTION:
;     Get state of LED
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS: none
;
;  RETURNS:  
;    State of LED   1 = ON,  0 = OFF
;
;  SIDE EFFECTS:
;    REGISTERS ARE VOLATILE: THE A AND X REGISTERS MAY BE MODIFIED!
;
;-----------------------------------------------------------------------------
_LED_5_GetState:
 LED_5_GetState:
   RAM_PROLOGUE RAM_USE_CLASS_4
   RAM_PROLOGUE RAM_USE_CLASS_2
   RAM_SETPAGE_CUR >Port_0_Data_SHADE

   mov   A,[Port_0_Data_SHADE]         ; Get shade value
IF(1)                                  ; Active High Digit Drive
   // Nothing for now
ELSE                                   ; Active Low Digit Drive
   cpl   A                             ; Invert bit if Active low
ENDIF
   and   A,LED_5_PinMask               ; Mask off the trash
   jz    .End_LED_GS                   ; If zero, we're done
   mov   A,0x01                        ; Return a 1 no mater what the mask is.

.End_LED_GS:
   RAM_EPILOGUE RAM_USE_CLASS_2
   RAM_EPILOGUE RAM_USE_CLASS_4
   ret
.ENDSECTION
