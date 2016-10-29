void serialEvent() {
  if(!inputStringComplete){
    while (Serial.available()) {
      // get the new byte:
      char inChar = (char)Serial.read();
      if (inChar == ';') {
        Serial.print("Serial: ");
        Serial.println(inputString);
        inputStringComplete = true;
        break;
      }
      else{
        inputString += inChar;
      }
    }
  }
}
