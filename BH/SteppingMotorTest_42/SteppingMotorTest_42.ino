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
    delayMicroseconds(800);
    digitalWrite(Y_STP, LOW);
    digitalWrite(X_STP, LOW);
    delayMicroseconds(800);
  }
}
void go(int x1, int y1, int x2, int y2) //从x1y1到x2y2
{
  int d_x = x1 - x2;                        //正数左行负数右行，单位mm
  int d_y = y1 - y2;                        //正数上行负数下行，单位mm
  int d_move = sqrt(d_x * d_x + d_y * d_y); //移动距离，单位mm
  const int speed = 30;                     //设定：1s移动30mm，对1s进行拆分，制作pwm,一个周期1000ms
  int t_delay = 1000000 * d_move / speed;   //延迟时间，单位microsecond
  int onegopwm = d_move * 1000;             //例如：走30mm，用时1s，拆成1000pmw，走60mm用时2s拆成2000pmw

  int step_dx = 200;
  int step_dy = 200;

  digitalWrite(Y_STP, true);
  digitalWrite(X_STP, true);
  delay(50);
  for (int i1 = 0; i1 < onegopwm; i1++) //一周期约1000ms
  {
    if (step_dx != 0)
    {
      if (onegopwm % step_dx == 0)
        digitalWrite(X_STP, HIGH);
    }
    if (step_dy != 0)
    {
      if (onegopwm % step_dy == 0)
        digitalWrite(Y_STP, HIGH);
    }

    delayMicroseconds(5000);
    if (step_dx != 0)
    {
      if (onegopwm % step_dx == 0)
        digitalWrite(X_STP, HIGH);
    }
    if (step_dy != 0)
    {
      if (onegopwm % step_dy == 0)
        digitalWrite(Y_STP, HIGH);
    }
    delayMicroseconds(5000);
  }
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

  go(0, 0, 0, 30);
  delay(5000);

  step(false, Y_DIR, Y_STP, 200); //y轴电机 反转1圈，200步为一圈
}