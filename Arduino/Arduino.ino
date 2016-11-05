#include <Stepper.h>

const int keyRows = 8;
const int keyCols = 8;

String keyCode[keyCols][keyRows] = {
  {",", "-", "1", "3", "7", "5", "+", "9"},
  {".", "enter", "2", "4", "8", "6", "´", "0"},
  {"å", "q", "e", "t", "o", "u", "n", "v"},
  {"æ", "z", "f", "h", "s", "k", "x", "c"},
  {"¨", "w", "r", "y", "p", "i", "m", "b"},
  {"ø", "a", "g", "j", "d", "l", "active", "tab"},
  {" ", "enter", "axa", "superback", "alt", "backspace", "backx", "ctrl"},
  {"shift", "capslock", "nc", "nc", "nc", "nc", "nc", "nc"}
};

int keyboardRowPin[keyRows] = {38, 39, 40, 41, 42, 43, 44, 45};
int keyboardColPin[keyCols] = {46, 47, 48, 49, 50, 51, 52, 43};

String inputString = "";
//String daisyArray = "1324567809$ø€å£<Ø>\"æ´§!Æ`Å^R'Q_OJG?D\"C-FE=BV&YATLSPZ*X+K)H(UIN;W:M,.ersaioctmlhpnbfgukvdyzqxjw/%";
String daisyArray = "9087654231%/wjxqzydvkugfbnphlmtcoiasre.,M:W;NIU(H)K+X*ZPSLTAY&VB=EF-C+D?GJO_Q'R^Å+Æ!++++>Ø<+++++"; // reversed

int sweeperLastDir = 0;
int sweeperMaxPos = 75;
int sweeperPos = 0;
int daisyPos = 0;

int stepsPrCharSweeper = 10;
int stepsPrCharRoller = 40;
int stepsPrCharDaisy = 2;

Stepper sweeper(100, 22, 23, 24, 25);
Stepper roller(100, 34, 35, 36, 37);
Stepper daisy(95, 26, 27, 28, 29);

int loadPin = 30;
int trigPin = 31;

boolean inputStringComplete = false;
boolean doneTyping = false;

String endLineCommand = "EnDlInE";

void setup() {
  Serial.begin(9600);
/*
  for (int i = 0; i < 8; i++) {
    pinMode(keyboardRowPin[i], INPUT_PULLUP);
    pinMode(keyboardColPin[i], OUTPUT);
    digitalWrite(keyboardColPin[i], HIGH);
  }
*/
  pinMode(loadPin, OUTPUT);
  pinMode(trigPin, OUTPUT);

  sweeper.setSpeed(100);
  roller.setSpeed(100);
  daisy.setSpeed(100);

  homing();
  //daisy.setSpeed(1);
}

void loop() {
  serialEvent();
  if (inputStringComplete) {
    //boolean sendDoneMsg = inputString.length() > 1;
    writeString(inputString);
    Serial.print("done;");
  }
  //else{
   // handleUserInput();
  //}
}
