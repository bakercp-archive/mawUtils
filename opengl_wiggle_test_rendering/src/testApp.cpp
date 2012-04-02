#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    i = 0;
    f = 0;
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){

    i = (i + 1) % ofGetWidth();
    f = (f + 0.5);
    if(f > ofGetWidth()) f = 0;
    
}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackground(0);
    ofSetColor(255);

//    drawString(500,500, "this is at est!");
    
    
    string s = ofToString(mouseX) + "/" + ofToString(mouseY) + " : " + ofToString(ofGetWidth()) + "/" + ofToString(ofGetHeight());
    
    string si = "i=" + ofToString(i);
    string sf = "f=" + ofToString(f);
    
    ofDrawBitmapString(si, i+10,i+15);
    ofLine(i, 0, i, ofGetHeight());
    ofLine(0, i, ofGetWidth(), i);

 //   ofEnableSmoothing();

    
    ofDrawBitmapString(sf, f+10,f+15);
    ofLine(f, 0, f, ofGetHeight());
    ofLine(0, f, ofGetWidth(), f);

 //   ofDisableSmoothing();
    
    
    
    ofSetColor(255);
    ofFill();
    ofDrawBitmapString(s, mouseX, mouseY-10);

    ofSetColor(0,255,0);
    ofLine(mouseX, 0, mouseX, ofGetHeight());
    ofLine(0, mouseY, ofGetWidth(), mouseY);

    ofRect(100, 100, 100, 100);

    ofSetColor(255,100);
    ofNoFill();
    ofPushMatrix();
    ofTranslate(10, i+10);
    ofRect(0, 0, 100, 100);
//    ofRect(400, 400, 100, 100);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(i+10, 400);
    ofRect(0, 0, 100, 100);
    //    ofRect(400, 400, 100, 100);
    ofPopMatrix();

    ofSetColor(255,0,0);
    
    ofSetLineWidth(1);
    
    float line_vertex[]=
    {
        (int)(i+32),(int)0,(int)(i+32),(int)ofGetHeight()
    };
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, line_vertex);
    glDrawArrays(GL_LINES, 0, 2);
    
    float line_vertex2[]=
    {
        (int)(i+35),(int)0,(int)(i+35),(int)ofGetHeight()
    };
    
    ofSetColor(0,255,0);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, line_vertex2);
    glDrawArrays(GL_LINES, 0, 2);
    

    float line_vertex3[]=
    {
        (int)0, (int)(i+32),(int)ofGetWidth(),(int)(i+32)
    };
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, line_vertex3);
    glDrawArrays(GL_LINES, 0, 2);
    
    float line_vertex4[]=
    {
        (int)0, (int)(i+35),(int)ofGetWidth(),(int)(i+35)
    };
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, line_vertex4);
    glDrawArrays(GL_LINES, 0, 2);
    

    
    
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