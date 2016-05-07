#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofBackground(0); //背景色を黒に
    //ofSetBackgroundAuto(false);
    
    for (int i = 0; i < 100000; i++) {
        float theta = ofRandom(PI * 2);
        float phai = ofRandom(PI * 2);
        float length = 300;
        ofVec3f loc;
        loc.x = sin(theta) * cos(phai) * length;
        loc.y = sin(theta) * sin(phai) * length;
        loc.z = cos(theta) * length;
        location.push_back(loc);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    for (int i = 0; i < 100000; i++) {
        ofSetColor(255, 63);
        ofPushMatrix();
        ofTranslate(location[i]);
        //ofRotate(ofRandom(360), ofRandom(1.0), ofRandom(1.0), ofRandom(1.0));
        ofDrawLine(0, 0, -10, 0, 0, 0);
        ofPopMatrix();
    }
    cam.end();
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
