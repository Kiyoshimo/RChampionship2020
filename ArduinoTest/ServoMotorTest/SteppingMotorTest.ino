
void setup() {
  // 定义输出脚位
  for (int i = 2; i < 6; i++) {
    pinMode(i, OUTPUT);
  }
}

void clockwise(int num,int sp)//num 步数，sp速度
{
  if  (num>=0){
    for (int count = 0; count < num; count++){
      for (int i = 2; i < 6; i++){
        digitalWrite(i, HIGH);
        delay(sp);
        digitalWrite(i, LOW);
      }
    }
  }

  else{
    for (int count = 0; count > num; count--){
      for (int i = 5; i >=2; i--){
        digitalWrite(i, HIGH);
        delay(sp);
        digitalWrite(i, LOW);
      }
    }
  }
  
}


void loop() {
  clockwise(512,3);
  clockwise(-512,3);

}
