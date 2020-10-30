/*
 * button.h
 *
 *  Created on: Oct 26, 2020
 *      Author: Darek
 */

#ifndef BUTTON_H_
#define BUTTON_H_

typedef enum
{
	IDLE = 0,
	DEBOUNCE,
	PRESSED,
	REPEAT,
	RELEASE
} BUTTON_STATE;

typedef struct button_struct
{
	BUTTON_STATE 	State;
	GPIO_TypeDef* 	GpioPort;
	uint16_t	 	GpioPin;
	GPIO_TypeDef* 	LedPort;
	uint16_t	 	LedPin;
	uint32_t		Timer;
	uint32_t		TimerIdle;
	uint32_t		TimerDebounce;
	uint32_t		TimerPressed;
	uint32_t		TimerRepeat;
	uint32_t		TimerRelease;
	uint32_t		LastTick;
	int i;
	int j;

	void(*ButtonPress)(void);
	void(*ButtonLongPress)(void);
	void(*ButtonRepeatPress)(void);
	void(*ButtonReleasePress)(void);
} TButton;
void ButtonTask(TButton* Key);
void ButtonInitKey(TButton* Key, GPIO_TypeDef* GpioPort, uint16_t GpioPin, GPIO_TypeDef* LedPort, uint16_t LedPin, uint32_t TimerIdle, uint32_t TimerDebounce, uint32_t TimerPressed, uint32_t TimerRepeat, uint32_t TimerRelease, int i);
void ButtonRegisterPressCallback(TButton* Key, void* Callback);
void ButtonRegisterLongPressCallback(TButton* Key, void* Callback);
void ButtonRegisterRepeatPressCallback(TButton* Key, void* Callback);
void ButtonRegisterReleasePressCallback(TButton* Key, void* Callback);
#endif /* BUTTON_H_ */
