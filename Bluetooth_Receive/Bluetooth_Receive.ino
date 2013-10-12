/******************************************
遥控器程序——通过蓝牙发送速度
前进(w) 左转(l) 右转(r) 后退(s) 原地左转(a) 原地右转(d) 停止(t)
摇杆5 红3蓝4 模拟口0,1
数据格式：‘C’+ 命令字 + speed参数
电容为左边电机接口
Cw100
*******************************************/

 int INA = 4; //电机A正反转控制端
 int PWMA = 5; //电机A调速端
 int INB = 7; //电机B正反转控制端
 int PWMB = 6; //电机B调速端

 char  comtemp,old_comtemp = NULL;
 int  speedtemp,old_speedtemp = 0;

 void stopmoto()
 {
      digitalWrite(INA,LOW);
      digitalWrite(INB,LOW);
      analogWrite(PWMA,0);
      analogWrite(PWMB,0);
 }
 void initmoto()
 {
    int value;
    for(value = 250 ; value <= 255; value+=5)
    {
      digitalWrite(INA,HIGH);
      digitalWrite(INB,HIGH);
      analogWrite(PWMA,value);
      analogWrite(PWMB,value);
      delay(50);
    }
 }
  void forward(int _speed)
  {
      int value ;
      for(value = _speed ; value <= 255; value+=5)
      {
        digitalWrite(INA,HIGH);
        digitalWrite(INB,HIGH);
        analogWrite(PWMA,value);
        analogWrite(PWMB,value);
        delay(50);
      }
  }
  
  void back(int _speed)
  {
    digitalWrite(INA,LOW);
    digitalWrite(INB,LOW);
    analogWrite(PWMA,_speed);
    analogWrite(PWMB,_speed);
  }
  
  void turnleft(int _speed)
  {
    digitalWrite(INA,HIGH);
    digitalWrite(INB,HIGH);
    analogWrite(PWMA,_speed);
    analogWrite(PWMB,(_speed/2));
  }
  
  void turnright(int _speed)
  {
    digitalWrite(INA,HIGH);
    digitalWrite(INB,HIGH);
    analogWrite(PWMB,_speed);
    analogWrite(PWMA,(_speed/2));
  }
  
  void left(int _speed)
  {
    digitalWrite(INA,HIGH);
    digitalWrite(INB,LOW);
    analogWrite(PWMA,_speed);
    analogWrite(PWMB,_speed);  
  }
  
  void right(int _speed)
  {
    digitalWrite(INA,LOW);
    digitalWrite(INB,HIGH);
    analogWrite(PWMA,_speed);
    analogWrite(PWMB,_speed);  
  }
 void setup()
 {
    pinMode(INA,OUTPUT);
    pinMode(INB,OUTPUT);   
    //init moto shield
//    initmoto();
//    stopmoto();
    Serial.begin(9600);
 }
 void loop()
{
    if (Serial.available())
    {
       if ('C'==Serial.read())
       {
          while(!Serial.available());      //命令字
          comtemp= Serial.read();
          while(!Serial.available());      //speed参数
          speedtemp= Serial.read();
        }
    }
//    Serial.print(comtemp);
//    Serial.println(speedtemp);
    if(comtemp != old_comtemp || speedtemp != old_speedtemp)
    {
        Serial.println("change"); 
        Serial.print(comtemp);
        Serial.println(speedtemp);
        switch(comtemp)
        {
            case 'w':
                forward(speedtemp*5);        
                break;
            case 's':
                back(speedtemp*5);        
                break;
            case 'a':
                left(speedtemp*5);        
                break;
            case 'd':
                right(speedtemp*5);        
                break;
            case 'l':
                turnleft(speedtemp*5);        
                break;
            case 'r':
                turnright(speedtemp*5);        
                break;    
            case 't':
                 stopmoto();        
                 break;
            default:
                 stopmoto();
                 break;    
        }    
        old_comtemp = comtemp;
        old_speedtemp = speedtemp;
    }
}

