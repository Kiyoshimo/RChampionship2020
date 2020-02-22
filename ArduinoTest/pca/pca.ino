#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// 默认地址 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define angle_load  210 //装填角度
#define angle_fire  320 //释放角度

void setup() {
  //串口初始化
  Serial.begin(9600);
  Serial.println("BOOT！");
  
  //舵机驱动芯片初始化
  pwm.begin();
  pwm.setPWMFreq(50);  // 50HZ更新频率，相当于20ms的周期
  delay(10);
  
}

//丢下珠子，no为颜色（0-3）
void BallDrop(int no){
   pwm.setPWM(no, 0, angle_load);
   delay(500);
   pwm.setPWM(no, 0, angle_fire);
   delay(500);
  }



  
void loop() {
  BallDrop(1);
  BallDrop(2);
  BallDrop(3);
}
