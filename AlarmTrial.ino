#include <LiquidCrystal.h>
#define TON 6
#define EN 11
#define RS 12
#define BT0 7  //10
#define BT1 8  //11
#define BT2 9  //13
#define BT3 10 //8

LiquidCrystal lcd(RS, EN, 5, 4, 3, 2);

int starttime;
int activetime;
int prevoustime = 0;

int hours = 0;
int mins = 0;

int ahours = 0;
int amins = 0;

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  
  Serial.begin(9600);
  
  pinMode(BT2, INPUT);
  digitalWrite(BT2, HIGH);
  pinMode(BT1, INPUT);
  digitalWrite(BT1, HIGH);
  pinMode(BT0, INPUT);
  digitalWrite(BT0, HIGH);
  
   pinMode(8, INPUT);
  digitalWrite(8, HIGH);
  pinMode(A0, OUTPUT);
  digitalWrite(A0, HIGH);
  
   pinMode(TON, OUTPUT);
  
  starttime = millis()/1000;
}

void loop()
{
  while(digitalRead(8) == LOW)
  {
    lcd.setCursor(EN,1);
    lcd.print("Alarm");
    lcd.setCursor(EN,0);
       if(digitalRead(BT1) == LOW)
    {
     amins++;
    } 
    else if (digitalRead(BT0) == LOW)
    {
      ahours++;
    }
     lcd.setCursor(EN,0);
  
  if(ahours < BT3)
  {
    lcd.print("0");
    lcd.print(ahours);
  }
  else
  {
    lcd.print(ahours);
  }
    
    lcd.print(":");
    
  if (amins < BT0)
  {
    lcd.print("0");
      lcd.print(amins);
  }
  else
  {
      lcd.print(amins);
  }
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
  
  if(digitalRead(BT2) == LOW)
  {
    
    lcd.setCursor(5,1);
    lcd.print("Set Time");
    lcd.setCursor(EN,0);
     if(digitalRead(BT1) == LOW)
    {
     mins++;
    } 
    else if (digitalRead(BT0) == LOW)
    {
      hours++;
    }
    

  }
  
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
  
  
  lcd.setCursor(EN,0);
  
  if(hours < BT0)
  {
    lcd.print("0");
    lcd.print(hours);
  }
  else
  {
    lcd.print(hours);
  }
    
    lcd.print(":");
    
  if (mins < BT0)
  {
    lcd.print("0");
      lcd.print(mins);
  }
  else
  {
      lcd.print(mins);
  }



if(ahours == hours && amins == mins && amins != 0)
{
  tone(TON, 1000, 200);
  delay(200);
  noTone(TON);
delay(200);
}
else
{
    delay(300);
}
  lcd.clear();
 

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

