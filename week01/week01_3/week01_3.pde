// week01_3_painter_if_mousePressed_line_if_mouseButton_stroke
// 用 mouse 畫圖
void setup(){ 
 size(500, 500); // 視窗大小
}

void draw(){
  if(mouseButton==LEFT)stroke(255, 0, 0);
  if(mouseButton==RIGHT)stroke(0, 0, 255);
  if(mouseButton==CENTER)stroke(0, 255, 0);
  if(mousePressed) line(mouseX, mouseY, pmouseX, pmouseY);
  // 按下去的時候, 用不同色彩畫線
}
