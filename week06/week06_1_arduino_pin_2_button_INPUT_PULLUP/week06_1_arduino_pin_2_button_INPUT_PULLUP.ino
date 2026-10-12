// week06_1_arduino_pin_2_button_INPUT_PULLUP
void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP); // 預設是 pin 2 是 Boutton
  pinMode(8, OUTPUT); // 預設是 pin 8 是 Buzzer 喇叭
  tone(8, 523, 100); // 開啟時, 發一下聲音, 代表城市沒錯
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( digitalRead(2) == LOW ) {
    tone(8, 523, 100); // 0.1秒
    delay(100); // 等一下(讓聲音夠長)
  }
}
