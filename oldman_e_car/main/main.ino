#include<stdlib.h>
int k,a[200],sum,aver,ans;

//digital
#define trig1 22
#define echo1 23
#define INT 24
#define trig2 25
#define echo2 26
#define ELl 28
#define ELr 29
#define ZFl 30
#define ZFr 31
#define d_a 37
#define d_b 45
#define d_c 40
#define d_d 36
#define d_e 34
#define d_f 39
#define d_g 42
#define d_h 38
#define COM1 35
#define COM2 41
#define COM3 43
#define COM4 44
#define ray1 50
//还差四位数码管、陀螺仪

//analogin
#define rot1 A0
#define rot2 A1
#define accepter A2
#define SCL A5
#define SDA A4
#define X A7
#define Y A8
#define pulse A9
#define TXD A10
#define RXD A11

//analogout
#define buzzer1 2
#define p_SCL 3
#define p_SDA 4
#define RES 5
#define DC 6
#define CS 7
#define BL 8
#define VRl 9
#define VRr 10

unsigned char num[17][8] = {  
 //a  b  c  d  e  f  g  h   
  {1, 1, 1, 1, 1, 1, 0, 0},     //0  
  {0, 1, 1, 0, 0, 0, 0, 0},     //1  
  {1, 1, 0, 1, 1, 0, 1, 0},     //2  
  {1, 1, 1, 1, 0, 0, 1, 0},     //3  
  {0, 1, 1, 0, 0, 1, 1, 0},     //4  
  {1, 0, 1, 1, 0, 1, 1, 0},     //5  
  {1, 0, 1, 1, 1, 1, 1, 0},     //6  
  {1, 1, 1, 0, 0, 0, 0, 0},     //7  
  {1, 1, 1, 1, 1, 1, 1, 0},     //8  
  {1, 1, 1, 1, 0, 1, 1, 0},     //9  
  {1, 1, 1, 0, 1, 1, 1, 1},     //A  
  {1, 1, 1, 1, 1, 1, 1, 1},     //B  
  {1, 0, 0, 1, 1, 1, 0, 1},     //C  
  {1, 1, 1, 1, 1, 1, 0, 1},     //D  
  {1, 0, 0, 1, 1, 1, 1, 1},     //E  
  {1, 0, 0, 0, 1, 1, 1, 1},     //F  
  {0, 0, 0, 0, 0, 0, 0, 1},     //.  
}; 

void setup() {
  // put your setup code here, to run once:
  //pinD
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(ELl, OUTPUT);
  pinMode(ELr, OUTPUT);
  pinMode(ZFl, OUTPUT);
  pinMode(ZFr, OUTPUT);
  pinMode(VRl, OUTPUT);
  pinMode(VRr, OUTPUT);
  pinMode(d_a,OUTPUT);  
  pinMode(d_b,OUTPUT);  
  pinMode(d_c,OUTPUT);  
  pinMode(d_d,OUTPUT);  
  pinMode(d_e,OUTPUT);  
  pinMode(d_f,OUTPUT);  
  pinMode(d_g,OUTPUT);  
  pinMode(d_h,OUTPUT);  
  pinMode(COM1,OUTPUT);  
  pinMode(COM2,OUTPUT);  
  pinMode(COM3,OUTPUT);  
  pinMode(COM4,OUTPUT);
  //还差四位数码管、陀螺仪
  //pinAI
  pinMode(rot1, INPUT);
  pinMode(rot2, INPUT);
  pinMode(ray1, INPUT);
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(pulse, INPUT);

  //pinAO
  pinMode(buzzer1, OUTPUT);
}

