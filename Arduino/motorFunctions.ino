int findChar(char c){
  for(int i = 0; i < daisyArray.length(); i++){
    if(daisyArray[i] == c) return i;
  }
  return -1;
}

bool moveDaisyTo(char c){
  int charNo = findChar(c);
  if(charNo == -1) return false;
  daisy.step((charNo - daisyPos) * stepsPrCharDaisy);
  daisyPos = charNo;
  return true;
}

void moveSweeper(int chars){
  sweeper.step(chars * stepsPrCharSweeper);
  sweeperPos += chars;
  if(chars > 0) sweeperLastDir = 1;
  else if(chars < 0) sweeperLastDir = -1;
}

void trig() {
  digitalWrite(loadPin, HIGH);
  digitalWrite(trigPin, HIGH); //Up for a test
  delay(20);
  digitalWrite(loadPin, LOW);
  delay(130);
  digitalWrite(trigPin, LOW);
}
  
