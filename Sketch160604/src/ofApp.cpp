#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    light.enable();
    light.setPosition(-100, 100, 800);
    ofEnableDepthTest();
    //myMesh = ofSpherePrimitive(200, 60).getMesh();
    myMesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(2.0);
    for (int i = 0; i < 5000; i++) {
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
        ofVec3f loc = myMesh.getVertices()[i] / 800.0;
        float r = ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef() * 0.5);
        float g = ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef() * 0.6);
        float b = ofNoise(loc.x, loc.y, loc.z, ofGetElapsedTimef() * 0.7);
        myMesh.setColor(i, ofFloatColor(r, g, b, 1.0));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofHideCursor();
    cam.begin();
    ofPushMatrix();
    ofRotateX(30);
    ofRotateY(ofGetElapsedTimef() * 2);
    //myMesh.draw();
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        ofPushMatrix();
        ofTranslate(myMesh.getVertices()[i]);
        ofRotateX(myMesh.getColors()[i].r * 360);
        ofRotateY(myMesh.getColors()[i].g * 360);
        ofRotateZ(myMesh.getColors()[i].b * 360);
        //ofSetColor(myMesh.getColors()[i].r*255, myMesh.getColors()[i].g*255, myMesh.getColors()[i].b*255);
        ofDrawLine(-10, 0, 10, 0);
        ofPopMatrix();
    }
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
