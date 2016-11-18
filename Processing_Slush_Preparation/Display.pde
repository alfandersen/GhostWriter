PFont f;
float lineSpacing = 30;
PVector textPlacement;
String input = "";
ArrayList<String> formerInputs = new ArrayList<String>();

void setupDisplay(){
  //printArray(PFont.list());
  f = createFont("Source Code Pro", 24);
  textFont(f);
  textAlign(LEFT);
  //fill(0, 255, 0);
  //stroke(0, 255, 0);
  fill(0);
  stroke(0);
  strokeWeight(2);
  textPlacement = new PVector(100, height-100);
}

void drawFormerInputs() {
  int maxIndex = formerInputs.size()-1;
  int remove = 0;
  for (int i = maxIndex; i >= 0; i--) {
    float yPos = textPlacement.y-((maxIndex-i+1)*lineSpacing);
    text(formerInputs.get(i), textPlacement.x, yPos); 
    if (yPos < 0) {
      remove = i;
      break;
    }
  }

  for (int i = 0; i < remove; i++) {
    formerInputs.remove(0);
  }
}