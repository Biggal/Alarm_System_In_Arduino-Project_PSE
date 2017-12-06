#include"Alarm.h"

LiquidCrystal lcd(RS, EN, 5, 4, 3, 2);

Alarm::Alarm()
{
   starttime = millis()/1000;
   
   previoustime = 0;
   hours = 0;
   mins = 0;
   ahours = 0;
   amins = 0;
}
 
int Alarm::getHours()
{
   return hours;
}
 
int Alarm::getMinutes()
{
   return mins;
}
 
int Alarm::getAMins()
{
   return amins;
}

int Alarm::getAHours()
{
   return ahours;
}

void Alarm::increaseAMins() 
{
	amins = amins + 1;
}

void Alarm::increaseMins() 
{
	mins = mins + 1;
}

void Alarm::increaseAHours() 
{
	ahours = ahours + 1;
}

void Alarm::increaseHours() 
{
	hours = hours + 1;
}

void Alarm::at(int h, int m) 
{
	ahours = h;
	amins = m;
}

void Alarm::printtime() 
{
	Serial.println(mins);
  Serial.println(hours);
  Serial.println("");
  Serial.println(amins);
  Serial.println(ahours);
  Serial.println("");
  Serial.println(activetime);
  Serial.println(prevoustime);
  Serial.println(starttime);
  Serial.println("");
}

void Alarm::update() 
{
	activetime = (millis() / 1000) - starttime;
      
	  if(prevoustime < (activetime - 59))
      {
       mins++;
       prevoustime = activetime;
      } 
      
      if(mins > 59)
     {
      hours++;
      mins = 0;
     } 
     
     if(hours > 23)
     {
      hours = 0; 
     }
}

void Alarm::verify() {
	if(amins > 59)
	{
		ahours++;
		amins = 0;
	} 
	if(ahours > 23)
	{
		ahours = 0; 
	}
		
	delay(500);
	lcd.clear();
	
}