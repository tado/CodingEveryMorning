#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    num = 10000;
    for (int i = 0; i < num; i++) {
        float radius =ofGetHeight()/3.0;
        float theta = 2.0 * PI * ofRandom(1.0);
        float phi = acos(2 * ofRandom(1.0) - 1);
        float x = (radius * sin(phi) * cos(theta));
        float y = (radius * sin(phi) * sin(theta));
        float z = (radius * cos(phi));
        locations.push_back(ofVec3f(x, y, z));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    for (int i = 0; i < num; i++) {
        ofPushMatrix();
        ofTranslate(locations[i]);
        billboardBegin();
        ofDrawEllipse(0, 0, 2, 2);
        billboardEnd();
        ofPopMatrix();
    }
    cam.end();
}

void ofApp::billboardBegin() {
    float modelview[16];
    int i,j;
    glPushMatrix();
    glGetFloatv(GL_MODELVIEW_MATRIX , modelview);
    for( i=0; i<3; i++ ) {
        for( j=0; j<3; j++ ) {
            if ( i==j ) {
                modelview[i*4+j] = 1.0;
            } else {
                modelview[i*4+j] = 0.0;
            }
        }
    }
    glLoadMatrixf(modelview);
}

void ofApp::billboardEnd() {
    glPopMatrix();
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
