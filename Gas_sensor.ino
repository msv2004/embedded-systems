int ledPin_1 = 2;  // BUZZER POSITIVE
int ledPin_2 = 3;  // BUZZER NEAGATIVE
int ledPin_3 = 13;  // green led positive
int ledPin_4 = 12;  /// green neGATIVE
int ledPin_5 = 6;  // red led positive
int ledPin_6 = 7;  // red neagtive
int mq8Pin = A0;         // MQ-8 sensor connected to analog pin A0
int sensorValue = 0;     // Variable to store sensor value
int threshold = 350;     // Define a threshold for gas detection

void setup() {
  pinMode(ledPin_1, OUTPUT); 
  pinMode(ledPin_2, OUTPUT);   
  pinMode(ledPin_3, OUTPUT); 
  pinMode(ledPin_4, OUTPUT);
  pinMode(ledPin_5, OUTPUT); 
  pinMode(ledPin_6, OUTPUT); // Set LED pin as output
         // Set up the LCD (16 columns and 2 rows)
  Serial.begin(9600);         // Initialize serial communication
}

void loop() {
  sensorValue = analogRead(mq8Pin);   // Read the analog value from the MQ-8 sensor


  Serial.print("Gas Sensor Value: ");
  Serial.println(sensorValue);  // Print the sensor value in Serial Monitor

  // Check if the sensor value exceeds the threshold
  if (sensorValue > threshold) {
    digitalWrite(ledPin_2, LOW);  // Turn on the LED
    digitalWrite(ledPin_1, HIGH);
    digitalWrite(ledPin_5, LOW);  // Turn on the LED
    digitalWrite(ledPin_6, HIGH);
    digitalWrite(ledPin_4, LOW); 
  } else {
  delay(1000);  // Wait for a second before the next reading
    digitalWrite(ledPin_1, LOW);
    digitalWrite(ledPin_4, LOW);
    digitalWrite(ledPin_6, LOW);  // Turn on the LED
    digitalWrite(ledPin_4, HIGH); 
}}