void writeString(String s){
  inputStringComplete = false;
  s.toUpperCase();
  for(int i = 0; i < s.length(); i++){
    typeChar(s[i]);
    if(sweeperPos >= sweeperMaxPos) newLine();
  }
  newLine(); 
  inputString = "";
}

boolean nextWordFits(){
  for(int i = sweeperPos; i < inputString.length(); i++){
    if(inputString[i] == ' '){
      if(i >= sweeperMaxPos) return false;
      else                  return true;
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
