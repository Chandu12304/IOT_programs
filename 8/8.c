#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN 7
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

unsigned long previousMillis = 0;
int seconds = 0, minutes = 0, hours = 13;
int day = 14, month = 9, year = 2025;  // start date

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
  lcd.clear();
}

void loop() {
  // ---- Update time every second ----
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    seconds++;
    if (seconds >= 60) { seconds = 0; minutes++; }
    if (minutes >= 60) { minutes = 0; hours++; }
    if (hours >= 24) { hours = 0; day++; }
  }

  // ---- Read temperature ----
  float temp = dht.readTemperature();
  if (isnan(temp)) temp = 0;

  // ---- Display ----
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("C   ");   // spaces to clear leftovers

  lcd.setCursor(0, 1);
  if (day < 10) lcd.print("0");
  lcd.print(day);
  lcd.print("/");
  if (month < 10) lcd.print("0");
  lcd.print(month);
  lcd.print("/");
  lcd.print(year);

  lcd.print(" ");
  if (hours < 10) lcd.print("0");
  lcd.print(hours);
  lcd.print(":");
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
}
