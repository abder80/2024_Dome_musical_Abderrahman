

#include <Wire.h>                   // Inclusion de la bibliothèque Wire pour la communication I2C
#include <FastLED.h>                // Inclusion de la bibliothèque FastLED pour le contrôle des LED
#include "Arduino.h"                // Inclusion de la bibliothèque Arduino pour les fonctions de base
#include "PCF8575.h"                // Inclusion de la bibliothèque PCF8575 pour le contrôle du démultiplexeur
#include "pixeltypes.h"             // Inclusion de la bibliothèque pixeltypes pour les types de pixels
#include "playnoteI2S.h"            // Inclusion de la bibliothèque playnoteI2S pour la lecture des notes via I2S

#define NUM_LEDS 16                 // Définition du nombre de LEDs
#define DATA_PIN 14                 // Définition du numéro de broche de données pour FastLED

CRGB leds[NUM_LEDS];                // Déclaration d'un tableau de LEDs
// salut
PCF8575 pcf8575(0x20);              // Création d'une instance de PCF8575 avec l'adresse I2C 0x20

void setup() {
  Serial.begin(115200);             // Initialisation de la communication série à 115200 bauds
  pcf8575.begin();                  // Initialisation du PCF8575
  
  setupCustomI2S(33, 12, 27);        // Configuration I2S pour la lecture des notes
  
  for (char i = 0; i < 15; i++) {   // Boucle pour configurer chaque broche du PCF8575 en tant qu'entrée
    pcf8575.pinMode(i, INPUT); 
  }
  
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); // Ajout des LEDs à FastLED
}

void loop() {

  if (pcf8575.digitalRead(1)) {
    leds[0] = CRGB::Black; // Allumer la LED en rouge
    playNote(0, 250, 100); // Jouer une note
  } else {
    leds[0] = CRGB::Red; // Éteindre la LED
    playNote(100, 250, 50); // Jouer une autre note
  } 
  FastLED.show();
  

  if (pcf8575.digitalRead(2)) {
    leds[1] = CRGB::Black; // Allumer la LED en rouge
    playNote(0, 250, 100); // Jouer une note
  } else {
    leds[1] = CRGB::Green; // Éteindre la LED
    playNote(500, 250, 50); // Jouer une autre note
  } 
  FastLED.show();


  if (pcf8575.digitalRead(3)) {
    leds[2] = CRGB::Black; // Allumer la LED en rouge
    playNote(0, 250, 100); // Jouer une note
  } else {
    leds[2] = CRGB::Blue; // Éteindre la LED
    playNote(1000, 250, 50); // Jouer une autre note
  } 
  FastLED.show();
  
}
