// week01_5_google_gemini_nouse_wheel_void_mouseWhee
float circleSize = 50;

void setup(){ 
 size(400, 400);
}

void draw(){
  background(220);
  // 畫出圓形
  ellipse(width / 2, height / 2, circleSize, circleSize);
}

void mouseWheel(MouseEvent event){
  float e = event.getCount();
  // 每次滾動改變大小
  circleSize -= e * 5;
  // 固定最大與最大與最小值
  circleSize -= e * 5;
}
