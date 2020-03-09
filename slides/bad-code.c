int button = getPressedButton();
if (button == 1) {
  digitalWrite(RELAIS_1_PIN, HIGH);
  delay(350);
  digitalWrite(RELAIS_2_PIN, LOW);
  digitalWrite(RELAIS_3_PIN, LOW);
  digitalWrite(RELAIS_4_PIN, LOW);
}
if (button == 2) {
  digitalWrite(RELAIS_1_PIN, LOW);
  digitalWrite(RELAIS_2_PIN, HIGH);
  delay(350);
  digitalWrite(RELAIS_3_PIN, LOW);
  digitalWrite(RELAIS_4_PIN, LOW);
}
if (button == 3) {
  digitalWrite(RELAIS_1_PIN, LOW);
  digitalWrite(RELAIS_2_PIN, LOW);
  digitalWrite(RELAIS_3_PIN, LOW);
  
  