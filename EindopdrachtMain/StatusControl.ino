// Constants
// Verschillende statusen
const int STAAT_VERKEER_STIL = 0;
const int STAAT_AUTO_LINKS = 1;
const int STAAT_AUTO_RECHTS = 2;
const int STAAT_VOETGANGERS = 3;
const int STAAT_NACHTMODE = 4;

//huidige status
int huidigeStaat;
boolean statusSwitch = false;

//stoplicht
const int ROOD = 0;
const int GEEL = 1;
const int GROEN = 2;

//verkeerslichten
const int VERKEERSLICHT_LINKS = 0;
const int VERKEERSLICHT_RECHTS = 1;

//methodes
void setup_StatusControl() {
  setupServo();
  setupBuzzer();
  setupLDRSensor();
  setupKnop();
  setupDisplay();
  SetupVerkeerslichtControl();
  huidigeStaat = STAAT_VERKEER_STIL;
  Staat_Verkeer_Stil_Entry();
}


void statusControl_loop() {
  Serial.println(huidigeStaat);
  switch (huidigeStaat) {
    case STAAT_VERKEER_STIL:
      if (statusSwitch) {
        Staat_Verkeer_Stil_Entry();
        statusSwitch = false;
      } else {
        Staat_Verkeer_Stil_Do();
      }
      break;
    case STAAT_AUTO_LINKS:
      if (statusSwitch) {
        Staat_Auto_Links_Entry();
        statusSwitch = false;
      } else {
        Staat_Auto_Links_Do();
      }
      break;
    case STAAT_AUTO_RECHTS:
      if (statusSwitch) {
        Staat_Auto_Rechts_Entry();
        statusSwitch = false;
      } else {
        Staat_Auto_Rechts_Do();
      }
      break;
    case STAAT_VOETGANGERS:
      if (statusSwitch) {
        Staat_voetgangers_Entry();
        statusSwitch = false;
      } else {
        Staat_voetgangers_Do();
      }
      break;
    case STAAT_NACHTMODE:
      if (statusSwitch) {
        Staat_Nachtmode_Entry();
        statusSwitch = false;
      } else {
        Staat_Nachtmode_Do();
      }
      break;
  }
}

void switchHuidigeStaat(int switchNaar) {
  switch (switchNaar) {
    case STAAT_VERKEER_STIL:
      Staat_Verkeer_Stil_Exit();
      break;
    case STAAT_AUTO_LINKS:
      Staat_Auto_Links_Exit();
      break;
    case STAAT_AUTO_RECHTS:
      Staat_Auto_Rechts_Exit();
      break;
    case STAAT_VOETGANGERS:
      Staat_voetgangers_Exit();
      break;
    case STAAT_NACHTMODE:
      Staat_Nachtmode_Exit();
      break;
  }
  huidigeStaat = switchNaar;
  statusSwitch = true;
}
// Alle acties na of tijdens een status switch
/* ------ verkeer stil ------- */
void Staat_Verkeer_Stil_Entry() {
  lampVerkeerslicht(VERKEERSLICHT_LINKS, ROOD);
  lampVerkeerslicht(VERKEERSLICHT_RECHTS, ROOD);
  shiftRegisterS();
   
}

void Staat_Verkeer_Stil_Do() {
  if (!nachtmode()) {
    switchHuidigeStaat(STAAT_NACHTMODE);
  }
}

void Staat_Verkeer_Stil_Exit() {
  // doe niks
}


/* ------ auto nadert links ------- */
void Staat_Auto_Links_Entry() {
  lampVerkeerslicht(VERKEERSLICHT_LINKS, GROEN);
}

void Staat_Auto_Links_Do() {
  // doe niks
}

void Staat_Auto_Links_Exit() {
  lampVerkeerslicht(VERKEERSLICHT_LINKS, GEEL);
}


/* ------ auto nadert rechts ------- */
void Staat_Auto_Rechts_Entry() {
  lampVerkeerslicht(VERKEERSLICHT_RECHTS, GROEN);
}

void Staat_Auto_Rechts_Do() {
  // doe niks
}

void Staat_Auto_Rechts_Exit() {
  lampVerkeerslicht(VERKEERSLICHT_RECHTS, GEEL);
}


/* ------ voetganger heeft op knop geklikt ------- */
void Staat_voetgangers_Entry() {
  servoOmhoog();
  voetgangerTimerReset();
}

void Staat_voetgangers_Do() {
  voetgangersTimer();
}

void Staat_voetgangers_Exit() {
  servoOmlaag();
}

/* ------ nachtmode ------- */
void Staat_Nachtmode_Entry() {
  servoOmhoog();
  lampVerkeerslicht(VERKEERSLICHT_LINKS, GEEL);
  lampVerkeerslicht(VERKEERSLICHT_RECHTS, GEEL);
  shiftRegisterO();
}

void Staat_Nachtmode_Do() {
  if (!nachtmode()) {
    switchHuidigeStaat(STAAT_VERKEER_STIL);
  }
}

void Staat_Nachtmode_Exit() {
  servoOmlaag();
}

boolean nachtModeFalse(){
  return huidigeStaat != STAAT_NACHTMODE;
}

int getHUIDIGESTATUS(){
  return huidigeStaat;
}
