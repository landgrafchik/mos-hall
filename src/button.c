/*
 @autor:       Alexandr Haidamaka
 @file:        button.c
 @description: button driver functionality
 */

/*******************************************************************************
 *** INCLUDES
 ******************************************************************************/
#include "main.h"

/*******************************************************************************
 *** DEFENITIONS
 ******************************************************************************/

/*******************************************************************************
 *** VARIABLES
 ******************************************************************************/
switcher_t* button;

button_relay_t* button_relay; // smart home object

//------------------------------------------------------------------------------
static void button_periph()
{
	for (int i = 0; i < NUM_NODES; i++)
	{
		pin_input_up(SWITCH_PIN(i));
	}
}

void button_relay_on_callback(int i)
{
	bool state = !pin_read(LIGHT_PIN(i));
	pin_write(LIGHT_PIN(i), state);
	button_relay[i].mqtt_update = true;
}

//------------------------------------------------------------------------------
static void light_periph()
{
	for (int i = 0; i < NUM_NODES; i++)
	{
		pin_output(LIGHT_PIN(i));
	}
}

void button_relay_init(void)
{
	light_periph();

	for (int i = 0; i < NUM_NODES; i++)
	{
		button[i].on_callback = button_relay_on_callback;
		button[i].off_callback = NULL;
		button[i].state = pin_read(SWITCH_PIN(i));
		button_relay[i].mqtt_update = true;
		pin_write(LIGHT_PIN(i), true); // off state
		printf("%s(): button %d = %d\r\n", __func__, i, button[i].state);
	}
}

//------------------------------------------------------------------------------
void button_init()
{
	button = calloc(NUM_NODES, sizeof(switcher_t));
	button_relay = calloc(NUM_NODES, sizeof(button_relay_t));
	button_periph();
	button_relay_init();
}

//------------------------------------------------------------------------------
void button_driver()
{
	for (int i = 0; i < NUM_NODES; i++)
	{
		bool state = pin_read(SWITCH_PIN(i));

		if (state != button[i].state)
		{
			button[i].state = state;

			switch (state)
			{
			case false: // button push-up
				if (button[i].on_callback != NULL)
					button[i].on_callback(i);
				printf("%s(): button %d = click\n", __func__, i);
				break;
			case true:  // button push-down
				if (button[i].off_callback != NULL)
					button[i].off_callback(i);
				break;
			}
		}
	}
}
