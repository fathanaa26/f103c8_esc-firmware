int count = 1;
bool cw = true;

unsigned long prevMicros = 0;
unsigned long prevMillis = 0;

void setup() {
  pinMode(PA0, OUTPUT);
  pinMode(PA1, OUTPUT);
  pinMode(PA3, OUTPUT);

  analogWrite(PA0, LOW);
  analogWrite(PA1, LOW);
  analogWrite(PA3, LOW);
  
}
int i = 0;
float pwm_in = 1000;
void loop() {
  unsigned long currentMicros = micros();
  unsigned long currMillis = millis();

  if(currMillis - prevMillis >= 1000){
    prevMillis = currMillis;
    
    if(cw){
      pwm_in = pwm_in - 100;
  
      if(pwm_in == 0){
        cw = false;
      }
    }else{
      pwm_in = pwm_in + 100;
      if(pwm_in == 1000){
        cw = true;
      }
    }

    
  }
  
  
  if(currentMicros - prevMicros >= pwm_in){
    
    prevMicros = currentMicros;
    i++;

    if(count == 1){
      analogWrite(PA0, i);
      analogWrite(PA1, 0);
      analogWrite(PA3, 0);
    }else if(count == 2){
      analogWrite(PA0, 0);
      analogWrite(PA1, i);
      analogWrite(PA3, 0);
    }else if(count == 3){
      analogWrite(PA0, 0);
      analogWrite(PA1, 0);
      analogWrite(PA3, i);
    }else{
      count = 1;
    }
    
    if(i == 255){
      i = 0;
      count++;
    }
  }
  
    
}
