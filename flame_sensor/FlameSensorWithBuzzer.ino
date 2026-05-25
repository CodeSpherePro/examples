// ініціалізація змінних з номером піна
// Датчик YS-17 через резистор 10 кОм
const int flamePin = A0;
// Активний зумер
const int buzzerPin = 2;

// Налаштування порогів чутливості
// Початок задимлення / вогонь далеко
const int thresholdLow = 100;
// Пряме полум'я близько
const int thresholdHigh = 300;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);

  // Тестовий гудок при ввімкненні, щоб перевірити зумер
  digitalWrite(buzzerPin, HIGH);
  delay(100);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  int flameValue = analogRead(flamePin); // Зчитуємо дані з датчика YS-17

  Serial.print("Рівень ІЧ-випромінювання: ");
  Serial.println(flameValue);

  // Випадок 1: КРИТИЧНА НЕБЕЗПЕКА (Вогонь дуже близько)
  if (flameValue > thresholdHigh) {
    // Швидке переривчасте пищання
    digitalWrite(buzzerPin, HIGH);
    delay(80);
    digitalWrite(buzzerPin, LOW);
    delay(80);
  }
  // Випадок 2: ПОПЕРЕДЖЕННЯ (Слабкий вогонь або фіксація на відстані)
  else if (flameValue > thresholdLow) {
    // Повільне переривчасте пищання
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(300);
  }
  // Випадок 3: ВСЕ БЕЗПЕЧНО
  else {
    digitalWrite(buzzerPin, LOW);  // Гарантовано вимикаємо зумер
    delay(150);                    // Невелика пауза між опитуваннями
  }
}