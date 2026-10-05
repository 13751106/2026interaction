// week05_3_arduino_do_re_mi_Serail_blink
// 修改自 week05_2_arduino_do_re_mi_Serail_tone_noTone
void setup(){
  pinMode(8, OUTPUT); // Buzzer 8 聲音
  pinMode(10, OUTPUT); // 對應'0'
  pinMode(11, OUTPUT); // 對應'1'
  pinMode(12, OUTPUT); // 對應'2'
  pinMode(13, OUTPUT); // 對應'3'

  Serial.begin(9600); // USB Serial 開始傳輸,速度 9600 bps
  tone(8, 523, 100); delay(200); // DO
  tone(8, 587, 100); delay(200); // Re
  tone(8, 659, 100); delay(200); // Me
  tone(8, 587, 100); delay(200); // Re
  tone(8, 523, 100); delay(200); // DO
}
char c = '0'; // 0:不要發出聲音 1:Do 2:Re 3:Mi
void loop() {
  if (Serial.available()){
    c = Serial.read();
  }
  for (int i=10; i<=13; i++) digitalWrite(i, LOW);
  if (c>='0' && c<='3')  digitalWrite(c-'0'+10, HIGH);
  if (c=='0') noTone(8);
  if (c=='1') tone(8, 523); // DO 一直發出聲音
  if (c=='2') tone(8, 587); // Re 一直發出聲音
  if (c=='3') tone(8, 659); // Mi 一直發出聲音
}
