int temperature = 25; // Глобальна змінна

void setup() {
  Serial.begin(9600); // публічний метод в класі
  temperature++;
  Serial.print("temperature=");
  Serial.println(temperature); // Ок

}

void loop() {
  myMethod(HIGH);           // Виклик методу
  delay(1000);
  blinkLED(13, 500);  // Виклик методу
  temperature++;      // Ок, можемо змінювати звідусіль
  Serial.print("temperature=");
  Serial.println(temperature); // Ок

  if (analogRead(A0) > 500) {
    int alertValue = 1; // Видна тільки всередині цього "if"
  }
  // Serial.print(alertValue); // Помилка!

  int myVar = 10;

  valueChange(myVar);
  Serial.print("myVar valueChange =");
  Serial.println(myVar); // myVar все ще 10

  referenceChange(myVar);
  Serial.print("myVar referenceChange =");
  Serial.println(myVar); // myVar тепер 100!

  const int myTest = 33;
  printData(myTest);
  countCalls();
  delay(1000);
  Serial.println();
  Serial.println();

}

void myMethod(int value) {  // Оголошення функції/методу
  digitalWrite(13, value);
}

void blinkLED(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
  delay(duration);
}

float calculateCelsius(int rawAnalog) {
  float voltage = rawAnalog * (5.0 / 1023.0);
  return (voltage - 0.5) * 100; // Повертає температуру
}

void countCalls() {
  static int counter = 0; // Створюється один раз
  counter++;
  Serial.print("counter=");
  Serial.println(counter);
  int localCounter = 0;
  localCounter++;
  Serial.print("local counter=");
  Serial.println(localCounter);
}
// При кожному виклику countCalls() число буде зростати (1, 2, 3...)

void valueChange(int x) {
  x = 100; // Змінюється лише локальна копія
}

void referenceChange(int &x) {
  x = 100; // Змінюється ОРИГІНАЛ
}

void printData(const int &data) {
  //data = 44; // Помилка компіляції! Тільки для читання.
  Serial.print("data=");
  Serial.println(data);
}
