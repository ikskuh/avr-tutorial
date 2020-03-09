int button = getPressedButton();
PORTD = 0x00;
if (button != 0) {
  delay(350);
  PORTD = (1 << (button + 2));
}