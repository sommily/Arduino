void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  char cd=Serial.read(); //从串口读取一个字符
  if(cd=='1')
    digitalWrite(13,HIGH);
  if(cd=='0')
    digitalWrite(13,LOW);
  delay(100);
}
