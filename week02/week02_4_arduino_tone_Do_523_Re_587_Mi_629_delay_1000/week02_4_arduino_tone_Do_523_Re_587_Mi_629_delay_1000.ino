// week02_4_arduino_tone_Do_523_Re_587_Mi_659_delay_1000
void setup() { // 只做一次
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);

  tone(8, 523, 1000); // Do 0.1秒
  delay(1000);
  tone(8, 587, 1000); // Re 0.1秒
  delay(1000);
  tone(8, 659, 1000); // Mi 0.1秒
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
}
