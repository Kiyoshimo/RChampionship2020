#include <Servo.h>

//脚位定义
#define EN 8        //步进电机使能端，低电平有效
#define Y_DIR 6     //y轴 步进电机方向控制脚位
#define Y_STP 3     //y轴 步进控制脚位
#define Z_WJ 2      //z轴 伺服马达输出脚位
#define Z_LED 1     //z轴 测试用led输出脚位
#define I_I 4       //归零光感测器输入脚位
#define Z_SWITCH A0 //开关输入脚位
//参数
const int Num_round = 1200; // 走一圈步进电机的步数200*6*1 （跳线： 000全细分1 001细分1/2  010细分1/4  110细分1/8  111细分1/16）(全细分200步一圈)
int ag_ser = 45;            // Servo角度存储变量
int ag_down = 75;           // Servo下降角度
int ag_up = 45;             // Servo上升角度

String mes;        //串口string
int num_pin = 6;   //针的数量，默认6
int num_wire = 16; //绕线的次数，默认14

int list_wire[14] = {0, 2, 4, 0, 5, 3, 1, 5, 0, 1, 2, 3, 4, 5};
//int list_wire[16] = {0, 1, 0, 1, 2, 0, 1, 3, 0, 1, 4, 0, 1, 5, 0, 1};

//int list_wire[500];           //线的list, Max5000
int flag_pattern = 1;         //图形样式
boolean light_senser = false; //光感测器度数，有1无0

Servo myservo; // 定义Servo对象来控制

