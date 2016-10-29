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
