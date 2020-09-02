#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

const int AirValue = 575;
const int WaterValue = 320;

int soilMoistureValue = 0;
int soilMoisturePercent = 0;

void setup() {
    Serial.begin(115200);
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    delay(1000);
}

void loop() {
    soilMoistureValue = analogRead(A0);
    soilMoisturePercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

    if(soilMoisturePercent < 10) {
        Serial.println(soilMoisturePercent);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Moisture: ");
        lcd.print(soilMoisturePercent);
        lcd.print("%");
        lcd.setCursor(0, 1);
        lcd.print("Water now");
    }
    else if(soilMoisturePercent >= 10 && soilMoisturePercent < 40 ) {
        Serial.println(soilMoisturePercent);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Moisture: ");
        lcd.print(soilMoisturePercent);
        lcd.print("%");
        lcd.setCursor(0, 1);
        lcd.print("Good moisture");
    }
    else if(soilMoisturePercent >= 40) {
        Serial.println(soilMoisturePercent);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Moisture: ");
        lcd.print(soilMoisturePercent);
        lcd.print("%");
        lcd.setCursor(0, 1);
        lcd.print("Too much water"); 
    }

    delay(2000);
}