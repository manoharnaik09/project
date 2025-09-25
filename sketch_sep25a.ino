#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensorPin = A0;
float sensitivity = 0.185;
float Vref = 2.5;

void setup() {
  lcd.begin(16, 2, LCD_5x8DOTS);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Current Sensor");
  delay(2000);
  lcd.clear();
}

void loop() {
  int rawValue = analogRead(sensorPin);
  float voltage = (rawValue * 5.0) / 1023.0;
  float current = (voltage - Vref) / sensitivity;
  current = abs(current);

  lcd.setCursor(0, 0);
  lcd.print("Current:       ");
  lcd.setCursor(0, 1);
  lcd.print(current, 2);
  lcd.print(" A       ");

  delay(1000);
}


