//Type 	                            Size (typical)	            Range / Description	Use Case
bool var1 = false;              //	1 byte	true or false	    Digital states (ON/OFF), flags.
// 0 s false any other is true // 0 — це false, будь-яке інше число — це true.
byte var2 = 127;              //	1 byte	0 to 255	        Storing small numbers or raw data.
// позначає будь яке число від 0 до 255
char var3 = 65;              //	1 byte	-128 to 127	        Single characters (e.g., 'A').
// також 1 байт 256 символів, але в діапазоні -128 до 127
int	var4 = -30123;               //  2 bytes	-32,768 to 32,767	General counting, sensor readings.
// ціле число займає 2 байта памяті, описує діапазон від -32,768 до 32,767
unsigned int var5 = 64123; 	    //  2 bytes	0 to 65,535	        When negative numbers aren't needed.
// тільки додатнє ціле число, також займає 2 байта, але діапазон від 0 до 65535
long var6 = -4567890;	            //  4 bytes	-2.1B to 2.1B	    Large whole numbers.
// розширені цілі числа, займають в памяті 4 байта. Діопазон від - 2.1 мільярда до +2.1
unsigned long var7 = 4567890;    //  4 bytes	0 to 4.2B	    Time tracking (essential for millis()).
// розширені додатні числа, займають в памяті тих же 4 байта, але тільки додатні від 0 до 4.2 мільярда
float var8 = 1.234567;	        //  4 bytes	~3.4E±38	        Numbers with decimals (accurate to ~6-7 digits).
// число з плаваючою крапкою, або дійсне, або число з дробовою частиною. Наприклад: 4.12345. Займає 4 байта в памяті
double var9 = 1.234567; 	        //  4/8 bytes	Same as float	On many Arduinos, double is identical to float.
// число з плаваючою крапкою розширене.  Займає 4 або 8 байт в памяті. Здебілбшого в ардуіно ідентичні з float через брак памяті.



char  var11 = 'c';            // Array (C-String): An array of characters ending in a null character \0. It is memory-efficient and preferred for low-memory boards.
// 1 символ, займає 1 байт в памяті.
String var12 = "some text";   // A String Class that allows for easier manipulation (like concatenation) but can fragment memory if used heavily.
// список символів, або рядок. Як правило використовується для тексту.


// typical comment / коментар. Цей текст виключно для читання людиною машина його не бачить
/*
  multiline comment
  багаторядковий коментар
*/

void setup() {
    Serial.begin(9600);		// Initialize serial communications with the PC
}

void loop() {
    Serial.println("Start");
    Serial.println(var1);
    Serial.println(var2);
    Serial.println(var3);
    Serial.println(var4);
    Serial.println(var5);
    Serial.println(var6);
    Serial.println(var7);
    Serial.println(var8, 6);
    Serial.println(var9, 6);
    Serial.println(var11);
    Serial.println(var12);
    Serial.print("fist part ");
    Serial.print("second");
    delay(10000);
}
