/************************************************************************************************
->This program is for Angeline's weapon, the "Sorey and Mikleo armatization weapon".
->This program is only to turn on and off lights
->This program is for the Arduino Uno atm. Will modify when arduino minis arrive.
->This is a test version.
->The LED will be soldered so all connections will be onto one entry pin.
->We will be just using a siomple open switch, which means that the arduino will be only used to provide a means for the button and nothing else.
--------------------Questions and Answers.--------------------------------------------------------
1.Are you using blueeooth?
1.No
2.Which arduino board?
2.Probably the arduino mini.
3.How many LED's?
3.5 of the bigge pieces, 1 or 2 for the smaller pieces.
*************************************************************************************************/

int buttonstate;
int currentstate;
int button=8;
int paststate=LOW;
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;
int ledState=LOW;

void setup() {
 
pinMode(button,INPUT);


}

void loop() {
  currentstate=digitalRead(button);
 //if statement for if the current state does not equal the past state.
 if(currentstate !=paststate)
 {
lastDebounceTime=millis();
 }
 if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (currentstate != buttonstate) {
      buttonstate = currentstate;

      // only toggle the LED if the new button state is HIGH
      if (buttonstate == HIGH) {
        ledState = !ledState;
      }
    }
 }

paststate=currentstate;
}
