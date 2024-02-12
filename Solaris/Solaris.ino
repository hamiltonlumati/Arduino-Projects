#include <RBD_LightSensor.h>

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

RBD::LightSensor light_sensor(A5);
float logR2, R2, T;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(light_sensor.getInversePercentValue());



  sensors.requestTemperatures();
  //Serial.print(sensors.getTempCByIndex(0));


  //Serial.println(analogRead(A4));
  Serial.print("Tensão1: ");
  Serial.println(analogRead(A0));

  Serial.print("Tensão2: ");
  Serial.println(analogRead(A1));



  //Temperatura
  R2 = 10000 * (1023.0 / (float)analogRead(A4) - 1.0); //calculate resistance on thermistor
  logR2 = log(R2);
  T = (1.0 / (0.001129148 + 0.000234125*logR2 + 0.0000000876741*logR2*logR2*logR2)); // temperature in Kelvin
  T = T - 273.15; //convert Kelvin to Celcius
  //T = (T * 9.0)/ 5.0 + 32.0; //convert Celcius to Farenheit
  Serial.print("Temperatura: ");
  Serial.println(T);
  delay(360);

}
