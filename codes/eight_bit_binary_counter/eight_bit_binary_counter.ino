 
const int ledPins[] = {9,8,7,6,5,4,3,2}; // Array of pins connected to LEDs (modify if needed)
byte counter = 0; // Variable to store the counter value (0-255)

void setup() {
  for (int pin : ledPins) { // Set all LED pins to output
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  // Increment counter (wrap around at 256)
  counter++;
  if (counter == 256) {
    counter = 0;
  }

  // Display counter value on LEDs (LSB -> MSB)
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], (counter >> i) & 1); // Check if bit is high using bitwise AND
  }

  delay(1000); // Delay between counts (adjust as desired)
}
