import processing.serial.*;

Serial serial = new Serial(this, Serial.list()[0], 9600);
String endLine = "-endLine-";

void typeWrite() {
  if(typeWriterReady && !queue.isEmpty()){
    String out = queue.pollFirst()+';';
    serial.write(out);
    println(out);
    typeWriterReady = false;
    if(queue.size() == 0){
      ghostIsWriting = false;
    }
    println("queue.size() = " + queue.size());
  }
}

void sendDirectly(String out){
  serial.write(out);
    typeWriterReady = false;
}

void serialEvent(Serial p) {
  String in = p.readString();
  if (in.equals("done;")) {
    typeWriterReady = true;
    
    println("arduino: DONE");
  }
}