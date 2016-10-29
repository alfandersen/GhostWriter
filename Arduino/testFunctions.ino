void printAll(){
  for(int i = 0; i < daisyArray.length()/2; i++){
    moveSweeper(1);
    moveDaisyTo(daisyArray[i]);
    if(sweeperLastDir == 1){
      trig();
    }
    delay(100);
  }
  newLine();
  delay(1000);
  
  for(int i = daisyArray.length()/2; i < daisyArray.length(); i++){
    moveSweeper(1);
    moveDaisyTo(daisyArray[i]);
    if(sweeperLastDir == 1){
      trig();
    }
    delay(100);
  }
  newLine();
  delay(1000);
}


bool testLowerCase(char c){
  int charNo = findChar(c);
  if(charNo == -1) return false;
  int stepsToMove = (charNo - daisyPos) * stepsPrCharDaisy;
  
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
  return true;
}
