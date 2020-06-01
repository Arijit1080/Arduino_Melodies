#define SPEAKER 3
#define DRUMS 5
#define INTERVAL 160
#define NOTE_SPACING 16
const uint16_t FREQUENCIES[]={0,31,33,35,37,39,41,44,46,49,52,55,58,62,65,69,73,78,82,87,93,98,104,110,117,123,131,139,147,156,165,175,185,196,208,220,233,247,262,277,294,311,330,349,370,392,415,440,466,494,523,554,587,622,659,698,740,784,831,880,932,988,1047,1109,1175,1245,1319,1397,1480,1568,1661,1760,1865,1976,2093,2217,2349,2489,2637,2794,2960,3136,3322,3520,3729,3951,4186,4435,4699,4978};
const uint16_t SONG_LENGTH=64;
const uint8_t LEADTK[]={52,0,0,0,51,0,0,0,49,0,44,0,44,44,44,44,44,49,49,49,49,0,47,49,0,0,45,0,45,45,45,45,45,49,49,49,49,0,51,52,0,0,47,0,47,47,47,47,52,51,52,51,52,0,54,54,0,51,0,0,0,0,0,0};
const uint8_t LEADLN[]={4,0,0,0,4,0,0,0,2,0,1,0,1,1,1,1,1,1,1,1,2,0,1,1,0,0,1,0,1,1,1,1,1,1,1,1,2,0,1,1,0,0,1,0,1,1,1,1,1,1,1,1,2,0,1,2,0,3,0,0,0,0,0};
const uint8_t DRUMTK[]={0,0,0,0,0,0,0,0,30,0,0,5,5,0,5,0,30,0,0,5,5,0,5,0,30,0,0,5,5,0,5,0,30,0,0,5,5,0,5,0,30,0,0,5,5,0,5,0,30,0,0,5,5,0,5,0,30,0,0,5,5,0,5,0};
void setup() {
  pinMode(2, OUTPUT);   
      digitalWrite(2, HIGH);
  pinMode(SPEAKER,OUTPUT);
  pinMode(DRUMS,OUTPUT);
}
uint16_t ctr=0,t=0;
void loop() {
  t=millis();
  if(LEADLN[ctr]!=0){
    noTone(SPEAKER);
    if(LEADTK[ctr]!=0) tone(SPEAKER,FREQUENCIES[LEADTK[ctr]],LEADLN[ctr]*INTERVAL-NOTE_SPACING);
  }
  if(DRUMTK[ctr]!=0){
    digitalWrite(DRUMS,HIGH);
    delay(DRUMTK[ctr]);
    digitalWrite(DRUMS,LOW);
  }
  ctr=(ctr+1)%SONG_LENGTH;
  delay(INTERVAL-(millis()-t));
}