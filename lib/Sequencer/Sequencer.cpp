#include "Sequencer.h"


Sequencer::Sequencer(
    int phase,
    int beaconLight,
    int strobeLightSX,
    int strobeLightDX,
    int positionSX,
    int positionDX,
    int landingFront,
    int buildInLED
) {
    //Reset sequence position
    sequencePosition = 0;

    this->activePhase = phase;

    this->beaconLight = beaconLight;
    this->strobeLightSX = strobeLightSX;
    this->strobeLightDX = strobeLightDX;
    this->positionSX = positionSX;
    this->positionDX = positionDX;
    this->landingFront = landingFront;
    this->buildInLED = buildInLED;


    //Pinout assignment
    pinMode(this->beaconLight, OUTPUT);
    pinMode(this->strobeLightSX, OUTPUT);
    pinMode(this->strobeLightDX, OUTPUT);
    pinMode(this->positionSX, OUTPUT);
    pinMode(this->positionDX, OUTPUT);
    pinMode(this->landingFront, OUTPUT);
    pinMode(this->buildInLED, OUTPUT);
}

int Sequencer::seek() 
{
    sequencePosition ++;

    if(sequencePosition >= Sequencer::sequenceLength)
    {
        sequencePosition = 0;
    }

    //Only for test, remove it
    activePhase = 2;

    //BuildIntLed Sequence
    digitalWrite(this->buildInLED, (sequences[activePhase][4][sequencePosition] == 1)?HIGH:LOW);

    //Beacon Light
    digitalWrite(this->beaconLight, (sequences[activePhase][1][sequencePosition] == 1)?HIGH:LOW);

    //strobeLightSX
    digitalWrite(this->strobeLightSX, (sequences[activePhase][2][sequencePosition] == 1)?HIGH:LOW);

    //strobeLightDX
    digitalWrite(this->strobeLightDX, (sequences[activePhase][3][sequencePosition] == 1)?HIGH:LOW);

    //positionSX
    digitalWrite(this->positionSX, (sequences[activePhase][4][sequencePosition] == 1)?HIGH:LOW);

    //positionDX
    digitalWrite(this->positionDX, (sequences[activePhase][5][sequencePosition] == 1)?HIGH:LOW);

    //Landing Front
    digitalWrite(this->landingFront, (sequences[activePhase][6][sequencePosition] == 1)?HIGH:LOW);

    return sequencePosition;
}