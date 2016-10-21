int findChar(char c){
  for(int i = 0; i < charArray.length(); i++){
    if(charArray[i] == c) return i;
  }
  return -1;
}

bool moveDaisyTo(char c){
  int charNo = findChar(c);
  if(charNo == -1) return false;
  daisy.step((charNo - daisyPos) * 2);
  daisyPos = charNo;
  return true;
}

void moveSweeper(int chars){
  sweeper.step(chars*10);
  sweeperPos += chars;
  if(chars > 0) sweeperLastDir = 1;
  else if(chars < 0) sweeperLastDir = -1;
}

void trig() {
  digitalWrite(loadPin, HIGH);
  delay(20);
  digitalWrite(loadPin, LOW);
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);
}
