#include <Arduino.h>

int main(void) {
    // Вручну викликаємо ініціалізацію заліза
    init();

    pinMode(13, OUTPUT);

    while (1) {
        digitalWrite(13, HIGH);
        delay(500);
        digitalWrite(13, LOW);
        delay(500);
    }

    return 0;
}
