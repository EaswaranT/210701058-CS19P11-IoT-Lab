#define wetSoil 277   // Define max value we consider soil 'wet'
#define drySoil 380   // Define min value we consider soil 'dry'

// Define analog input
#define sensorPin A0
#define wetLED 10   // Define wet LED pin
#define perfectLED 6  // Define perfect moisture LED pin
#define dryLED 12   // Define dry LED pin

void setup() {  
  Serial.begin(9600);
  pinMode(wetLED, OUTPUT); // Initialize wet LED pin as an output
  pinMode(perfectLED, OUTPUT); // Initialize perfect moisture LED pin as an output
  pinMode(dryLED, OUTPUT); // Initialize dry LED pin as an output
}

void loop() {
  // Read the Analog Input and print it
  int moisture = analogRead(sensorPin);
  Serial.print("Analog output: ");
  Serial.println(moisture);
  
  // Determine status of our soil
  if (moisture < wetSoil) {
    Serial.println("Status: Soil is too wet");
    blinkLED(wetLED, 2000); 
  } else if (moisture >= wetSoil && moisture < drySoil) {
    Serial.println("Status: Soil moisture is perfect");
    blinkLED(perfectLED, 2000); 
  } else {
    Serial.println("Status: Soil is too dry - time to water!");
    blinkLED(dryLED, 2000); 
  }
  Serial.println();
  
  // Take a reading every second
  delay(1000);
}

// Function to blink LED with a specified interval
void blinkLED(int ledPin, int interval) {
  digitalWrite(ledPin, HIGH); // Turn LED on
  delay(interval / 2); // Wait for half the interval
  digitalWrite(ledPin, LOW); // Turn LED off
  delay(interval / 2); // Wait for half the interval
}  Serial.println();
  
  // Take a reading every second
  delay(1000);
}

