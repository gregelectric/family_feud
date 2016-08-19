/*
  Button

Family Feud Buttons
Buttons 1 and 2 connect from 5V to pin 10 and 11 with 10K pullup
LED 1 and 2 connected to pin 12 and 13

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2016
 by gregelectric <http://www.gregelectric.com>

 This example code is in the public domain.
 */

// constants won't change. They're used here to
// set pin numbers:
const int button1 = 10;     // the number of the pushbutton pin
const int button2 = 11;     // the number of the pushbutton pin
const int led1 =  12;      // the number of the LED pin
const int led2 =  13;      // the number of the LED pin

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status
int winner = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if ((buttonState1 == HIGH) && (buttonState2 == LOW) && (winner == 0))
  {
    // turn LED on:
    digitalWrite(led1, HIGH);
    winner = 1;
  } 

  if ((buttonState2 == HIGH) && (buttonState1 == LOW) && (winner == 0))
  {
    // turn LED on:
    digitalWrite(led2, HIGH);
    winner = 1;
  } 

  if( winner == 1)
  {
    delay(5000); 
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    winner = 0;
  }
}
