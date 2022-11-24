#include <Arduino.h>
#include <arduino-timer.h>

const int beaconLight = 12;
const int strobeLightSX = 11;
const int strobeLightDX = 10;
const int positionSX = 9;
const int positionDX = 8;
const int landingFront = 7;
const int buildInLED = 13;

const int phaseLanding = 1;
const int phaseNavigation = 2;
const int phaseIdle = 3;
volatile int activePhase = 1;

const int rxInput = 3;

const int navigation = 2013;
const int landing = 1000;
const int idle = 1501;

auto timer = timer_create_default();

int sequenceLength = 20;
int navigationSequence[] = {0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0};
int seqPosition = 0;

void pulseGet()
{
  int ch = pulseIn(rxInput, HIGH, 30000);
  
  Serial.println(ch);

  if( ch <= landing) {
    activePhase = phaseLanding;
  } else if( ch > landing && ch <= idle ) {
    activePhase = phaseIdle;
  } else if( ch > idle && ch <= navigation ) {
    activePhase = phaseNavigation;
  }
}

bool seekSequence(void *argument)
{
  auto activeSeq = navigationSequence;

  digitalWrite(buildInLED, (activeSeq[seqPosition] == 1)?HIGH:LOW);

  if(seqPosition < sequenceLength)
  {
    seqPosition ++;
  } else {
    seqPosition = 0;
  }

  return true;
}

void setup() {

  pinMode(beaconLight, OUTPUT);
  pinMode(strobeLightSX, OUTPUT);
  pinMode(strobeLightDX, OUTPUT);
  pinMode(positionSX, OUTPUT);
  pinMode(positionDX, OUTPUT);
  pinMode(landingFront, OUTPUT);
  pinMode(buildInLED, OUTPUT);


  pinMode(rxInput, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(rxInput), pulseGet, CHANGE);

  timer.every(100, seekSequence);

  Serial.begin(115200);
}


void loop() {

  timer.tick();
  //Scan delay
  //delay(500);
}

