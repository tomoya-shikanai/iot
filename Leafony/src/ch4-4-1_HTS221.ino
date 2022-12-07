#include <HTS221.h> // 温湿度ライブラリ読込
HTS221 hts;
void setup() {
  Serial.begin(115200);  // シリアル通信宣言
  hts.begin();
}

void loop() {
  float tmp = hts.readTemperature();
  float hum = hts.readHumidity();
  Serial.print("温度 = " + String(tmp) + " C, ");
  Serial.println("湿度 = " + String(hum) + "%");
  if (tmp > 26.8) {
    Serial.println("【注意】温度が26.8Cを超えました！");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(1000);
}