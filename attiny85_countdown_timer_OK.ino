// kleine Anpassung an Schaltung:
// https://www.youtube.com/watch?v=fnGzRqVI4YI

// ACHTUNG:
// wird ein Attiny85 Digispark (China Teil) eingesetzt, dann 

// die türkise Leitung statt auf Masse, auf VCC umlegen

//    if(digitalRead(changecountdown)==0) {  // Countdown einstellen - Knopf gedrückt
//    if(digitalRead(startcountdown)==0) { // Countdown starten - Knopf gedrückt
// auf 
//   if(digitalRead(changecountdown)==HIGH) {  // Countdown einstellen - Knopf gedrückt
//    if(digitalRead(startcountdown)==HIGH) { // Countdown starten - Knopf gedrückt
// ändern


// Attiny85 Digispark Pinbelegung
// P0 (PB0) -> OLED SDA
// P1 (PB1) -> Button 1
// P2 (PB2) -> OLED SCL
// P3 (PB3) -> Buzzer Plus
// P4 (PB4) -> Button 2
// P5 (PB5) nicht verwendet - Reset Pin

// Button 1 und Button 2 auf Plus legen
// Buzzer auf GND

// OLED VCC nach 5V Plus
// OLED GND -> GND

// Attiny85 Digispark 5V -> 5V Plus 
// Attiny85 Digispark GND -> GND


#include <TinyWireM.h>
#include <Tiny4kOLED.h>

#include "font16x32digits.h"


uint8_t width = 64;
uint8_t height = 32;

#define startcountdown 1        // PB1
#define SPEAKER_PIN 3           // PB3
#define changecountdown 4       // PB4

int minutes=1;
int seconds=0;
int fase=0;
int chosen=0;
int times[]={1,2,3,4,5};        // Countdown - Minuten
int debounce4=0;
int debounce1=0;



void setup() {
  pinMode(changecountdown,INPUT_PULLUP);
  pinMode(startcountdown,INPUT_PULLUP);
  pinMode(SPEAKER_PIN,OUTPUT);
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64), tiny4koled_init_128x64); // display initialization
  oled.setRotation(1);     // The default orientation is not the most commonly used.
  oled.clear();
  oled.on();
}


void loop() {
 
 // Countdown einstellen
  if(fase==0){
   if(digitalRead(changecountdown)==HIGH) {  // Countdown einstellen - Knopf gedrückt
    delay(50); // kleines Entprellen
    if(debounce4==0) {
      oled.clear();
      debounce4=1;
      chosen++;
      if(chosen>4) chosen=0;
      if(fase==3) fase=0;
    }
    } else {
      debounce4=0;
    }
   }

    // Countdown startet bei jedem Klickauf den Button von vorne
    // somit muss man nicht warten bis Countdown abgelaufen ist.
    if(digitalRead(startcountdown)==HIGH) { // Countdown starten - Knopf gedrückt
      delay(50); // kleines Entprellen
     if(debounce1==0)  {
      oled.clear();
      debounce1=1;
      seconds=0;
      minutes=times[chosen];
      fase=1;
     }
    } else {
      debounce1=0;
    }


  if(fase==1 || fase==2){ // Min:Sek oder nur Sek anzeigen
    //delay(10);
    delay(1000);
    seconds--;
    if(seconds<=0) {
      seconds=59;
      minutes--;
    }
  }

  if (fase == 3) // piep piep
  {
    oled.clear();
    analogWrite(SPEAKER_PIN, 128); // PWM Ton
    delay(500);
    analogWrite(SPEAKER_PIN, 0);   // ausschalten
    fase = 0;
    minutes = 1;
    seconds = 0;
  }

   if(minutes==0)    fase=2; // nur die Sekunden anzeigen
   if(minutes==-1)   fase=3; // Piep
   
   updateDisplay();
}



void updateDisplay() {
  if(fase==0) // -------------- Countdown Einstellfenster anzeigen
     {
      oled.setFont(FONT8X16P);
      oled.setCursor(0, 0);
      oled.print("Countdown setzen");
      oled.setCursor(0, 10);
      oled.print("-----------------");
      oled.setCursor(15, 20);
      for(int i=0;i<5;i++) 
        {
           oled.print(" ");
           oled.print(times[i]);
        }
        if(chosen>1)
        oled.setCursor(15+5+chosen*14, 30);
        else
        oled.setCursor(15+5+chosen*14, 30);
        oled.print("/\\");
      }

  if(fase==1){     // Min : Sek   anzeigen
    oled.clear();
    oled.setFont(FONT16X32DIGITS);
    oled.setCursor(20, 10);
    if(minutes<10)  oled.print(0);
    oled.print(minutes);
    oled.print(" : ");
    if(seconds<10)  oled.print(0); 
    oled.print(seconds);
  }

  if(fase==2) // große Sekunden anzeigen
  {
    oled.clear();
    oled.setFont(FONT16X32DIGITS);
    oled.setCursor(50, 10);
    if(seconds<10)  oled.print(0); 
    oled.print(seconds);
  }
  
}
