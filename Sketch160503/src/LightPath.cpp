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
    velocity = ofVec2f(0.0, 1.0);
    location = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    col.setHsb(ofRandom(255), 180 , 255, 200);
}

void LightPath::update(ofVec2f mouse){
    path.push_back(location);
    while(path.size() < length){
        if (ofDist(path[path.size()-1].x, path[path.size()-1].y, location.x, location.y) > 4) {
            velocity.rotate(60 * int(ofRandom(1.05)));
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
        ofVertex(path[i].x, path[i].y);
    }
    ofEndShape();
}