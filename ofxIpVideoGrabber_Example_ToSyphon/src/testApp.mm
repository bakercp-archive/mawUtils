#include "testApp.h"

bool locked = false;

//--------------------------------------------------------------
void testApp::setup(){
        
    loadStreams();
	ipcam0.setup("ipcam0", width, height, true);

    ofSetFrameRate(60);

}


//--------------------------------------------------------------


void testApp::loadStreams()
{
    
    ofImage
    
	ofxXmlSettings XML;
    
	ofLog(OF_LOG_NOTICE, "Loading Streams:");
	ofLog(OF_LOG_NOTICE, "---------------");
	
	if( XML.loadFile("streams.xml") ){
		
		XML.pushTag("streams");
		string tag = "stream";
		
		int nStreams = XML.getNumTags(tag);
		
		for(int n = 0; n < nStreams; n++) {
			string name = XML.getAttribute(tag, "name", "unknown", n);
			string address = XML.getAttribute(tag, "address", "NULL", n);
			string username = XML.getAttribute(tag, "username", "NULL", n); 
			string password = XML.getAttribute(tag, "password", "NULL", n); 
			
			string logMessage = "STREAM LOADED: " + name + 
			" address: " +  address + 
			" username: " + username + 
			" password: " + password;
			
            cout << logMessage << endl;
        
            ipGrabber[n].setUsername(username);
            ipGrabber[n].setPassword(password);
            URI uri(address);
            ipGrabber[n].setURI(uri);
            ipGrabber[n].connect();
            // set up the listener!
            ofAddListener(ipGrabber[n].videoResized, this, &testApp::videoResized);
            
		}
		
		XML.popTag();
		
		
		
	} else {
		ofLog(OF_LOG_ERROR, "Unable to load streams.xml.");
	}
	ofLog(OF_LOG_NOTICE, "---------------");
}



//--------------------------------------------------------------
void testApp::videoResized(const void * sender, ofResizeEventArgs& arg) {

    ofLog(OF_LOG_VERBOSE, "A VIDEO GRABBER WAS RESIZED");

    // find the camera that sent the resize event changed
    for(int i = 0; i < NUM_CAMERAS; i++) {
        if(sender == &ipGrabber[i]) {
            string msg = "Camera connected to: " + ipGrabber[i].getURI() + " ";
            msg+= ("New DIM = " + ofToString(arg.width) + "/" + ofToString(arg.height));
            ofLog(OF_LOG_VERBOSE, msg);

        }
    }

    ofLog(OF_LOG_VERBOSE, "Unable to locate the camera.  Very odd.");

    
}


//--------------------------------------------------------------
void testApp::update(){
    // update the cameras
    for(int i = 0; i < NUM_CAMERAS; i++) {
        ipGrabber[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0,0,0);

	ofSetHexColor(0xffffff);
    
    int row = 0;
    int col = 0;
    
    int x = 0;
    int y = 0;
    
    int w = 320;
    int h = 240;
    
    float totalKBPS = 0;
    float totalFPS = 0;
    
    for(int i = 0; i < NUM_CAMERAS; i++) {
        x = col * w;
        y = row * h;

        
        row = (row + 1) % NUM_ROWS;
        
        if(row == 0) {
            col = (col + 1) % NUM_COLS;
        }

        
        ofPushMatrix();
        ofTranslate(x,y);
        ofSetColor(255,255,255,255);
        ipGrabber[i].draw(0,0,w,h);
        

        
        
        ofEnableAlphaBlending();
        
        ofSetColor(0,0,0,127);
        ofRect(10,h-45,w-20,35);
        
        float kbps = ipGrabber[i].getBps() / 1000.0;
        totalKBPS+=kbps;
        
        float fps = ipGrabber[i].getFps();
        totalFPS+=fps;
        
        ofSetColor(255,255,255);
        ofDrawBitmapString(" FPS: " + ofToString(fps, 2), 20, h-35);
        ofDrawBitmapString("KB/S: " + ofToString(kbps,2), 20, h-20);
        
        ofDisableAlphaBlending();
        
        ofPopMatrix();
    }
    
    float avgFPS = totalFPS / NUM_CAMERAS;
    float avgKBPS = totalKBPS / NUM_CAMERAS;

    ofEnableAlphaBlending();
    ofSetColor(255,255,255,80);
    ofRect(0,0, 50, 20);
    ofSetColor(0,0,0,80);
    
    ofDrawBitmapString(" AVG_FPS: " + ofToString(avgFPS,   2), 5,10);
    ofDrawBitmapString("AVG_KBPS: " + ofToString(avgKBPS,  2), 5,20);
    ofDrawBitmapString("TOT_KBPS: " + ofToString(totalKBPS,2), 5,30);
    ofDisableAlphaBlending();

    
   // ipcam0.publishTexture(&ipGrabber[0].getImage().getTexture());

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    if(key == ' ') {
     
        
    }
    
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int butipGrabbern){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int butipGrabbern){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int butipGrabbern){

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