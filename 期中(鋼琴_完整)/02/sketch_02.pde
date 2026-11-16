import processing.serial.*;
import processing.sound.*;

Serial myPort;
SoundFile[] notes = new SoundFile[7];
String[] noteNames = {"Do", "Re", "Mi", "Fa", "Sol", "La", "Ti"};
int activeKey = -1; // 目前按下的琴鍵索引 (-1 表示無)

void setup() {
  size(700, 320);
  textAlign(CENTER, CENTER);
  textSize(24);

  // 1. 列出可用序列埠並連接 Arduino (請依實際情況調整索引 [0])
  printArray(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);

  // 2. 載入 7 個音階音效檔 (請放在專案的 data/ 資料夾內)
  for (int i = 0; i < 7; i++) {
    String fileName = (i + 1) + ".mp3";
    if (dataFile(fileName).exists()) {
      notes[i] = new SoundFile(this, fileName);
    } else {
      println("提醒：找不到音檔 " + fileName + "，僅透過 Arduino 蜂鳴器發聲");
    }
  }
}

void draw() {
  background(30);
  float keyWidth = width / 7.0;

  for (int i = 0; i < 7; i++) {
    // 按下時琴鍵變色，未按下時為白色
    if (i == activeKey) {
      fill(20, 184, 166); // 青綠色高亮
    } else {
      fill(255);
    }
    stroke(40);
    strokeWeight(2);
    rect(i * keyWidth, 0, keyWidth, height, 0, 0, 8, 8);

    // 顯示音名與對應按鍵編號
    fill(i == activeKey ? 255 : 30);
    text(noteNames[i], i * keyWidth + keyWidth / 2, height - 70);
    textSize(16);
    text("[" + (i + 1) + "]", i * keyWidth + keyWidth / 2, height - 35);
    textSize(24);
  }
}

// 觸發指定琴鍵
void triggerNote(int keyIndex) {
  if (keyIndex >= 0 && keyIndex < 7 && activeKey != keyIndex) {
    activeKey = keyIndex;
    if (notes[keyIndex] != null) {
      notes[keyIndex].play();
    }
    char serialChar = char('1' + keyIndex);
    myPort.write(serialChar);
  }
}

// 停止發聲與熄燈
void stopNote() {
  activeKey = -1;
  myPort.write('0');
}

void mousePressed() {
  int keyIndex = int(mouseX / (width / 7.0));
  triggerNote(keyIndex);
}

void mouseReleased() {
  stopNote();
}

void keyPressed() {
  if (key >= '1' && key <= '7') {
    triggerNote(key - '1');
  }
}

void keyReleased() {
  if (key >= '1' && key <= '7') {
    stopNote();
  }
}
