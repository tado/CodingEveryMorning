#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    velocity = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1));
    location = ofVec2f(mouseX, mouseY);
    radius = ofGetHeight()/2.0;
}

//--------------------------------------------------------------
void ofApp::update(){
    path.clear();
    ofVec2f curVel = velocity;
    location = ofVec2f(mouseX, mouseY);
    bool reflected;
    while(path.size() < 100000){
        location += curVel;
        
        if (ofDist(location.x, location.y, ofGetWidth()/2, ofGetHeight()/2) > radius && !reflected ) {
            //float angle = cos(location.x - ofGetWidth()/2);
            //angle = ofMap(angle, 0, PI * 2, 0, 360);
            curVel.rotate(91);
        }
        path.push_back(location);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofBeginShape();
    ofSetColor(255);
    for (int i = 0; i < path.size(); i++) {
        ofVertex(path[i].x, path[i].y);
    }
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
