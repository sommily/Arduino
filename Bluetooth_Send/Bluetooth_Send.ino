/******************************************
遥控器程序——通过蓝牙发送速度
前进(w) 左转(l) 右转(r) 后退(s) 原地左转(a) 原地右转(d) 停止(t)
摇杆5 红3蓝4 模拟口0,1

*******************************************/

int valueHori;          //左右方向模拟量数值
int valueVerti;         //上下方向模拟量数值
char comTemp;
char oldComTemp;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  valueHori = analogRead(1);
  valueVerti = analogRead(0);
  if (valueVerti<230)           //摇杆向上时
    {
      if (valueHori<230)          //摇杆向右时
      {
          comTemp='r';            //右转
      }
      else if (valueHori>800)          //摇杆向左时
      {
          comTemp='l';            //左转
      }
      else
      {
          comTemp='w';            //前进
      }
    }
    else if (valueVerti>800)          //摇杆向下时
    {
      comTemp='s';
    }
    else                           //摇杆在中间位置
    {
      if (valueHori<230)          //摇杆向右时
      {
          comTemp='d';            //原地右转
      }
      else if (valueHori>800)          //摇杆向左时
      {
          comTemp='a';            //原地左转
      }
      else 
      {
          comTemp='t';
      }
    }
    //都不为零时发送命令
  if(!((comTemp == 't') && (oldComTemp== 't')))
  {
    Serial.print('C');             //发送命令起始标记
    Serial.print((comTemp));
    if(comTemp=='w')
    {
      Serial.println((255-(valueVerti/2)));
      //通过公示变化为速度参考值
    }
    else if(comTemp=='s')
    {
      Serial.println(((valueVerti-512)/2));
      //通过公示变化为速度参考值
    }
    else if((comTemp=='l')||(comTemp=='a'))
    {
      Serial.println(((valueHori-512)/2));
      //通过公示变化为速度参考值
    }
    else if((comTemp=='r')||(comTemp=='d'))
    {
      Serial.println((255-(valueHori/2)));
      //通过公示变化为速度参考值
    }
    else
    { Serial.println((0));}
    oldComTemp= comTemp;
  }  
  delay(20);
}

