/*
 * COPYRIGHT:       GPL - See COPYING in the top level directory
 * PROJECT:         ReactOS Virtual DOS Machine
 * FILE:            pic.h
 * PURPOSE:         Programmable Interrupt Controller emulation (header file)
 * PROGRAMMERS:     Aleksandar Andrejevic <theflash AT sdf DOT lonestar DOT org>
 */

#ifndef _PIC_H_
#define _PIC_H_

/* INCLUDES *******************************************************************/

#include "ntvdm.h"

/* DEFINES ********************************************************************/

#define PIC_MASTER_CMD 0x20
#define PIC_MASTER_DATA 0x21
#define PIC_SLAVE_CMD 0xA0
#define PIC_SLAVE_DATA 0xA1
#define PIC_ICW1 0x10
#define PIC_ICW1_ICW4 (1 << 0)
#define PIC_ICW1_SINGLE (1 << 1)
#define PIC_ICW4_8086 (1 << 0)
#define PIC_ICW4_AEOI (1 << 1)
#define PIC_OCW2_NUM_MASK 0x07
#define PIC_OCW2_EOI (1 << 5)
#define PIC_OCW2_SL (1 << 6)
#define PIC_OCW3 (1 << 3)
#define PIC_OCW3_READ_ISR 0x0B

typedef struct _PIC
{
    BOOLEAN Initialization;
    BYTE MaskRegister;
    BYTE IntRequestRegister;
    BYTE InServiceRegister;
    BYTE IntOffset;
    BYTE ConfigRegister;
    BYTE CascadeRegister;
    BOOLEAN CascadeRegisterSet;
    BOOLEAN AutoEoi;
    BOOLEAN Slave;
    BOOLEAN ReadIsr;
} PIC, *PPIC;

/* FUNCTIONS ******************************************************************/

BYTE PicReadCommand(BYTE Port);
VOID PicWriteCommand(BYTE Port, BYTE Value);
BYTE PicReadData(BYTE Port);
VOID PicWriteData(BYTE Port, BYTE Value);
VOID PicInterruptRequest(BYTE Number);
BYTE PicGetInterrupt(VOID);

#endif // _PIC_H_

/* EOF */
