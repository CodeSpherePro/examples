// підключення бібліотеки math
#include <math.h>

// асоціація змінної з номером піна. Змінна типу int.
// Пін, до якого підключено дільник
int sensePin = 0;
// Пін, до якого підключено світлодіод
int ledPin = 3;

// Опір постійного резистора (10кОм)
const float R_FIXED = 10000.0;

// Коефіцієнти Стейнхарта-Харта для MF52A1 (B=3950)
const float A = 1.106837e-03;
const float B = 2.384642e-04;
const float C = 6.507393e-08;

void setup() {
    // налаштування режиму пінів
    pinMode(ledPin, OUTPUT);
    // налаштування дебаг
    Serial.begin(9600);
}

void loop() {
    // вичитуєм значення з аналогового піна
    // до якого підключений фоторезистор
    int thermValue = analogRead(sensePin);
    Serial.print("Значення з термістора: ");
    Serial.println(thermValue);


    // 1. Обчислюємо опір термістора
    // Формула: R = R_fixed * ( (1023 / ADC) - 1 )
    float resistance = R_FIXED * (1023.0 / (float)thermValue - 1.0);
    Serial.print("Опір термістора: ");
    Serial.println(resistance);

    // 2. Формула Стейнхарта-Харта
    float logR = log(resistance);
    float tempK = 1.0 / (A + B * logR + C * logR * logR * logR);
    Serial.print("температура в кельвінах: ");
    Serial.println(tempK);

    // 3. Переводимо в Цельсії
    float tempC = tempK - 273.15;
    Serial.print("температура в цельсіях: ");
    Serial.println(tempC);


    // приводимо значення в певний діапазон
    // все що виходить за межі відсікається
    int value = constrain(thermValue, 500, 900);
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
