// week09_1_arduino_ai_makeruno_PCM_D8
// 想要讓 MakerUNO 發出更多元的聲音，不要只是用單調的 tone()

// Q1: MakerUNO 本身可以用 pin 8 的 buzzer 利用 tone() 來發出單調的聲音。
// 有辦法發出比較精彩的聲音嗎? ex. wav or mp3
// 

#include "PCM.h"
#include "sounddata.h"

void setup() {
  startPlayback(sounddata_data, sounddata_length);
}

void loop() {
  // One-shot sample plays for 1 second. Press RESET to play again.
}
