int rfPin = 7;       // Pin where RF receiver data pin is connected
int stepPin = 8;     // Pin connected to STEP on DRV8825
int dirPin = 9;      // Pin connected to DIR on DRV8825
bool previousState = LOW; // Previous state of the RF button, default to LOW

void setup() {
  pinMode(rfPin, INPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600); // Start serial communication
}

void loop() {
  bool currentState = digitalRead(rfPin);
  
  if(currentState != previousState) { // Check if state has changed
    if(currentState == HIGH) {
      Serial.println("Button Pressed");
    } 
    else {
      Serial.println("Button Released");
    }
    previousState = currentState; // Update the previous state
  }

  if(currentState == HIGH) {
    digitalWrite(dirPin, HIGH); // Define rotation direction
    digitalWrite(stepPin, HIGH); // Make a step
    delay(1); 
    digitalWrite(stepPin, LOW); // Turn off step
    delay(1);
  } 
  else {
    // When button is released, stop the motor by not sending any step pulses
  }
}
