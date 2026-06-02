// Підключення бібліотеки
#include <LiquidCrystal.h>

// RS: 2 EN: 3 D4: 4 D5: 5 D6: 6 D7: 7
const int RS = 2, EN = 3, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
// Ініціалізаці об'єкта LCD
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
    // Налаштування розмірів екрану
    lcd.begin(16, 2);
    // Виводимо фразу з 0 рядка 0 символа
    lcd.print(" Hello, world!");
}

void loop() {
    // Переводимо курсор в стовпець 0, ряд 1
    lcd.setCursor(0, 1);
    // Додаємо 6 пропусків, щоб перемістити в середину
    lcd.print("       ");
    // Виводимо число секунд після перезавантаження
    lcd.print(millis() / 1000);
}