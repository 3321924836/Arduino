#include<SCoop.h>
#define t1 2
#define e1 3
#define t2 4
#define e2 5
#define in1 6
#define in2 7
#define s1 8
#define s2 9

defineTask(BT1);
void BT1::setup() {
  Serial.begin(9600);
  pinMode(t1, OUTPUT);
  pinMode(e1, INPUT);
  pinMode(s1, OUTPUT);
  pinMode(in1, INPUT); 
}
void BT1::loop() {
  int duration, cm = 0;
  if (digitalRead(in1)==0) {
    for (int i = 1; i <= 3; i++) {
      digitalWrite(t1, LOW);
      sleep(1);
      digitalWrite(t1, HIGH);
      sleep(1);
      digitalWrite(t1, LOW);
      duration = pulseIn(e1, HIGH);
      cm += (duration / 2) / 29.1;
    }
    cm /= 3;
    if (cm < 20) {
      //angle = 0;
      for (int i = 0; i <= 50; i++)
      {
        digitalWrite(s1, HIGH);
        sleep(1);
        digitalWrite(s1, LOW);
        sleep(19);
      }
      sleep(2000);
      for (int i = 0; i <= 50; i++)
      {
        digitalWrite(s1, HIGH);
        sleep(2);
        digitalWrite(s1, LOW);
        sleep(18);
      }
    }
  }
  else{
    for (int i = 0; i <= 10; i++)
    {
      digitalWrite(s1, HIGH);
      sleep(1);
      digitalWrite(s1, LOW);
      sleep(19);
    }
    sleep(2000);
    for (int i = 0; i <= 10; i++)
    {
      digitalWrite(s1, HIGH);
      sleep(2);
      digitalWrite(s1, LOW);
      sleep(18);
    }
  }
  sleep(50);
}

defineTask(BT2);
void BT2::setup() {
  pinMode(t2, OUTPUT);
  pinMode(e2, INPUT);
  pinMode(s2, OUTPUT);
  pinMode(in2, INPUT);
}
void BT2::loop() {
  int duration, cm = 0;
  if (digitalRead(in2) ==0) {
    for (int i = 1; i <= 3; i++) {
      digitalWrite(t2, LOW);
      sleep(1);
      digitalWrite(t2, HIGH);
      sleep(1);
      digitalWrite(t2, LOW);
      duration = pulseIn(e2, HIGH);
      cm += (duration / 2) / 29.1;
    }
    cm /= 3;
    if (cm < 20) {
      for (int i = 0; i <= 50; i++)
      {
        digitalWrite(s2, HIGH);
        sleep(1);
        digitalWrite(s2, LOW);
        sleep(19);
      }
      sleep(2000);
      for (int i = 0; i <= 50; i++)
      {
        digitalWrite(s2, HIGH);
        sleep(2);
        digitalWrite(s2, LOW);
        sleep(18);
      }
    }
  }
  else{
    for (int i = 0; i <= 10; i++)
    {
      digitalWrite(s2, HIGH);
      sleep(1);
      digitalWrite(s2, LOW);
      sleep(19);
    }
    sleep(2000);
    for (int i = 0; i <= 10; i++)
    {
      digitalWrite(s2, HIGH);
      sleep(2);
      digitalWrite(s2, LOW);
      sleep(18);
    }
  }
  sleep(50);
}

void setup() {
  mySCoop.start();
}
void loop() {
  yield();
}
