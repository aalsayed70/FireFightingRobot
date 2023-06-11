#include <Servo.h> 
#include <Wire.h> 
Servo myservo; 
int m1a = 9;
int m1b = 10;
int m2a = 11;
int m2b = 12;  
int WaterP=8;
int t=0;
int dis=0;
// blue1 pin L - grey pin C 
// green pin R - brown,white and blue2 5v
// red ,black and violet ground


int pos = 120;    // variable to store the servo position

int LFLAM=5;
int SFLAM=2;
int RFLAM=4; 

int b;
char val;

void setup() 
{  
  pinMode(WaterP,OUTPUT); 
  pinMode(7,OUTPUT); 
  pinMode(6,INPUT);
  pinMode(LFLAM,INPUT);
  pinMode(SFLAM,INPUT);
  pinMode(RFLAM,INPUT);
  pinMode(m1a, OUTPUT);  // Digital pin 09 set as output Pin 
  pinMode(m1b, OUTPUT);  // Digital pin 10 set as output Pin
  pinMode(m2a, OUTPUT);  // Digital pin 11 set as output Pin
  pinMode(m2b, OUTPUT);  // Digital pin 12 set as output Pin
  Serial.begin(9600); 
  myservo.attach(3);    
  myservo.write(pos); 
  myservo.write(70); 
  delay(500); 
  myservo.write(160);   
  myservo.write(pos); 
}

void loop()
{
 if(digitalRead(LFLAM) == HIGH ||digitalRead(RFLAM) == HIGH || digitalRead(SFLAM) == HIGH ) 
  { 
      int l=0;
      if(digitalRead(RFLAM) == HIGH) 
      {
        bool b1=0,b2=0,b3=0;
       if(digitalRead(SFLAM) == HIGH) b1=1; 
           if(digitalRead(SFLAM) == HIGH) b2=1;  
           if(digitalRead(SFLAM) == HIGH) b3=1;
        while(b1 == 0 && b2 == 0 && b3==0) 
        {
           b1=0,b2=0,b3=0; 
          if(digitalRead(SFLAM) == HIGH) b1=1; 
           if(digitalRead(SFLAM) == HIGH) b2=1;  
           if(digitalRead(SFLAM) == HIGH) b3=1; 
          digitalWrite(m1b, HIGH); 
          digitalWrite(m2a, HIGH); 
          digitalWrite(m2b, LOW); 
          digitalWrite(m1a, LOW); 
          if(digitalRead(LFLAM) == HIGH) break; 
        }
      }  
      l=0;
      if(digitalRead(LFLAM) == HIGH) 
      {
        bool b1=0,b2=0,b3=0;
       if(digitalRead(SFLAM) == HIGH) b1=1; 
           if(digitalRead(SFLAM) == HIGH) b2=1;  
           if(digitalRead(SFLAM) == HIGH) b3=1;
        while(b1 == 0 && b2 == 0 && b3==0) 
        {
          b1=0,b2=0,b3=0; 
          if(digitalRead(SFLAM) == HIGH) b1=1; 
           if(digitalRead(SFLAM) == HIGH) b2=1;  
           if(digitalRead(SFLAM) == HIGH) b3=1; 
          digitalWrite(m1b, LOW); 
          digitalWrite(m2a, LOW); 
          digitalWrite(m2b, HIGH); 
          digitalWrite(m1a, HIGH); 
          if(digitalRead(RFLAM) == HIGH) break;          
        }
      } 
      if(digitalRead(SFLAM) == HIGH)
      {
      digitalWrite(m1b, LOW); 
      digitalWrite(m2a, LOW); 
      digitalWrite(m2b, LOW); 
      digitalWrite(m1a, LOW); 
      digitalWrite(7,LOW); 
      delay(0.005); 
      digitalWrite(7,HIGH); 
      delay(0.01); 
      digitalWrite(7,LOW); 
      t = pulseIn(6,HIGH);  
      Serial.println(t); 
      int A=t/57; 
      while(A > 22 && b > 22) 
      {
        digitalWrite(m1a, HIGH); 
        digitalWrite(m2a, HIGH); 
        digitalWrite(m1b, LOW); 
        digitalWrite(m2b, LOW);  
        digitalWrite(7,LOW); 
        delay(0.005); 
        digitalWrite(7,HIGH); 
        delay(0.01); 
        digitalWrite(7,LOW); 
        t = pulseIn(6,HIGH);  
        Serial.println(t); 
        A=t/57;  
        digitalWrite(7,LOW); 
        delay(0.005); 
        digitalWrite(7,HIGH); 
        delay(0.01); 
        digitalWrite(7,LOW); 
        t = pulseIn(6,HIGH);  
        Serial.println(t); 
        b=t/57; 
      } 
        
      digitalWrite(m1a, LOW); 
      digitalWrite(m2a, LOW); 
      digitalWrite(m1b, LOW); 
      digitalWrite(m2b, LOW);  
      int y=-1; 
      digitalWrite(WaterP,1);
      int count=10; 
     while(true)
      { 
        pos+=15*y;
        myservo.write(pos);  
        delay(10);
        bool b1=false,b2=false,b3=false,b4=false;
        if(digitalRead(SFLAM) == LOW)  b1=1; 
        delay(5); 
        if(digitalRead(SFLAM) == LOW)  b2=1; 
        delay(5); 
        if(digitalRead(SFLAM) == LOW)  b3=1;  
        delay(5);
        if(digitalRead(SFLAM) == LOW)  b4=1; 
        if(b1 && b2 && b3 && b4) break;
        if(pos <= 95 || pos>=145) 
        {
        delay(200); 
        y=-y; 
        } 
      }  
      digitalWrite(WaterP,0); 
      }
  }  
  while (Serial.available() > 0)
  {
   val = Serial.read();
   Serial.println(val);
  }

  if( val == 'F') // Forward
    {
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);  
    }
  else if(val == 'B') // Backward
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH); 
    }
  
    else if(val == 'R') //Left
    {
     digitalWrite(m1a, LOW);
     digitalWrite(m1b, HIGH);
     digitalWrite(m2a, HIGH);
     digitalWrite(m2b, LOW);
    }
    else if(val == 'L') //Right
    {
     digitalWrite(m1a, HIGH);
     digitalWrite(m1b, LOW);
     digitalWrite(m2a, LOW);
     digitalWrite(m2b, HIGH); 
    }
    
  else if(val == 'FORWARD') //Stop
    {
     digitalWrite(m1a, HIGH);
     digitalWrite(m1b, LOW);
     digitalWrite(m2a, HIGH);
     digitalWrite(m2b, LOW); 
    }
  else if(val == 'S') //Forward Right
    {
     digitalWrite(m1a, LOW);
     digitalWrite(m1b, LOW);
     digitalWrite(m2a, LOW);
     digitalWrite(m2b, LOW);
    }
  else if(val == 'BACK') //Backward Right
    {
     digitalWrite(m1a, LOW);
     digitalWrite(m1b, HIGH);
     digitalWrite(m2a, LOW);
     digitalWrite(m2b, HIGH);
    }
   else if(val == 'G') //Forward Left
    {
     digitalWrite(m1a, LOW);
     digitalWrite(m1b, LOW);
     digitalWrite(m2a, HIGH);    
     digitalWrite(m2b, LOW);
    }
  else if(val == 'H') //Backward Left
    {
     digitalWrite(m1a, LOW);
     digitalWrite(m1b, LOW);
     digitalWrite(m2a, LOW);
     digitalWrite(m2b, HIGH); 
    } 
}