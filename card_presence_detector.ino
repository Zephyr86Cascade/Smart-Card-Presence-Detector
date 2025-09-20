const int IR_SENSOR_PIN = A0;
const int LED_GREEN = 8;
const int LED_RED = 9;
const int BUZZER_PIN = 10;
const int BUTTON_PIN = 7;

bool cardPresent = false;
bool lastCardState = false;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(9600);
  Serial.println("Smart Card Presence Detector Initialized");
  Serial.println("Insert a card to test detection...");
  
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, LOW);
  
  beep(100);
  delay(100);
  beep(100);
}

void loop() {
  bool sensorReading = analogRead(IR_SENSOR_PIN) < 500;
  
  if (sensorReading != lastCardState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (sensorReading != cardPresent) {
      cardPresent = sensorReading;
      
      if (cardPresent) {
        cardInserted();
      } else {
        cardRemoved();
      }
    }
  }
  
  lastCardState = sensorReading;
  
  if (digitalRead(BUTTON_PIN) == LOW) {
    resetSystem();
    delay(500);
  }
  
  updateIndicators();
  
  delay(10);
}

void cardInserted() {
  Serial.println("CARD DETECTED!");
  Serial.println("Card Type: Standard Size Card");
  Serial.println("Status: Present");
  Serial.println("Timestamp: " + String(millis()) + "ms");
  Serial.println("----------------------------");
  
  beep(200);
  delay(100);
  beep(200);
  
  blinkLED(LED_GREEN, 3, 150);
}

void cardRemoved() {
  Serial.println("CARD REMOVED");
  Serial.println("Status: Not Present");
  Serial.println("Timestamp: " + String(millis()) + "ms");
  Serial.println("----------------------------");
  
  beep(100);
  
  blinkLED(LED_RED, 2, 100);
}

void updateIndicators() {
  if (cardPresent) {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
  } else {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
  }
}

void beep(int duration) {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(duration);
  digitalWrite(BUZZER_PIN, LOW);
}

void blinkLED(int ledPin, int times, int interval) {
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPin, HIGH);
    delay(interval);
    digitalWrite(ledPin, LOW);
    delay(interval);
  }
}

void resetSystem() {
  Serial.println("SYSTEM RESET");
  Serial.println("Ready for card detection...");
  
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, HIGH);
  
  beep(300);
}

void displayStatus() {
  Serial.println("=== SYSTEM STATUS ===");
  Serial.println("Card Present: " + String(cardPresent ? "YES" : "NO"));
  Serial.println("Sensor Reading: " + String(digitalRead(IR_SENSOR_PIN)));
  Serial.println("Uptime: " + String(millis()) + "ms");
  Serial.println("====================");
}
