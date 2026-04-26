// асоціація змінної з номером піна. Змінна типу int.
unsigned int  redPin = 12;
unsigned int  yellowPin = 8;
unsigned int  greenPin = 4;
unsigned int  switchPin = 2;

// збереження статусу
boolean lastButton = HIGH;
boolean lighterOn = false;
// HIGH для INPUT_PULLUP режиму
boolean currentButton = HIGH;

void setup() {
  // налаштування режиму пінів
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  // налаштування дебаг
  Serial.begin(9600);
}

void loop() {
  checkButtonStatus();
  // перевіряєм який резим включений, якщо true то працює
  if (lighterOn) {
    turnOnLighter();
  // інакше моргаючий жовтий
  } else {
    yellowBlinkingLighter();
  }

  lastButton = currentButton;
}

void checkButtonStatus(){
  // вичитуєм значення піна кнопки
  currentButton = debounce(lastButton);
  //дебаг для відслідковування натискання, можна відключити
  if (currentButton == LOW) {
    Serial.print("currentButton=");
    Serial.println(currentButton);
  }
  // якщо натиснута кнопка
  if (lastButton == HIGH && currentButton == LOW) {
    Serial.println("inversion");
    lighterOn = !lighterOn; // інвертуємо значення
  }
}

void turnOnLighter() {
  // світимо червоне, жовте, зелене, моргаюче жовте перед червоним
  blinkWithCheck(redPin, 3000, 200);
  blinkWithCheck(yellowPin, 1000, 200);
  blinkWithCheck(greenPin, 3000, 200);
  blinkWithCheck(yellowPin, 1000, 200);
  for(int index = 0; index < 3; index++) {
    blinkWithCheck(yellowPin, 200, 200);
  }
}

void blinkWithCheck(int pin, int durationHigh, int durationLow){
  // якщо світлофор в робочому стані
  if (lighterOn) {
    blinkLED(pin, durationHigh, durationLow);
  }
}

// усунення тремтіння кнопки
boolean debounce(boolean last) {
  boolean current = digitalRead(switchPin);
  if (last != current) {
    delay(50);
    current = digitalRead(switchPin);
  } else {
    // додаєм затримку для коректності прорахунку
    delay(50);
  }
  return current;
}

// гасимо все світло
void turnOffLighter() {
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}

// режим моргаючого світлофора з відслідковуванням включення
void yellowBlinkingLighter() {
  turnOffLighter();
  blinkLED(yellowPin, 1000, 500);
}

// моргання світлодіодом
void blinkLED(int pin, int durationHigh, int durationLow) {
  digitalWrite(pin, HIGH); // включення
  customDelay(durationHigh); // затримка
  digitalWrite(pin, LOW); // виключення
  customDelay(durationLow); // затримка
}

// налаштування затримки з перевіркою натискання кнопки
// імітація конкурентності
void customDelay(int inputDelay) {
  int counter = 0;
  while(counter < inputDelay) {
    checkButtonStatus();
    delay(5);
    counter = counter + 55;
  }
}