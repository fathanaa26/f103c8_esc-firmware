int potVal;

void setup(){
  pinMode(A0, OUTPUT);
}

void loop(){
  potVal = map(analogRead(A7), 0, 1023, 0, 255);
  analogWrite(A0, potVal);
}