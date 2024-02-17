
// variables
int led1 = 10;
int led2 = 11;
int sensorPin = A0; // analog pin
int sensorValue; // to store value

void setup() {
  // put your setup code here, to run once:
  
  // set LED as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  
  // initialize serial communication
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // read sensor value
  sensorValue = analogRead(sensorPin);
  
  // print sensor value
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  // LED directions
  if(sensorValue > 750) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  else if(sensorValue <= 750 && sensorValue > 100) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  delay(200);
  
}
