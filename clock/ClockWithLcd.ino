// Бібліотека для LCD по I2C
#include <LiquidCrystal_I2C.h>

// Бібліотека інтерфейсу
// ThreeWire
#include <ThreeWire.h>

// Бібліотека для роботи
// з модулем DS1302
#include <RtcDS1302.h>

// Створюємо об'єкт LCD.
// 0x27 - I2C адреса.
// 16 символів.
// 2 рядки.
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Підключення DS1302:
// DAT -> D7
// CLK -> D6
// RST -> D8
ThreeWire myWire(7, 6, 8);

// Створюємо об'єкт
// годинника реального часу.
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {

  // Запускаємо Serial Monitor
  // для налагодження.
  Serial.begin(9600);

  // Ініціалізація LCD.
  lcd.init();

  // Вмикаємо підсвічування.
  lcd.backlight();

  // Виводимо привітання.
  lcd.print("Hello to Display");

  // Очищаємо дисплей.
  lcd.clear();

  // Повідомлення про запуск.
  lcd.print("    Load   ");

  // Невелика затримка.
  delay(200);

  // Ініціалізація DS1302.
  Rtc.Begin();

  // Створюємо дату та час
  // із моменту компіляції.
  RtcDateTime currentTime =
      RtcDateTime(__DATE__, __TIME__);

  // Записуємо дату і час
  // у модуль DS1302.
  Rtc.SetDateTime(currentTime);

  // Виводимо дату
  // компіляції.
  Serial.println(__DATE__);

  // Виводимо час
  // компіляції.
  Serial.println(__TIME__);
}

void loop() {

  // Оновлення раз
  // на секунду.
  delay(1000);

  // Очищаємо дисплей.
  lcd.clear();

  // Виводимо дату
  // та час.
  printDateTime();
}

// Отримуємо поточний
// час із DS1302.
void printDateTime() {

  // Зчитуємо дату та час.
  RtcDateTime now =
      Rtc.GetDateTime();

  // Виводимо дату.
  printDate(now);

  // Виводимо час.
  printTime(now);
}

// Виведення дати.
void printDate(RtcDateTime now) {

  // Початок першого рядка.
  lcd.setCursor(0, 0);
  lcd.print("Date: ");

  // День.
  lcd.print(now.Day());
  lcd.print("/");

  // Місяць.
  lcd.print(now.Month());
  lcd.print("/");

  // Рік.
  lcd.print(now.Year());
}

// Виведення часу.
void printTime(RtcDateTime now) {
  // Початок другого рядка.
  lcd.setCursor(0, 1);
  lcd.print("Time: ");

  // Години.
  lcd.print(now.Hour());
  lcd.print(":");

  // Хвилини.
  lcd.print(now.Minute());
  lcd.print(":");

  // Секунди.
  lcd.print(now.Second());
}