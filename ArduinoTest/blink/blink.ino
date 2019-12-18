//test program
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  int i=1;
  for(i=1;i<=1000;i=i*2){
    digitalWrite(LED_BUILTIN, HIGH);  
    delay(i);                      
    digitalWrite(LED_BUILTIN, LOW);   
    delay(i);                       
  }
  
}
