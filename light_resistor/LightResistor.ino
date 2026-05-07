// асоціація змінної з номером піна. Змінна типу int.
int sensePin = 0;

void setup() {
    // налаштування дебаг
    Serial.begin(9600);
}

void loop() {
    // вичитуєм значення з аналогового піна
    // до якого підключений фоторезистор
    int lightValue = analogRead(sensePin);
    Serial.print("Значення з фоторезистора: ");
    Serial.println(lightValue);

    delay(500);
}
