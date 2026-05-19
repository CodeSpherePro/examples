// ініціалізація змінних з номером піна
// Пін до якого підключено ІЧ сенсор
int sensePin = 4;
// Пін до якого підключено світлодіод
int ledPin = 2;

void setup() {
    // налаштування режиму пінів
    pinMode(ledPin, OUTPUT);
    // налаштування дебаг
    Serial.begin(9600);
}

void loop() {
    // вичитування статусу піна
    int currentState = digitalRead(sensePin);
    // запис стану в консоль
    Serial.println(currentState);
    // передача стану 0 або 1 на світлодіод
    digitalWrite(ledPin, currentState);

    delay(1000);
}