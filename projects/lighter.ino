unsigned int  redPin = 12;  // association variable with pin number
unsigned int  yellowPin = 8; // асоціація змінної з номером піна. Змінна типу int.
unsigned int  greenPin = 4;
unsigned int  switchPin = 2;

boolean lastButton = LOW;
boolean lighterOn = false;
boolean currentButton = LOW;

boolean debounce(boolean last) {
  boolean current = digitalRead(switchPin);
  if (last != current) {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}

void setup() {
  // налаштування режиму пінів
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(switchPin, INPUT);

}

void customDelay(int inputDelay) {
  int counter = 0;
  while(counter < inputDelay) {
    checkButtonStatus();
    delay(5);
    counter = counter + 5;
  }
}

void loop() {
  checkButtonStatus();

  if (lighterOn) {
    turnOnLighter();
  } else {
    yellowBlinkingLighter();
  }

  lastButton = currentButton;
}

void checkButtonStatus(){
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH) { // перевірка натиску кнопки
    lighterOn = !lighterOn; // інвертуємо значення включено на виключено і навпаки
  }
}

void turnOnLighter() {
  blinkLED(redPin, 3000, 200);
  blinkLED(yellowPin, 1000, 200);
  blinkLED(greenPin, 3000, 200);

  blinkLED(yellowPin, 1000, 200);
  for(int index = 0; index < 3; index++) {
    blinkLED(yellowPin, 200, 200);
  }
}

void turnOffLighter() {
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}

void yellowBlinkingLighter() {
  turnOffLighter();
  blinkLED(yellowPin, 1000, 500);
}

void blinkLED(int pin, int durationHigh, int durationLow) {
  digitalWrite(pin, HIGH); // включення
  delay(durationHigh); // затримка
  digitalWrite(pin, LOW); // виключення
  delay(durationLow); // затримка
}