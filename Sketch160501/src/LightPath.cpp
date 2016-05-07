//
//  LightPath.cpp
//  Sketch160501
//
//  Created by Atsushi Tadokoro on 5/1/16.
//
//

#include "LightPath.hpp"

void LightPath::setup(int _length, float angle){
    length = _length;
    velocity = ofVec2f(ofRandom(0, 0), ofRandom(0, 1)).rotate(angle);
    radius = ofGetHeight()/2.0;
}

void LightPath::update(ofVec2f mouse){
    path.clear();
    ofVec2f curVel = velocity;
    location = mouse;
    path.push_back(location);
    bool reflected;
    while(path.size() < length){
        location += curVel;
        if (ofDist(location.x, location.y, ofGetWidth()/2, ofGetHeight()/2) > radius && !reflected ) {
            ofVec2f N = ofVec2f(location.x - ofGetWidth()/2 , location.y - ofGetHeight()/2).normalize();
            curVel = curVel - 2.0 * (curVel.dot(N)) * N;
            path.push_back(location);
        }
    }
}

void LightPath::draw(){
    ofNoFill();
    ofBeginShape();
    float alpha = 255;
    for (int i = 0; i < path.size(); i++) {
        ofVertex(path[i].x, path[i].y);
    }
    ofEndShape();
}