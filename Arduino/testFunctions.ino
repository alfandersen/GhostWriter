void printAll(){
  for(int i = 0; i < charArray.length()/2; i++){
    moveSweeper(1);
    moveDaisyTo(charArray[i]);
    if(sweeperLastDir == 1){
      trig();
    }
    delay(100);
  }
  newLine();
  delay(1000);
  
  for(int i = charArray.length()/2; i < charArray.length(); i++){
    moveSweeper(1);
    moveDaisyTo(charArray[i]);
    if(sweeperLastDir == 1){
      trig();
    }
    delay(100);
  }
  newLine();
  delay(1000);
}
