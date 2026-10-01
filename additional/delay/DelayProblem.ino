const int redLed = 2;
const int greenLed = 3;

// ЦЕЙ КОД ДЕМОНСТРУЄ БАГ І БЛОКУВАННЯ ПРОЦЕСОРА
void setup() {
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
}

void loop() {
    // Червоний діод повністю паралізує loop на 1 секунду
    digitalWrite(redLed, HIGH);
    delay(1000);
    digitalWrite(redLed, LOW);
    delay(1000);

    // Зелений діод ніколи не зможе блимати
    // паралельно чи швидше, він заблокований!
    digitalWrite(greenLed, HIGH);
    delay(200);
    digitalWrite(greenLed, LOW);
    delay(200);
}
