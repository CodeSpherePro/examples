// ініціалізація змінних з номером піна
// Датчик MQ2
const int gasPin = A0;
// Датчик YS-17 через резистор 10 кОм
const int flamePin = A1;
// Активний зумер
const int buzzerPin = 2;
// Реле
const int relayPin = 4;
// Зелений світлодіод
const int greenPin = 7;
// Червоний світлодіод
const int redPin = 8;

// Налаштування порогів чутливості
// Невелика кількість газу
const int thresholdGasLow = 150;
// Багато газу
const int thresholdGasHigh = 300;
// Початок задимлення / вогонь далеко
const int thresholdFlameLow = 100;
// Пряме полум'я близько
const int thresholdFlameHigh = 300;

void setup() {
  Serial.begin(9600);
  // Налаштування портів
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  // Тестовий гудок при ввімкненні, щоб перевірити зумер
  blinkDevice(buzzerPin, 100, 100);
}

void loop() {
  // Зчитуємо дані з датчика MQ2
  int gasValue = analogRead(gasPin);
  Serial.print("Насиченість газом: ");
  Serial.println(gasValue);

  // Зчитуємо дані з датчика вогню
  int flameValue = analogRead(flamePin);
  Serial.print("Рівень вогню: ");
  Serial.println(flameValue);

  if (gasValue > thresholdGasLow) {
    // Включаємо витяжку
    digitalWrite(relayPin, HIGH);
  }
  // Випадок 1: КРИТИЧНА НЕБЕЗПЕКА
  // газу багато або полум'я
  if (gasValue > thresholdGasHigh
        || flameValue > thresholdFlameHigh) {
    // Включаємо червоний світлодіод
    digitalWrite(redPin, HIGH);
    // Швидке переривчасте пищання
    blinkDevice(buzzerPin, 80, 80);

  }
  // Випадок 2: ПОПЕРЕДЖЕННЯ (невелике збільшення газу)
  else if (gasValue > thresholdGasLow
        || flameValue > thresholdFlameLow) {
    slowBeepWithRedLed();
  }
  // Випадок 3: ВСЕ БЕЗПЕЧНО
  else {
    standby();
  }
}

void slowBeepWithRedLed() {
    // Світимо світлодіодом на чам сигналу
    digitalWrite(redPin, HIGH);
    // Повільне переривчасте пищання
    blinkDevice(buzzerPin, 300, 300);
    digitalWrite(redPin, LOW);
}

void standby() {
  // Гарантовано вимикаємо всі пристрої
  digitalWrite(buzzerPin, LOW);
  digitalWrite(relayPin, LOW);
  digitalWrite(redPin, LOW);
  // Блимання світлодіодом
  blinkDevice(greenPin, 50, 200);
  // Невелика пауза між опитуваннями
  delay(150);
}

void blinkDevice (int pin, int durationHigh, int durationLow) {
  digitalWrite(pin, HIGH); // включення
  delay(durationHigh); // затримка
  digitalWrite(pin, LOW); // виключення
  delay(durationLow); // затримка
}