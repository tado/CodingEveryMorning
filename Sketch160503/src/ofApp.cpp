#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::darkSlateGray);
    
    for (int i = 0; i < PATHNUM; i++) {
        path[i].setup(1000, 0);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < PATHNUM; i++) {
        path[i].update(ofVec2f(mouseX, mouseY));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetLineWidth(3.0);
    //ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (int i = 0; i < PATHNUM; i++) {
        path[i].draw();
    }
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
    for (int i = 0; i < PATHNUM; i++) {
        path[i].location = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        path[i].path.clear();
    }
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
