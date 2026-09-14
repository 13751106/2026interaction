// week02_1_void_setup_void_draw_fill_textSize_text_key
void setup() {
  size(500, 500); // 視窗大小
}
void draw() {
  if (mousePressed) background(#F58A8A);
  else background(#D6F074); // 用 Tool-Color 選擇器
  fill(0, 0, 255); // 藍色的填充
  textSize(80); // 字的大小
  text("key:" + key, 200, 300); 
}
