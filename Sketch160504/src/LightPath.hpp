#pragma once
#include "ofMain.h"

class LightPath {
public:
    void setup(int length, float angle);
    void update(ofVec2f mouse);
    void draw();
    
    vector<ofVec3f> path;
    ofVec3f velocity;
    ofVec3f location;
    int length;
    ofColor col;
};