unsigned short ledPin = 13; // association variable with ping number // асоціація змінної з номером піна. Змінна типу short.

void setup() {
  // initialize digital pin LED_BUILTIN as an output. // ініціалізація порта та налатування його як вихідного
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH);  // change state of the LED by setting the pin to the HIGH voltage level // подаємо сигнал на пін який описаний в змінній ledPin
  delay(1000);                 // wait time // час очікування в мілісекундах
  digitalWrite(ledPin, LOW);   // change state of the LED by setting the pin to the LOW voltage level // забираємо сигнал з піну який описаний в змінній ledPin
  delay(1000);                 // wait time // час очікування в мілісекундах
}