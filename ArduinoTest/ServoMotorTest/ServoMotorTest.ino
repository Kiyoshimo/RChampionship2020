#include <Servo.h>

Servo myservo;  // 定义Servo对象来控制
int ag_ser = 0;    // 角度存储变量

void setup() {
  myservo.attach(9);  // 控制线连接数字9
}

void loop() {
    ag_ser=180;
    myservo.write(ag_ser);              // 舵机角度写入
    delay(1000);
    ag_ser=0;
    myservo.write(ag_ser);              // 舵机角度写入
    delay(1000);
  
}
