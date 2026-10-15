#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Встановлюємо 5-й біт порту B (Пін D13) на вихід
    DDRB |= (1 << PB5);

    while (1) {
        // Вмикаємо світлодіод (HIGH)
        PORTB |= (1 << PB5);
        _delay_ms(500);

        // Вимикаємо світлодіод (LOW)
        PORTB &= ~(1 << PB5);
        _delay_ms(500);
    }

    return 0;
}