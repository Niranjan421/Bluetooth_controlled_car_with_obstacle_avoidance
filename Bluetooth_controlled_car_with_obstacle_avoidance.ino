#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial bluetooth(11,12); // RX, TX
Servo Myservo;
char t;

#define MLa 4     //left motor 1st pin
#define MLb 5     //left motor 2nd pin
#define MRa 6    //right motor 1st pin
#define MRb 7    //right motor 2nd pin
#define trigPin 9           // Trig Pin Of HC-SR04
#define echoPin 8        // Echo Pin Of HC-SR04
long duration, distance;
 
void setup()
{
  Serial.begin(9600);
bluetooth.begin(9600);
pinMode(MLa,OUTPUT);   //left motors forward
pinMode(MLb,OUTPUT);   //left motors reverse
pinMode(MRa,OUTPUT);   //right motors forward
pinMode(MRb,OUTPUT);   //right motors reverse
pinMode(trigPin, OUTPUT);       // Set Trig Pin As O/P To Transmit Waves
  pinMode(echoPin, INPUT);        //Set Echo Pin As I/P To Receive Reflected Waves
  Myservo.attach(10);


}
 
void loop() 
{
if(bluetooth.available()>0)
{
  t = bluetooth.read();
  Serial.println(t);
}
 switch(t)
 {
  case 'F':
        {            //move forward(all motors rotate in forward direction)
          digitalWrite(MLa,LOW);
          digitalWrite(MLb,HIGH);
          digitalWrite(MRa,LOW);
          digitalWrite(MRb,HIGH);

           digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);       // Transmit Waves For 10us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);        // Receive Reflected Waves
  distance = duration / 58.2;                       // Get Distance
  Serial.println(distance);
  delay(10);
  if (distance > 3)               // Condition For Absence Of Obstacle            
  {
    Myservo.write(90);
    digitalWrite(MRb, HIGH);       // Move Forward
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, HIGH);                                
    digitalWrite(MLa, LOW);                                                       
  }
  else if ((distance < 2)&&(distance > 0))            // Condition For Presence Of Obstacle
  {
    digitalWrite(MRb, LOW);     //Stop                
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);
    delay(100);
    
    Myservo.write(0);
    delay(500);
    Myservo.write(180);
    delay(500);
    Myservo.write(90);
    delay(500);
    
    digitalWrite(MRb, LOW);     // Move Backward             
    digitalWrite(MRa, HIGH);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, HIGH);
    delay(500);
    digitalWrite(MRb, LOW);        //Stop                
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);  
    delay(100);  
    digitalWrite(MRb, HIGH);     // Move Left     
    digitalWrite(MRa, LOW);   
    digitalWrite(MLa, LOW);                                 
    digitalWrite(MLb, LOW);  
    delay(500);
          delay(10);
        }
        
   break;
   
  case 'B':
        {      //move reverse (all motors rotate in reverse direction)
          digitalWrite(MLa,HIGH);
          digitalWrite(MLb,LOW);
          digitalWrite(MRa,HIGH);
            digitalWrite(MRb,LOW);
          
          delay(10);
        }
        
   break;
   
  case 'L':
        {      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
          digitalWrite(MLa,LOW); 
          digitalWrite(MLb,HIGH); 
          digitalWrite(MRa,LOW);
          digitalWrite(MRb,LOW);
        }
   break;
   
  case 'R':
        {      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
          digitalWrite(MLa,LOW); 
          digitalWrite(MLb,LOW); 
          digitalWrite(MRa,LOW);
          digitalWrite(MRb,HIGH);
        }
   break;
   
  
  
    case 'S':
        {           //STOP (all motors stop)
          digitalWrite(MLa,LOW);
          digitalWrite(MLb,LOW); 
          digitalWrite(MRa,LOW);
          digitalWrite(MRb,LOW);
          
          
        }

        } 
        
 }
}
