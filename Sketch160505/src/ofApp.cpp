#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::black);
    ofHideCursor();
    for (int i = 0; i < PATHNUM; i++) {
        path[i].setup(20000, 0);
    }
    
    post.init(ofGetWidth(), ofGetHeight());
    post.createPass<BloomPass>()->setEnabled(true);
    dof = post.createPass<DofPass>();
    dof->setFocus(0.99);
    dof->setAperture(0.2);
    
    //light.setSpotlight();
    light.setPointLight();
    light.setPosition(0, 0, 0);
    //light.lookAt(ofVec3f(0, 0, 0));
    light.setAmbientColor(ofFloatColor(0.1));
    light.setDiffuseColor(ofFloatColor(1.0));
    light.setSpecularColor(ofFloatColor(0.1));
    ofEnableLighting();
}

//--------------------------------------------------------------
void ofApp::update(){
    //dof->setFocus(ofMap(mouseX, 0, ofGetWidth(), 0, 1));
    //dof->setAperture(ofMap(mouseY, 0, ofGetWidth(), 0, 1));
    //cout << "Focus = " << dof->getFocus() << endl;
    //cout << "Aperture = " << dof->getAperture() << endl;
    for (int i = 0; i < PATHNUM; i++) {
        path[i].update(ofVec2f(mouseX, mouseY));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetLineWidth(2.0);
    post.begin(cam);
    light.enable();
    //ofPushMatrix();
    //ofRotateY(ofGetElapsedTimef()*5.0);
    for (int i = 0; i < PATHNUM; i++) {
        path[i].draw();
    }
    //ofPopMatrix();
    light.disable();
    post.end();
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
