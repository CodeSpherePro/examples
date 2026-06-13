// Підключення бібліотеки для І2С
#include <Wire.h>

// По замовчуванню використовують порти А4 для SDA та А5 для SCL
// Порти змінити неможливо
void setup() {
    Wire.begin();        // Ініціалізація шини I2C як ведучого (Master)
    Serial.begin(9600);  // Ініціалізація послідовного порту на швидкості 9600
    while (!Serial);     // Очікування відкриття Монітора порту
    Serial.println("\n--- I2C Сканер запускається ---");
}

void loop() {
    byte error, address;
    int nDevices = 0;

    Serial.println("Сканування...");

    // Цикл перебирає всі можливі 7-бітні адреси I2C
    for (address = 1; address < 127; address++) {
        // Починаємо передачу даних на конкретну адресу
        Wire.beginTransmission(address);
        // Завершуємо передачу. Функція повертає 0, якщо пристрій підтвердив свою адресу (ACK)
        error = Wire.endTransmission();

        if (error == 0) {
            Serial.print("Знайдено пристрій за адресою: 0x");
            // Додаємо нуль для красивого відображення HEX
            if (address < 16) Serial.print("0");
            Serial.print(address, HEX);
            Serial.println(" !");

            nDevices++;
        }
        else if (error == 4) {
            Serial.print("Невідома помилка за адресою: 0x");
            if (address < 16) Serial.print("0");
            Serial.println(address, HEX);
        }
    }

    if (nDevices == 0) {
        Serial.println("Пристроїв I2C не знайдено.\n");
    } else {
        Serial.println("Сканування завершено.\n");
    }

    delay(5000); // Повторювати сканування кожні 5 секунд
}