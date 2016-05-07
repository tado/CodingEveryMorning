#include "Node.hpp"

void Node::setup() {
    toLoc.clear();
    curLoc.clear();
    nodes.clear();
    
    nodeNum = 4;
    generated = false;
    initTime = ofGetElapsedTimef() + 1;
    for (int i = 0; i < nodeNum; i++) {
        float length = ofMap(generation, 0, 6, ofGetHeight()/4.0, ofGetHeight()/256.0);
        float r = length;
        float theta = PI / 2.0 * int(ofRandom(4));
        float phi = PI / 2.0 * int(ofRandom(4));
        ofVec3f loc = ofVec3f(r * sin(theta) * cos(phi), r * sin(theta) * sin(phi), r * cos(theta));
        toLoc.push_back(loc);
        curLoc.push_back(ofVec3f(0, 0, 0));
    }
}

void Node::update() {
    auto now = ofGetElapsedTimef();
    curLoc.clear();
    for (int i = 0; i < nodeNum; i++) {
        ofVec3f loc;
        loc.x = ofxeasing::map_clamp(now, initTime, initTime + 2.0, 0, toLoc[i].x, &ofxeasing::elastic::easeOut);
        loc.y = ofxeasing::map_clamp(now, initTime, initTime + 2.0, 0, toLoc[i].y, &ofxeasing::elastic::easeOut);
        loc.z = ofxeasing::map_clamp(now, initTime, initTime + 2.0, 0, toLoc[i].z, &ofxeasing::elastic::easeOut);
        curLoc.push_back(loc);
    }
    
    if (ofGetElapsedTimef() > initTime + 1.0 && !generated) {
        for (int i = 0; i < nodeNum; i++) {
            if (generation < 6) {
                Node n;
                n.generation = generation + 1;
                n.setup();
                n.location = toLoc[i];
                n.initTime = initTime + 1.0;
                nodes.push_back(n);
            }
        }
        generated = true;
    }
    
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].update();
    }
}

void Node::draw(){
    if (ofGetElapsedTimef() > initTime) {
        ofPushMatrix();
        ofTranslate(location);
        for (int i = 0; i < nodeNum; i++) {
            float alpha = ofMap(generation, 0, 6, 255, 190);
            ofSetColor(255, alpha);
            ofDrawLine(ofVec3f(0, 0, 0), curLoc[i]);
            ofPushMatrix();
            ofTranslate(curLoc[i]);
            float size = ofMap(generation, 0, 6, 20, 1);
            billboardBegin();
            ofSetColor(0, 127, 255);
            ofDrawEllipse(0, 0, size, size);
            billboardEnd();
            ofPopMatrix();
        }
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i].draw();
        }
        ofPopMatrix();
        
    }
}

void Node::billboardBegin() {
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



void Node::billboardEnd() {
    glPopMatrix();
}