// асоціація змінної з номером піна. Змінна типу int.
// Пін, до якого підключено дільник
int sensePin = 0;
// Пін, до якого підключено світлодіод
int ledPin = 3;

void setup() {
    // налаштування режиму пінів
    pinMode(ledPin, OUTPUT);
    // налаштування дебаг
    Serial.begin(9600);
}

void loop() {
    // вичитуєм значення з аналогового піна
    // до якого підключений ткрморезистор
    int thermValue = analogRead(sensePin);
    Serial.print("Значення з термістора: ");
    Serial.println(thermValue);

    // приводимо значення в певний діапазон
    // все що виходить за межі відсікається
    int value = constrain(thermValue, 500, 900);
    Serial.print("Cтабілізоване значення: ");
    Serial.println(value);

    // адаптовуємо обрізаний діапазон
    // до значень напруги
    int ledLevel = map(value, 500, 900, 0, 255);
    Serial.print("Рівень led: ");
    Serial.println(ledLevel);
    analogWrite(ledPin, ledLevel);

    delay(500);
}
