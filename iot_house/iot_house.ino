#include <SoftwareSerial.h>

#define l_lr1 2
#define l_lr2 3
#define l_p 4
#define l_br 5
#define l_t 6
#define l_d 7

int status[8]={0,0,0,0,0,0,0,0};

SoftwareSerial bt(10,11);
void switchLight(int l);
void sendStatus();
void setup() {
  pinMode(l_lr1,OUTPUT);
  pinMode(l_lr2,OUTPUT);
  pinMode(l_p,OUTPUT);
  pinMode(l_br,OUTPUT);
  pinMode(l_t,OUTPUT);
  pinMode(l_d,OUTPUT);
  bt.begin(9600);
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
  for(int i=2;i<=7;i++){
  bt.print(char(status[i]+48));
  }
}
