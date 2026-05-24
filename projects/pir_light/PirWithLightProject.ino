// підключення бібліотеки math
#include <math.h>

// ініціалізація змінних з номером піна
// Пін до якого підключено
// PIR-сенсор (Passive Infrared Sensor) ІЧ сенсор
int pirPin = 4;
// Пін до якого підключено
// NTC (термістор із негативним температурним коефіцієнтом)
int ntcPin = A0;
// Пін до якого підключено
// Light Dependent Resistor (фоторезистор)
int ldrPin = A1;
// Пін до якого підключено реле
int releyPin = 2;

const float R_FIXED = 10000.0;

// Коефіцієнти Стейнхарта-Харта для MF52A1 (B=3950)
const float A = 1.106837e-03;
const float B = 2.384642e-04;
const float C = 6.507393e-08;

// Налаштування порогів
const int LIGHT_THRESHOLD = 700; // Порог темряви

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(releyPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // зчитуємо дані з сенсорів
  int motionDetected = digitalRead(pirPin);
  Serial.print("Значення з порта pir: ");
  Serial.println(motionDetected);

  int lightRaw = analogRead(ldrPin);
  Serial.print("Значення з порта ldr: ");
  Serial.println(lightRaw);

  int temperature = getTemperature();
  Serial.print("Температура: ");
  Serial.println(temperature);

  // АДАПТИВНА ЛОГІКА (Корекція під температуру)
  int scanDelay = 500; // Стандартна затримка опитування (0.5 сек)

  if (temperature >= 32.0) {
    // У СПЕКУ: PIR-датчик починає пропускати рухи або "гальмувати".
    // Зменшуємо затримку опитування до мінімуму, щоб схопити найкоротший імпульс.
    scanDelay = 50;

    // Якщо у спеку проскочив навіть найменший натяк на рух,
    // система відпрацьовує його пріоритетно.
    if (motionDetected == HIGH && lightRaw < LIGHT_THRESHOLD) {
      Serial.print("[РЕЖИМ СПЕКИ] Гаряче: ");
      Serial.print(temperature, 1);
      Serial.println("°C. Рух зафіксовано примусово!");

      digitalWrite(releyPin, HIGH);
      delay(3000); // Тримаємо світло увімкненим 3 секунд
    }
  }
  else {
    // НОРМАЛЬНА ТЕМПЕРАТУРА: звичайна робота системи
    if (motionDetected == HIGH && lightRaw < LIGHT_THRESHOLD) {
      Serial.println("[НОРМАЛЬНИЙ РЕЖИМ] Рух виявлено.");
      digitalWrite(releyPin, HIGH);
      delay(2000); // Стандартне увімкнення на 2 секунди
    }
  }

  if (digitalRead(pirPin) == LOW) {
    digitalWrite(releyPin, LOW);
  }

  delay(scanDelay); // Динамічна затримка циклу
}

float getTemperature() {
  // вичитуєм значення з аналогового піна
  // до якого підключений фоторезистор
  int thermValue = analogRead(ntcPin);

  // 1. Обчислюємо опір термістора
  // Формула: R = R_fixed * ( (1023 / ADC) - 1 )
  float resistance = R_FIXED * (1023.0 / (float)thermValue - 1.0);

  // 2. Формула Стейнхарта-Харта
  float logR = log(resistance);
  float tempK = 1.0 / (A + B * logR + C * logR * logR * logR);

  // 3. Переводимо в Цельсії
  float tempC = tempK - 273.15;

  return tempC;
}