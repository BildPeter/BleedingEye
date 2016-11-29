//
// Created by Peter A. Kolski on 29.11.16.
//

#ifndef BLEEDINGEYE_MIDIMAPPING_H
#define BLEEDINGEYE_MIDIMAPPING_H

#include <vector>
#include <string>
#include "ofxMidi.h"
#include "MidiValues.hpp"
#include "ofxXmlSettings.h"


namespace bildpeter
{

class MidiMapping
{
public:
    void midiSetup( string path, ofxMidiListener *listener );
    void close( ofxMidiListener *listener );

    bildpeter::MidiValues   midiUsed;

private:
    ofxXmlSettings  xmlReader;
    const int       midiValStandard = 88;
    const string    keyMidiPort     = "port";
    ofxMidiIn               midiIn;


    std::vector< std::string >   midiKeywordsOld =
            {   "networkFade",
                "networkFadeSensor",
                "networkMovement",
                "networkMovementSensor",
                "networkDistCenter",
                "networkDistCenterSensor",
                "networkDistDiff",
                "networkDistDiffSensor",
                "linesFade",
                "linesSpeed",
                "linesSpeedSensor",
                "linesColor",
                "flowFade",
                "flowStrength",
                "flowStrengthSensor",
                "ribbonFade",
                "ribbonSize",
                "videoFaderA",
                "videoFaderB",
                "videoSensorA",
                "videoSensorB",
                "sensitivity",
            };

};

} // namespace bildpeter

#endif //BLEEDINGEYE_MIDIMAPPING_H
