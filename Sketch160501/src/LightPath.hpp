#pragma once
#include "ofMain.h"

class LightPath {
public:
    void setup(int length, float angle);
    void update(ofVec2f mouse);
    void draw();
    
    vector<ofVec2f> path;
    ofVec2f velocity;
    ofVec2f location;
    float radius;
    ofMesh mesh;
    int length;
};