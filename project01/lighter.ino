unsigned int  redPin = 12;  // association variable with pin number // асоціація змінної з номером піна. Змінна типу short.
unsigned int  yellowPin = 8;
unsigned int  greenPin = 4;
unsigned int  switchPin = 2;

boolean lastButton = LOW;
boolean ledOn = false;
boolean currentButton = LOW;
boolean turnOn = false;

boolean debounce(boolean last) {
  boolean current = digitalRead(switchPin);
  if (last != current) {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(switchPin, INPUT);

}

void customDelay(int inputDelay) {
  int counter = 0;
  while(counter < inputDelay) {
    currentButton = debounce(lastButton);
    if (lastButton == LOW && currentButton == HIGH) {
      ledOn = !ledOn;
    }
    delay(5);
    counter = counter + 10;
  }
}

void loop() {
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH) {
    ledOn = !ledOn;
  }

  if (ledOn) {
    turnOnLighter();
  } else {
    yellowBlinkingLighter();
  }

  lastButton = currentButton;


}

void turnOnLighter() {
  digitalWrite(12, HIGH);  // turn the LED on (HIGH is the voltage level)
  customDelay(3000);

  digitalWrite(12, LOW);
  customDelay(200);

  digitalWrite(8, HIGH);  // turn the LED on (HIGH is the voltage level)
  customDelay(1000);

  digitalWrite(8, LOW);
  customDelay(200);

  digitalWrite(4, HIGH);  // turn the LED on (HIGH is the voltage level)
  customDelay(3000);

  digitalWrite(4, LOW);
  customDelay(200);

  digitalWrite(8, HIGH);  // turn the LED on (HIGH is the voltage level)
  customDelay(1000);

  digitalWrite(8, LOW);
  customDelay(200);

  digitalWrite(8, HIGH);  // turn the LED on (HIGH is the voltage level)
  customDelay(200);

  digitalWrite(8, LOW);
  customDelay(200);

  digitalWrite(8, HIGH);  // turn the LED on (HIGH is the voltage level)
  customDelay(200);

  digitalWrite(8, LOW);
  customDelay(200);
}

void turnOffLighter() {
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}

void yellowBlinkingLighter() {

  digitalWrite(yellowPin, LOW);
  customDelay(500);
  digitalWrite(8, HIGH);  // turn the LED on (HIGH is the voltage level)
  customDelay(1000);

}