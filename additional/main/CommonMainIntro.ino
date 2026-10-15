#include <avr/io.h>
#include <util/delay.h>
int main(void) {
    // Налаштовуємо 5-й біт порту B
    // (цифровий пін 13 на Uno) на ВИХІД
    DDRB = 32;
    // Безкінечний цикл
    while (1) {
        // Вмикаємо світлодіод (HIGH)
        PORTB |= 32;
        // Чиста затримка кристалу на 500 мілісекунд
        _delay_ms(500);
        // Вимикаємо світлодіод (LOW)
        PORTB &= ~32;
        _delay_ms(500);
    }
    return 0;
}