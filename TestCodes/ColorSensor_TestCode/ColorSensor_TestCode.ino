#define ColorSensor_S0 4
#define ColorSensor_S1 5
#define ColorSensor_S2 6
#define ColorSensor_S3 7

#define ColorSensor_SignalPin 8

int Filter_RED = 0;
int Filter_GREEN = 0;
int Filter_BLUE = 0;


void setup() {
  Serial.begin(115200);
  Serial.println("ColorSensor Start");
  ColorSensor_init();
}


void loop() {
  Filter_RED = getColorFrequency(0, 0);
  Filter_GREEN = getColorFrequency(1, 1);
  Filter_BLUE = getColorFrequency(0, 1);

  Serial.println("**************************");
  Serial.println("RED Filter: " + String(Filter_RED));
  Serial.println("GREEN Filter: " + String(Filter_GREEN));
  Serial.println("BLUE Filter: " + String(Filter_BLUE));

  delay(500);
}


void ColorSensor_init() {
  pinMode(ColorSensor_S0, OUTPUT);
  pinMode(ColorSensor_S1, OUTPUT);
  pinMode(ColorSensor_S2, OUTPUT);
  pinMode(ColorSensor_S3, OUTPUT);
  pinMode(ColorSensor_SignalPin, INPUT);

  digitalWrite(ColorSensor_S0, HIGH);
  digitalWrite(ColorSensor_S1, LOW);
}

int getColorFrequency(bool s2_state, bool s3_state) {
  digitalWrite(ColorSensor_S2, s2_state);
  digitalWrite(ColorSensor_S3, s3_state);
  int RetFreq = pulseIn(ColorSensor_SignalPin, LOW);
  return RetFreq;
}