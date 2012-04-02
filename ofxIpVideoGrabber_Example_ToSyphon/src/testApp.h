#pragma once

#include "ofMain.h"
#include "ofxIpVideoGrabber.h"
#include "ofxXmlSettings.h"
#include "ofxSyphonServer.h"

#define NUM_CAMERAS 4
#define NUM_ROWS 2
#define NUM_COLS 2

class IPCameraDef {
public:
    IPCameraDef(string _uri) {
        uri = _uri;
    }
    
    IPCameraDef(string _uri, string _username, string _password) {
        uri = _uri;
        username = _username;
        password = _password;
    }
    
    string uri;
    string username;
    string password;
};



class testApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		

		ofxIpVideoGrabber	ipGrabber[NUM_CAMERAS]; // our four cameras
        
        void loadStreams();
    
        vector<IPCameraDef> ipcams; // a list of IPCameras
        
       // ofxSyphonServer ipcam0;
       // ofxSyphonServer ipcam1;
       // ofxSyphonServer ipcam2;
       // ofxSyphonServer ipcam3;

    
        // This message occurs when the incoming video stream image size changes. 
        // This can happen if the IPCamera has a single broadcast state (some cheaper IPCams do this)
        // and that broadcast size is changed by another user. 
        void videoResized(const void * sender, ofResizeEventArgs& arg);
    
};