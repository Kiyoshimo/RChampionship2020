#define EN        8       //步进电机使能端，低电平有效

#define Y_DIR     6       //y轴 步进电机方向控制
#define Y_STP     3       //y轴 步进控制
#define Y_WJ      1       //y轴 步进电机精度

#define X_WJ      1       //y轴 步进电机精度

/*
 * （跳线： 000全细分1 001细分1/2  010细分1/4  110细分1/8  111细分1/16）
 * (全细分200步一圈)
 */
 
/*
//函数：step    功能：控制步进电机方向，步数。
//参数：dir 方向控制, dirPin对应步进电机的DIR引脚，stepperPin 对应步进电机的step引脚， steps 步进的步数
//无返回值
*/

void step(boolean dir, byte dirPin, byte stepperPin, int steps)
{
  digitalWrite(dirPin, dir);
  delay(50);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepperPin, HIGH);
    delayMicroseconds(1200);  
    digitalWrite(stepperPin, LOW);
    delayMicroseconds(1200);  
  }
}

void setup(){//将步进电机用到的IO管脚设置成输出
  //pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);
  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);   
  //pinMode(Z_DIR, OUTPUT); pinMode(Z_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
}

void loop(){

  step(false, Y_DIR, Y_STP, 200); //y轴电机 反转1圈，200步为1圈
  delay(100);

}
