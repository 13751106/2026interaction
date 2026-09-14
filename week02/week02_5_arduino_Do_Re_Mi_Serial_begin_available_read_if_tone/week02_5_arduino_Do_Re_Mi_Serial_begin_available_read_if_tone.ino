// week02_5_arduino_Do_Re_Mi_Serial_begin_available_read_if_tone
// 在 Prossing 按下 key 1 2 3 對應 arduino 的 Do Re Mi 使用 USB Serial
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()){
    char c = Serial.read();
    if (c=='1') tone(8, 523, 1000); // Do 1秒
    if (c=='2') tone(8, 587, 1000); // Re 1秒
    if (c=='3') tone(8, 659, 1000); // Mi 1秒
  }
}
