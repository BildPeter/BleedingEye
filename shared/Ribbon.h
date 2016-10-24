//
// Created by Peter A. Kolski on 24.10.16.
//

#ifndef BLEEDINGEYE_RIBBON_H
#define BLEEDINGEYE_RIBBON_H

#include "ofMain.h"
#include "ofxMidi.h"
#include "ofxTwistedRibbon.h"
#include "MidiValues.hpp"

namespace bildpeter
{
class Ribbon
{

public:
    Ribbon();

    Ribbon( int ribbonLength, const ofColor &ribbonColor, float ribbonThickness );

    // TODO extract Midi
    void update( bildpeter::MidiValues midiValues, string sizeTxt, string fadeTxt, double x, double y, double z );
    void    draw( bildpeter::MidiValues &midiValues, string nameDev );

private:
    ofxTwistedRibbon        *ribbonLeft_, *ribbonRight_;
    int                     ribbonLength_    = 200;
    ofColor                 ribbonColor_     = ofColor::black;
    float                   ribbonThickness_ = 10.0;
    float                   ribbonRadius_    = 600;
    float                   ribbonRadiusMax_ = 1000;
};

}



#endif //BLEEDINGEYE_RIBBON_H