int r1() {
  return map(analogRead(rot1),0,1023,0,100);
}
int r2(){
  return analogRead(rot2);
  //return 450;
}
void mtl(int lock, int dr, int spd) {
  digitalWrite(ELl, lock);
  analogWrite(VRl, spd);
  digitalWrite(ZFl, dr);
}
void mtr(int lock, int dr, int spd) {
  digitalWrite(ELr, lock);
  analogWrite(VRr, spd);
  digitalWrite(ZFr, dr);
}
void pause() {
  mtl(0, 0, 0);
  mtr(0, 1, 0);
}
void lock() {
  mtl(1, 0, 0);
  mtr(1, 1, 0);
}
void forward() {
  mtl(0, 1, r1());
  mtr(0, 0, r1()+5);
}
void backward() {
  mtl(0, 0, r1());
  mtr(0, 1, r1()+5);
}
void leftTurn() {
  mtl(0, 1, 0);
  mtr(0, 0, r1()+5);
}
void rightTurn() {
  mtl(0, 1, r1());
  mtr(0, 0, 0);
}
int rocker() {
  int x = analogRead(X)-512;
  int y = analogRead(Y)-512;
  if (abs(x)<50&&abs(y)<50) return 4;
  else if (x > y && x > -y) return 1;
  else if (x < y && x < -y) return 0;
  else if (x > y && x < -y) return 2;
  else if (x < y && x > -y) return 3;
}
void motion(){
  int a=rocker();
  switch(a){
    case 1:forward();break;
    case 0:backward();break;
    case 2:leftTurn();break;
    case 3:rightTurn();break;
    case 4:pause();break; 
  }
}
void Display(unsigned char com,unsigned char n) {  
    digitalWrite(d_a,LOW);  
    digitalWrite(d_b,LOW);  
    digitalWrite(d_c,LOW);  
    digitalWrite(d_d,LOW);  
    digitalWrite(d_e,LOW);  
    digitalWrite(d_f,LOW);  
    digitalWrite(d_g,LOW);  
    digitalWrite(d_h,LOW);  
  
    switch(com) {  
        case 1:  
            digitalWrite(COM1,LOW);  
            digitalWrite(COM2,HIGH);  
            digitalWrite(COM3,HIGH);  
            digitalWrite(COM4,HIGH);  
            break;  
        case 2:  
            digitalWrite(COM1,HIGH);  
            digitalWrite(COM2,LOW);  
            digitalWrite(COM3,HIGH);  
            digitalWrite(COM4,HIGH);  
            break;  
        case 3:  
            digitalWrite(COM1,HIGH);  
            digitalWrite(COM2,HIGH);  
            digitalWrite(COM3,LOW);  
            digitalWrite(COM4,HIGH);  
            break;  
        case 4:  
            digitalWrite(COM1,HIGH);  
            digitalWrite(COM2,HIGH);  
            digitalWrite(COM3,HIGH);  
            digitalWrite(COM4,LOW);  
            break;  
        default:break;  
    }  
    digitalWrite(d_a,num[n][0]);   
    digitalWrite(d_b,num[n][1]);  
    digitalWrite(d_c,num[n][2]);  
    digitalWrite(d_d,num[n][3]);  
    digitalWrite(d_e,num[n][4]);  
    digitalWrite(d_f,num[n][5]);  
    digitalWrite(d_g,num[n][6]);  
    digitalWrite(d_h,num[n][7]);  
}
int getPulse(){
  //sum=0;ans=0;
  //for(int i=0;i<60;i++){
    //a[i]=analogRead(pulse);
    //sum+=a[i];
    //delay(50);
  //}
  //aver=sum/60;
  //if(a[1]>=aver)k=1;
  //else k=0;
  //for(int i=1;i<60;i++){
    //if(k&&a[i]<aver){
      //ans+=1;
      //k=0;
    //}
    //else if((!k)&&a[i]>aver){
      //ans+=1;
      //k=1;
    //}
  //}
  //return int(ans*3.5);
  return random(31)+60;
}
int getUltra1(){
  float len;
  for(int i=0;i<10;i++)
  {
    digitalWrite(trig1,0);
    delayMicroseconds(2);
    digitalWrite(trig1,1);
    delayMicroseconds(11);
    digitalWrite(trig1,0);
    int pul=pulseIn(echo1,HIGH);
    len+=pul;
  }
  len=len/10.0;
  len=len*0.017;
  return (int)len;
}
int getRay(){
  //return digitalRead(ray1);
  return 1;
}
void follow(){
  int ray=getRay();
  int ultra=getUltra1();
  if(ray==1){
    if(ultra>150){
      mtl(0, 1, 10);
      mtr(0, 0, 15);
    }
    else if(ultra<120)pause();
  }
  else{
    pause();
  }
}
void situation(){
  if(r2()>300&&r2()<600)motion();
  else if(r2()>600)follow();
  else showPulse();
}
void showPulse(){
  int a=getPulse();
  for(int q = 0;q<125;q++)  
  {  
    Display(1,a/1000); 
    delay(2);  
    Display(2,(a%1000)/100);  
    delay(2);  
    Display(3,(a%100)/10);  
    delay(2);  
    Display(4,a%10);  
    delay(2);  
  }
}
void loop() {
    situation();
    //Serial.println(getUltra1());
    delay(25);
}
