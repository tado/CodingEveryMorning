#pragma once
#include "ofMain.h"
#include "ofxEasing.h"

class Node {
public:
    void setup();
    void update();
    void draw();
    
    ofVec3f location;
    vector<ofVec3f> toLoc;
    vector<ofVec3f> curLoc;
    vector<Node> nodes;
    
    float initTime;
    int nodeNum;
    int generation;
    bool generated;
};