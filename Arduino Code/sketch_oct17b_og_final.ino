#include <LiquidCrystal.h>

int redLed = 13;
int greenLed = 12;
int buzzer = 2;
int gasA0 = A0;
int sensorThres =49;
void send_message(void);


#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(gasA0, INPUT);

  // set the speed at 60 rpm:
  myStepper.setSpeed(100);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(gasA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);

  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
    
     Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

   // send_message();
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
}
//void send_message()
//{
// Serial.println("AT"); 
// delay(1000);
// Serial.println("ATE0");
 //delay(1000);
// Serial.println("AT+CMGF=1");
// delay(1000);
 //Serial.print("AT+CMGS=\"9820285201\"\r\n");
 //delay(1000);
 //Serial.print("GAS LEAKED");
 //delay(10000);
// Serial.print(char(26));
 //delay(1000);
 //Serial.print("ATD9820258201;\n\r");
//}  
  
 
