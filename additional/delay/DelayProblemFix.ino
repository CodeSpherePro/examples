const int redLed = 2;
const int greenLed = 3;

bool redState = LOW;
bool greenState = LOW;

unsigned long previousRedMillis = 0;
// Для micros() теж використовуємо unsigned long!
unsigned long previousGreenMicros = 0;

// 1000 мілісекунд (1 секунда)
const unsigned long redIntervalMillis = 1000;
// 200 000 мікросекунд (0.2 секунди)
const unsigned long greenIntervalMicros = 200000;

void setup() {
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
}

void loop() {
    unsigned long currentMillis = millis();
    // Опитуємо високоточний таймер мікросекунд
    unsigned long currentMicros = micros();

    // --- ПРОЦЕС 1: Повільний таймер на millis() ---
    if (currentMillis - previousRedMillis >= redIntervalMillis) {
        previousRedMillis = currentMillis;
        redState = !redState;
        digitalWrite(redLed, redState);
    }

    // --- ПРОЦЕС 2: Швидкий високоточний таймер на micros() ---
    if (currentMicros - previousGreenMicros >= greenIntervalMicros) {
        previousGreenMicros = currentMicros;
        greenState = !greenState;
        digitalWrite(greenLed, greenState);
    }
}