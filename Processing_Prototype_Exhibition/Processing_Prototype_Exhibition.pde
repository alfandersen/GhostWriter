//*
import processing.serial.*;

Serial serial = new Serial(this, Serial.list()[0], 9600);
void sendMessage(String msg) {
  println(msg);
  serial.write(msg+';');
}

void serialEvent(Serial p) {
  String in = p.readString();
  if (in.equals("done;")) {
    typeWriterReady = true;
    println("arduino returned done");
  }
}
//*/

PFont f;
float lineSpacing = 30;
PVector textPlacement;
String input = "";
ArrayList<String> formerInputs = new ArrayList<String>();
boolean calibrating = false;
boolean typeWriterReady = false;
String ghostLines[];
int currentGhostLine = 0;
boolean ghostIsWriting = false;
String endlineCommand = "EnDlInE";

void stop() {
  sendMessage(endlineCommand);
}

void setup() {
  serial.bufferUntil(';');
  fullScreen();
  noCursor();
  ghostLines = loadStrings("ghost.txt");

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

void draw() {
  background(250);
  float sw = textWidth(input)+2;
  line(textPlacement.x+sw, textPlacement.y-25, textPlacement.x+sw, textPlacement.y+5);
  text(input, textPlacement.x, textPlacement.y);
  drawFormerInputs();
  
  if(ghostIsWriting){
    ghostWrite();
  }
}

void ghostWrite(){
  if(typeWriterReady){
    typeWriterReady = false;
    if(ghostLines[currentGhostLine].isEmpty()){
      ghostIsWriting = false;
      sendMessage(endlineCommand);
      sendMessage(endlineCommand);
    }
    else{
      sendMessage(ghostLines[currentGhostLine]);
    }
    currentGhostLine = (currentGhostLine + 1) % ghostLines.length;
  }
}

void keyTyped() {
  switch(key) {
  case BACKSPACE:
    String oneLess = "";
    for (int i = 0; i < input.length()-1; i++) {
      oneLess += input.charAt(i);
    }
    input = oneLess;
    break;

  case RETURN:
  case ENTER:
    sendMessage(endlineCommand);

    formerInputs.add(input);
    input = "";

    ghostIsWriting = true;

    break;

  case ESC:
    sendMessage(endlineCommand);
    break;

  default:
    input += key;
    String s = "" +key;
    sendMessage(s);
    break;
  }
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