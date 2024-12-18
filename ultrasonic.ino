const int trigPin = 2;
const int echoPin = 3;
const int buzzerPin = 8;  // Pin for the piezo buzzer
float length = 0;
const float thresholdDistance = 30.0;  // Set the threshold distance in cm

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);  // Set the buzzer pin as output
}

void loop() {
  // Send a short pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  length = duration * 0.0343 / 2;
  
  // Display the distance
  Serial.print("Distance: ");
  Serial.print(length);
  Serial.println(" cm");

  // Check if the distance is below the threshold
  if (length < thresholdDistance) {
    // Emit a sound if the object is close
    tone(buzzerPin, 1000);  // Play a tone at 1000 Hz
    delay(200);              // Sound duration
    noTone(buzzerPin);       // Stop the tone
  }

  delay(500);  // Delay between measurements
}