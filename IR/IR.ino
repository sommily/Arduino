#include <IRremote.h>
//the port of the arduino
int IR_OUT0 = 13;
int IR_OUT1 = 12;
int IR_OUT2 = 11;
int IR_OUT3 = 10;
int IR_OUT4 = 9;
int IR_OUT5 = 8;
int IR_OUT6 = 7;
int IR_OUT7 = 6;

int RECV_PIN = 5;//定义红外接收器的引脚为9

IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;

int i0 = 0;
int i1 = 0;
int i2 = 0;
int i3 = 0;
int i4 = 0;
int i5 = 0;
int i6 = 0;
int i7 = 0;
//the key value of the keyboard
long int key[8] = {16593103,16582903,16615543,16599223,16591063,16623703,16607383,16586983};
long int off_key = 16580863;
long int on_key ;
void setup()
{
  Serial.begin(9600);
  Serial.println("this's working!");
  irrecv.enableIRIn(); // 初始化红外接收器
  pinMode(IR_OUT0, OUTPUT);
  pinMode(IR_OUT1, OUTPUT);  
  pinMode(IR_OUT2, OUTPUT); 
  pinMode(IR_OUT3, OUTPUT);   
  pinMode(IR_OUT4, OUTPUT);
  pinMode(IR_OUT5, OUTPUT);  
  pinMode(IR_OUT6, OUTPUT); 
  pinMode(IR_OUT7, OUTPUT);  
}
 
void loop() 
{
  i0 = digitalRead(IR_OUT0);
  i1 = digitalRead(IR_OUT1);
  i2 = digitalRead(IR_OUT2);
  i3 = digitalRead(IR_OUT3);
  i4 = digitalRead(IR_OUT4);
  i5 = digitalRead(IR_OUT5);
  i6 = digitalRead(IR_OUT6);
  i7 = digitalRead(IR_OUT7);
  //receive the key
  if (irrecv.decode(&results)) 
  {
      Serial.print("receive the key:");
      Serial.println(results.value);
      if(results.value == key[0])
      {
         if(i0 == 0)
         {
           digitalWrite(IR_OUT0,1);
           Serial.println("IR_0 open");
         }
         else
         {
           digitalWrite(IR_OUT0,0);  
           Serial.println("IR_0 close");
         }
      }
     if(results.value == key[1])
      {
         if(i1 == 0)
         {
           digitalWrite(IR_OUT1,1);
           Serial.println("IR_1 open");
         }
         else
         {
           digitalWrite(IR_OUT1,0);  
           Serial.println("IR_1 close");
         } 
      } 
     if(results.value == key[2] )
      {
         if(i2 == 0)
         {
           digitalWrite(IR_OUT2,1);
           Serial.println("IR_2 open");
         }
         else
         {
           digitalWrite(IR_OUT2,0);  
           Serial.println("IR_2 close");
         }   
      }  
      if(results.value == key[3] )
      {
         if(i3 == 0)
         {
           digitalWrite(IR_OUT3,1);
           Serial.println("IR_3 open");
         }
         else
         {
           digitalWrite(IR_OUT3,0);  
           Serial.println("IR_3 close");
         } 
      }  
      if(results.value == key[4] )
      {
         if(i4 == 0)
         {
           digitalWrite(IR_OUT4,1);
           Serial.println("IR_4 open");
         }
         else
         {
           digitalWrite(IR_OUT4,0);  
           Serial.println("IR_4 close");
         } 
      }   
      if(results.value == key[5] )
      {
         if(i5 == 0)
         {
           digitalWrite(IR_OUT5,1);
           Serial.println("IR_5 open");
         }
         else
         {
           digitalWrite(IR_OUT5,0);  
           Serial.println("IR_5 close");
         } 
      }  
      if(results.value == key[6] )
      {
         if(i6 == 0)
         {
           digitalWrite(IR_OUT6,1);
           Serial.println("IR_6 open");
         }
         else
         {
           digitalWrite(IR_OUT6,0);  
           Serial.println("IR_6 close");
         } 
      }  
      if(results.value == key[7] )
      {
         if(i7 == 0)
         {
           digitalWrite(IR_OUT7,1);
           Serial.println("IR_7 open");
         }
         else
         {
           digitalWrite(IR_OUT7,0);  
           Serial.println("IR_7 close");
         } 
      }  
      if(results.value == off_key)
      {
        digitalWrite(IR_OUT0,0);
        digitalWrite(IR_OUT1,0);
        digitalWrite(IR_OUT2,0);
        digitalWrite(IR_OUT3,0);
        digitalWrite(IR_OUT4,0);
        digitalWrite(IR_OUT5,0);
        digitalWrite(IR_OUT6,0);
        digitalWrite(IR_OUT7,0);
        Serial.println("all port off");  
      }
      irrecv.resume(); // 接收下一个值
      delay(100);  
  }
}
