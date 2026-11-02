// wweek09_2_ai_PCM_D8_laser_powerUp_siren
// 想要發出更特別的聲音，有滑音
// Q5: 剛剛的 week09_1_ai_makerUNO_PCM_D8 修改自你的 MakerUNO_PCM_D8.zip 成功了
// 現在想做 week09_2 想要有比較精彩、好聽、有變化的聲音，而且希望聲音比剛剛大一些。
// 請給我建議

#include "PCM.h"
#include "sounddata.h"

void playClip(const unsigned char* data, int sampleCount) {
  startPlayback(data, sampleCount);
  delay((unsigned long)sampleCount / 8 + 25);
  stopPlayback();
}

void setup() {
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
}

void loop() {

  playClip(siren_data, siren_length);
  
  // 播放完畢後等待 3 秒鐘
  delay(3000);
}
