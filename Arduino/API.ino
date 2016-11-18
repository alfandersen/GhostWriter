void writeString(String s) {
  inputStringComplete = false;
  if (s.equals(endLineCommand)) {
    newLine();
  }
  else {
    s.toUpperCase();
    int charsThisLine = 0;
    for (int i = 0; i < s.length(); i++) {
      typeChar(s[i]);
      charsThisLine++;
      if (s[i] == ' ') {
        if (!nextWordFits(i + 1, charsThisLine) || sweeperPos >= sweeperMaxPos) {
          newLine();
          charsThisLine = 0;
        }
      }
    }
    //newLine();
  }
  inputString = "";
}

boolean nextWordFits(int charNoInString, int charNoThisLine) {
  for (int i = charNoInString; i < inputString.length(); i++) {
    if (inputString[i] == ' ') {
      int nextSpaceThisLine = charNoThisLine + (i - charNoInString);
      if (nextSpaceThisLine >= sweeperMaxPos) return false;
      else                                   return true;
    }
  }
  return true;
}

void typeChar(char c) {
  if (moveDaisyTo(c)) {
    trig();
  }
  moveSweeper(1);
}

void newLine() {
  moveSweeper(-(sweeperPos + 1));
  roller.step(stepsPrCharRoller);
  moveSweeper(1);
}

void homing() {
  moveSweeper(-10);
  //daisy.step(-daisyArray.length()*stepsPrCharDaisy);
  daisy.step(daisyArray.length()*stepsPrCharDaisy);
  daisyPos = findChar(','); //home character
  moveSweeper(9);
  sweeperPos = 0;
}

void toggleDelete() {
  if (sweeperLastDir != -1) moveSweeper(-1);
  trig();
}

String getKeyboardInput() {
  for (int col = 0; col < keyCols; col++) {
    /*Serial.print("col: ");
    Serial.print(col);
    Serial.print("of ");
    Serial.println(keyCols);
    */digitalWrite(keyboardColPin[col], LOW);
    delay(1);
    for (int row = 0; row < keyRows; row++) {
      /*Serial.print("\trow: ");
      Serial.print(row);
      Serial.print("of ");
      Serial.println(keyCols);
      */if (digitalRead(keyboardRowPin[row]) == LOW) {
        if(!keyCode[row][col].equals("active")){
          /*Serial.print("\tKey pressed: ");
          Serial.print(keyCode[row][col]);
          Serial.println();
          */digitalWrite(keyboardColPin[col], HIGH);
          return keyCode[row][col];
        }
      }
      //Serial.println();
    }
    digitalWrite(keyboardColPin[col], HIGH);
  }
  return "nokey";
}

void handleUserInput() {
  String key = getKeyboardInput();
  //Serial.println(key);
  
  if (key.length() == 1){
    key.toUpperCase();  //Until we fix the lower case problem
    typeChar(key[0]);
  }else
  if (key.equals("enter"))     newLine(); else
  if (key.equals("tab"))       moveSweeper(8); else //Notepad on windows moved 8 characters with a tab
  if (key.equals("superback")) {moveSweeper(-(sweeperPos + 1)); moveSweeper(1);}/* else
  if (key.equals("shift"))     ; else
  if (key.equals("capslock"))  ;*/
}
