#include <Arduino.h>
//                                      PushButtons
const int mode = A2;
const int color = A3; 
//                                      Lights
const int red = 3;
const int green = 5;
const int blue  = 6;
const int red2 = 9;
const int green2 = A1;  // not ~
const int blue2 = 10;

int RXLED = 17; 
int TXLED = 30; 

int modepush = 1;
int modestate = 0;
int lastmodestate = 0;
int colorpush = 1;
int colorstate = 0;
int lastcolorstate = 0;
int i = 0;
int j = 0;
int waittime = 17;
int fade = 1;
int close = 0;
int retur = 0;

void setup() {
  pinMode(mode, INPUT);
  pinMode(color, INPUT);
  Serial.begin(9600);
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RXLED, OUTPUT); 
  pinMode(TXLED, OUTPUT); 

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(blue2, OUTPUT);
}

void loop() {
//                                                PushButtons
  digitalWrite(RXLED, HIGH); 
  digitalWrite(TXLED, HIGH); 
  digitalWrite(LED_BUILTIN, LOW); 
  colorstate = digitalRead(color);
  if(colorstate != lastcolorstate)
  {
    if(colorstate == HIGH)
    {
      colorpush++;
      digitalWrite(red, LOW);
      digitalWrite(red2, LOW);
      digitalWrite(green, LOW);
      digitalWrite(green2, LOW);
      digitalWrite(blue, LOW);
      digitalWrite(blue2, LOW);
      Serial.print("color: ");
      Serial.println(colorpush);
      i=0;
      j=0;
      close=0;
      retur=0;
      fade = 1;
    }
    delay(50);
  }
  lastcolorstate = colorstate;

  modestate = digitalRead(mode);
  if(modestate != lastmodestate)
  {
    if(modestate == HIGH)
    {
      modepush++;
      colorpush = 1;
      digitalWrite(red, LOW);
      digitalWrite(red2, LOW);
      digitalWrite(green, LOW);
      digitalWrite(green2, LOW);
      digitalWrite(blue, LOW);
      digitalWrite(blue2, LOW);
      Serial.print("Mode: ");
      Serial.println(modepush);
      i=0;
      j=0;
      close=0;
      retur=0;
    }
    delay(50);
  }
  lastmodestate = modestate;

  if(modepush == 5)
  {
    modepush = 1;
    close=0;
    retur=0;
  }

//                                                Mode 1
  if(modepush == 1)
  {
    if(colorpush == 1)
    {
      digitalWrite(red, HIGH);
      digitalWrite(red2, HIGH);
    }

    if(colorpush == 2)
    {
      digitalWrite(green,HIGH);
      digitalWrite(green2, HIGH);
    }
    if(colorpush == 3)
    {
      digitalWrite(blue, HIGH);
      digitalWrite(blue2, HIGH);
    }
    if(colorpush == 4)
    {
      digitalWrite(red, HIGH);
      digitalWrite(red2, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(green2, HIGH);
    }
    if(colorpush == 5)
    {
      digitalWrite(red, HIGH);
      digitalWrite(red2, HIGH);
      digitalWrite(blue, HIGH);
      digitalWrite(blue2, HIGH);
    }
    if(colorpush == 6 )
    {
      digitalWrite(green, HIGH);
      digitalWrite(green2, HIGH);
      digitalWrite(blue, HIGH);
      digitalWrite(blue2, HIGH);
    }
    if(colorpush == 7)
    {
      digitalWrite(red, HIGH);
      digitalWrite(red2, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(green2, HIGH);
      digitalWrite(blue, HIGH);
      digitalWrite(blue2, HIGH);
    }
    if(colorpush == 8 && modepush == 1)
    {
      colorpush = 1;
    }
  }
//                                                Mode 2
  if(modepush == 2)
  {
    if(colorpush == 1)
    {
      digitalWrite(red, HIGH);
      digitalWrite(blue2, HIGH);
    }
    if(colorpush == 2)
    {
      digitalWrite(red, HIGH);
      digitalWrite(green2, HIGH);
    }
    if(colorpush == 3)
    {
      digitalWrite(blue, HIGH);
      digitalWrite(green2, HIGH);
    }
    if(colorpush == 4)
    {
      digitalWrite(red, HIGH);
      digitalWrite(blue, HIGH);
      digitalWrite(green2, HIGH);
    }
    if(colorpush == 5)
    {
      digitalWrite(red, HIGH);
      digitalWrite(blue, HIGH);
      digitalWrite(blue2, HIGH);
      digitalWrite(green2, HIGH);
    }

    if(colorpush == 6 && modepush == 2)
    {
      colorpush = 1;
    }

  }

  //                                          Mode 3

  if(modepush == 3)
  {
    
    //                                         COLOR 1
    
    if(colorpush == 1 && close != 2) 
    {
      analogWrite(blue, i);
      analogWrite(red2, i);
      i = i + fade;
      if(close > 2)
      {
        close = 2;
      }
      if (i <= 0 || i >= 255) {
        fade = -fade;
        close++;
        delay(waittime);
      }
      delay(waittime);
    }
    if (colorpush == 1 && close == 2)
    {
      analogWrite(red, i);
      analogWrite(green, i);
      analogWrite(blue2, i);
      i = i + fade;
      if (i <= 0 || i >= 255) {
        fade = -fade;
        retur++;
        delay(waittime);
      }
      delay(waittime);
      if(retur == close || retur == 2)
      {
        retur = 0;
        close = 0;
      }
    }
    //                                  COLOR 2

    if(colorpush == 2 && close != 2) 
    {
      analogWrite(green, i);
      analogWrite(blue2, i);
      i = i + fade;
      if (i <= 0 || i >= 255) {
        fade = -fade;
        close++;
        delay(waittime);
      }
      delay(waittime);
    }
    if (colorpush == 2 && close == 2)
    {
      analogWrite(green, i);
      analogWrite(red, i);
      analogWrite(red2, i);
      i = i + fade;
      if (i <= 0 || i >= 255) {
        fade = -fade;
        retur++;
        delay(waittime);
      }
      delay(waittime);
      if(retur == close || retur == 2)
      {
        retur = 0;
        close = 0;
      }
    }

     //                                  COLOR 3
    
    if(colorpush == 3 && close != 2) 
    {
      analogWrite(green, i);
      analogWrite(red2, i);
      i = i + fade;
      if (i <= 0 || i >= 255) {
        fade = -fade;
        close++;
        delay(waittime);
      }
      delay(waittime);
    }
    if (colorpush == 3 && close == 2)
    {
      analogWrite(blue, i);
      analogWrite(red, i);
      analogWrite(blue2, i);
      i = i + fade;
      if (i <= 0 || i >= 255) {
        fade = -fade;
        retur++;
        delay(waittime);
      }
      delay(waittime);
      if(retur == close || retur == 2)
      {
        retur = 0;
        close = 0;
      }
    }
    if(colorpush == 4 && modepush == 3)
    {
      colorpush = 1;
    }

  }

  //                                  MODE 4

  if(modepush == 4)
  {
    analogWrite(red, random(0, 255));
    analogWrite(green, random(0, 255));
    analogWrite(blue, random(0, 255));
    analogWrite(red2, random(0, 255));
    analogWrite(blue2, random(0, 255));
    delay(1000);
  }

  //                               MODE 5 - OFF
  if(modepush == 5)
  {
    digitalWrite(red, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(green, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(blue2, LOW);
  }
}