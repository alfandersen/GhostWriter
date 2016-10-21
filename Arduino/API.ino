void writeString(String s){
  int charsThisLine = 0;
  inputStringComplete = false;
  //s.toUpperCase();
  for(int i = 0; i < s.length(); i++){
    typeChar(s[i]);
    charsThisLine++;
    if(s[i] == ' '){
      
      if(!nextWordFits(i+1, charsThisLine || sweeperPos >= sweeperMaxPos)){
        newLine();
        charsThisLine = 0;
      }
    }
  }
  //newLine(); 
  inputString = "";
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
  roller.step(40);
  moveSweeper(1);
}

void homing(){
  moveSweeper(-10);
  daisy.step(200);
  daisyPos = findChar(','); //home character
  moveSweeper(9);
  sweeperPos = 0;
}

void toggleDelete(){
  if(sweeperLastDir != -1) moveSweeper(-1);
  trig();
}
