void setup() {
    Serial.begin(9600);
}

void loop() {
    int buttonState = 1; // виставляємо вхідне значення

    if (buttonState == HIGH) { // Якщо значення змінної buttonState рівне 1 (5V або HIGH)
      Serial.println("Pushed"); // то виводимо Pushed
    } else { // інакше
      Serial.println("Not pushed");  // інакше Not pushed
    }
    delay(1000);
    int temp = 36;
    if (temp > 35) {
      Serial.println("Hot"); // Дуже гаряче!
    } else if (temp > 20) {
      Serial.println("Comfortable"); // Комфортно
    } else {
      Serial.println("Cold"); // Холодно
    }


  int mode = 1; // Поточний режим
  switch (mode) {
    case 0: // Режим: Вимкнено
      digitalWrite(13, LOW);
      break;

    case 1: // Режим: Увімкнено постійно
      digitalWrite(13, HIGH);
      break;

    case 2: // Режим: Блимання
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
      break;

    default: // Якщо режим невідомий (наприклад, помилка)
      mode = 0;
      break;
  }

    delay(10000);
}

/*
    == : дорівнює (не плутайте з =, який призначає значення правої частини лівій).
    != : не дорівнює.
    >  : лівий операнд більше.
    <  : лівий операнд менше.
    >= : більше або дорівнює.
    <= : менше або дорівнює.


    && (І): умова істинна, лише якщо обидві частини правдиві.
    Наприклад:
    if (temp > 20 && light == LOW) { ... }
    || (АБО): умова істинна, якщо хоча б одна частина правдива.
    if (button1 == HIGH || button2 == HIGH) { ... }
    ! (НЕ): інвертує значення.
    if (!isPaused) { ... } (виконувати, якщо НЕ на паузі).

*/
