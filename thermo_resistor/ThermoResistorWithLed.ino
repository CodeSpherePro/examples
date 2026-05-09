// асоціація змінної з номером піна. Змінна типу int.
int sensePin = 0;
int ledPin = 3;

void setup() {
    // налаштування режиму пінів
    pinMode(ledPin, OUTPUT);
    // налаштування дебаг
    Serial.begin(9600);
}

void loop() {
    // вичитуєм значення з аналогового піна
    // до якого підключений фоторезистор
    int termValue = analogRead(sensePin);
    Serial.print("Значення з термістора: ");
    Serial.println(termValue);

    // приводимо значення в певний діапазон
    // все що виходить за межі відсікається
    int value = constrain(termValue, 500, 900);
    Serial.print("стабілізоване значення: ");
    Serial.println(value);

    // адаптовуємо обрізаний діапазон
    // до значень напруги
    int ledLevel = map(value, 500, 900, 0, 255);
    Serial.print("Рівень led: ");
    Serial.println(ledLevel);
    analogWrite(ledPin, ledLevel);

    delay(500);
}
