int l1=3;//连接IN1
int l2=5;//连接IN2
int r1=6;//连接IN3
int r2=9;//连接IN4
int green=2;//绿灯
int red=4;//红灯
int yellow=7;//黄灯
int beep=10;//蜂鸣器
int k1=0,k2=0;
void setup()
{
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(beep,OUTPUT);
  pinMode(13,OUTPUT);
}
void up()
{
  analogWrite(l1,200);
  analogWrite(l2,0);
  analogWrite(r2,200);
  analogWrite(r1,0);
  digitalWrite(green,1);
  delay(5000);
  digitalWrite(green,0);
  analogWrite(l1,0);
  analogWrite(r2,0);
}
void down()
{
  analogWrite(l2,200);
  analogWrite(l1,0);
  analogWrite(r1,200);
  analogWrite(r2,0);
  delay(500);
  for(int i=0;i<5;i++)
  {
    digitalWrite(red,1);
    digitalWrite(13,1);
    tone(beep,320);
    delay(500);
    digitalWrite(red,0);
    digitalWrite(13,0);
  }
  analogWrite(l2,0);
  analogWrite(r1,0);
}
void loop()
{
  if(k1+k2==0)
  {
    up();
    k1=1;
  }
  else if(k1+k2==1)
  {
    down();
    k2=1;
  }
  else if(k1+k2==2)
  {
    digitalWrite(yellow,1);
  }
}
