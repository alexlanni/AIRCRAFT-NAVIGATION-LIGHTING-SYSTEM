#ifndef Sequencer_h
#define Sequencer_h

#include <Arduino.h>

class Sequencer {
  private:
    int activePhase;
    int sequenceLength;
    int sequencePosition;

  public:
    Sequencer(int phase);
};

#endif