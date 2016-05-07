#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::black);
    ofHideCursor();
    for (int i = 0; i < PATHNUM; i++) {
        path[i].setup(20000, 0);
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
    ofSetLineWidth(2.0);
    cam.begin();
    ofRotateY(ofGetElapsedTimef()*5.0);
    for (int i = 0; i < PATHNUM; i++) {
        path[i].draw();
    }
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    for (int i = 0; i < PATHNUM; i++) {
        path[i].path.clear();
        path[i].setup(20000, 0);
    }
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
