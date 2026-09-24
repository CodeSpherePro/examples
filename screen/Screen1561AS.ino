// Визначаємо піни Arduino для кожного сегмента дисплея
const int segA = 2;
const int segB = 3;
const int segC = 4;
const int segD = 5;
const int segE = 6;
const int segF = 7;
const int segG = 8;
// Пін для крапки (Decimal Point)
const int segDP = 9;

// Загальна кількість сегментів (без крапки)
const int SEGMENT_COUNT = 7;

// Масив для привязки сегменту до піна
int segments[SEGMENT_COUNT] = {segA, segB, segC, segD, segE, segF, segG};
// Двовимірний масив (матриця) карт цифр від 0 до 9
// Порядок сегментів у рядку: A, B, C, D, E, F, G
byte digitMap[10][SEGMENT_COUNT] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};
void setup() {
    // Налаштовуємо всі піни сегментів та крапки як ВИХОДИ (OUTPUT)
    for (int i = 0; i < SEGMENT_COUNT; i++) {
        pinMode(segments[i], OUTPUT);
    }
    pinMode(segDP, OUTPUT);
    // Гасимо крапку при старті
    digitalWrite(segDP, LOW);
}

void loop() {
    // Послідовно перебираємо цифри від 0 до 9
    for (int digit = 0; digit < 10; digit++) {
        // 1. КЕРУВАННЯ КРАПКОЮ:
        // Вмикаємо її ТІЛЬКИ якщо поточна цифра дорівнює 6 або 9
        if (digit == 6 || digit == 9) {
            // Вмикаємо крапку
            digitalWrite(segDP, HIGH);
        } else {
            // Вимикаємо крапку для всіх інших цифр
            digitalWrite(segDP, LOW);
        }

        // 2. ВИВЕДЕННЯ ЦИФРИ: Обходимо 2D-масив для поточного номера рядка
        for (int seg = 0; seg < SEGMENT_COUNT; seg++) {
            digitalWrite(segments[seg], digitMap[digit][seg]);
        }

        // Затримка в 1 секунду перед наступною цифрою
        delay(1000);
    }
}