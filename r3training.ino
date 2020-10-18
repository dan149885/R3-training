/*
Daniel Vo
*/

const int Pin1 = 5;
const int Pin2 = 6;
const int Pin3 = 4;
const int Pin4 = 3;

const int S1 = A1;
const int S2 = A2;
const int S3 = A3;
const int S4 = A4;

int Potpin = A5;
int speed;

int s1state;
int s2state;
int s3state;
int s4state;

void setup() {
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
}

void loop() {
  s1state = digitalRead(S1);
  s2state = digitalRead(S2);
  s3state = digitalRead(S3);
  s4state = digitalRead(S4);

  //1
  if (s1state == 1 && s2state == 0 && s3state == 0 && s4state == 0){
    analogWrite(5, speed);
    analogWrite(6, LOW);
    analogWrite(4, LOW);
    analogWrite(3, speed);
  }
  //2
  else if (s1state == 0 && s2state == 1 && s3state == 0 && s4state == 0){ 
    analogWrite(5, LOW);
    analogWrite(6, speed);
    analogWrite(4, speed);
    analogWrite(3, LOW);
  }
  //3
  else if (s1state == 0 && s2state == 0 && s3state == 1 && s4state == 0){ 

    analogWrite(5, LOW);
    analogWrite(6, speed);
    analogWrite(4, LOW);
    analogWrite(3, speed);
  }
  //4
  else if (s1state == 0 && s2state == 0 && s3state == 0 && s4state == 1){
    analogWrite(5, speed);
    analogWrite(6, LOW);
    analogWrite(4, speed);
    analogWrite(3, LOW);
  }
  else {
  	analogWrite(5, LOW);
    analogWrite(6, LOW);
    analogWrite(4, LOW);
    analogWrite(3, LOW);
  }
  
  speed = analogRead(Potpin);
  speed = map(speed, 0, 1023, 0, 255);

}