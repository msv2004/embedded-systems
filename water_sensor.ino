int sensorPin = A3;
int sensorValue = 0;
int value;
void setup() {

// put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //sensorValue = analogRead(sensorPin);
  value = analogRead(sensorPin);

 if (value<=480){ 
    Serial.println("Water level: 0mm - Empty!"); 
  }

else if (value>480 && value<=530){ 
    Serial.println("Water level: 0mm to 5mm"); 
  }
  else if (value>530 && value<=615){ 
    Serial.println("Water level: 5mm to 10mm"); 
  }

  else if (value>615 && value<=660){ 
    Serial.println("Water level: 10mm to 15mm"); 
  } 

else if (value>660 && value<=680){ 
    Serial.println("Water level: 15mm to 20mm"); 
  }

else if (value>680 && value<=690){ 
    Serial.println("Water level: 20mm to 25mm"); 
  }

else if (value>690 && value<=700){ 
    Serial.println("Water level: 25mm to 30mm"); 
  }

else if (value>700 && value<=705){ 
    Serial.println("Water level: 30mm to 35mm"); 
  }

else if (value>705){ 
    Serial.println("Water level: 35mm to 40mm"); 
  }
  delay(2000);
}
