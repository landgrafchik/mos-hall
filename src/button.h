#ifndef __BUTTON_H__
#define __BUTTON_H__

/*******************************************************************************
 *** TYPEDEF
 ******************************************************************************/
typedef struct
{
	bool mqtt_update;
} bt_relay_t;

/*******************************************************************************
 *** EXTERN VARIABLES
 ******************************************************************************/
extern bt_relay_t* bt_relay;

/*******************************************************************************
 *** PROTOTYPES
 ******************************************************************************/
void button_init();
void button_driver();

#endif  //__SWITCH_H__
