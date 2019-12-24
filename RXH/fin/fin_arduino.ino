 #include <Servo.h>
//脚位定义
#define EN        8       //步进电机使能端，低电平有效
#define Y_DIR     6       //y轴 步进电机方向控制脚位
#define Y_STP     3       //y轴 步进控制脚位
#define Z_WJ      2       //z轴 伺服马达输出脚位
#define I_I      4       //归零光感测器输入脚位
//参数
#define Num_round 1200     //200*6*1 走一圈步进电机的步数 （跳线： 000全细分1 001细分1/2  010细分1/4  110细分1/8  111细分1/16）(全细分200步一圈)
int ag_ser = 0;    // Servo角度存储变量
int ag_down =75;    // Servo下降角度
int ag_up =45;    // Servo上升角度

String mes; //串口string
int num_pin = 6;//针的数量，默认6
int list_wire[500];//线的list, Max5000
//int num_wire = 6;//绕线的次数，默认6
Servo myservo;  // 定义Servo对象来控制


//步进控制：dir 方向控制, dirPin对应步进电机的DIR引脚，stepperPin 对应步进电机的step引脚， steps 步进的步数
void step(boolean dir, byte dirPin, byte stepperPin, int steps) {
  digitalWrite(dirPin, dir);
  delay(50);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepperPin, HIGH);
    delayMicroseconds(800);  
    digitalWrite(stepperPin, LOW);
    delayMicroseconds(800);  
  }
}



void setup(){
  //将步进电机用到的IO管脚设置成输出
  pinMode(Y_DIR, OUTPUT); 
  pinMode(Y_STP, OUTPUT);   
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
  //伺服电机设置
  myservo.attach(Z_WJ);  // 控制线连接
  //将归零光感器用到的IO管脚设置成输入
  pinMode(I_I, INPUT);     
}

void loop(){
  //一、串口接收
  mes = String("");

  while (Serial.available()>0){  //接收到信号----------
  
    char data= Serial.read();
    mes+=data;
    delay(2);}
    
  
  if(mes!=""){  //分割数据--------------

    int commaPosition; 
    int cont=0; 
    commaPosition = mes.indexOf(',');//第一个逗号找出针的数量
    num_pin=mes.substring(0,commaPosition).toInt();

    for(int i=0 ; i<500 ;i++){list_wire[i]=0;} //initial
    mes = mes.substring(commaPosition+1, mes.length());//挖走qian面的
    
    do{
      commaPosition = mes.indexOf(',');
      list_wire[cont]=mes.substring(0,commaPosition).toInt();
      mes = mes.substring(commaPosition+1, mes.length());//挖走qian面的
      cont++; 
    }
    while(commaPosition >=0); //没逗号退出
    //print to debug
    Serial.print("cont=");Serial.println(cont);
    Serial.print("num_pin=");Serial.println(num_pin);
     }



  //未知、基本操控（归零，步进走，舵机动，步进走，归零）
  
  //

  step(false, Y_DIR, Y_STP, Num_round); 
  delay(1000);

}