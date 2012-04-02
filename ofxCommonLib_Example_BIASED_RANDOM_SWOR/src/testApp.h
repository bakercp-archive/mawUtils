#pragma once

#include "ofMain.h"

#include "RandomSWR.h"



class testApp : public ofBaseApp{

	public:
    virtual ~testApp();
    
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        RandomSWR* rs;
        RandomSWR* rsw;
        RandomSWR* rsw0;
        int numCounts;
        int* counts;
        int* weightedCounts;
        int* randCounts;
        int* weightedCounts0;

};
