const int ROWS = 3;
const int COLS = 3;

// Масив розміром 3х3 (Індекси від 0 до 2)
int matrix[ROWS][COLS] = {
    {10, 20, 30},
    {40, 50, 60},
    {70, 80, 90}
};

void setup() {
    Serial.begin(9600);
    delay(1000);

    Serial.println("--- ТЕСТУВАННЯ МЕЖ ПАМ'ЯТІ ---");

    // Правильне читання в межах масиву (останній елемент)
    Serial.print("Правильний елемент matrix[2][2] ➔ ");
    Serial.println(matrix[2][2]); // Виведе 90

    Serial.println();
    Serial.println("⚠️ УВАГА! НАВМИСНИЙ ВИХІД ЗА МЕЖІ (БАГ):");

    // Неіснуючі індекси для масиву 3х3
    int fakeRow = 5;
    int fakeCol = 8;

    Serial.print("Зчитуємо комірку matrix[");
    Serial.print(fakeRow);
    Serial.print("][");
    Serial.print(fakeCol);
    Serial.print("] ➔ Цифрове сміття з ОЗУ: ");

    // Arduino Uno не захищає пам'ять і видасть випадкові байти, що лежать поруч у пам'яті
    Serial.println(matrix[fakeRow][fakeCol]);
    Serial.println("---------------------------------------------");
}

void loop() {}
