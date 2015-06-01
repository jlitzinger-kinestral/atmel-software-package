/**
 * \page sama5d2_xult_board_desc sama5d2-XULT - Board Description
 *
 * \section Purpose
 *
 * This file is dedicated to describe the sama5d2-XULT board.
 *
 * \section Contents
 *
 *  - sama5d2-XULT
 *  - For sama5d2-XULT information, see \subpage sama5d2_xult_board_info.
 *  - For operating frequency information, see \subpage sama5d2_xult_opfreq.
 *  - For using portable PIO definitions, see \subpage sama5d2_xult_piodef.
 *  - For on-board memories, see \subpage sama5d2_xult_mem.
 *  - Several USB definitions are included here, see \subpage sama5d2_xult_usb.
 *  - For External components, see \subpage sama5d2_xult_extcomp.
 *  - For Individual chip definition, see \subpage sama5d2_xult_chipdef.
 *
 * To get more software details and the full list of parameters related to the
 * sama5d2-XULT board configuration, please have a look at the source file:
 * \ref board.h\n
 *
 * \section Usage
 *
 *  - The code for booting the board is provided by board_cstartup_xxx.c and
 *    board_lowlevel.c.
 *  - For using board PIOs, board characteristics (clock, etc.) and external
 *    components, see board.h.
 *  - For manipulating memories, see board_memories.h.
 *
 * This file can be used as a template and modified to fit a custom board, with
 * specific PIOs usage or memory connections.
 */

/**
 *  \file board.h
 *
 *  Definition of sama5d2-XULT
 *  characteristics, sama5d4-dependant PIOs and external components interfacing.
 */

#ifndef _BOARD_D2_H
#define _BOARD_D2_H

/*----------------------------------------------------------------------------
 *        HW BOARD Definitions
 *----------------------------------------------------------------------------*/

/**
 * \page sama5d2_xult_board_info "sama5d2-XULT - Board informations"
 * This page lists several definition related to the board description.
 *
 * \section Definitions
 * - \ref BOARD_NAME
 */

/** Name of the board */
#define BOARD_NAME "sama5d2-xult"

/** Family definition */
#if !defined sama5d2
  #define sama5d2
#endif

/** Board definition */
#define sama5d2xult
/** Core definition */
#define cortexa5

#define BOARD_REV_A_XULT

/*----------------------------------------------------------------------------*/
/**
 *  \page sama5d2_xult_opfreq "sama5d2-XULT - Operating frequencies"
 *  This page lists several definition related to the board operating frequency
 *  (when using the initialization done by board_lowlevel.c).
 */

/** Frequency of the board main oscillator */
#define BOARD_MAINOSC           12000000
#define BOARD_MAINOSC_MHZ       BOARD_MAINOSC/1000000

/* =================== PIN CONSOLE definition ================== */

/** CONSOLE pin definition, Use only UART */
#define PINS_CONSOLE            PINS_UART0_IOS1
#define CONSOLE_PER_ADD         UART0
#define CONSOLE_ID              ID_UART0
#define CONSOLE_BAUDRATE        115200
#define CONSOLE_DRIVER          DRV_UART

/* =================== PIN LED definition ====================== */

/* RGB LED index */
#define LED_RED       0    /* led red shared with SDHC0 (eMMC) card detect used only by RomBoot */
#define LED_GREEN     1
#define LED_BLUE      2

#define PIO_CFG_LED  (PIO_OUTPUT | PIO_OPENDRAIN)

/** LED #0 pin definition (Red). */
#define PIN_LED_0       { PIO_PD21, PIO_ADD, PIO_GROUP_D, PIO_OUTPUT_0, PIO_OPENDRAIN }

/** LED #1 pin definition (Green). */
#define PIN_LED_1       { PIO_PD22, PIO_ADD, PIO_GROUP_D, PIO_OUTPUT_0, PIO_OPENDRAIN }

/** List of all LEDs definitions. */
#define PINS_LEDS       {PIN_LED_0, PIN_LED_1}

/* =================== PIN PUSH BUTTON definition ============== */

#define PIO_CFG_PB  (PIO_PULLUP)

#define PIN_PUSHBUTTON_1 { PIO_PD19, PIO_ADD, PIO_GROUP_D, PIO_INPUT, PIO_CFG_PB }

#define PIN_PUSHBUTTON_2 { PIO_PD20, PIO_ADD, PIO_GROUP_D, PIO_INPUT, PIO_CFG_PB }

/** List of all push button definitions. */
#define PINS_PUSHBUTTONS    {PIN_PUSHBUTTON_1, PIN_PUSHBUTTON_2}

/** Push button index. */
#define PUSHBUTTON_BP1   0
#define PUSHBUTTON_BP2   1

/* ================== PIN USB definition ======================= */

/** USB VBus pin */
#define PIN_USB_VBUS      {\
	{ PIO_PA31, PIO_ADD, PIO_GROUP_A, PIO_INPUT, PIO_DEFAULT },\
}
/** USB OverCurrent detection*/
#define PIN_USB_OVCUR     {\
	{ PIO_PA29, PIO_ADD, PIO_GROUP_A, PIO_INPUT, PIO_DEFAULT },\
}
/** USB Power Enable A, Active high */
#define PIN_USB_POWER_ENA {\
	{ PIO_PB9, PIO_ADD, PIO_GROUP_B, PIO_OUTPUT_0, PIO_DEFAULT },\
}
/** USB Power Enable B, Active high  */
#define PIN_USB_POWER_ENB {\
	{ PIO_PB10, PIO_ADD, PIO_GROUP_B, PIO_OUTPUT_0, PIO_DEFAULT },\
}

/* ================= PIN GMAC IRQ definition ==================== */

#define PIO_CFG_GMAC_IRQ  (PIO_PULLUP | PIO_IT_FALL_EDGE)
#define PIN_GMAC_IRQ	{\
	{ PIO_PC9, PIO_ADD, PIO_GROUP_C, PIO_INPUT, PIO_CFG_GMAC_IRQ },\
}

/* ================= PIN LCD IRQ definition ===================== */

#define PIO_CFG_LCD_IRQ  (PIO_PULLUP | PIO_IT_FALL_EDGE)

#define PIN_QT1070_IRQ {\
	{ PIO_PB7, PIO_ADD, PIO_GROUP_B, PIO_INPUT, PIO_CFG_LCD_IRQ },\
}
#define PIN_MXT336S_IRQ {\
	{ PIO_PB8, PIO_ADD, PIO_GROUP_B, PIO_INPUT, PIO_CFG_LCD_IRQ },\
}
#define PIN_MXT768E_IRQ	{\
  { PIO_PB8, PIO_ADD, PIO_GROUP_B, PIO_INPUT, PIO_CFG_LCD_IRQ },\
}

/* =================== PIN ISC definition ======================= */

#define PIN_ISC_RST	{\
	{ PIO_PB11, PIO_ADD, PIO_GROUP_B, PIO_OUTPUT_1, PIO_DEFAULT },\
}
#define PIN_ISC_PWD	{\
	{ PIO_PB12, PIO_ADD, PIO_GROUP_B, PIO_OUTPUT_1, PIO_DEFAULT  },\
}

/* =================== PIN HSDHC definition ======================= */

#define PIN_HSDHC1_CD	{\
	{ PIO_PA30, PIO_ADD, PIO_GROUP_A, PIO_INPUT, PIO_PULLUP },\
}


#define swap(a, b) { uint16_t t = a; a = b; b = t; }


/*----------------------------------------------------------------------------
 *        Headers for board
 *----------------------------------------------------------------------------*/



#endif /* #ifndef _BOARD_D2_H */