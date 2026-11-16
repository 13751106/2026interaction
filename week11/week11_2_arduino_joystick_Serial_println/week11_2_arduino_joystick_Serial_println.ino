// week11_2_arduino_joystick_Serial_println
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(A0); // 匯入 X 座標
  int y = analogRead(A1); // 匯入 Y 座標
  int sw = analogRead(2); // joystick 座標
  if (digitalRead(2)==LOW) sw = 1; // 按下去, 設1
  else sw = 0; // 彈起來, 設0
  char line[200];
  sprintf(line, "x:%d y:%d sw:%d, x, y, sw");
  Serial.print(line); // 改用 print() 不要用 println
}
