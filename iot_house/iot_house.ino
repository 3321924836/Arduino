#include <SoftwareSerial.h>

#define l_lr 2
#define l_k 3
#define l_p 4
#define l_br 5
#define l_toi 6
#define l_d 7
#define l_tea 8
#define relay 9

int status[10]={0,0,0,0,0,0,0,0,0,0};

SoftwareSerial bt(10,11);
void switchLight(int l);
void sendStatus();
void setup() {
  for(int i=2;i<=9;i++)
    pinMode(i,OUTPUT);
  bt.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if(bt.available()){
    int in=bt.read();
    switchLight(in);
    sendStatus();
  }
}

void switchLight(int l){
  if(status[l]==1){
    digitalWrite(l,LOW);
    status[l]=0;
  }
  else if(status[l]==0){
    digitalWrite(l,HIGH);
    status[l]=1;
  }
}

void sendStatus(){
  bt.print(char(48));
  for(int i=2;i<=9;i++){
  bt.print(char(status[i]+48));
  Serial.print(char(status[i]+48));
  }
  Serial.println();
}
