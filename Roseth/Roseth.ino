//int Buzzer = 7; //for Arduino Microcontroller
//int Buzzer = D7; //for ESP8266 Microcontroller
int Buzzer = 4; //for ESP32 Microcontroller

void setup(){
  pinMode (Buzzer, OUTPUT);
}

void loop(){
  digitalWrite (Buzzer, HIGH); //turn buzzer on
  delay(2000);
  digitalWrite (Buzzer, LOW);  //turn buzzer off
  delay(1000);
}
