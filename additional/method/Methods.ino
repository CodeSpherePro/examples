int temperature = 25; // Глобальна змінна

void setup() {
  Serial.begin(9600); // публічний метод в класі
  temperature++;
  Serial.print("temperature=");
  Serial.println(temperature); // Ок
}

void loop() {
  myMethod(HIGH);           // Виклик методу з одним параметром
  delay(1000);

  blinkLED(13, 500);  // Виклик методу з двома параметрами
  blinkLED(12, 1000); // 2 виклик того ж коду

  float tempC = calculateCelsius(50); // виклик метода з параметром і поверненням значення
  // Serial.print(voltage); // Помилка!

  temperature++;      // Ок, можемо змінювати звідусіль temperature
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

  int myTest = 33;
  printData(myTest);
  countCalls();

  // затримка для можливості переглянути результати
  delay(2000);
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
  // При кожному виклику countCalls() число буде зростати (1, 2, 3...)
  counter++;
  Serial.print("counter=");
  Serial.println(counter);
  // Кожен раз перестворюється
  int localCounter = 0;
  localCounter++;
  Serial.print("local counter=");
  Serial.println(localCounter);
}


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
