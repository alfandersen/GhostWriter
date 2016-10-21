int findChar(char c){
  for(int i = 0; i < charArray.length(); i++){
    if(charArray[i] == c) return i;
  }
  return -1;
}

bool moveDaisyTo(char c){
  int charNo = findChar(c);
  if(charNo == -1) return false;
  
  int stepsToMove = (charNo - daisyPos) * 2;
  
  int a = findChar('a'); //34
  Serial.print(c);
  Serial.print(":\t no ");
  Serial.print(charNo);
  Serial.print("\t pos ");
  Serial.print(daisyPos);
  Serial.print("\t move ");
  
  if(daisyPos >= a && charNo < a){
    stepsToMove -= 1;
    Serial.print(stepsToMove);
    Serial.println(" \t unter");
  }
  else if(daisyPos < a && charNo >= a){
    stepsToMove += 1;
    Serial.print(stepsToMove);
    Serial.println(" \t over");
  }
  else {
    Serial.print(stepsToMove);
    Serial.println();
  }
  
  daisy.step(stepsToMove);
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
  //delay(200);
  digitalWrite(trigPin, HIGH);
  delay(150);
  digitalWrite(trigPin, LOW);
  //delay(50);
}
