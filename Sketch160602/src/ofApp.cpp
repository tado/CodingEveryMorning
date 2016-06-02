#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    light.enable();
    light.setPosition(-200, 200, 500);
    ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update(){
    myMesh.clear();
    myMesh = ofSpherePrimitive(200, 20).getMesh();
    
    float time = ofGetElapsedTimef();
    float noiseTime = time * 1.0;
    for (int i = 0; i < myMesh.getVertices().size(); i++) {
        ofVec3f loc = myMesh.getVertices()[i];
        ofVec3f noiseVec;
        noiseVec.x = ofSignedNoise(loc.x, loc.y, loc.z, noiseTime );
        noiseVec.y = ofSignedNoise(noiseTime,  loc.z, loc.y, loc.x);
        noiseVec.z = ofSignedNoise(loc.z, noiseTime, loc.y, loc.x);
        loc += noiseVec * 30.0;
        myMesh.setVertex(i, loc);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(200);
    cam.begin();
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
