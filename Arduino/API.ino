void writeString(String s){
  if(s.equals(endLineCommand)){
    newLine();
  }
  else{
    s.toUpperCase();
    int charsThisLine = 0;
    for(int i = 0; i < s.length(); i++){
      typeChar(s[i]);
      charsThisLine++;
      if(s[i] == ' '){
        if(!nextWordFits(i+1, charsThisLine) || sweeperPos >= sweeperMaxPos){
          newLine();
          charsThisLine = 0;
        }
      }
    }
    //newLine(); 
  }
  inputString = "";
  inputStringComplete = false;
}

boolean nextWordFits(int charNoInString, int charNoThisLine){
  for(int i = charNoInString; i < inputString.length(); i++){
    if(inputString[i] == ' '){
      int nextSpaceThisLine = charNoThisLine + (i - charNoInString);
      if(nextSpaceThisLine >= sweeperMaxPos) return false;
      else                                   return true;
    }
  }
  return true;
}

void typeChar(char c) {
  if(moveDaisyTo(c)){
    trig();
  }
  moveSweeper(1);
}

void newLine() {
  moveSweeper(-(sweeperPos+1));
  roller.step(stepsPrCharRoller);
  moveSweeper(1);
}

void homing(){
  moveSweeper(-10);
  daisy.step(daisyArray.length()*stepsPrCharDaisy);
  daisyPos = findChar(','); //home character
  moveSweeper(9);
  sweeperPos = 0;
}

void toggleDelete(){
  if(sweeperLastDir != -1) moveSweeper(-1);
  trig();
}

char getKeyboardInput(){
  for(int col = 0; col < sizeof(keyboardColPin); col++){
    digitalWrite(keyboardColPin[col], HIGH);
    delay(1);
    for(int row = 0; row < sizeof(keyboardRowPin); row++){
      if(digitalRead(keyboardRowPin[row]) == LOW){
        String key = keyCode[row][col];
        if(key.length() == 1) {
          return key[0];
        }
      }
    }
    digitalWrite(keyboardColPin[col], LOW);
  }
}
