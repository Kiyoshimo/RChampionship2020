#include <Servo.h>

Servo myservo;  // 定义Servo对象来控制
int ag_ser = 0;    // 角度存储变量

void setup() {
  myservo.attach(2);  // 控制线连接数字2
}

void loop() {
    ag_ser=75;
    myservo.write(ag_ser);              // 舵机角度写入
    delay(500);
    ag_ser=45 ;
    myservo.write(ag_ser);              // 舵机角度写入
    delay(500);
  
}
