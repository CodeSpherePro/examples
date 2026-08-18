// Розмір статичний
#define SIZE 4

// Макрос підрахунку розміру
#define GET_SIZE(x) \
(sizeof(x) / sizeof(x[0]))

void setup() {
    Serial.begin(9600);

    // Спосіб А: порожній
    int arrA[SIZE];
    arrA[0] = 10;
    arrA[1] = 20;
    arrA[2] = 30;
    arrA[3] = 40;

    // Спосіб Б: з даними
    int arrB[4] = {
        5, 6, 7, 8
      };

    // Спосіб В: авто-розмір
    int arrC[] = {
        100, 200, 300
      };

    // Доступ по індексу
    int val = arrB[2];
    Serial.print("arrB[2]=");
    Serial.println(val);

    // Вивід через цикл for
    for (int i = 0; i < 4; i++) {
        Serial.print("A[");
        Serial.print(i);
        Serial.print("]=");
        Serial.println(arrA[i]);
    }

    // Зміна елементу
    arrB[0] = 99;

    // Просте використання
    int sum = arrB[0] + \
              arrB[1];
    Serial.print("Sum=");
    Serial.println(sum);


    // Спосіб Г: авто-розмір
    int arr[] = {
        10, 20, 30, 40, 50
      };

    // Авто-вирахування довжини
    int len = GET_SIZE(arr);

    Serial.print("Len=");
    Serial.println(len);

    // Вивід через макрос
    for (int i = 0; i < len; i++) {
        Serial.print("arr[");
        Serial.print(i);
        Serial.print("]=");
        Serial.println(arr[i]);
    }
}

void loop() {
    // Код не повторюється
}