void setup()
{
  //将步进电机用到的IO管脚设置成输出
  pinMode(Y_DIR, OUTPUT);
  pinMode(Y_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
  //伺服电机设置
  myservo.attach(Z_WJ);     // 控制线连接
  pinMode(I_I, INPUT);      //将归零光感器用到的IO管脚设置成输入
  pinMode(Z_LED, OUTPUT);   //测试用led
  pinMode(Z_SWITCH, INPUT); //
  Serial.begin(9600);       //设置串口波特率9600
}

//步进控制：dir 方向控制(f逆时针t顺时针), dirPin对应步进电机的DIR引脚，stepperPin 对应步进电机的step引脚， steps 步进的步数
void stepper(boolean dir, byte dirPin, byte stepperPin, int steps)
{
  digitalWrite(dirPin, dir);
  delay(50);
  for (int i = 0; i < steps; i++)
  {
    digitalWrite(stepperPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepperPin, LOW);
    delayMicroseconds(2000);
  }
}
void button()
{
  Serial.println("PUSH A0 to start");
  while (1)
  {
    int vvv = analogRead(Z_SWITCH);
    //Serial.println(vvv);
    if (vvv >= 650)
    {
      Serial.println("Turn_On");
      break;
    }
  }
}
void loop()
{
  myservo.write(ag_up); // 初始化舵机down角度写入
  button();
  //测试数据
  /*
  if (flag_pattern == 1)
  {
    num_pin = 6;
    num_wire = 13;
    int list_wire_test[15] = {0, 2, 4, 0, 1, 3, 5, 1, 2, 3, 4, 5, 0};

    for (int i = 0; i < num_pin; i++)
    {
      list_wire[i] = list_wire_test[i];
    }
    flag_pattern = 0;
    num_pin = 0;
  }
  else if (flag_pattern == 2)
  {
    num_pin = 6;
    num_wire = 15;
    int list_wire_test[15] = {0, 1, 5, 0, 1, 4, 0, 1, 3, 0, 1, 2, 0, 1, 0};

    for (int i = 0; i < num_pin; i++)
    {
      list_wire[i] = list_wire_test[i];
    }
    flag_pattern = 0;
    num_pin = 0;
  }

  else if (flag_pattern == 3)
  {
    num_pin = 60;
    //num_wire = ? ? ;  //算完是15
    int p_f3_i1 = 0; //第一个点
    int p_f3_i2 = 0; //第2个点
    int cont_f3 = 0; //计数器
    int list_wire_test[15];
    while (1)
    {
      p_f3_i1++;
      p_f3_i2 = p_f3_i1 * p_f3_i1;
      if (p_f3_i2 > num_pin)
      {
        break;
      }
      else
      {
        list_wire_test[cont_f3] = p_f3_i1;
        cont_f3++;
        list_wire_test[cont_f3] = p_f3_i1;
        cont_f3++;
      }
    }
    num_wire = cont_f3 + 1;

    for (int i = 0; i < num_pin; i++)
    {
      list_wire[i] = list_wire_test[i];
    }
    flag_pattern = 0;
    num_pin = 0;
  }
*/
  //测试数据END

  /*
  //串口接收
  mes = String("");

  while (Serial.available() > 0) //接收到信号----------
  {
    char data = Serial.read();
    mes += data;
    delay(2);
  }

  if (mes != "") //分割数据--------------
  {

    int commaPosition;
    int cont = 0;
    commaPosition = mes.indexOf(','); //第一个逗号找出针的数量
    num_pin = mes.substring(0, commaPosition).toInt();

    for (int i = 0; i < 500; i++)
    {
      list_wire[i] = 0;
    }                                                     //initial
    mes = mes.substring(commaPosition + 1, mes.length()); //挖走qian面的

    do
    {
      commaPosition = mes.indexOf(',');
      list_wire[cont] = mes.substring(0, commaPosition).toInt();
      mes = mes.substring(commaPosition + 1, mes.length()); //挖走qian面的
      cont++;
    } while (commaPosition >= 0); //没逗号退出
    //print to debug
    Serial.print("cont=");
    Serial.println(cont);
    Serial.print("num_pin=");
    Serial.println(num_pin);
  }
//串口接收END
  //未知、基本操控（步进归零，步进走，舵机下，步进走，舵机上，步进归零）
*/
  /*
  //歸零
  while (1)
  {
    stepper(true, Y_DIR, Y_STP, 1); //y轴电机 zheng转1step，
    if (digitalRead(I_I) == 1)
    {
      Serial.print("归零完成");
      break;
    }
  }
  //歸零END
*/

  //绕线(激进版本，无归零)
  int one_step = Num_round / num_pin; //一针需要的步数
  int p_last = 0;                     //上一个点
  myservo.write(ag_up);               // 初始化舵机down角度写入
  for (int i = 0; i < num_wire; i++)  //一次for循环绕一个点
  {

    if (p_last == list_wire[i]) //不用动
    {
      Serial.print("from ");
      Serial.print(p_last);
      Serial.print("to ");
      Serial.print(list_wire[i]);
      Serial.println("by stop");
      myservo.write(ag_down); // 舵机down角度写入
      Serial.println("servo_down");
      delay(500);
      Serial.println("step1");

      stepper(false, Y_DIR, Y_STP, one_step); //步进转到list_wire[i+1]前面
      delay(500);
      Serial.println("servo_up");
      myservo.write(ag_up);

      p_last = list_wire[i] + 1;
      if (p_last == num_pin)
      {
        p_last = 0;
      }
    }                                                                                          //测试
    else if (((p_last - list_wire[i]) > num_pin / 2) and ((p_last - list_wire[i]) <= num_pin)) //顺时针
    {

      Serial.print("from ");
      Serial.print(p_last);
      Serial.print("to ");
      Serial.print(list_wire[i]);
      Serial.println("by shun1");
      Serial.print("(");
      Serial.print(abs(num_pin - (p_last - list_wire[i])));
      Serial.println("step)");
      stepper(false, Y_DIR, Y_STP, (abs(num_pin - (p_last - list_wire[i])) * one_step)); //步进转到list_wire[i]前面
      delay(500 * abs(num_pin - (p_last - list_wire[i])));
      myservo.write(ag_down); // 舵机down角度写入
      Serial.println("servo_down");
      delay(500);
      Serial.println("step1");
      stepper(false, Y_DIR, Y_STP, one_step); //步进转到list_wire[i+1]前面
      delay(500);
      Serial.println("servo_up");
      myservo.write(ag_up);
      p_last = list_wire[i] + 1;
      if (p_last == num_pin)
      {
        p_last = 0;
      }
    }
    else if (((p_last - list_wire[i]) > 0) and ((p_last - list_wire[i]) <= (num_pin / 2))) //ni时针
    {
      Serial.print("from ");
      Serial.print(p_last);
      Serial.print("to ");
      Serial.print(list_wire[i]);
      Serial.println("by ni2");
      Serial.print("step1");
      Serial.print("(");
      Serial.print(p_last - list_wire[i]);
      Serial.println("step)");
      stepper(true, Y_DIR, Y_STP, (p_last - list_wire[i]) * one_step); //步进转到list_wire[i]前面
      delay(500 * (p_last - list_wire[i]));
      myservo.write(ag_down); // 舵机down角度写入
      Serial.println("servo_down");
      delay(500);

      stepper(false, Y_DIR, Y_STP, one_step); //步进转到list_wire[i+1]前面
      delay(500);
      Serial.println("servo_up");
      myservo.write(ag_up);
      p_last = list_wire[i] + 1;
      if (p_last == num_pin)
      {
        p_last = 0;
      }
    }
    else if (((p_last - list_wire[i]) > -(num_pin / 2)) and ((p_last - list_wire[i]) <= 0)) //shun时针
    {
      Serial.print("from ");
      Serial.print(p_last);
      Serial.print("to ");
      Serial.print(list_wire[i]);
      Serial.println("by shun3");
      Serial.print("(");
      Serial.print(-(p_last - list_wire[i]));
      Serial.println("step)");
      stepper(false, Y_DIR, Y_STP, (-(p_last - list_wire[i]) * one_step)); //步进转到list_wire[i]前面
      delay(500 * (-(p_last - list_wire[i])));
      myservo.write(ag_down); // 舵机down角度写入
      Serial.println("servo_down");
      delay(500);
      Serial.println("step1");
      stepper(false, Y_DIR, Y_STP, one_step); //步进转到list_wire[i+1]前面
      delay(500);
      Serial.println("servo_up");
      myservo.write(ag_up);
      p_last = list_wire[i] + 1;
      if (p_last == num_pin)
      {
        p_last = 0;
      }
    }
    else if (((p_last - list_wire[i]) <= -num_pin / 2) and ((p_last - list_wire[i]) > -(num_pin))) //ni时针
    {
      Serial.print("from ");
      Serial.print(p_last);
      Serial.print("to ");
      Serial.print(list_wire[i]);
      Serial.print("by ni4");
      Serial.print("(");
      Serial.print(num_pin + p_last - list_wire[i]);
      Serial.println("step)");
      stepper(true, Y_DIR, Y_STP, ((num_pin + p_last - list_wire[i]) * one_step)); //步进转到list_wire[i]前面
      delay(500 * (num_pin + p_last - list_wire[i]));
      myservo.write(ag_down); // 舵机down角度写入
      Serial.println("servo_down");
      delay(500);
      Serial.println("step1");
      digitalWrite(Z_LED, HIGH);              //测试
      stepper(false, Y_DIR, Y_STP, one_step); //步进转到list_wire[i+1]前面
      delay(500);
      Serial.println("servo_up");
      myservo.write(ag_up);
      p_last = list_wire[i] + 1;
      if (p_last == num_pin)
      {
        p_last = 0;
      }
    }
    else
    {
      Serial.print("from ");
      Serial.print(p_last);
      Serial.print("to ");
      Serial.print(list_wire[i]);
      Serial.print(" but error");
      break;
    }

    delay(500);
  }
  //绕线(激进版本，无归零)END

  /*
  //绕线(保守版本，一针一归零)
  int one_step = Num_round / num_pin;
  for (int i = 0; i < num_pin; i++) //一次for循环绕一个点
  {
    stepper(true, Y_DIR, Y_STP, (list_wire[i] * one_step));                 //步进转到list_wire[i]前面
    myservo.write(ag_down);                                                 // 舵机down角度写入
    stepper(true, Y_DIR, Y_STP, one_step);                                  //步进转到list_wire[i+1]前面
    myservo.write(ag_up);                                                   // 舵机up角度写入
    stepper(true, Y_DIR, Y_STP, (Num_round - 1 - list_wire[i]) * one_step); //把剩下的步数走完
    //复位
    
    while (1)                                                                  //回归0点
    {
      stepper(true, Y_DIR, Y_STP, 1); //y轴电机 zheng转1step，
      if (digitalRead(I_I) == 1)
      {
        //Serial.print("归零完成");
        break;
      }
    }
    
  }
  //绕线END
*/
  Serial.print("fin");
}
