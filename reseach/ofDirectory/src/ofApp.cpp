#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

//    std::string  _startPath = "/Users/sonneundasche/programming/of/apps/BleedingEye/reseach/ofDirectory/folders/A";
    std::string  _startPath = "/Users/sonneundasche/programming/of/apps/BleedingEye/reseach/ofDirectory/folders/B";

    dirList_.listDir( _startPath );
    dirDetect.readDirectories( _startPath );

    for( auto &file : dirList_.getFiles() )
    {
        ofLogNotice() << file.path()
                      << " | F: " << file.isFile()
                      << " | D: " << file.isDirectory();
    }

    ofLogNotice() << "paths: " << dirDetect.getPathsAmount();

    for ( auto &path : dirDetect.getPaths() )
    {
        ofLogNotice() << path;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
}
