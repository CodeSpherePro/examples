// ініціалізація змінних з номером піна
// Датчик MQ2
// Датчик газу
const int gasPin = A0;
// Активний зумер
const int buzzerPin = 2;

// Налаштування порогів чутливості
// Невелика кількість газу
const int thresholdLow = 150;
// Багато газу
const int thresholdHigh = 300;

void setup() {
    Serial.begin(9600);
    pinMode(buzzerPin, OUTPUT);

    // Тестовий гудок при ввімкненні, щоб перевірити зумер
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
}

void loop() {
    // Зчитуємо дані з датчика MQ2
    int gasValue = analogRead(gasPin);

    Serial.print("Насиченість газом: ");
    Serial.println(gasValue);

    // Випадок 1: КРИТИЧНА НЕБЕЗПЕКА (газу багато)
    if (gasValue > thresholdHigh) {
        // Швидке переривчасте пищання
        digitalWrite(buzzerPin, HIGH);
        delay(80);
        digitalWrite(buzzerPin, LOW);
        delay(80);
    }
    // Випадок 2: ПОПЕРЕДЖЕННЯ (невелике збільшення газу)
    else if (gasValue > thresholdLow) {
        // Повільне переривчасте пищання
        digitalWrite(buzzerPin, HIGH);
        delay(300);
        digitalWrite(buzzerPin, LOW);
        delay(300);
    }
    // Випадок 3: ВСЕ БЕЗПЕЧНО
    else {
        // Гарантовано вимикаємо зумер
        digitalWrite(buzzerPin, LOW);
        // Невелика пауза між опитуваннями
        delay(150);
    }
}