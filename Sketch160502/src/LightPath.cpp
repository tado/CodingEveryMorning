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
    //velocity = ofVec2f(ofRandom(0, 0), ofRandom(0, 1)).rotate(angle);
    velocity = ofVec3f(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1));
    radius = ofGetHeight()/2.0;
}

void LightPath::update(ofVec2f mouse){
    path.clear();
    ofVec3f curVel = velocity;
    location = ofVec3f(mouse.x, mouse.y, 0);
    path.push_back(location);
    while(path.size() < length){
        location += curVel;
        if (ofDist(location.x, location.y, location.z, 0, 0, 0) > radius ) {
            ofVec3f N = ofVec3f(location.x , location.y, location.z).normalize();
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
        ofVertex(path[i].x, path[i].y, path[i].z);
    }
    ofEndShape();
}