// Пін фоторезистора
const int ldrPin = A0;

void setup() {
    Serial.begin(9600);

    // Легенда для Serial Plotter
    Serial.println("Мін_%,Макс_%,Освітленість_%");
}

void loop() {
    // Зчитуємо сирі дані (0 - 1023)
    int rawValue = analogRead(ldrPin);

    // Конвертуємо 0-1023 у 0-100%
    int percentValue = map(rawValue, 0, 1023, 0, 100);

    // Виводимо межі (0% та 100%) для стабілізації масштабу графіку
    Serial.print(0);
    Serial.print(",");
    Serial.print(100);
    Serial.print(",");

    // Виводимо поточний відсоток освітленості
    Serial.println(percentValue);

    delay(100);
}
