// ініціалізація змінних з номером піна
// Пін, до якого підключено кнопку
unsigned int switchPin = 2; 
// Пін, до якого підключено реле
unsigned int relayPin = 4;
// змінна для збереження статусу
bool turnOn = false;

void setup() {
  // налаштування режиму пінів
  pinMode(relayPin, OUTPUT);
  pinMode(switchPin, INPUT);
  // налаштування дебаг
  Serial.begin(9600);
}

void loop() {
  // якщо статус == true 
  if (digitalRead(switchPin)) {
    // інвертує статус
    turnOn = !turnOn;
  }

  if (turnOn) {
    Serial.println("подаєм живлення");
    digitalWrite(relayPin, HIGH);
  } else {
    Serial.println("знімаєм живлення");
    digitalWrite(relayPin, LOW);
  }

  delay(300);

}

