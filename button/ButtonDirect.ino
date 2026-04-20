// ініціалізація змінних з номером піна
unsigned int switchPin = 2;
unsigned int ledPin = 4;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(switchPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    // якщо статус == true
    if (digitalRead(switchPin)) {
        // то подаєм живлення
        Serial.println("подаєм живлення");
        digitalWrite(ledPin, HIGH);
    } else {
        // інакше знімаєм живлення
        Serial.println("знімаєм живлення");
        digitalWrite(ledPin, LOW);
    }

}

