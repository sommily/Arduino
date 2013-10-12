void setup()
{
  Serial.begin(9600);//设定波特率为9600
}
 
void loop()
{
  delay(10000);     
  Serial.print('0');//通过串口发送一个’0’字符
  delay(1000);
  Serial.print('1');
}
