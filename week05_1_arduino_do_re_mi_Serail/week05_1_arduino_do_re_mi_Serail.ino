// week05_1_arduino_do_re_mi_Serail
// 修改自 week02_5_arduino_Do_Re_Mi_Serial_begin_available_read_if_tone
void setup() {
  Serial.begin(9600); // USB Serial 開始傳輸,速度 9600 bps
  
  tone(8, 523, 100); // Do 0.1秒
  delay(200); // 等一下聲音出來不要滑過去
  
  tone(8, 587, 100); // Re 0.1秒
  delay(200); // 等一下聲音出來不要滑過去
  
  tone(8, 659, 100); // Mi 0.1秒
}

void loop() {
  if (Serial.available()){
    char c = Serial.read();
    if (c=='1') tone(8, 523, 100); // Do 0.1秒
    if (c=='2') tone(8, 587, 100); // Re 0.1秒
    if (c=='3') tone(8, 659, 100); // Mi 0.1秒
  }
}
