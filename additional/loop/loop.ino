unsigned int ledPin = 9; // Пін з підтримкою ШІМ (PWM)
unsigned int ledPins[] = {3, 5, 6, 10, 11}; // Масив номерів пінів ШІМ (PWM)
int count = sizeof(ledPins) / sizeof(ledPins[0]); // Обчислюємо довжину (5)

int sensorPin = A0;
int sensorValue;

void setup() {
  //  Налаштовуємо led пін на вихід
  pinMode(ledPin, OUTPUT);

  // Налаштовуємо всі піни на вихід одним циклом
  for (int i = 0; i < count; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  Serial.begin(9600);
  Serial.println("Очікування стабілізації датчика...");
  
  // Цикл триває, поки значення з датчика занадто низьке
  while (analogRead(sensorPin) < 200) {
    delay(100); 
    // Програма "зависне" тут, поки сигнал не перевищить 200
  }
  
  Serial.println("Датчик готовий до роботи!");
}

void loop() {
  for(int i = 0; i < 5; i++){
    blinkLED(ledPin, 500);
  }

  // Збільшуємо яскравість від 0 до 255
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);
    delay(5); // Затримка для плавності
  }

  // Зменшуємо яскравість від 255 до 0
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(5);
  }

  // Почергово вмикаємо кожен світлодіод ("біжучий вогонь")
  for (int i = 0; i < count; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(200);
    digitalWrite(ledPins[i], LOW);
  }

  do {
    sensorValue = analogRead(A1);
    Serial.print("Зчитуємо: ");
    Serial.println(sensorValue);
    delay(100);
    // Повторюємо, поки значення менше 100
  } while (sensorValue < 100);
  Serial.println("Поріг подолано!");

  // 1. Зовнішній цикл вибирає, який світлодіод зараз працює
  for (int i = 0; i < count; i++) {
    
    // 2. Внутрішній цикл плавно піднімає яскравість вибраного LED
    for (int brightness = 0; brightness <= 255; brightness++) {
      analogWrite(ledPins[i], brightness);
      delay(2); 
    }
    // Вимикаємо перед переходом до наступного піна
    digitalWrite(ledPins[i], LOW); 
  }

  Serial.println("--- Початок сканування датчиків ---");

  for (int i = 2; i <= 11; i++) {
    // 1. Приклад continue
    if (i == 5) {
      Serial.println("Пін 5 зарезервовано. Пропускаємо...");
      continue; // негайно переходить до i = 6, ігноруючи код нижче
    }

    Serial.print("Перевірка піна ");
    Serial.println(i);

    // 2. Приклад break
    if (digitalRead(i) == HIGH) {
      Serial.print("Знайдено сигнал на піні: ");
      Serial.println(i);
      // негайно перериває весь цикл for і виходить із нього
      break;
    }
  }
}

void blinkLED(int pin, int duration) {
  // включення pin
  digitalWrite(pin, HIGH);
  // затримка
  delay(duration);
  // виключення pin
  digitalWrite(pin, LOW);
  // затримка
  delay(duration);
}
