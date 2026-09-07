// Вбудований світлодіод на Arduino Uno
const byte ledPin = 13;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);

    // Зменшуємо таймаут очікування з 1000мс до 100мс,
    // щоб Arduino не "зависала" на секунду, чекаючи всі 9 байтів
    Serial.setTimeout(100);

    Serial.println("Система готова. Введіть ON або OFF:");
}

void loop() {
    if (Serial.available() > 0) {
        char inputBuffer[10]; // Масив на 10 елементів (9 для даних + 1 для \0)

        // Зчитуємо максимум 9 байтів (як у вашому запиті)
        int bytesRead = Serial.readBytes(inputBuffer, 9);

        // Обов'язково закриваємо рядок нуль-термінатором
        inputBuffer[bytesRead] = '\0';

        // Перетворюємо в String для очищення від невидимих символів (\r, \n)
        String command = String(inputBuffer);
        command.trim();

        if (command.length() > 0) {
            // Виводимо фразу за вашим шаблоном
            Serial.print("введено було <");
            Serial.print(command);
            Serial.println(">");

            // Керування світлодіодом
            if (command == "ON") {
                digitalWrite(ledPin, HIGH);
                Serial.println("Результат: Світлодіод УВІМКНЕНО");
            }
            else if (command == "OFF") {
                digitalWrite(ledPin, LOW);
                Serial.println("Результат: Світлодіод ВИМКНЕНО");
            }
            else {
                Serial.println("Результат: Невідома команда!");
            }

            Serial.println("------------------------------------");
        }
    }
}
