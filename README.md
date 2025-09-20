Arduino Card Presence Detector
A smart card detection system that identifies when a card is inserted into a slot using an Arduino microcontroller and sensor feedback.

Wiring Instructions
Step 1: Power Distribution

Connect Arduino 5V → Breadboard red power rail
Connect Arduino GND → Breadboard blue ground rail

Step 2: Photoresistor (Card Sensor)

Connect photoresistor leg 1 → red power rail (5V)
Connect photoresistor leg 2 → Arduino Pin A0
Connect photoresistor leg 2 → 10kΩ resistor → blue ground rail

Step 3: LED Indicators
Green LED (Card Present):

Connect LED long leg (anode) → Arduino Pin 8
Connect LED short leg (cathode) → 220Ω resistor → blue ground rail

Red LED (No Card):

Connect LED long leg (anode) → Arduino Pin 9
Connect LED short leg (cathode) → 220Ω resistor → blue ground rail

Step 4: Audio Feedback

Connect buzzer positive (red wire) → Arduino Pin 10
Connect buzzer negative (black wire) → blue ground rail

Step 5: Reset Button

Connect button leg 1 → Arduino Pin 7
Connect button leg 2 → blue ground rail

Example Output:
Smart Card Presence Detector Initialized
Insert a card to test detection...
CARD DETECTED!
Card Type: Standard Size Card
Status: Present
Timestamp: 2456ms
----------------------------
CARD REMOVED
Status: Not Present
Timestamp: 4123ms
----------------------------
