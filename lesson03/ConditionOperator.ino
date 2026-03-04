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
    delay(10000);
}

/*
    == : дорівнює (не плутайте з =, який призначає значення правої частини лівій).
    != : не дорівнює.
    > / < : більше або менше.
    >= / <= : більше або дорівнює, або менше або дорівнює.


    && (І): умова істинна, лише якщо обидві частини правдиві.
    Наприклад:
    if (temp > 20 && light == LOW) { ... }
    || (АБО): умова істинна, якщо хоча б одна частина правдива.
    if (button1 == HIGH || button2 == HIGH) { ... }
    ! (НЕ): інвертує значення.
    if (!isPaused) { ... } (виконувати, якщо НЕ на паузі).

*/
