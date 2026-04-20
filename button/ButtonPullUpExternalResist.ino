// ініціалізація змінних з номером піна
unsigned int switchPin = 2;
unsigned int ledPin = 4;

// створення змінних для запам'ятовування статусу
boolean ledOnStatus = false;
// високе по замовчуванню при пулап підключенні
boolean lastButtonStatus = HIGH;

void setup() {
    pinMode(ledPin, OUTPUT);
    // працює тільки з зовнішнім резистором
    pinMode(switchPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    // вичитуємо статус кнопки
    boolean currentButtonStatus = debounce(lastButtonStatus);
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

boolean debounce(boolean last) {
    boolean current = digitalRead(switchPin);
    if (last != current) {
        delay(50);
        current = digitalRead(switchPin);
    }
    return current;
}



