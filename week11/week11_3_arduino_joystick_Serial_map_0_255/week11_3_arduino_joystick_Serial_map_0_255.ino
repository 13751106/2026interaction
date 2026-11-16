// week11_3_arduino_joystick_Serial_map_0_255
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
}
int myAnalogRead(int pin) {
  return map( analogRead(pin), 0, 1023, 0, 255);
}

void loop() {
  delay(30); // 要在慢一點
  Serial.write( myAnalogRead(A0) );
  Serial.write( myAnalogRead(A1) );
  if (digitalRead(2)==LOW) Serial.println("D"); // DOWN 按下
  else Serial.println("U"); // UP 沒按
}
