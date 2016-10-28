/*
import processing.serial.*;
 
Serial serial = new Serial(this, Serial.list()[0], 9600);
void sendMessage(String msg) {
  serial.write(msg+';');
}
//*/

//Flags that will be used to control the game's flow
boolean introDone = false;
boolean answerToIntro = false;
boolean answerToDream = false;
boolean answerToFantasy = false;

PFont f;
float lineSpacing = 30;
PVector textPlacement;
String input = "";
ArrayList<String> formerInputs = new ArrayList<String>();
//ArrayList<String> ghostWriting = new ArrayList<String>();
String ghostTyping = "";



void setup() {
  fullScreen();
  noCursor();

  //String ghostLines[] = loadStrings("ghost.txt");
  //println("The ghost knows " + ghostLines.length + " lines:");
  //for (int i = 0; i < ghostLines.length; i++) {
  //  print(i+1);
  //  println(ghostLines[i]);
  //}

  //printArray(PFont.list());
  f = createFont("Source Code Pro", 24);
  textFont(f);
  textAlign(LEFT);
  fill(0, 255, 0);
  stroke(0, 255, 0);
  strokeWeight(2);
  textPlacement = new PVector(100, height-100);
}

void draw() {
  String ghostLines[] = loadStrings("ghost.txt");
  background(0);
  float sw = textWidth(input)+2;
  line(textPlacement.x+sw, textPlacement.y-25, textPlacement.x+sw, textPlacement.y+5);
  text(input, textPlacement.x, textPlacement.y);
  
  // Intro
  if (!introDone){
    formerInputs.add(ghostLines[1]);
    formerInputs.add(ghostLines[0]);
    introDone = true;
  }
  
    
    //INTRO PART
    if (!answerToIntro){
      //Yes
      if ( checkInput(formerInputs) == 1 ){
        formerInputs.add(ghostLines[2]);
        formerInputs.add(ghostLines[3]);
        formerInputs.add(ghostLines[4]);
        formerInputs.add(ghostLines[5]);
        answerToIntro = true;
      }
      //No
      if ( checkInput(formerInputs) == -1 ){
        formerInputs.add(ghostLines[20]);
        formerInputs.add(ghostLines[21]);
        formerInputs.add(ghostLines[3]);
        formerInputs.add(ghostLines[4]);
        formerInputs.add(ghostLines[5]);
        answerToIntro = true;
      }
      ////Other
      //if ( checkInput(formerInputs) == 0 ){
      //  formerInputs.add(ghostLines[23]);
      //  formerInputs.add(ghostLines[24]);
      //  formerInputs.add(ghostLines[3]);
      //  formerInputs.add(ghostLines[4]);
      //  formerInputs.add(ghostLines[5]);
      //  answerToIntro = true;
      //}
    }
    
    // DREAM PART
    if(!answerToDream && answerToIntro){
      //Yes
      if ( checkInput(formerInputs) == 1 ){
        formerInputs.add(ghostLines[7]);
        formerInputs.add(ghostLines[8]);
        formerInputs.add(ghostLines[9]);
        formerInputs.add(ghostLines[10]);
        answerToDream = true;
      }
      //No
      if ( checkInput(formerInputs) == -1 ){
        formerInputs.add(ghostLines[26]);
        formerInputs.add(ghostLines[27]);
        formerInputs.add(ghostLines[9]);
        formerInputs.add(ghostLines[10]);
        answerToDream = true;
      }
    }
    
   // FANTASY PART + ENDING
   if(answerToDream && answerToIntro && !answerToFantasy){
     //Yes
      if ( checkInput(formerInputs) == 1 ){
        formerInputs.add(ghostLines[12]);
        formerInputs.add(ghostLines[13]);
        formerInputs.add(ghostLines[14]);
        formerInputs.add(ghostLines[15]);
        formerInputs.add(ghostLines[16]);
        formerInputs.add(ghostLines[17]);
        formerInputs.add(ghostLines[18]);
        answerToFantasy = true;
      }
      //No
      if ( checkInput(formerInputs) == -1 ){
        formerInputs.add(ghostLines[29]);
        formerInputs.add(ghostLines[30]);
        formerInputs.add(ghostLines[14]);
        formerInputs.add(ghostLines[15]);
        formerInputs.add(ghostLines[16]);
        formerInputs.add(ghostLines[17]);
        formerInputs.add(ghostLines[18]);
        answerToFantasy = true;
      }   
    }
    
  drawFormerInputs();
  
}

// Checks for keywords and outputs 1 (yes), -1 (no) or 0 (else)
float checkInput( ArrayList<String> input ){
 int size = input.size();
 String lastInput = input.get(size -1);
 // Player input is something else (default)
 float decision = 0;
 
 
 // Player input is positive
 if (
      lastInput.indexOf("yes") > -1 ||
      lastInput.indexOf("Yes") > -1 || 
      lastInput.indexOf("Of course") > -1 ||
      lastInput.indexOf("sure") > -1 ||
      lastInput.indexOf("Sure") > -1 ||
      lastInput.indexOf("Mmkay") > -1 ||
      lastInput.indexOf("mmkay") > -1 ||
      lastInput.indexOf("ok") > -1 ||
      lastInput.indexOf("Ok") > -1 ||
      lastInput.indexOf("Sometimes") > -1 ||
      lastInput.indexOf("sometimes") > -1 ||
      lastInput.indexOf("maybe") > -1 ||
      lastInput.indexOf("Maybe") > -1 ||
      lastInput.indexOf("Do") > -1 ||
      lastInput.indexOf("do") > -1 ||
      lastInput.indexOf("Come back") > -1 ||
      lastInput.indexOf("come back") > -1 ||
      lastInput.indexOf("of course") > -1
      ){
         decision = 1; 
      }
 
 // Player input is negative
 if (
      lastInput.indexOf("no") > -1 ||
      lastInput.indexOf("No") > -1 || 
      lastInput.indexOf("not") > -1 ||
      lastInput.indexOf("Not") > -1 ||
      lastInput.indexOf("can't") > -1 ||
      lastInput.indexOf("Can't") > -1 ||
      lastInput.indexOf("Cannot") > -1 ||
      lastInput.indexOf("cannot") > -1 ||
      lastInput.indexOf("Of course not") > -1 || 
      lastInput.indexOf("of course not") > -1
      ){
         decision = -1; 
      }
 
 return decision;

 
  
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
    formerInputs.add(input);
    input = "";
    break;

  default:
    input += key;
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


//void drawGhostWriting() {
//  int maxIndex = ghostWriting.size()-1;
//  int remove = 0;
//  for (int i = maxIndex; i >= 0; i--) {
//    float yPos = textPlacement.y-((maxIndex-i+1)*lineSpacing);
//    text(ghostWriting.get(i), textPlacement.x, yPos); 
//    if (yPos < 0) {
//      remove = i;
//      break;
//    }
//  }

//  for (int i = 0; i < remove; i++) {
//    ghostWriting.remove(0);
//  }
//}