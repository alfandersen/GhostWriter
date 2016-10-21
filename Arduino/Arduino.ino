#include <Stepper.h>

String inputString = "";
//String charArray = "1324567809$ø€å£<Ø>\"æ´§!Æ`Å^R'Q_OJG?D\"C-FE=BV&YATLSPZ*X+K)H(UIN;W:M,.ersaiocjmlhpndfgukvbyzqxjw/%";
String charArray = "9087654231%/wjxqzybvkugfdnphlmjcoiasre.,M:W;NIU(H)K+X*ZPSLTAY&VB=EF-C+D?GJO_Q'R^Å+Æ!++++>Ø<+++++"; // reversed

int sweeperLastDir = 0;
int sweeperMaxPos = 75;
int sweeperPos = 0;
int daisyPos = 0;

Stepper sweeper(100, 22, 23, 24, 25);
Stepper roller(100, 34, 35, 36, 37);
Stepper daisy(95, 26, 27, 28, 29);

int loadPin = 30;
int trigPin = 31;

boolean inputStringComplete = false;
boolean doneTyping = false;

void setup() {
  Serial.begin(9600);

  pinMode(loadPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  
  sweeper.setSpeed(100);
  roller.setSpeed(100);
  daisy.setSpeed(100);
  
  homing();
}

void loop() {
  if(inputStringComplete){
    writeString(inputString);
  }
}
