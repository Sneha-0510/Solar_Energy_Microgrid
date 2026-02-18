 // Solar Microgrid Controller - Arduino Uno R3
// LL = Solar source | O = Auto | L = Grid source
const int pinGridSense = 2; // Grid presence detect
const int pinSolarManual = 3; // LL pressed → Solar
const int pinGridManual = 6; // L pressed → Grid
const int pinRedLED = 4; // Grid active LED
const int pinGreenLED = 5; // Solar/Battery active LED
const int pinRelay = 8; // Relay IN (Active LOW)
void setup() {
 Serial.begin(9600);
 pinMode(pinGridSense, INPUT);
 pinMode(pinSolarManual, INPUT);
 pinMode(pinGridManual, INPUT);
 pinMode(pinRedLED, OUTPUT);
 pinMode(pinGreenLED, OUTPUT);
 pinMode(pinRelay, OUTPUT);
 // Safe startup: default to Grid via NC
 digitalWrite(pinRelay, HIGH);
 digitalWrite(pinRedLED, LOW);
 digitalWrite(pinGreenLED, LOW);
 Serial.println("=== SOLAR MICROGRID READY ===");
 Serial.println("LL=Solar | O=Auto | L=Grid");
}
void loop() {
 bool solarManual = digitalRead(pinSolarManual); // LL
 bool gridManual = digitalRead(pinGridManual); // L
 bool gridPresent = digitalRead(pinGridSense);
 // -------- MANUAL OVERRIDE --------
 if (solarManual && !gridManual) {
 // LL pressed → Solar
 digitalWrite(pinRelay, LOW);
 digitalWrite(pinGreenLED, HIGH);
 digitalWrite(pinRedLED, LOW);
 Serial.println("MANUAL: Solar/Battery ON");
 }
 else if (gridManual && !solarManual) {
 // L pressed → Grid
 digitalWrite(pinRelay, HIGH);
 digitalWrite(pinRedLED, HIGH);
 digitalWrite(pinGreenLED, LOW);
 Serial.println("MANUAL: Grid ON");
 }
 else {
 // -------- AUTOMATIC MODE --------
 autoSwitch(gridPresent);
 }
 delay(500);
}
// ---------------- AUTO MODE ----------------
void autoSwitch(bool gridPresent) {
 if (gridPresent) {
 // Prefer grid
 digitalWrite(pinRelay, HIGH); // Grid via NC
 digitalWrite(pinRedLED, HIGH);
 digitalWrite(pinGreenLED, LOW);
 Serial.println("AUTO: Grid supplying load");
 } else {
 digitalWrite(pinRelay, LOW); // Solar/Battery via NO
 digitalWrite(pinGreenLED, HIGH);
 digitalWrite(pinRedLED, LOW);
 Serial.println("AUTO: Solar/Battery supplying load");
 }
}
