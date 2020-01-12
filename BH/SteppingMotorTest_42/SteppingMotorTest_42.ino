#define EN 8    //步进电机使能端，低电平有效
#define X_DIR 5 //X轴 步进电机方向控制
#define Y_DIR 6 //y轴 步进电机方向控制
#define Z_DIR 7 //z轴 步进电机方向控制
#define X_STP 2 //x轴 步进控制
#define Y_STP 3 //y轴 步进控制
#define Z_STP 4 //z轴 步进控制
//函数：step    功能：控制步进电机方向，步数。
//参数：dir 方向控制, dirPin对应步进电机的DIR引脚，
//stepperPin 对应步进电机的step引脚， steps 步进的步数
//无返回值

//壁画参数。两台步进间距kx=585mm，步进一圈（200步）走v_1round=31.43mm
//Y电机F上T下，X电机T上F下
#define num_kx 585
#define num_oneround 31

void step(boolean dir, byte dirPin, byte stepperPin, int steps)
{
  digitalWrite(dirPin, dir);
  delay(50);
  for (int i = 0; i < steps; i++)
  {
    digitalWrite(Y_STP, HIGH);
    digitalWrite(X_STP, HIGH);
    delayMicroseconds(8000);
    digitalWrite(Y_STP, LOW);
    digitalWrite(X_STP, LOW);    
    delayMicroseconds(8000);
  }
}
void go(int x1,int y1,int x2,int y2)//从x1y1到x2y2
{
  int d_x=x1-x2;//正数左行负数右行
  int d_y=y1-y2;//正数上行负数下行

}
void setup()
{ //将步进电机用到的IO管脚设置成输出
  pinMode(X_DIR, OUTPUT);
  pinMode(X_STP, OUTPUT);
  pinMode(Y_DIR, OUTPUT);
  pinMode(Y_STP, OUTPUT);
  pinMode(Z_DIR, OUTPUT);
  pinMode(Z_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
}
void loop()
{

  step(false, Y_DIR, Y_STP, 200); //y轴电机 反转1圈，200步为一圈
  step(true, X_DIR, X_STP, 200);  //y轴电机 反转1圈，200步为一圈
  delay(1000);
  step(false, Y_DIR, Y_STP, 200); //y轴电机 反转1圈，200步为一圈
  step(true, X_DIR, X_STP, 200);  //y轴电机 反转1圈，200步为一圈
  delay(1000);
  step(false, Y_DIR, Y_STP, 200); //y轴电机 反转1圈，200步为一圈
  step(true, X_DIR, X_STP, 200);  //y轴电机 反转1圈，200步为一圈
  delay(1000);
  step(false, Y_DIR, Y_STP, 200); //y轴电机 反转1圈，200步为一圈
  step(true, X_DIR, X_STP, 200);  //y轴电机 反转1圈，200步为一圈
  delay(1000);
}