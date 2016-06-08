#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    light.enable();
    light.setPosition(-500, 500, 500);
    ofEnableDepthTest();
    model.loadModel("FinalBaseMesh.obj");
    myMesh = model.getMesh(0);
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        myMesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    myMesh = model.getMesh(0);
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        ofVec3f loc = myMesh.getVertex(i);
        loc.y = loc.y - 10;
        loc = loc / 4.0;
        
        float noise = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()), 0, 1, 250, 400);
        ofVec3f newLoc = loc * noise;
        myMesh.setVertex(i, newLoc);

        float c = ofMap(ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef()),0, 1, 0.5, 1.2);
        myMesh.addColor(ofFloatColor(c, c, c, 1.0));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofRotateY(ofGetElapsedTimef() * 50.0);
    ofPushMatrix();
    myMesh.draw();
    ofPopMatrix();
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
