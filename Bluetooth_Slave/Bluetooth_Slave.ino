/* 
使用AT指令设置波特率和主从机模式，波特率:9600，配对密码8888，从机模式。 
*/ 
#define AT 2                   //此为Zduino Shield V2.0传感器扩展板专用 
#define LED 13 

void setup() 
{ 
    pinMode(LED,OUTPUT); 
    pinMode(AT,OUTPUT);     //此为Zduino Shield V2.0传感器扩展板专用 
    digitalWrite(AT,HIGH);     //此为Zduino Shield V2.0传感器扩展板专用 
    Serial.begin(9600);         //AT 模式下蓝牙模块通信波特率 
    delay(100);  
    Serial.println("AT");  
    delay(100);  
    Serial.println("AT+NAME=Bluetooth-Slave"); //模块名：Master为主机，Slave为从机 
    delay(100);  
    Serial.println("AT+ROLE=0");       //设置主从模式：0从机，1主机，2回环 
    delay(100);  
    Serial.println("AT+CMODE=1");   //设置连接模式为任意蓝牙地址连接模式 
    delay(100); 
    Serial.println("AT+PSWD=1234");       //设置配对密码，1234 
    delay(100);  
    Serial.println("AT+UART=9600,1,0");     //设置波特率9600，停止位1，校验位无 
    delay(100);   
    Serial.println("AT+RMAAD");       //清空配对列表 
} 
 
void loop() 
{ 
    digitalWrite(LED, HIGH);  
    delay(500);  
    digitalWrite(LED, LOW);  
    delay(500);  
} 
 
