//#include "pitches.h"  //add note library

//notes in the melody
int melody[]={262, 196, 196, 220, 196, 0, 247, 262};

//digital pin 12 has a button attached to it. Give it an name
int buttonPin= 12;

//note durations. 4=quarter note / 8=eighth note
int noteDurations[]={4, 8, 8, 4, 4, 4, 4, 4};


void setup(){

  //make the button's pin input
  pinMode(buttonPin, INPUT);
}


void loop(){

  //read the input pin
  int buttonState = digitalRead(buttonPin);

  //if the button is pressed
  if (buttonState == 1){

    //iterate over the notes of the melody
    for (int thisNote=0; thisNote <8; thisNote++){

      //to calculate the note duration, take one second. Divided by the note type
      int noteDuration = 1000 / noteDurations [thisNote];
      tone(8, melody [thisNote], noteDuration);

      //to distinguish the notes, set a minimum time between them
      //the note's duration +30% seems to work well
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      //stop the tone playing
      noTone(8);
    }
  }
}