#include <Arduino.h>
#include <arduino-timer.h>
#include <Sequencer.h>

const int beaconLight = 12;
const int strobeLightSX = 11;
const int strobeLightDX = 10;
const int positionSX = 9;
const int positionDX = 8;
const int landingFront = 7;
const int buildInLED = 13;

volatile int activePhase = 1;

const int rxInput = 3;

const int pulseNavigation = 2013;
const int pulseLanding = 1000;
const int pulseIdle = 1501;

auto timer = timer_create_default();

int seqPosition = 0;

Sequencer mySeq = Sequencer(0,beaconLight,strobeLightSX,strobeLightDX,positionSX,positionDX,landingFront,buildInLED);

void pulseGet()
{
  int ch = pulseIn(rxInput, HIGH, 30000);
  
  Serial.println(ch);

  if( ch <= pulseLanding) {
    activePhase = Sequencer::phaseLanding;
  } else if( ch > pulseLanding && ch <= pulseIdle ) {
    activePhase = Sequencer::phaseIdle;
  } else if( ch > pulseIdle && ch <= pulseNavigation ) {
    activePhase = Sequencer::phaseNavigation;
  }

  mySeq = Sequencer(activePhase,beaconLight,strobeLightSX,strobeLightDX,positionSX,positionDX,landingFront,buildInLED);

}

bool localSeek(void *arguments)
{
  int test = mySeq.seek();
  Serial.println(test);
  return true;
}

void setup() {
  pinMode(rxInput, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(rxInput), pulseGet, CHANGE);

  //Seek the Sequencer
  timer.every(100, localSeek);

  Serial.begin(115200);
}


void loop() {
  timer.tick();
  //Scan delay
  //delay(500);
}

