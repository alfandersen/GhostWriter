import java.util.ArrayDeque;

ArrayDeque<String> queue = new ArrayDeque<String>();

void addToQueue(String input) {
  println("addToQueue() \"" + input + '"');
  String[] words = input.split(" ");
  for (int i = 0; i < words.length; i++) {
    if(words.length > 1) words[i] += " ";
    queue.add(words[i]);
    if(i == words.length-1){
      queue.add(endLine);
      queue.add(endLine);
      ghostIsWriting = false;
    }
  }
}