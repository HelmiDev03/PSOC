;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME: DELSIG11_1.inc
;;   Version: 3.2, Updated on 2015/3/4 at 22:25:33
;;
;;  DESCRIPTION: Assembler declarations for the 11-bit Delta-Sigma A/D
;;               Converter User Module with a 1st-order modulator.
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "m8c.inc"


;--------------------------------------------------
; Constants for DELSIG11_1 API's.
;--------------------------------------------------

DELSIG11_1_INT_REG:                        equ  0e1h
DELSIG11_1_INT_MASK:                       equ  01h     ; Interrupt mask

DELSIG11_1_OFF:                    equ  0
DELSIG11_1_LOWPOWER:               equ  1
DELSIG11_1_MEDPOWER:               equ  2
DELSIG11_1_HIGHPOWER:              equ  3

HIGHBYTE:                          equ   0
LOWBYTE:                           equ   1

DATAPOSITION:                      equ 1h
LEFTJUST:                          equ 02h
RIGHTJUST:                         equ 01h
DELSIG11_1_LEFTJUSTIFIED:          equ DATAPOSITION & LEFTJUST
DELSIG11_1_RIGHTJUSTIFIED:         equ DATAPOSITION & RIGHTJUST

DELSIG11_1_POLL_ENABLE:            equ 1
DELSIG11_1_DATA_READY_BIT:         equ  10h


;--------------------------------------------------
; Register Address Constants for DELSIG11_1
;--------------------------------------------------

DELSIG11_1_TimerDR0:           equ 0x20    ; Period reg
DELSIG11_1_TimerDR1:           equ 0x21    ; Down count reg
DELSIG11_1_TimerDR2:           equ 0x22    ; Compare reg
DELSIG11_1_TimerCR0:           equ 0x23    ; Control reg
DELSIG11_1_TimerFN:            equ 0x20    ; Function reg
DELSIG11_1_TimerSL:            equ 0x21    ; Input  select reg
DELSIG11_1_TimerOS:            equ 0x22    ; Output select reg

DELSIG11_1_AtoDcr0:            equ 0x80    ; SC Block Control Reg 0
DELSIG11_1_AtoDcr1:            equ 0x81    ; SC Block Control Reg 1
DELSIG11_1_AtoDcr2:            equ 0x82    ; SC Block Control Reg 2
DELSIG11_1_AtoDcr3:            equ 0x83    ; SC Block Control Reg 3


; end of file DELSIG11_1.inc
