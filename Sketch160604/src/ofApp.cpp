#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    //light.enable();
    //light.setPosition(-200, 200, 500);
    ofEnableDepthTest();
    //myMesh = ofSpherePrimitive(200, 60).getMesh();
    myMesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(2.0);
    for (int i = 0; i < 20000; i++) {
        float x = ofRandom(-ofGetWidth()/6, ofGetWidth()/6);
        float y = ofRandom(-ofGetWidth()/6, ofGetWidth()/6);
        float z = ofRandom(-ofGetWidth()/6, ofGetWidth()/6);
        ofVec3f location = ofVec3f(x, y, z);
        myMesh.addVertex(location);
        myMesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));
    }
    
    box.set(ofGetWidth()/3.0, ofGetWidth()/3.0, ofGetWidth()/3.0);
    box.setResolution(1);
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    float noiseTime = time * 1.0;
    
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        ofVec3f loc = myMesh.getVertices()[i] / 400.0;
        float r = ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef() * 1.5);
        float g = ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef() * 1.7);
        float b = ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef() * 1.9);
        myMesh.setColor(i, ofFloatColor(r, g, b, 1.0));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofPushMatrix();
    ofRotateX(30);
    ofRotateY(ofGetElapsedTimef() * 5);
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
