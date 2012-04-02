#include "testApp.h"


testApp::~testApp() {
    delete rs;
    delete counts;
    delete randCounts;
}


//--------------------------------------------------------------
void testApp::setup(){
//    ofSetFrameRate(30);
    numCounts = ofGetWidth();
    
    rs = new RandomSWR(numCounts);

    float* weights = new float[numCounts];
    for(int i = 0; i < numCounts; i++) {
        weights[i] = (int)ofMap(i, 0, numCounts, 0, 127);
    }
    
    rsw = new RandomSWR(numCounts,weights);

    for(int i = 0; i < numCounts; i++) {
        float r = ((float)i / numCounts ) * TWO_PI* 2;
        float s = sin(r);
        s*=(s*10);//*10); // square it and scale it
        s+=1; // make sure it is never zero
        weights[i] = (int)s;
    }
    
    rsw0 = new RandomSWR(numCounts,weights);

    
    
    delete weights;
    
    
    counts = new int[numCounts];
    randCounts = new int[numCounts];
    weightedCounts = new int[numCounts];
    weightedCounts0 = new int[numCounts];
    for(int i = 0; i < numCounts; i++) {
        counts[i] = randCounts[i] = weightedCounts[i] = weightedCounts0[i] = 0;
    }   
}

//--------------------------------------------------------------
void testApp::update(){
    
    // do a bunch
    for(int i = 0; i < 10; i++) {
        counts[rs->next()]++;
        randCounts[(int)ofRandom(0,numCounts)]++;
        weightedCounts[rsw->next()]++;
        weightedCounts0[rsw0->next()]++;

    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    
    float cw = ofGetWidth() / numCounts;
    
    ofFill();
  
    ofEnableAlphaBlending();
    ofSetColor(255,0,0,127);
    for(int i = 0; i < numCounts; i++) {
        float x = i * cw;
        float y = ofGetHeight() - counts[i];
        float w = cw;
        float h = counts[i];
        
        ofRect(x, y, w, h);
    }
    
    ofSetColor(0,0,255,127);
    for(int i = 0; i < numCounts; i++) {
        float x = i * cw;
        float y = ofGetHeight() - randCounts[i];
        float w = cw;
        float h = randCounts[i];
        
        ofRect(x, y, w, h);
    }
    
    ofSetColor(255,255,0,127);
    for(int i = 0; i < numCounts; i++) {
        float x = i * cw;
        float y = ofGetHeight() - weightedCounts[i];
        float w = cw;
        float h = weightedCounts[i];
        
        ofRect(x, y, w, h);
    }

    ofSetColor(0,255,0,127);
    for(int i = 0; i < numCounts; i++) {
        float x = i * cw;
        float y = ofGetHeight() - weightedCounts0[i];
        float w = cw;
        float h = weightedCounts0[i];
        
        ofRect(x, y, w, h);
    }

    ofDisableAlphaBlending();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}