//LCD
#include <LiquidCrystal.h>

#define DB7 13
#define DB6 12
#define DB5 11
#define DB4 10
#define E 9
#define RS 8
LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7)
;

//DS18B20
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


float tf = 0, h = 0, tk = 0, tc = 0;


void setup() {
Serial.begin(9600);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(2, OUTPUT);

//dht.begin();
sensors.begin();
lcd.begin(16, 2);
}

void loop() {

lcd.setCursor(0, 0);
sensors.requestTemperatures();

tc = sensors.getTempCByIndex(0);
tf = sensors.getTempFByIndex(0);

tk = tc + 273.15;

lcd.leftToRight();
lcd.print("TEMP: ");
lcd.print(tf);
lcd.print("F");
lcd.setCursor(0,1);
lcd.print(tc);
lcd.print("C  ");
lcd.print(tk);
lcd.print("K");
delay(1000);
}
