/*This code is for 500 Litre water tank. The device and code for 500 Litre water tank is tested and marked as varified.
500 Litre water tank has 84 cm depth. So, I have divided the tank in 4 parts. Frist of all we have to remember that the Ultrasonic Sensor and the 
water must have 10 cm distance so that the water can't touch the sensor. So, I kept a minimum distance of 10cm. */
int echo = 8;
int trig = 7;
int relay = 3;
int red_led = 12;
int yellow_led = 11;
int green_led1 = 9;
int green_led2 = 10;
int minimum_distance = 10;
int current_distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led1, OUTPUT);
  pinMode(green_led2, OUTPUT);
  digitalWrite(relay, LOW);
  //Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int current_distance = findDistance(trig,echo);
  //Serial.println(current_distance);
  if(current_distance <= minimum_distance)
  {
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(red_led, HIGH);
    delay(700);
    digitalWrite(relay,LOW);
  }
   if(current_distance > minimum_distance && current_distance <= 22.3)
  {
    digitalWrite(green_led1, HIGH);
    digitalWrite(green_led2, HIGH);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(red_led, HIGH);
    delay(700);
    digitalWrite(relay,LOW);
   }
   if(current_distance > 22.3 && current_distance <= 34.6)
  {
    digitalWrite(green_led1, LOW);
    digitalWrite(green_led2, HIGH);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(red_led, HIGH);
    delay(700);
    digitalWrite(relay,LOW);
   }

  if(current_distance > 34.6 && current_distance <= 59.2)
  {
    digitalWrite(green_led1, LOW);
    digitalWrite(green_led2, LOW);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(red_led, HIGH);
    delay(700);
    digitalWrite(relay,LOW);
  }
   
    if(current_distance > 59.2)
  {
    digitalWrite(green_led1, LOW);
    digitalWrite(green_led2, LOW);
    digitalWrite(yellow_led, LOW);
    digitalWrite(red_led, HIGH);
   
    while(current_distance > minimum_distance)
    {
      
      if(current_distance <= minimum_distance)
        {
          digitalWrite(green_led1, HIGH);
          digitalWrite(green_led2, HIGH);
          digitalWrite(yellow_led, HIGH);
          digitalWrite(red_led, HIGH);
        }
   else if(current_distance > minimum_distance && current_distance <= 22.3)
        {
          digitalWrite(green_led1, HIGH);
          digitalWrite(green_led2, HIGH);
          digitalWrite(yellow_led, HIGH);
          digitalWrite(red_led, HIGH);
        }
   else if(current_distance > 22.3 && current_distance <= 34.6)
        {
          digitalWrite(green_led1, LOW);
          digitalWrite(green_led2, HIGH);
          digitalWrite(yellow_led, HIGH);
          digitalWrite(red_led, HIGH); 
         }
   else if(current_distance > 34.6 && current_distance <= 59.2)
        {
          digitalWrite(green_led1, LOW);
          digitalWrite(green_led2, LOW);
          digitalWrite(yellow_led, HIGH);
          digitalWrite(red_led, HIGH);
        }
   else if(current_distance > 59.2)
        {
          digitalWrite(green_led1, LOW);
          digitalWrite(green_led2, LOW);
          digitalWrite(yellow_led, LOW);
          digitalWrite(red_led, HIGH);
        }
      delay(3000); 
      digitalWrite(relay,HIGH);
      current_distance = findDistance(trig,echo); 
      //Serial.println("loop: ");
      //Srial.println(current_distance);
    }
    
   }
}



int findDistance(int trig, int echo)
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int duration = pulseIn(echo, HIGH);
  int distance = microsecondsToCentimeters(duration);

  return distance;
}

int microsecondsToCentimeters(int microseconds)
{
  return microseconds / 29 / 2;
}
