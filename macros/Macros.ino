// ==============================
// 1. МАКРОСИ-КОНСТАНТИ
// ==============================

// Номер піна світлодіода
#define LED_PIN 13

// Затримка в мілісекундах
#define DELAY_TIME 5000

// ==============================
// 2. УМОВНІ МАКРОСИ
// ==============================

// Увімкнути режим дебагу
#define DEBUG_MODE 1

// Версія плати
#define BOARD_VERSION 2

// ==============================
// 3. МАКРОСИ-ФУНКЦІЇ
// ==============================

// Піднесення числа до квадрату
#define SQUARE(x) ((x) * (x))

// Увімкнення світлодіода
#define LED_ON() digitalWrite(LED_PIN, HIGH); \
  Serial.println("LED Включений")

// Вимкнення світлодіода
#define LED_OFF() digitalWrite(LED_PIN, LOW); \
  Serial.println("LED Виключений")

// Перевірка числа на парність
#define IS_EVEN(num) (((num) % 2) == 0)

// ==============================
// 4. МАКРОС ДЛЯ ДЕБАГУ
// ==============================

// Виводить назву змінної
// та її значення
#define DEBUG_PRINT(var) \
  Serial.print(#var); \
  Serial.print(" = "); \
  Serial.println(var)

void setup() {
  // Перевіряємо режим дебагу
  #if DEBUG_MODE == 1
    // Запускаємо Serial Monitor
    Serial.begin(9600);
    // Повідомлення про дебаг
    Serial.println(
      "--- Дебаг АКТИВНИЙ ---"
    );
  #endif

  // Налаштовуємо пін світлодіода
  pinMode(LED_PIN, OUTPUT);

  // Перевіряємо версію плати
  #if BOARD_VERSION == 1
    // Конфігурація плати V1
    Serial.println(
      "Стара плата V1"
    );

  #elif BOARD_VERSION == 2
    // Конфігурація плати V2
    Serial.println(
      "Нова плата V2"
    );
  #else

    // Невідома версія плати
    Serial.println(
      "Невідома версія!"
    );

  #endif


  // 1. Тестуємо SQUARE
  int value = 5;

  // Підносимо число до квадрату
  int result = SQUARE(value);

  // Виводимо результат
  #if DEBUG_MODE == 1
    DEBUG_PRINT(result);
  #endif

  // 2. Тестуємо IS_EVEN
  int testNum = 8;

  // Перевіряємо число
  if (IS_EVEN(testNum)) {
    #if DEBUG_MODE == 1
      // Повідомлення про парність
      Serial.println(
        "Число парне!"
      );
    #endif
  }

  // 3. Перевіряємо дужки
  // SQUARE(2 + 3) дає 25
  int complexResult = SQUARE(2 + 3);

  // Виводимо результат
  #if DEBUG_MODE == 1
    DEBUG_PRINT(complexResult);
  #endif
}


void loop() {
  // Вмикаємо світлодіод
  LED_ON();

  // Затримка 5000 мс
  delay(DELAY_TIME);

  // Вимикаємо світлодіод
  LED_OFF();

  // Затримка 5000 мс
  delay(DELAY_TIME);
}
