#include "Node.hpp"

void Node::setup() {
    toLoc.clear();
    curLoc.clear();
    nodes.clear();
    
    nodeNum = 3;
    generated = false;
    initTime = ofGetElapsedTimef() + 1;
    for (int i = 0; i < nodeNum; i++) {
        float length = ofMap(generation, 0, 8, ofGetHeight()/6.0, ofGetHeight()/64.0);
        float r = length;
        float theta = ofRandom(PI * 2.0);
        toLoc.push_back(ofVec3f(cos(theta)*r, sin(theta)*r, 0));
        curLoc.push_back(ofVec3f(0, 0, 0));
    }
}

void Node::update() {
    auto now = ofGetElapsedTimef();
    curLoc.clear();
    for (int i = 0; i < nodeNum; i++) {
        ofVec3f loc;
        loc.x = ofxeasing::map_clamp(now, initTime, initTime + 2.0, 0, toLoc[i].x, &ofxeasing::elastic::easeOut);
        loc.y = ofxeasing::map_clamp(now, initTime, initTime + 2.0, 0, toLoc[i].y, &ofxeasing::elastic::easeOut);
        loc.z = ofxeasing::map_clamp(now, initTime, initTime + 2.0, 0, toLoc[i].z, &ofxeasing::elastic::easeOut);
        curLoc.push_back(loc);
    }
    
    if (ofGetElapsedTimef() > initTime + 1.0 && !generated) {
        for (int i = 0; i < nodeNum; i++) {
            if (generation < 7) {
                Node n;
                n.generation = generation + 1;
                n.setup();
                n.location = toLoc[i];
                n.initTime = initTime + 1.0;
                nodes.push_back(n);
            }
        }
        generated = true;
    }
    
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].update();
    }
}

void Node::draw(){
    if (ofGetElapsedTimef() > initTime) {
        ofPushMatrix();
        ofTranslate(location);
        for (int i = 0; i < nodeNum; i++) {
            ofDrawLine(ofVec3f(0, 0, 0), curLoc[i]);
            ofPushMatrix();
            ofTranslate(curLoc[i]);
            float size = ofMap(generation, 0, 8, 20, 5);
            ofDrawEllipse(0, 0, size, size);
            ofPopMatrix();
        }
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i].draw();
        }
        ofPopMatrix();
        
    }
}