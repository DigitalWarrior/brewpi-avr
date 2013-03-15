/*
 * Copyright 2012 BrewPi/Elco Jacobs.
 *
 * This file is part of BrewPi.
 * 
 * BrewPi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * BrewPi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with BrewPi.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef ROTARYENCODER_H_
#define ROTARYENCODER_H_

#include <inttypes.h>
#include "ActivityHandler.h"

#define ROTARY_THRESHOLD 20000ul

class RotaryEncoder
{
	public:
	static void init(void);
	static void setRange(int start, int min, int max);
	
	static void pinAHandler(bool pinState);
	static void pinBHandler(bool pinState);
	
		
	static bool changed(void); // returns one if the value changed since the last call of changed.
	static int read(void);
	static int readHalfSteps(void);
	
	static bool pushed(void);
	static void resetPushed(void);
	static void setPushed(void);
	
	static void setActivityHandler(ActivityHandler* handler) {
		activityHandler = handler;
	}
	
	private:
	
	static void notifyActivity(ActivityType type) {
		if (activityHandler)
			activityHandler->notifyActivity(type);
	}
	
	static int maximum;
	static int minimum;
	static int prevRead;
	static volatile int halfSteps;
	static volatile bool pushFlag;
	
	static volatile uint8_t pinASignal;
	static volatile uint8_t pinBSignal;
	static volatile uint8_t pinAHistory;
	static volatile uint8_t pinBHistory;
	static volatile unsigned long pinATime;
	static volatile unsigned long pinBTime;	
	
	static ActivityHandler* activityHandler;
};

static RotaryEncoder rotaryEncoder;

#endif /* ROTARYENCODER_H_ */