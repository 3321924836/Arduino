int r = 2, y = 3, g = 4, bre = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(bre, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(r,1);
delay(10000);
digitalWrite(r,0);
digitalWrite(y,1);
delay(3000);
digitalWrite(y,0);
digitalWrite(g,1);
delay(5000);
digitalWrite(g,0);
for(int i=0;i<=255;i+=20)
{
  analogWrite(bre,i);
  delay(50);
}
delay(3000);
}
