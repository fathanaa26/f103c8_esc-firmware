int count = 0;
int potVal = 0;
int i = 0;
float pwm_in = 1;
bool cw = true;

unsigned long prevMicros = 0;

void setup() {
  pinMode(PA0, OUTPUT);
  pinMode(PA1, OUTPUT);
  pinMode(PA3, OUTPUT);

}

void loop() {
  potVal = map(analogRead(A7), 0,4095, 0 ,1000000);
  unsigned long currentMicros = micros();
  
  if(currentMicros - prevMicros >= potVal){
    
    prevMicros = currentMicros;
    count++;

    if(count == 1){
      digitalWrite(PA0, HIGH);
      digitalWrite(PA1, LOW);
      digitalWrite(PA3, LOW);
    }else if(count == 2){
      digitalWrite(PA0, LOW);
      digitalWrite(PA1, HIGH);
      digitalWrite(PA3, LOW);
    }else if(count == 3){
      digitalWrite(PA0, LOW);
      digitalWrite(PA1, LOW);
      digitalWrite(PA3, HIGH);
    }else{
      count = 1;
      digitalWrite(PA0, HIGH);
    }
    
  }
  
    
}
