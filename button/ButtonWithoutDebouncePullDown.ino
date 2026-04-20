// ініціалізація змінних з номером піна
unsigned int switchPin = 2;
unsigned int ledPin = 4;

// створення змінних для запам'ятовування статусу
boolean ledOnStatus = false;
// низьке по замовчуванню при пулдаун підключенні
boolean lastButtonStatus = LOW;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(switchPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    // вичитуємо статус кнопки
    boolean currentButtonStatus = digitalRead(switchPin);
    Serial.print("currentButtonStatus=");
    Serial.println(currentButtonStatus);
    // якщо не статус не рівний попередньому
    if (lastButtonStatus != currentButtonStatus) {
        // то робимо інверсію статусу світлодіода
        ledOnStatus = !ledOnStatus;
        Serial.print("ledOnStatus=");
        Serial.println(ledOnStatus);
    }
    // якщо статус == true
    if (ledOnStatus) {
        // то подаєм живлення
        Serial.println("подаєм живлення");
        digitalWrite(ledPin, HIGH);
    } else {
        // інакше знімаєм живлення
        Serial.println("знімаєм живлення");
        digitalWrite(ledPin, LOW);
    }

}
