void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    if (inChar == ';') {
      inputStringComplete = true;
    }
    else{
      inputString += inChar;
    }
  }
  //Serial.print("serialEvent saw ");
  //Serial.println(inputString);
}
