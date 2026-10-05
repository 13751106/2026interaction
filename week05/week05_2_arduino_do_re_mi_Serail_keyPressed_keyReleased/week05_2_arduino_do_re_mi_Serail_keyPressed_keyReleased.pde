// week05_2_arduino_do_re_mi_Serail_keyPressed_keyReleased
// 修改自 week05_1_arduino_do_re_mi_Serail
import processing.serial.*; // 使用 USB Serial 外掛
Serial myPort;
void setup() {
  size(300, 200);
  myPort = new Serial(this, "COM3", 9600); // 中間 "COM3"
}
void draw() {
  
}
int p1 = 0, p2 = 0, p3 = 0; // 
void keyPressed() {
  if (p1==0 && key=='1') myPort.write('1'); // 之前沒有現在按
  if (p2==0 && key=='2') myPort.write('2');
  if (p3==0 && key=='3') myPort.write('3');
  if (p1==0 && key=='1') p1 = 1; // 0 代表放下去
  if (p2==0 && key=='2') p2 = 1;
  if (p3==0 && key=='3') p3 = 1;
}
void keyReleased() {
  if (key=='1') p1 = 0; // 放開 1 鍵
  if (key=='2') p2 = 0; // 放開 2 鍵
  if (key=='3') p3 = 0; // 放開 3 鍵
  myPort.write('0'); // 告訴 Arduino 你不要發聲音!!!
}
