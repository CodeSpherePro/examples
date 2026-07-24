// Бібліотека датчика DHT
#include <DHT.h>

// Бібліотека LCD по I2C
#include <LiquidCrystal_I2C.h>

// Бібліотека шини I2C
#include <Wire.h>

// Бібліотека інтерфейсу
// ThreeWire
#include <ThreeWire.h>

// Бібліотека годинника
// реального часу DS1302
#include <RtcDS1302.h>

// Пін підключення DHT11
#define DHTPIN 2

// Тип датчика
#define DHTTYPE DHT11

// Створюємо об'єкт DHT11
DHT dht(DHTPIN, DHTTYPE);

// Створюємо LCD 16x2
// Адреса дисплея 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Підключення DS1302
// DAT -> D7
// CLK -> D6
// RST -> D8
ThreeWire myWire(7, 6, 8);

// Створюємо об'єкт DS1302
RtcDS1302<ThreeWire> Rtc(myWire);

// Символ заповнення 20%
byte p20[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
};

// Символ заповнення 40%
byte p40[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};

// Символ заповнення 60%
byte p60[8] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
};

// Символ заповнення 80%
byte p80[8] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
};

// Символ заповнення 100%
byte p100[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

// Символ градуса
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

  // Запускаємо DHT11
  dht.begin();

  // Ініціалізація LCD
  lcd.init();

  // Вмикаємо підсвічування
  lcd.backlight();

  // Виводимо привітання
  lcd.print("Hello to Display");

  // Записуємо символи
  // у пам'ять LCD
  lcd.createChar(0, p20);
  lcd.createChar(1, p40);
  lcd.createChar(2, p60);
  lcd.createChar(3, p80);
  lcd.createChar(4, p100);
  lcd.createChar(5, degree);

  // Очищаємо дисплей
  lcd.clear();

  // Повідомлення запуску
  lcd.print("    Load   ");

  // Невелика затримка
  delay(200);

  // Малюємо індикатор
  // завантаження
  for (int i = 0; i < 16; i++) {

    // Заповнюємо символ
    // поетапно
    for (int j = 0; j < 5; j++) {

      // Позиція символу
      lcd.setCursor(i, 1);

      // Виведення символу
      lcd.write(j);

      // Затримка анімації
      delay(10);
    }
  }

  // Ініціалізація DS1302
  Rtc.Begin();

  // Створюємо дату та час
  // компіляції скетча
  RtcDateTime currentTime =
    RtcDateTime(__DATE__, __TIME__);

  // Записуємо дату
  // і час у DS1302
  Rtc.SetDateTime(currentTime);

  // Виводимо дату
  // компіляції
  Serial.println(__DATE__);

  // Виводимо час
  // компіляції
  Serial.println(__TIME__);
}

void loop() {

  // Оновлення кожні
  // 2 секунди
  delay(2000);

  // Очищаємо дисплей
  lcd.clear();

  // Виводимо температуру
  // та вологість
  printTempHumidity();

  // Чекаємо 2 секунди
  delay(2000);

  // Очищаємо дисплей
  lcd.clear();

  // Виводимо дату
  // та час
  printDateTime();
}

// Зчитування температури
// та вологості
void printTempHumidity() {

  // Зчитуємо вологість
  float h = dht.readHumidity();

  // Зчитуємо температуру
  float t = dht.readTemperature();

  // Якщо дані не отримано
  if (isnan(h) || isnan(t)) {

    // Початок рядка
    lcd.setCursor(0, 0);

    // Повідомлення
    // про помилку
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
  lcd.write(5);

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

  // Символ %
  lcd.print("%");
}

// Отримання дати
// та часу
void printDateTime() {

  // Зчитуємо дані
  RtcDateTime now =
    Rtc.GetDateTime();

  // Виводимо дату
  printDate(now);

  // Виводимо час
  printTime(now);
}

// Якщо число менше 10,
// додаємо нуль
void print2digits(int value) {

  if (value < 10) {
    lcd.print("0");
  }

  lcd.print(value);
}

// Виведення дати
void printDate(RtcDateTime now) {

  // Початок першого рядка
  lcd.setCursor(0, 0);

  lcd.print("Date: ");

  // День
  print2digits(now.Day());

  lcd.print("/");

  // Місяць
  print2digits(now.Month());

  lcd.print("/");

  // Рік
  lcd.print(now.Year());
}

// Виведення часу
void printTime(RtcDateTime now) {

  // Початок другого рядка
  lcd.setCursor(0, 1);

  lcd.print("Time: ");

  // Години
  print2digits(now.Hour());

  lcd.print(":");

  // Хвилини
  print2digits(now.Minute());

  lcd.print(":");

  // Секунди
  print2digits(now.Second());
}