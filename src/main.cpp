#include <Arduino.h>
#include <DFRobot_DF1201S.h>


// define

#define BT_PLAY 5


DFRobot_DF1201S DF1201S;
void setup(void){

  // initialisation du serial pour le debug cote pc
  Serial.begin(115200);
  // initilisation du serial pour le modul son
  Serial2.begin(115200);
  pinMode(BT_PLAY,INPUT_PULLUP);

  while(!DF1201S.begin(Serial2)){
    Serial.println("Init failed, please check the wire connection!");
    delay(1000);
  }
  /*Set volume to 20*/
  DF1201S.setVol(/*VOL = */20);
  Serial.print("VOL:");
  /*Get volume*/
  Serial.println(DF1201S.getVol());
  /*Enter music mode*/
  DF1201S.switchFunction(DF1201S.MUSIC);
  /*Wait for the end of the prompt tone */
  delay(2000);

  
  //Set baud rate to 115200(Need to power off and restart, power-down save)
  //DF1201S.setBaudRate(115200);
  //Turn on indicator LED (Power-down save)
  //DF1201S.setLED(true);
  //Turn on the prompt tone (Power-down save) 
  //DF1201S.setPrompt(true);
  //Enable amplifier chip 
  //DF1201S.enableAMP();
  //Disable amplifier chip 
  //DF1201S.disableAMP();
}

void loop(){

  // lecture du switch
  if (digitalRead(BT_PLAY)==LOW){
  Serial.println("Start playing");
  /*Start playing*/
  DF1201S.start();
  // ceci est un anti rebon pour le bouton 
  delay(150);
  }

}