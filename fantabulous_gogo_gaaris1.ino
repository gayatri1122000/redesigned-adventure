 #include<Servo.h>
//this is the beginning of the code.it mainly deals with the motion of the servo motors.
Servo myservo1,myservo2;
  #define ledpin1 A0
  #define ledpin2 A1
  #define ledpin3 A2
  #define ledpin4 A3
  #define irpin1  13
  #define irpin2  12
  #define irpin3  7
  #define irpin4  3
  int i=1;
int pirs=0;
 int pirs2=0;//these are for the PIR sensors
int pirs3=0;
int pirs4=0;
int trigpin1=10;
int echopin1=8;
int pinservo1=9;
int trigpin2=6;               //declaration of all the variables
int echopin2=4;
int pinservo2=5;
float durationtime1,distance1,durationtime2,distance2;
int distancethreshold=150;

void setup()
{//
  pinMode(trigpin1, OUTPUT);
   pinMode(echopin1, INPUT);
  
  
  myservo1.attach(pinservo1);//attaching servo pin to the servo
  myservo1.write(0);
   pinMode(trigpin2, OUTPUT);
   pinMode(echopin2, INPUT);
  
  
  myservo2.attach(pinservo2);
  myservo2.write(0);//begins with the initial position of 0 degrees

  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
  pinMode(ledpin4, OUTPUT);
   pinMode(irpin1,INPUT);
  pinMode(irpin2,INPUT);
  pinMode(irpin3,INPUT);
  pinMode(irpin4,INPUT);
    Serial.begin(9600);
}

void loop()
{digitalWrite(trigpin1,HIGH);
  delayMicroseconds(10);             //trigger pin blinking
  digitalWrite(trigpin1,LOW);
 
  
  durationtime1= pulseIn(echopin1,HIGH);
  
  distance1=0.018*durationtime1; // calculation of object's proximity
                                    //to the sensor
  
  if(distance1<distancethreshold)
  {
  myservo1.write(90);
  delay(3000);                  //if the object is close,the servo motor rotates by 90 degrees
    myservo1.write(0);
  delay(3000);  // there is a gap of 3 seconds
 
 
  }
else
{
   myservo1.write(0);
}
  Serial.print("distance: ");
  Serial.println(distance1);   // this gives us the approximate distance of the object in the serial monitor
  Serial.println(" cm");

 

 digitalWrite(trigpin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin2,LOW);
 
  
  durationtime2= pulseIn(echopin2,HIGH);
  
  distance2=0.018*durationtime2; 
  
  if(distance2<distancethreshold)// threshold distance shall remain same for both the sensors
  {
  myservo2.write(90);
  delay(3000);
    myservo2.write(0);
  delay(3000);
 
 
  }
else
{
   myservo2.write(0);
}
  Serial.print("distance: ");
  Serial.println(distance2);
  Serial.println(" cm");
//the code from here on is for the PIR sesnors and their connection to the LEDs
 //there is a time gap between recieval of signal by PIr and the turning
 //on of the LED.this is to consider the time taken to prepare food 
 //items and its payment.
 ;
 // this section is for the activation of PIR sensors

 while(i<2){
    pirs=digitalRead(irpin1);
 if (pirs==HIGH&&pirs2==LOW&&pirs3==LOW&&pirs4==LOW)
 {
 digitalWrite(ledpin1,HIGH);        //the while loop makes sure that the condition of the PIR sensors is looked into.
   delay(1000);
    digitalWrite(ledpin1,LOW);
   digitalWrite(ledpin3,LOW);
   digitalWrite(ledpin4,LOW);
   digitalWrite(ledpin2,LOW);
   
   Serial.println("item red has been ordered");
 } pirs2=digitalRead(irpin2);
 
    if (pirs2==HIGH&&pirs==LOW&&pirs3==LOW&&pirs4==LOW)
   {
 digitalWrite(ledpin2,HIGH);
   delay(1000);
   digitalWrite(ledpin2,LOW);
   digitalWrite(ledpin1,LOW);
   digitalWrite(ledpin3,LOW);
   digitalWrite(ledpin4,LOW);
  Serial.println("item blue has been ordered");
   } pirs3=digitalRead(irpin3);
  
          if (pirs3==HIGH&&pirs==LOW&&pirs2==LOW&&pirs4==LOW)
          {
 digitalWrite(ledpin3,HIGH);
   delay(1000);
   digitalWrite(ledpin3,LOW);
   digitalWrite(ledpin1,LOW);
   digitalWrite(ledpin2,LOW);
   digitalWrite(ledpin4,LOW);
   Serial.println("item green has been ordered");
          }pirs4=digitalRead(irpin4);
  if(pirs4==HIGH&&pirs==LOW&&pirs==LOW&&pirs3==LOW)
 {
 digitalWrite(ledpin4,HIGH);
   delay(1000);
   digitalWrite(ledpin4,LOW);
   digitalWrite(ledpin1,LOW);
   digitalWrite(ledpin2,LOW);
   digitalWrite(ledpin3,LOW);
   Serial.println("item yellow has been ordered");
 i++;
 }
   
 }
 

}

// IR remote has not been used since that faciclity may not be available in practical world

 //instead PIR sensors which can sense human motion have been used




