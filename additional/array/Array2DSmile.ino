const int SMILE_ROWS = 5;
const int SMILE_COLS = 5;

// 2D Масив для смайлика
byte smile[SMILE_ROWS][SMILE_COLS] = {
  {0, 1, 0, 1, 0},
  {0, 0, 0, 0, 0},
  {1, 0, 0, 0, 1},
  {0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0}
};

// ТЕСТОВІ багатовимірні масиви однакового базового розміру (4) для чесного порівняння Big O
volatile byte array2D[4][4];       // 2D масив на 16 комірок (4х4)
volatile byte array3D[4][4][4];    // 3D масив на 64 комірки (4х4х4)
volatile byte array4D[4][4][4][3]; // 4D масив на 192 комірки (4х4х4x3)

// Змінні для високоточного таймера
unsigned long startTime;
unsigned long endTime;

void setup() {
  Serial.begin(9600);
  delay(1000); // Пауза для стабілізації Serial-порту

  Serial.println("=====================================================");
  Serial.println("--- ДЕМОНСТРАЦІЯ 2: ВИВЕДЕННЯ ГРАФІКИ ТА ЧАСУ ---");
  Serial.println("=====================================================");
  Serial.println();
  Serial.println("1. Візуалізація 2D масиву (Малюємо смайлик):");
  Serial.println("-----------------------------------------------------");

  // Просто малюємо для глядача (час тут НЕ заміряємо, бо Serial.print гальмує)
  for (int r = 0; r < SMILE_ROWS; r++) {
    for (int c = 0; c < SMILE_COLS; c++) {
      if (smile[r][c] == 1) Serial.print("■ ");
      else Serial.print("  ");
    }
    Serial.println();
  }
  Serial.println();
  Serial.println("2. ЧИСТИЙ ТЕСТ ЧАСОВОЇ СКЛАДНОСТІ (Суто робота з ОЗУ):");
  Serial.println("-----------------------------------------------------");

  // =================================================================
  // ЗАМІР 1: 2D Матриця — Квадратична складність O(N²)
  // =================================================================
  startTime = micros(); // СТАРТ
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      array2D[r][c] = 1; // Чиста операція запису в ОЗУ
    }
  }
  endTime = micros(); // ФІНІШ

  Serial.print("[O(N²)] Чистий час обходу 2D масиву: ");
  Serial.print(endTime - startTime);
  Serial.println(" мкс");

  // =================================================================
  // ЗАМІР 2: 3D Куб — Кубічна складність O(N³)
  // =================================================================
  startTime = micros(); // СТАРТ
  for (int f = 0; f < 4; f++) {
    for (int r = 0; r < 4; r++) {
      for (int c = 0; c < 4; c++) {
        array3D[f][r][c] = 1; // Чиста операція запису в ОЗУ
      }
    }
  }
  endTime = micros(); // ФІНІШ

  Serial.print("[O(N³)] Чистий час обходу 3D куба:   ");
  Serial.print(endTime - startTime);
  Serial.println(" мкс");

  // =================================================================
  // ЗАМІР 3: 4D RGB Куб — Чотиривимірна складність O(N⁴)
  // =================================================================
  startTime = micros(); // СТАРТ
  for (int f = 0; f < 4; f++) {
    for (int r = 0; r < 4; r++) {
      for (int c = 0; c < 4; c++) {
        for (int color = 0; color < 3; color++) {
          array4D[f][r][c][color] = 255; // Чиста операція запису в ОЗУ
        }
      }
    }
  }
  endTime = micros(); // ФІНІШ

  Serial.print("[⚠️O(N⁴)] Чистий час обходу 4D RGB-куба: ");
  Serial.print(endTime - startTime);
  Serial.println(" мкс");
  Serial.println("=====================================================");
}

void loop() {}