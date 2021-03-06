//
// Created by Peter A. Kolski on 25.10.16.
//

#include "Video.h"

namespace bildpeter
{
void Video::setup( string pathA, string pathB )
{
    videoA_.loadDirectory( pathA );
    videoB_.loadDirectory( pathB );
    videoA_.play();
    videoB_.play();
}

void Video::update( float faderA, float faderB, float sensorA, float sensorB, float arm, float back )
{
    sensorValA_        = ( 1 - arm ) * sensorA;
    sensorValB_        = ( 1 - back ) * sensorB;

    if ( faderA )
    {
        if ( !videoA_.isPlaying() ) { videoA_.play(); }
        videoA_.update();
        videoA_.fade( ofClamp( faderA - sensorValA_, 0.0, 1.0 ) * 255 );
    }
    else    { videoA_.setPaused( true ); }

    if ( faderB ) {
        if ( !videoB_.isPlaying() ) { videoB_.play(); }
        videoB_.update();
        videoB_.fade( ofClamp( faderB - sensorValB_, 0.0, 1.0 ) * 255 );
    }
    else    { videoB_.setPaused( true ); }
}

void Video::draw( float faderA, float faderB )
{
    auto x = ofGetWidth() / 2;
    auto y = ofGetHeight() / 2;
    auto z = -2000;
    // macbookAir
    auto w = 5120;
    auto h = 3200;

    if ( faderA ) videoA_.draw( x, y, z, w, h );
    if ( faderB ) videoB_.draw( x, y, z, w, h );
}

void Video::next()
{
    videoA_.nextVideo();
    videoB_.nextVideo();
}

bool Video::setVideoA( int index )
{
    return videoA_.setVideoByIndex( index );
}

bool Video::setVideoB( int index )
{
    return videoB_.setVideoByIndex( index );
}

bool Video::setBankA( int index )
{

    return videoA_.setBankByIndex( index );
}

bool Video::setBankB( int index )
{
    return videoB_.setBankByIndex( index );
}

} // namespace bildpeter