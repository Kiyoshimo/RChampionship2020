#define EN 8 //步进电机使能端，低电平有效

#define X_DIR 5 //X轴步进电机方向控制

#define Y_DIR 6 //y轴步进电机方向控制

#define Z_DIR 7 //z轴步进电机方向控制

#define X_STP 2 //x轴步进控制

#define Y_STP 3 //y轴步进控制

#define Z_STP 4 //z轴步进控制

/*

//函数：step 功能：控制步进电机方向，步数。

//参数：dir 方向控制, dirPin对应步进电机的DIR引脚，stepperPin 对应步进电机的step引脚， steps 步进的步数

//无返回值

*/

void step(boolean dir, byte dirPin, byte stepperPin, int steps)

{

digitalWrite(dirPin, dir);

delay(50);

for (int i = 0; i < steps; i++) {

digitalWrite(stepperPin, HIGH);

delayMicroseconds(800);

digitalWrite(stepperPin, LOW);

delayMicroseconds(800);

}

}

void setup(){//将步进电机用到的IO管脚设置成输出

pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);

pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);

pinMode(Z_DIR, OUTPUT); pinMode(Z_STP, OUTPUT);

pinMode(EN, OUTPUT);

digitalWrite(EN, LOW);

}

void loop(){

step(false, X_DIR, X_STP, 200); //X轴电机反转1圈，200步为一圈
step(false, Y_DIR, Y_STP, 200); //y轴电机反转1圈，200步为一圈

step(false, Z_DIR, Z_STP, 200); //z轴电机反转1圈，200步为一圈

delay(1000);

step(true, X_DIR, X_STP, 200); //X轴电机正转1圈，200步为一圈

step(true, Y_DIR, Y_STP, 200); //y轴电机正转1圈，200步为一圈

step(true, Z_DIR, Z_STP, 200); //z轴电机正转1圈，200步为一圈

delay(1000);

}
