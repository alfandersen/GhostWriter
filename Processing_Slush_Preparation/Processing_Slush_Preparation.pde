boolean typeWriterReady = true;
String ghostLines[];
int currentGhostLine = 0;
boolean awakenGhost = false;
boolean ghostIsWriting = false;

void stop() {
  queue.clear();
  sendDirectly(endLine);
}

void setup() {
  serial.bufferUntil(';');
  //fullScreen();
  size(500,500);
  noCursor();
  ghostLines = loadStrings("ghost.txt");
  setupDisplay();
}

void draw() {
  background(250);
  float sw = textWidth(input)+2;
  line(textPlacement.x+sw, textPlacement.y-25, textPlacement.x+sw, textPlacement.y+5);
  text(input, textPlacement.x, textPlacement.y);
  drawFormerInputs();
  if (awakenGhost) {
    ghostIsWriting = true;
    awakenGhost = false;
    addToQueue(ghostLines[currentGhostLine]);
    currentGhostLine++;
  }
  typeWrite();
}