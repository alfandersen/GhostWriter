const int keyRows = 4;
const int keyCols = 8;

String keyCode[keyRows][keyCols] = {
  {"å", "q", "e", "t", "o", "u", "n", "v"},
  {"æ", "z", "f", "h", "s", "k", "x", "c"},
  {"¨", "w", "r", "y", "p", "i", "m", "b"},
  {"ø", "a", "g", "j", "d", "l", "active", "tab"},
};

int rowPin[keyRows] = {2, 3, 4, 5};
int colPin[keyCols] = {6, 7, 8, 9, 10, 11, 12, 13};

boolean lastState = HIGH;
int counter = 0;
void setup() {
  for (int i = 0; i < keyRows; i++) {
    pinMode(rowPin[i], OUTPUT);
    digitalWrite(rowPin[i], HIGH);
  }
  for (int i = 0; i < keyRows; i++) {
    pinMode(colPin[i], INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  for (int j = 0; j < keyCols; j++) {
    Serial.print("\t");
    Serial.print(colPin[j]);
  }
  Serial.println();
  for (int i = 0; i < keyRows; i++) {
    digitalWrite(rowPin[i], LOW);
    Serial.print(i);
    Serial.print(": ");
    delay(100);
    for (int j = 0; j < keyCols; j++) {
      Serial.print("\t");
      if (digitalRead(colPin[j]) == LOW) {
        Serial.print(keyCode[i][j]);
      }
      else{
        Serial.print("_");
      }
      delay(12);
    }
    Serial.println();
    digitalWrite(rowPin[i], HIGH);
  }
  Serial.println("------------------------------------------------------------------\n");
}
