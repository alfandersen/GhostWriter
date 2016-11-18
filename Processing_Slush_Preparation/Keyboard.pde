void keyTyped() {
  if (!ghostIsWriting) {
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
      queue.add(endLine);

      formerInputs.add(input);
      input = "";

      awakenGhost = true;

      break;

    case ESC:
      queue.add(endLine);
      break;

    default:
      input += key;
      String s = "" +key;
      queue.add(s);
      break;
    }
  }
}