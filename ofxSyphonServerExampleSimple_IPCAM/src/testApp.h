#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxSyphonServer.h"
#include "ofxXmlSettings.h"
#include "ofxIpVideoGrabber.h"


class testApp : public ofBaseApp{
	
public:
    
    virtual ~testApp();
    
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
	
    void exit();

    
    void loadStreams();
    
	vector<ofxSyphonServer*> ipcam;
    vector<ofxIpVideoGrabber*>	ipGrabber;
    
    bool disableRendering;

    vector<bool> showVideo;
    int currentCamera;
    
    int numRows;
    int numCols;
    
    int vidWidth;
    int vidHeight;
    
    float totalKBPS;
    float totalFPS;
    int numCams;
    
    
    ofxXmlSettings XML;
    
    // This message occurs when the incoming video stream image size changes. 
    // This can happen if the IPCamera has a single broadcast state (some cheaper IPCams do this)
    // and that broadcast size is changed by another user. 
    void videoResized(const void * sender, ofResizeEventArgs& arg);

};

#endif

