#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void drawUnit();
    void drawRectA(ofVec2f origin, float rotate);
    void drawRectB(ofVec2f origin, float rotate);
    void drawRectC(ofVec2f origin, float rotate);
};
