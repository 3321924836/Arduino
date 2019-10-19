#include <SPI.h>
#include <RFID.h>
#include<Servo.h>

/*
   舵机1  8
   舵机2  9
   RST  橘色 10
   MOSI 绿色 11
   MISO 蓝色 12
   SCK  黄色 13
   SDA  白色 A0,A1
*/

Servo servo1;
Servo servo2;

RFID r1(A0, 10);
RFID r2(A1, 10);

void setup()
{
  servo1.attach(8);
  servo2.attach(9);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  SPI.begin();
  r1.init();
  r2.init();
}

void loop()
{
  //找卡
  if (r1.isCard()) {
    for (int i = 0; i <= 100; i++) {
      servo1.write(i);
      delay(0.1);
    }
    delay(1000);
    for (int i = 100; i >= 0; i--) {
      servo1.write(i);
      delay(0.1);
    }
    //选卡，可返回卡容量（锁定卡片，防止多数读取），去掉本行将连续读卡
    r1.selectTag(r1.serNum);
    r1.halt();
  }
  //找卡
  if (r1.isCard()) {
    for (int i = 0; i <= 100; i++) {
      servo1.write(i);
      delay(0.1);
    }
    delay(1000);
    for (int i = 100; i >= 0; i--) {
      servo1.write(i);
      delay(0.1);
    }
    //选卡，可返回卡容量（锁定卡片，防止多数读取），去掉本行将连续读卡
    r1.selectTag(r1.serNum);
    r1.halt();
  }
  delay(1000);
}
