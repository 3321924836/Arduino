#include <ld3320.h>
#define s1 5
#define s2 6
#define s3 7
#define s4 8
VoiceRecognition Voice;
void setup() {
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(s4, OUTPUT);
  digitalWrite(s1, 0);
  digitalWrite(s2, 0);
  digitalWrite(s3, 0);
  digitalWrite(s4, 0);
  Voice.init();
  Voice.addCommand("qi ta", 0);
  Voice.addCommand("ke hui shou", 1);
  Voice.addCommand("chu yu", 2);
  Voice.addCommand("you hai", 3);
  Voice.start();
}

void loop() {
  switch (Voice.read()) {
    case 0:
      digitalWrite(s1, 1);
      delay(250);
      digitalWrite(s1, 0);
      break;
    case 1:
      digitalWrite(s2, 1);
      delay(250);
      digitalWrite(s2, 0);
      break;
    case 2:
      digitalWrite(s3, 1);
      delay(250);
      digitalWrite(s3, 0);
      break;
    case 3:
      digitalWrite(s4, 1);
      delay(250);
      digitalWrite(s4, 0);
      break;
  }
}
