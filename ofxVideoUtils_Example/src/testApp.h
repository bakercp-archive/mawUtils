#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxKeyFrameInterpolator.h"
#include "ofxVideoBufferPlayer.h"
#include "CanvasLayerTransform.h"
#include "AxisCameraPatch.h"
//#include "ofxVideoBufferManager.h"

class testApp : public ofBaseApp{

	public:

        ~testApp();

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void resized(int w, int h);

    
    bool ofKeyAlt() {
        return (glutGetModifiers() & GLUT_ACTIVE_ALT);
    }
    
    bool ofKeyShift() {
        return (glutGetModifiers() & GLUT_ACTIVE_SHIFT);
    }
    
    bool ofKeyControl() {
        return (glutGetModifiers() & GLUT_ACTIVE_CTRL);
    }

    
    void makeBuffer(int x, int y) {
        currentBuffer=buffers.size();
        int fps = 30;
        buffers.push_back(new ofxVideoBufferPlayer(camWidth, camHeight, OF_IMAGE_COLOR, fps, fps * 2));// * 5); //
        xform.push_back(CanvasLayerTransform(ofPoint(x,y), ofPoint(0,0,0), ofPoint(0,0,0), ofPoint(1,1,1)));
        buffers[currentBuffer]->setBufferMode(VB_BUFFERING);

    }
    
	/*
		ofVideoPlayer 		fingerMovie;
		bool                frameByframe;
	*/
	 
	//ofxKeyFrameInterpolator interp;

    //ofxVideoBufferManager bm;
    
    ofVideoGrabber 		vidGrabber;
    AxisCameraPatch cam;
	ofTexture			videoTexture0;

    
    
    unsigned char * 	videoInverted;
    ofTexture			videoTexture;
    int 				camWidth;
    int 				camHeight;

    vector<ofxVideoBufferPlayer*> buffers;
    vector<CanvasLayerTransform> xform;

    int currentSource;
    
    int currentBuffer;
        
    int thisKey;
};

#endif
