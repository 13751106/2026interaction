// week05_3_processing_do_re_mi_Serail_draw
// 修改自 week05_2_arduino_do_re_mi_Serail_keyPressed_keyReleased
import processing.serial.*; // 使用 USB Serial 外掛
Serial myPort;
void setup() {
  size(300, 200);
  myPort = new Serial(this, "COM3", 9600); // 中間 "COM3"
}
void draw() { // 這裡要寫程式
  background(128);
  if (p1==1) fill(0); // 黑色,按下去
  else fill(255); // 否則是白色,沒按下去
  rect(0, 0, 100, 150); // 第 1 個按鍵
  
  if (p2==1) fill(0);
  else fill(255);
  rect(100, 0, 100, 150); // 第 2 個按鍵
  
  if (p3==1) fill(0);
  else fill(255);
  rect(200, 0, 100, 150); // 第 3 個按鍵
  
  fill(255, 0, 0); // 紅色圈圈
  if (now=='1') ellipse(50, 175, 50, 50);
  if (now=='2') ellipse(50, 175, 50, 50);
  if (now=='3') ellipse(50, 175, 50, 50);
}
char now = '0'; // 現在案哪個按鍵呢
int p1 = 0, p2 = 0, p3 = 0; // 變數紀錄按鍵, 一開始沒按, 下面做修改
void keyPressed() {
  now = key;
  if (p1==0 && key=='1') myPort.write('1'); // 之前沒有現在按
  if (p2==0 && key=='2') myPort.write('2');
  if (p3==0 && key=='3') myPort.write('3');
  if (p1==0 && key=='1') p1 = 1; // 0 代表放下去
  if (p2==0 && key=='2') p2 = 1;
  if (p3==0 && key=='3') p3 = 1;
}
void keyReleased() {
  now = '0';
  if (key=='1') p1 = 0; // 放開 1 鍵
  if (key=='2') p2 = 0; // 放開 2 鍵
  if (key=='3') p3 = 0; // 放開 3 鍵
  myPort.write('0'); // 告訴 Arduino 你不要發聲音!!!
}
