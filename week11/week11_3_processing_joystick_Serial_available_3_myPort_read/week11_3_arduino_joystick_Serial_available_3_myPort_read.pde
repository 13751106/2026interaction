// week11_3_arduino_joystick_Serial_available_3_myPort_read
import processing.serial.*; // 
Serial myPort;
void setup() {
  size(512, 512);
  myPort = new Serial( this, "COM3", 9600);
}
int x = 0, y = 0, sw = 0;
void draw() {
  background(255);
  if (myPort.available() >= 3) { // 亂碼
    x = (int)myPort.read();
    y = (int)myPort.read();
    sw = (int)myPort.read();
    // myPort.read
  }
  ellipse( x+128, y+125, 8, 8);
}
