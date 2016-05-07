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
    velocity = ofVec3f(0.0, 1.0);
    location = ofVec3f(0, 0, 0);
    //col.setHsb(ofRandom(255), 180 , 255, 127);
    col = ofColor(255, 127);
}

void LightPath::update(ofVec2f mouse){
    path.push_back(location);
    while(path.size() < length){
        if (ofDist(path[path.size()-1].x, path[path.size()-1].y, path[path.size()-1].z, location.x, location.y, location.z) > 12) {
            velocity.rotate(90 * int(ofRandom(1.2)), ofVec3f(0, 0, 1));
            velocity.rotate(90 * int(ofRandom(1.2)), ofVec3f(0, 1, 0));
            velocity.rotate(90 * int(ofRandom(1.2)), ofVec3f(1, 0, 0));
            path.push_back(location);
        }
        location += velocity;
    }
}

void LightPath::draw(){
    ofNoFill();
    ofBeginShape();
    ofSetColor(col);
    for (int i = 0; i < path.size(); i++) {
        ofVertex(path[i].x, path[i].y, path[i].z);
    }
    ofEndShape();
}