#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor4(4);

int sensor_L = A0;
int sensor_R = A5;


void setup() {
  motor1.setSpeed(175);
  motor1.run(RELEASE);
  
  motor4.setSpeed(200);
  motor4.run(RELEASE);

  Serial.begin(9600);
  pinMode(sensor_L, INPUT);
  pinMode(sensor_R, INPUT);
}


void loop() {
  
  int valL = digitalRead(sensor_L);
  int valR = digitalRead(sensor_R);
 

  if (valL == 0 and valR == 0){
    motor1.run(FORWARD);
    motor4.run(FORWARD);

  }
  else if (valL == 1 and valR == 1){
    motor1.run(RELEASE);
    motor4.run(RELEASE);

  }
  else if (valL == 0 and valR == 1){
    
    motor4.run(RELEASE);
    motor1.run(FORWARD);

  }

  else if (valL == 1 and valR == 0){
    
    motor1.run(RELEASE);
    motor4.run(FORWARD);

  }
  
  
  
                                                 

}
