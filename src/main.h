#ifndef __MAIN_H__
#define __MAIN_H__

/*******************************************************************************
 *** INCLUDES
 ******************************************************************************/
#include "mgos.h"
#include "mgos_mqtt.h"
#include "config/config.h"
#include "driver/drv.h"
#include "driver/drv_led.h"
#include "driver/drv_switch.h"
#include "driver/drv_button.h"
#include "driver/drv_mqtt.h"
#include "iot/iot.h"
#include "iot/iot_relay.h"
#include "iot/iot_sw.h"
#include "iot/iot_sw_relay.h"
#include "iot/iot_bt.h"
#include "iot/iot_bt_relay.h"

/*******************************************************************************
 *** DEFENITIONS
 ******************************************************************************/
#define  SYS_TICK   (50) //time [ms]

//  Pin definitions for NodeMCU (ESP8266)
#define  D0         (16) // IO ONLY(no pull-up)
#define  D1         (5)  // IO
#define  D2         (4)  // IO
#define  D3         (0)  // BOOT_MODE
#define  D4         (2)  // BOOT_MODE - LED_PIN
#define  D5         (14) // IO
#define  D6         (12) // IO
#define  D7         (13) // IO strange behaviour
#define  D8         (15) // BOOT_MODE
#define  D9         (3)  // Rx - I
#define  D10        (1)  // Tx - O

/*******************************************************************************
 *** MACROSES
 ******************************************************************************/
#define pin_input(pin, mode) { mgos_gpio_set_mode(pin, MGOS_GPIO_MODE_INPUT);  \
                               mgos_gpio_set_pull(pin, mode); }
#define pin_output(pin)        mgos_gpio_set_mode(pin, MGOS_GPIO_MODE_OUTPUT);
#define pin_write(pin, state)  mgos_gpio_write(pin, state)
#define pin_read(pin)          mgos_gpio_read(pin)

/*******************************************************************************
 *** PROTOTYPES
 ******************************************************************************/
void delay(int ms);

#endif  //__MAIN_H__
