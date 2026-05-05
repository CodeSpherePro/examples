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
    // вичитуєм значення з аналогового піна до якого підключений фоторезистор
    int lightValue = analogRead(sensePin);
    Serial.print("Значення з фоторезистора: ");
    Serial.println(lightValue);

    // приводимо значення в певний діапазон
    // все що виходить за межі відсікається
    int value = constrain(lightValue, 500, 900);
    Serial.print("стабілізоване значення: ");
    Serial.println(value);

    // адаптовуємо обрізаний діапазон до значень напруги
    int ledLevel = map(value, 500, 900, 255, 0);
    Serial.print("Рівень led: ");
    Serial.println(ledLevel);
    digitalWrite(ledPin, ledLevel);

    delay(500);
}
