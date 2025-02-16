/*
 *  Project: Colorsort - Waste Paper Segregation Box
 *  Description: This program automates the sorting of waste paper based on color using the TCS3200 color sensor.
 *  
 *  Hardware Components:
 *    - Microcontroller: (Specify: Arduino/PIC/ESP32)
 *    - Color Sensor: TCS3200
 *    - Servo Motors: (Specify model if used for sorting)
 *    - Power Supply: (Specify voltage and current requirements)
 *    - Other Components: (e.g., relays, solenoids, etc.)
 *  
 *  Features:
 *    - Detects and classifies waste paper color (Red, Green, Blue, etc.)
 *    - Controls sorting mechanism (Servo, Conveyor, etc.)
 *    - Displays data via Serial Monitor (Optional: LCD, OLED)
 *    - Low power consumption for efficient waste management
 *  
 *  Author: 
 *  Date Created: February 16, 2025
 *  Last Updated: 
 *  Version: 1.0
 *  
 *  License: MIT License (or specify another license)
 *  
 *  Notes:
 *    - Ensure proper calibration of the TCS3200 sensor for accurate color detection.
 *    - Modify threshold values based on sensor readings in your environment.
 *    - Add fail-safe mechanisms if needed for real-world applications.
 */
#include <Servo.h>
Servo myservo;

int Filter_RED = 0;
int Filter_GREEN = 0;
int Filter_BLUE = 0;

int tolerance = 10;

int BaseValue_Red = 230;
int BaseValue_Green = 230;
int BaseValue_Blue = 70;

void setup() {  
  Serial.begin(115200);
  Serial.println("ColorSort System Start...");

  ColorSensor_init();
  myservo.attach(9);
  myservo.write(0);
  delay(2000);
}

void loop() {

  ColorSensor_ShowValues();

  //ColorSensor_UpdateFilters();

  if (Filter_RED <= (30 + tolerance) && Filter_GREEN <= (30 + tolerance) && Filter_BLUE <= (30 + tolerance)) {
    Serial.println("I see a WHITE thing!");
  } else if (Filter_RED >= (BaseValue_Red - tolerance) && Filter_RED <= (BaseValue_Red + tolerance) && Filter_GREEN >= (BaseValue_Green - tolerance) && Filter_GREEN <= (BaseValue_Green + tolerance) && Filter_BLUE >= (BaseValue_Blue - tolerance) && Filter_BLUE <= (BaseValue_Blue + tolerance)) {

    Serial.println("I see a WHITE thing!");

  } else {
    Serial.println("I see a COLORED thing!");
  }

  myservo.write(0);
  delay(2000);
  myservo.write(90);
  delay(2000);
  myservo.write(180);
  delay(2000);
  myservo.write(90);
  delay(2000);
}