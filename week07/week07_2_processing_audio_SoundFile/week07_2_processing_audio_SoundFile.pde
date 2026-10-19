// week07_2_processing_audio_SoundFile
// 修改自 week07_1_prcessing_audio_SoundFile_play

import processing.sound.*; // 使用外掛
SoundFile sound; // 宣告變數
SoundFile sound2;
void setup() {
  size(300, 300);
  sound = new SoundFile(this, "music.mp3");
  sound2 = new SoundFile(this, "mi.wav");
  sound.play(); // 準備好 music.mp3 拉到程式裡,播放
}      
void draw(){
  
}
void mousePressed() {
  sound2.play();
}
