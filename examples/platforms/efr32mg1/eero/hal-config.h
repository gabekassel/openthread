#ifndef HAL_CONFIG_H
#define HAL_CONFIG_H

#include "em_device.h"
#include "hal-config-types.h"

#ifndef BRD4151A_H
#define BRD4151A_H


#include "hal/micro/cortexm3/efm32/hal-config/hal-config-types.h"

#define HAL_PTA_OPTIONS DEFAULT_PTA_OPTIONS

// -----------------------------------------------------------------------------
/* BUTTON */
#define HAL_BUTTON_COUNT     0

// -----------------------------------------------------------------------------
/* CLK */
// Set up HFCLK source as HFXO
#define HAL_CLK_HFCLK_SOURCE HAL_CLK_HFCLK_SOURCE_HFXO
// Setup LFCLK source as LFRCO
#define HAL_CLK_LFCLK_SOURCE HAL_CLK_LFCLK_SOURCE_LFRCO
// Set HFXO frequency as 38.4MHz
#define BSP_CLK_HFXO_FREQ 38400000UL
// HFXO initialization settings
#define BSP_CLK_HFXO_INIT                                                  \
  {                                                                        \
    false,      /* Low-noise mode for EFR32 */                             \
    false,      /* Disable auto-start on EM0/1 entry */                    \
    false,      /* Disable auto-select on EM0/1 entry */                   \
    false,      /* Disable auto-start and select on RAC wakeup */          \
    _CMU_HFXOSTARTUPCTRL_CTUNE_DEFAULT,                                    \
    0x142,      /* Steady-state CTUNE for WSTK boards without load caps */ \
    _CMU_HFXOSTEADYSTATECTRL_REGISH_DEFAULT,                               \
    0x20,       /* Matching errata fix in CHIP_Init() */                   \
    0x7,        /* Recommended steady-state osc core bias current */       \
    0x6,        /* Recommended peak detection threshold */                 \
    _CMU_HFXOTIMEOUTCTRL_SHUNTOPTTIMEOUT_DEFAULT,                          \
    0xA,        /* Recommended peak detection timeout  */                  \
    0x4,        /* Recommended steady timeout */                           \
    _CMU_HFXOTIMEOUTCTRL_STARTUPTIMEOUT_DEFAULT,                           \
    cmuOscMode_Crystal,                                                    \
  }
// Board has HFXO
#define BSP_CLK_HFXO_PRESENT 1
// Set LFXO frequency as 32.768kHz
#define BSP_CLK_LFXO_FREQ 32768UL
// Board has LFXO
#define BSP_CLK_LFXO_PRESENT 1

// -----------------------------------------------------------------------------
/* DCDC */
// MCU is NOT wired for DCDC mode
#define BSP_DCDC_PRESENT 0
// Use emlib default DCDC initialization
#define BSP_DCDC_INIT    EMU_DCDCINIT_DEFAULT
// Enable bypass mode
#define HAL_DCDC_BYPASS  1

// -----------------------------------------------------------------------------
/* EXTFLASH */
#define BSP_EXTFLASH_PRESENT 0

// -----------------------------------------------------------------------------
/* LED */
#define HAL_LED_COUNT  0

// -----------------------------------------------------------------------------
/* PA */
#define HAL_PA_2P4_ENABLE   1
#define HAL_PA_2P4_VOLTMODE PA_VOLTMODE_VBAT
#define HAL_PA_2P4_POWER    190
#define HAL_PA_2P4_OFFSET   0
#define HAL_PA_2P4_RAMP     10

// -----------------------------------------------------------------------------
/* PTI */
#define HAL_PTI_ENABLE         1
#define HAL_PTI_BAUD_RATE      1600000
#define HAL_PTI_MODE           HAL_PTI_MODE_UART
#define BSP_PTI_PRESENT        1
#define BSP_PTI_DCLK_LOC       6
#define BSP_PTI_DCLK_PORT      gpioPortB
#define BSP_PTI_DCLK_PIN       11
#define BSP_PTI_DFRAME_LOC     6
#define BSP_PTI_DFRAME_PORT    gpioPortB
#define BSP_PTI_DFRAME_PIN     13
#define BSP_PTI_DOUT_LOC       6
#define BSP_PTI_DOUT_PORT      gpioPortB
#define BSP_PTI_DOUT_PIN       12

// -----------------------------------------------------------------------------
/* USART0 */
#define BSP_USART0_CTS_LOC               _USART_ROUTELOC1_CTSLOC_LOC31
#define BSP_USART0_CTS_PIN               3
#define BSP_USART0_CTS_PORT              gpioPortA
#define BSP_USART0_RTS_LOC               _USART_ROUTELOC1_RTSLOC_LOC29
#define BSP_USART0_RTS_PIN               2
#define BSP_USART0_RTS_PORT              gpioPortA
#define BSP_USART0_RX_LOC                _USART_ROUTELOC0_RXLOC_LOC0
#define BSP_USART0_RX_PIN                1
#define BSP_USART0_RX_PORT               gpioPortA
#define BSP_USART0_TX_LOC                _USART_ROUTELOC0_TXLOC_LOC0
#define BSP_USART0_TX_PIN                0
#define BSP_USART0_TX_PORT               gpioPortA

// -----------------------------------------------------------------------------
/* VCOM */
#define BSP_VCOM_PRESENT                 0

#endif /* HAL_CONFIG_H */
