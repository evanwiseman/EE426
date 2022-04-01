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

//DHT
#include <DHT.h>
#include <Adafruit_Sensor.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);




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

dht.begin();
lcd.begin(16, 2);
}

void loop() {

lcd.setCursor(0, 0);


tf = (9.0/5.0 * dht.readTemperature()) + 32;
tc = dht.readTemperature()*1.0;
tk = (dht.readTemperature())+273.15;


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
