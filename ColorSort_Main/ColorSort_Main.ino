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


void setup() {
  Serial.begin(115200);
  Serial.println("ColorSort System Start...");

  ColorSensor_init();
}

void loop() {
  ColorSensor_UpdateFilters();

  

}