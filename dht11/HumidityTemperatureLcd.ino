#include <DHT.h>
// Бібліотека датчика DHT

#include <LiquidCrystal_I2C.h>
// Бібліотека LCD по I2C

// Пін підключення DHT11
#define DHTPIN 2

// Тип датчика
#define DHTTYPE DHT11

// Створюємо об'єкт DHT
DHT dht(DHTPIN, DHTTYPE);

// Створюємо LCD:
// адреса 0x27, 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Власний символ градуса
byte degree[8] = {
  B00110,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

void setup() {

  // Запускаємо Serial Monitor
  Serial.begin(9600);

  // Ініціалізація DHT11
  dht.begin();

  // Ініціалізація LCD
  lcd.init();

  // Вмикаємо підсвічування
  lcd.backlight();

  // Вітальне повідомлення
  lcd.print("Hello to Display");

  // Створюємо символ градуса
  lcd.createChar(0, degree);
}

void loop() {
  // Оновлення кожні 2 секунди
  delay(2000);

  // Очищаємо дисплей
  lcd.clear();

  // Виводимо температуру
  // та вологість
  setTempHumidity();
}

// Зчитування показників
// із датчика DHT11
void setTempHumidity() {

  // Зчитуємо вологість
  float h = dht.readHumidity();

  // Зчитуємо температуру
  float t = dht.readTemperature();

  // Якщо дані не отримано
  if (isnan(h) || isnan(t)) {

    lcd.setCursor(0, 0);

    // Повідомлення про помилку
    lcd.print("Failed to read");

    return;
  }

  // Виводимо температуру
  printTemperature(t);

  // Виводимо вологість
  printHumidity(h);
}

// Виведення температури
void printTemperature(float t) {
  // Початок першого рядка
  lcd.setCursor(0, 0);

  lcd.print(F("Temp: "));

  // Значення температури
  lcd.print(t);

  // Символ градуса
  lcd.write(0);

  // Літера C
  lcd.print("C");
}

// Виведення вологості
void printHumidity(float h) {

  // Початок другого рядка
  lcd.setCursor(0, 1);

  lcd.print(F("Humidity: "));

  // Значення вологості
  lcd.print(h);

  // Символ відсотків
  lcd.print("%");
}