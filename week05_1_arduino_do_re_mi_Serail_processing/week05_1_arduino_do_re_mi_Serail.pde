// week05_1_arduino_do_re_mi_Serail
// 修改自 week02_5_prossing_Do_Re_Mi_im[ort_serial_myport_void_keyPressed_write
import processing.serial.*; // 使用 USB Serial 外掛
Serial myProt;
void setup() {
  size(300, 200);
  myProt = new Serial(this, "COM3", 9600); // 中間 "COM3"
}
void draw() {
  
}
void keyPressed() {
  if (key=='1') myProt.write('1');
  if (key=='2') myProt.write('2');
  if (key=='3') myProt.write('3');
}
