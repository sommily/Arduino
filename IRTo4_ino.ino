#include <IRremote.h>
 
int RECV_PIN = 9;//定义红外接收器的引脚为10

IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;

int i1 = 0;
int i2 = 0;
int i3 = 0;
int i4 = 0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // 初始化红外接收器
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);  
  pinMode(12, OUTPUT); 
  pinMode(13, OUTPUT);  
}
 
void loop() 
{
  i1 = digitalRead(11);
  i2 = digitalRead(12);
  i3 = digitalRead(13);
  i4 = digitalRead(10);
  if (irrecv.decode(&results)) 
  {
      Serial.println(results.value);
      if(results.value == 16582903 )
      {
         if(i1 == 0)
           digitalWrite(11,1);
         else
           digitalWrite(11,0);  
      }
     if(results.value == 16615543 )
      {
         if(i2 == 0)
           digitalWrite(12,1);
         else
           digitalWrite(12,0);  
      } 
     if(results.value == 16599223 )
      {
         if(i3 == 0)
           digitalWrite(13,1);
         else
           digitalWrite(13,0);  
      }  
      if(results.value == 16591063 )
      {
         if(i4 == 0)
           digitalWrite(10,1);
         else
           digitalWrite(10,0);  
      }  
      irrecv.resume(); // 接收下一个值
      delay(100); 
  }
}
