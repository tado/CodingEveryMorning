#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);
    ofNoFill();
    ofSetColor(255);
}

void ofApp::update(){
    
}

void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(255);
    drawUnit();
    ofRotateZ(120);
    drawUnit();
    ofRotateZ(120);
    drawUnit();
}

void ofApp::drawUnit(){
    drawRectA(ofVec2f(0, 0), 0);
    drawRectA(ofVec2f(0, 0), 30);
    drawRectA(ofVec2f(0, 0), 60);
    drawRectA(ofVec2f(0, 0), -30);
    drawRectA(ofVec2f(0, 0), -60);
    
    drawRectB(ofVec2f(-100, 0),15);
    drawRectB(ofVec2f(-100, 0),15+30);
    drawRectB(ofVec2f(-100, 0),-15);
    drawRectB(ofVec2f(-100, 0),-15-30);
    
    drawRectC(ofVec2f(-193, 0),0);
    drawRectC(ofVec2f(-193, 0),30);
    drawRectC(ofVec2f(-193, 0),60);
    drawRectC(ofVec2f(-193, 0),-30);
    drawRectC(ofVec2f(-193, 0),-60);
}

void ofApp::drawRectA(ofVec2f origin, float rotate){
    ofPushMatrix();{
        ofRotateZ(rotate+90);
        
        ofPushMatrix();
        {
            ofRotateZ(15);
            ofDrawLine(0, 0, -100, 0);
            ofTranslate(-100, 0);
            ofRotateZ(-30);
            ofDrawLine(0, 0, -100, 0);
            
            ofPushMatrix();
            {
                ofRotateZ(-75);
                ofDrawLine(0, 0, -50, 0);
            }
            ofPopMatrix();
            
            ofTranslate(-100, 0);
            ofRotateZ(15);
            ofDrawLine(0, 0, 200, 0);
        }
        ofPopMatrix();
        
        ofPushMatrix();
        {
            ofRotateZ(-15);
            ofDrawLine(0, 0, -100, 0);
            ofTranslate(-100, 0);
            ofRotateZ(30);
            ofDrawLine(0, 0, -100, 0);
        }
        ofPopMatrix();
    }
    ofPopMatrix();
}

void ofApp::drawRectB(ofVec2f origin, float rotate){
    ofPushMatrix();
    ofRotateZ(rotate+90);
    ofTranslate(origin);
    
    ofPushMatrix();
    ofRotateZ(30);
    ofDrawLine(0, 0, -100, 0);
    ofTranslate(-100, 0);
    ofRotateZ(-60);
    ofDrawLine(0, 0, -100, 0);
    ofRotateZ(-60);
    ofDrawLine(0, 0, -100, 0);
    ofPopMatrix();
    
    ofPushMatrix();
    ofRotateZ(-30);
    ofDrawLine(0, 0, -100, 0);
    ofTranslate(-100, 0);
    ofRotateZ(60);
    ofDrawLine(0, 0, -100, 0);
    ofPopMatrix();
    
    ofPopMatrix();
}

void ofApp::drawRectC(ofVec2f origin, float rotate){
    ofPushMatrix();
    ofRotateZ(rotate+90);
    ofTranslate(origin);
    
    ofPushMatrix();
    ofRotateZ(45);
    ofDrawLine(0, 0, -100, 0);
    ofTranslate(-100, 0);
    ofRotateZ(-90);
    ofDrawLine(0, 0, -100, 0);
    ofRotateZ(-45);
    ofDrawLine(0, 0, -100 * sqrt(2), 0);
    ofPopMatrix();
    
    ofPushMatrix();
    ofRotateZ(-45);
    ofDrawLine(0, 0, -100, 0);
    ofTranslate(-100, 0);
    ofRotateZ(90);
    ofDrawLine(0, 0, -100, 0);
    ofPopMatrix();
    
    ofPopMatrix();
}