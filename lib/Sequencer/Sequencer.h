#ifndef Sequencer_h
#define Sequencer_h

#include <Arduino.h>

class Sequencer {
  private:
    int activePhase = 0;
    int sequencePosition;

    int sequences[3][7][20] = {
        //Phase Ilde
        {
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //BuiltInLed
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //beaconLight
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //strobeLightSX
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //strobeLightDX
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //positionSX
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //positionDX
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}  //landingFront
        },
        //Phase Navigation
        {
            {0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0}, //BuiltInLed
            {0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //beaconLight
            {0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0}, //strobeLightSX
            {0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0}, //strobeLightDX
            {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //positionSX
            {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //positionDX
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}  //landingFront
        },
        //Phase Landing
        {
            {0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0}, //BuiltInLed
            {0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0}, //beaconLight
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //strobeLightSX
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //strobeLightDX
            {0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0}, //positionSX
            {0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0}, //positionDX
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}  //landingFront
        }
    };

    int beaconLight = 12;
    int strobeLightSX = 11;
    int strobeLightDX = 10;
    int positionSX = 9;
    int positionDX = 8;
    int landingFront = 7;
    int buildInLED = 13;


  public:
    static const int phaseLanding = 0;
    static const int phaseNavigation = 1;
    static const int phaseIdle = 2;

    static const int builtInLedSequence = 0;

    static const int phases = 3;
    static const int lights = 7;
    static const int sequenceLength = 20;

    Sequencer(
      int phase,
      int beaconLight,
      int strobeLightSX,
      int strobeLightDX,
      int positionSX,
      int positionDX,
      int landingFront,
      int buildInLED
      );
    
    int seek();
};

#endif