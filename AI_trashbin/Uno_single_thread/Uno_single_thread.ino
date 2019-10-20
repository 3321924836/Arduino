#include <ld3320.h>
#include <Servo.h>
#define s1 5
#define s2 6
#define s3 7
#define s4 8
#define t1 30
#define e1 31
#define t2 32
#define e2 33
#define t3 34
#define e3 35
#define t4 36
#define e4 37
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
VoiceRecognition Voice;
void setup() {
  servo1.attach(s1);
  servo2.attach(s2);
  servo3.attach(s3);
  servo4.attach(s4);
  pinMode(t1, OUTPUT);
  pinMode(e1, INPUT);
  pinMode(t2, OUTPUT);
  pinMode(e2, INPUT);
  pinMode(t3, OUTPUT);
  pinMode(e3, INPUT);
  pinMode(t4, OUTPUT);
  pinMode(e4, INPUT);
  servo1.write(140);
  servo2.write(140);
  servo3.write(140);
  servo4.write(140);
  Voice.init();
  Voice.addCommand("qi ta", 0);
  Voice.addCommand("ke hui shou", 1);
  Voice.addCommand("chu yu", 2);
  Voice.addCommand("you hai", 3);
  Voice.start();
}
void judgeUlt1() {
  int cm = 0, duration;
  for (int i = 1; i <= 10; i++) {
    digitalWrite(t1, LOW);
    delayMicroseconds(2);
    digitalWrite(t1, HIGH);
    delayMicroseconds(11);
    digitalWrite(t1, LOW);
    duration = pulseIn(e1, HIGH);
    cm += (duration / 2) / 29.1;
  }
  cm /= 3;
  if (cm < 15) {
    servo1.write(95);
    delay(2000);
    servo1.write(140);
    delay(2000);
  }
}

void judgeUlt2() {
  int cm = 0, duration;
  for (int i = 1; i <= 10; i++) {
    digitalWrite(t2, LOW);
    delayMicroseconds(2);
    digitalWrite(t2, HIGH);
    delayMicroseconds(11);
    digitalWrite(t2, LOW);
    duration = pulseIn(e2, HIGH);
    cm += (duration / 2) / 29.1;
  }
  cm /= 3;
  if (cm < 15) {
    servo2.write(95);
    delay(2000);
    servo2.write(140);
    delay(2000);
  }
}

void judgeUlt3() {
  int cm = 0, duration;
  for (int i = 1; i <= 10; i++) {
    digitalWrite(t3, LOW);
    delayMicroseconds(2);
    digitalWrite(t3, HIGH);
    delayMicroseconds(11);
    digitalWrite(t3, LOW);
    duration = pulseIn(e3, HIGH);
    cm += (duration / 2) / 29.1;
  }
  cm /= 3;
  if (cm < 15) {
    servo3.write(95);
    delay(2000);
    servo3.write(140);
    delay(2000);
  }
}

void judgeUlt4() {
  int cm = 0, duration;
  for (int i = 1; i <= 10; i++) {
    digitalWrite(t4, LOW);
    delayMicroseconds(2);
    digitalWrite(t4, HIGH);
    delayMicroseconds(11);
    digitalWrite(t4, LOW);
    duration = pulseIn(e4, HIGH);
    cm += (duration / 2) / 29.1;
  }
  cm /= 3;
  if (cm < 15) {
    servo4.write(95);
    delay(2000);
    servo4.write(140);
    delay(2000);
  }
}
void judgeVoi(int v) {
  switch (v) {
    case 0:
      servo1.write(95);
      delay(2000);
      servo1.write(140);
      delay(2000);
      break;
    case 1:
      servo2.write(95);
      delay(2000);
      servo2.write(140);
      delay(2000);
      break;
    case 2:
      servo3.write(95);
      delay(2000);
      servo3.write(140);
      delay(2000);
      break;
    case 3:
      servo4.write(95);
      delay(2000);
      servo4.write(140);
      delay(2000);
      break;
  }
}
void loop() {
  int voice = Voice.read();
  switch (voice) {
    case -1:
      judgeUlt1();
      judgeUlt2();
      judgeUlt3();
      judgeUlt4();
      break;
    default:
      judgeVoi(voice);
  }
}
