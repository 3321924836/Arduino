#define d_a 2  
#define d_b 3  
#define d_c 4  
#define d_d 5    
#define d_e 6  
#define d_f 7  
#define d_g 8  
#define d_h 9  
  
#define COM1 10  
#define COM2 11  
#define COM3 12  
#define COM4 13  
  
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
  
void setup()  
{  
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
}  
  
void loop()  
{ 
  for(int l = 0;l < 10;l++ )  
  {  
    for(int k = 0; k < 10;k++)  
    {  
      for(int j = 0; j < 10; j++)  
      {  
        for(int i = 0;i < 10;i++)  
        {  
          //1000/8=125  
          for(int q = 0;q<125;q++)  
          {  
            Display(1,l); 
            delay(2);  
            Display(2,k);  
            delay(2);  
            Display(3,j);  
            delay(2);  
            Display(4,i);  
            delay(2);  
          }  
        }  
      }  
    }  
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
