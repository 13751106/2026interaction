// week11_1_arduino_jeystick_analogRead_A0_A1
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(A0); // 匯入 X 座標
  int y = analogRead(A1); // 匯入 Y 座標
  tone(8, x); // 會把 X 的值,直接很吵的輸出
  // 如果覺得太吵就罷 MakerUno 的跳針, 往左推
}
