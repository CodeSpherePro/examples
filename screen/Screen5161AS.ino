// Піни для сегментів через резистори 220 Ом
const int segA = 2;
const int segB = 3;
const int segC = 4;
const int segD = 5;
const int segE = 6;
const int segF = 7;
const int segG = 8;

// Катоди розрядів (DIG1-DIG4) дисплея
const int dig1 = 10;
const int dig2 = 11;
const int dig3 = 12;
const int dig4 = 13;
// Кількість сегментів у одному розряді
const int SEGMENT_COUNT = 7;
// Загальна кількість розрядів дисплея
const int DIGIT_COUNT = 4;

// Масив з номерами пінів для сегментів A-G
int segments[SEGMENT_COUNT] = {segA, segB, segC, segD, segE, segF, segG};
// Масив з номерами пінів для катодів DIG1-DIG4
int digitPins[DIGIT_COUNT] = {dig1, dig2, dig3, dig4};

// Карта цифр 0-9 для спільного катода (1-горить)
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

// Великий масив чисел для ефекту біжучого рядка
int scrollSequence[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2};
// Поточний зсув індексу кадру вліво
int currentOffset = 0;
// Змінна таймера для зсуву біжучого рядка
unsigned long lastShiftTime = 0;
// Швидкість руху рядка в мілісекундах (300 мс)
const unsigned long shiftInterval = 300;

// Функція початкового налаштування мікроконтролера
void setup() {
    // Конфігуруємо піни сегментів як виходи
    for (int i = 0; i < SEGMENT_COUNT; i++) {
        pinMode(segments[i], OUTPUT);
    }
    // Конфігуруємо піни катодів як виходи
    for (int i = 0; i < DIGIT_COUNT; i++) {
        pinMode(digitPins[i], OUTPUT);
        // Гасимо розряди при старті (подаємо HIGH)
        digitalWrite(digitPins[i], HIGH);
    }
}

// Головний нескінченний цикл програми
void loop() {
    // Зчитуємо поточний час від старту плати
    unsigned long currentMillis = millis();
    // Перевіряємо інтервал часу для зсуву кадру
    if (currentMillis - lastShiftTime >= shiftInterval) {
        // Оновлюємо час останнього зсуву рядка
        lastShiftTime = currentMillis;
        // Зміщуємо кадр відображення на крок вліво
        currentOffset++;
        // Скидаємо цикл зсуву після відображення 9012
        if (currentOffset > 9) currentOffset = 0;
    }

    // Цикл динамічної індикації для 4 розрядів
    for (int d = 0; d < DIGIT_COUNT; d++) {
        // Визначаємо поточну цифру для розряду d
        int currentDigitValue = scrollSequence[currentOffset + d];

        // Виставляємо рівні на пінах для всіх сегментів
        for (int seg = 0; seg < SEGMENT_COUNT; seg++) {
            digitalWrite(segments[seg], digitMap[currentDigitValue][seg]);
        }

        // Активуємо поточний розряд подачею нуля (LOW)
        digitalWrite(digitPins[d], LOW);

        // Затримка 1 мс для інерції людського ока
        delay(1);

        // Вимикаємо розряд перед переходом до наступного
        digitalWrite(digitPins[d], HIGH);
    }
}
