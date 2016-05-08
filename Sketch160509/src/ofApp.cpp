#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int num = 60;
    fontSize = 48;
    myFont.loadFont("ヒラギノ明朝 ProN W6.ttc", fontSize, true);
    for (int i = 0; i < num; i++) {
        float r = ofRandom(ofGetHeight()/4.0, ofGetHeight()/1.5);
        float theta = ofRandom(PI * 2.0);
        float phi = ofRandom(PI * 2.0);
        ofVec3f loc = ofVec3f(r * sin(theta) * cos(phi), r * sin(theta) * sin(phi), r * cos(theta));
        locations.push_back(loc);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(31), ofColor(0));
    cam.begin();
    for (int i = 0; i < locations.size(); i++) {
        ofPushMatrix();
        ofTranslate(locations[i]);
        billboardBegin();
        ofScale(0.125, -0.125, 0.125);
        myFont.drawString("おはようございます", 0, 0);
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
