int k,a[200],sum,aver,ans;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sum=0;ans=0;
  for(int i=0;i<60;i++){
    a[i]=analogRead(A0);
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
  Serial.println(ans*4);
}
