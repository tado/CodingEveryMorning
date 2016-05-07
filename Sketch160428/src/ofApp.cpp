#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofBackground(0); //背景色を黒に
    ofSetBackgroundAuto(false);
    
    //数の上限を1000個に
    max_num = 80;
}

//--------------------------------------------------------------
void ofApp::update(){
    //NUM回くりかえし
    for (int i = 0; i < location.size(); i++) {
        location[i] += velocity[i];
    }
    
    //新規に位置ベクトルと速度ベクトルを生成し、配列に追加
    float theta = ofRandom(PI * 2);
    float phai = ofRandom(PI * 2);
    float length = ofRandom(300);
    ofVec3f loc;
    loc.x = sin(theta) * cos(phai) * length;
    loc.y = sin(theta) * sin(phai) * length;
    loc.z = cos(theta) * length;
    location.push_back(loc);
    
    //location.push_back(ofVec3f(ofRandom(-size, size), ofRandom(-size, size), ofRandom(-size, size)));
    //float angle = ofRandom(PI*2);
    //float length = ofRandom(400);
    
    velocity.push_back(ofVec3f(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1)));
    
    //もし上限値を超えたら、先頭の要素を削除する
    if(location.size() > max_num){
        location.erase(location.begin());
        velocity.erase(velocity.begin());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    //ofRotateX(-20);
    //ofRotateY(20);
    //計算した位置に円を描画
    ofSetColor(255, 31); //円の色
    //NUM回くりかえし
    for (int i = 0; i < location.size(); i++) {

        ofDrawCircle(location[i], 1); //半径5の円を描画
        ofDrawCircle(location[i], 1); //半径5の円を描画
        
        float size = 300;
        float dist = ofDist(0, 0, 0, location[i].x, location[i].y, location[i].z);
        if (dist > size) {
            velocity[i] = ofVec3f(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1));
        }
        
        /*
        float size = 200;
        //画面の端でバウンドするように
        if (location[i].x < -size || location[i].x > size) {
            velocity[i].x *= -1; //横向きの速度を反転(バウンド)
        }
        if (location[i].y < -size || location[i].y > size) {
            velocity[i].y *= -1; //横向きの速度を反転(バウンド)
        }
        if (location[i].z < -size || location[i].z > size) {
            velocity[i].z *= -1; //横向きの速度を反転(バウンド)
        }
        */
    }
    
    ofPopMatrix();
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
