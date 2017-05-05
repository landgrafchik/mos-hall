#ifndef __MAIN_H__
#define __MAIN_H__

/*******************************************************************************
 *** INCLUDES
 ******************************************************************************/
#include <stdio.h>
#include <user_interface.h>

#include "common/platform.h"
#include "common/platforms/esp8266/esp_missing_includes.h"
#include "fw/platforms/esp8266/src/esp_periph.h"
#include "fw/src/mgos_sys_config.h"
#include "fw/src/mgos_hal.h"
#include "fw/src/mgos_app.h"
#include "fw/src/mgos_gpio.h"
#include "fw/src/mgos_timers.h"
#include "fw/src/mgos_mqtt.h"
#include "fw/src/mgos_wifi.h"
#include "config.h"
#include "pwm_timer.h"
#include "switch.h"
#include "button.h"
#include "led.h"
#include "mqtt.h"

/*******************************************************************************
 *** DEFENITIONS
 ******************************************************************************/
#define  SYS_TICK   (50) //time [ms]

/*******************************************************************************
 *** MACROSES
 ******************************************************************************/
#define pin_input_up(pin)    { mgos_gpio_set_mode(pin, MGOS_GPIO_MODE_INPUT);  \
                               mgos_gpio_set_pull(pin, MGOS_GPIO_PULL_UP); }
#define pin_output(pin)        mgos_gpio_set_mode(pin, MGOS_GPIO_MODE_OUTPUT);
#define pin_write(pin, state)  mgos_gpio_write(pin, state)
#define pin_read(pin)          mgos_gpio_read(pin)

/*******************************************************************************
 *** COMMON TYPEDEF
 ******************************************************************************/
typedef struct
{
	bool state;

	void (*on_callback)(int i);
	void (*off_callback)(int i);
} input_t;

/*******************************************************************************
 *** EXTERN VARIABLES
 ******************************************************************************/
extern bool wifi_ip_acquired;

#endif  //__MAIN_H__
