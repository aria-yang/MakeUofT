// variables
int sensorPin = A0; // sensor location
int sensorValue;
int buzzerPin = 8; // buzzer location

// loudness
int loud = 300;
int midloud = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  // strong force = no sound
  if(sensorValue > 300) {
    noTone(buzzerPin);
    delay(100000);
  }
  // slight force = two sounds
  else if (sensorValue <= 300 && sensorValue > 50) {
    analogWrite(buzzerPin, midloud);
    delay(100000);
  }
  // no force = keeps ringing
  else {
    tone(buzzerPin, 440, 2000);
    analogWrite(buzzerPin, loud);
  }
}
