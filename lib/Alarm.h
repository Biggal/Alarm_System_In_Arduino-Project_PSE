#ifndef ALARM_H
#define ALARM_H
 
#include <Arduino.h>
#include <LiquidCrystal.h> 

class Alarm
{
public:
	Alarm();
   int  getHours();
   int  getMinutes();
   int  getAMins();
   int  getAHours();
   void increaseAMins();
   void increaseMins();
   void increaseAHours();
   void increaseHours();
   void at(int h, int m);
   void printtime();
   void update();
   void verify();
 
private:
	int starttime;
	int activetime;
	int prevoustime;

	int hours;
	int mins;

	int ahours;
	int amins;
};
 
 
#endif