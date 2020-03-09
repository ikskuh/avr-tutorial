void setup() {
  Serial.begin(19200);
  Serial.print("Hello, World!\r\n");
}

void loop() {
  Serial.write(Serial.read());
}
