// ініціалізація змінних з номером піна
unsigned int switchPin = 2;
unsigned int ledPin = 4;

// створення змінних для запам'ятовування статусу
boolean ledOnStatus = false;
boolean lastButtonStatus = LOW;
unsigned int count = 0;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(switchPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    // вичитуємо статус кнопки
    boolean currentButtonStatus = digitalRead(switchPin);
    // якщо не статус не рівний попередньому
    if (lastButtonStatus != currentButtonStatus && currentButtonStatus == HIGH) {
        count++;
        Serial.print("count=");
        Serial.println(count);
        if (count == 3) {
            // то робимо інверсію статусу світлодіода
            ledOnStatus = !ledOnStatus;
            Serial.print("ledOnStatus=");
            Serial.println(ledOnStatus);
            count = 0;
        }
    }
    // якщо статус == true
    if (ledOnStatus) {
        // то подаєм живлення
        digitalWrite(ledPin, HIGH);
    } else {
        // інакше знімаєм живлення
        digitalWrite(ledPin, LOW);
    }
    delay(200);
}
