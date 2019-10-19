int k,a[200],sum,aver,ans;

//digital
#define ultrig1 22
#define ulecho1 23
#define ultrig2 24
#define ulecho2 25
#define ultrig3 26
#define ulecho3 27
#define ELl 28
#define ELr 29
#define ZFl 30
#define ZFr 31
#define VRl 32
#define VRr 33
#define d_a 34
#define d_b 35
#define d_c 36
#define d_d 37
#define d_e 38
#define d_f 39
#define d_g 40
#define d_h 41
#define COM1 42
#define COM2 43
#define COM3 44
#define COM4 45
//还差四位数码管、陀螺仪

//analogin
#define rot1 A0
#define rot2 A1
#define rot3 A2
#define vib1 A3
#define vib2 A4
#define ray1 A5
#define ray2 A6
#define X A7
#define Y A8
#define pulse A9

//analogout
#define buzzer1 2
#define buzzer2 3

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
  pinMode(ultrig1, OUTPUT);
  pinMode(ulecho1, INPUT);
  pinMode(ultrig2, OUTPUT);
  pinMode(ulecho2, INPUT);
  pinMode(ultrig3, OUTPUT);
  pinMode(ulecho3, INPUT);
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
  pinMode(rot3, INPUT);
  pinMode(vib1, INPUT);
  pinMode(vib2, INPUT);
  pinMode(ray1, INPUT);
  pinMode(ray2, INPUT);
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(pulse, INPUT);

  //pinAO
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  Serial.begin(9600);
}

int r1() {
  return analogRead(rot1);
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
  mtr(0, 0, r1());
}
void backward() {
  mtl(0, 0, r1());
  mtr(0, 1, r1());
}
void leftTurn() {
  mtl(0, 1, 0);
  mtr(0, 0, r1());
}
void rightTurn() {
  mtl(0, 1, r1());
  mtr(0, 0, 0);
}
int rocker() {
  int x = analogRead(X)-512;
  int y = analogRead(Y)-512;
  //if(abs(x)<20&&abs(y)<20) return 4;
  if (x > y && x > -y) return 1;
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
    //case 4:pause();break;
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
  sum=0;ans=0;
  for(int i=0;i<60;i++){
    a[i]=analogRead(pulse);
    sum+=a[i];
    delay(50);
  }
  aver=sum/60;
  if(a[1]>=aver)k=1;
  else k=0;
  for(int i=1;i<60;i++){
    if(k&&a[i]<aver){
      ans+=1;
      k=0;
    }
    else if((!k)&&a[i]>aver){
      ans+=1;
      k=1;
    }
  }
  return int(ans*3.5);
}
void loop() {
  for(;;){
    int p=getPulse();
    int p1=p/1000;
    int p2=(p%1000)/100;
    int p3=(p%100)/10;
    int p4=(p%10);
    for(int q = 0;q<125;q++)  
    {  
      Display(1,p1);
      delay(2);  
          Display(2,p2);  
          delay(2);  
          Display(3,p3);  
          delay(2);  
          Display(4,p4);  
          delay(2);  
      }  
  }
  
  
}
