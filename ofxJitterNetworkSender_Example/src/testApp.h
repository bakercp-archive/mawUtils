#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"

#include "ofxJitterNetworkSender.h"

class testApp : public ofBaseApp{
    
public:
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
    
		ofVideoPlayer 		fingerMovie;
		ofVideoGrabber 		vidGrabber;

    ///////////////////
    
    ofxTCPClient tcpClient;
    string msgTx, msgRx;

    float counter;
    int connectTime;
    int deltaTime;		
    
    bool weConnected;
    
    int size;
    int pos;
    bool typed;
    
    t_jit_net_packet_header m_chunkHeader;
    t_jit_net_packet_matrix m_matrixHeader;
    t_jit_net_packet_latency m_latencyPacket;
    
	
    t_jit_net_packet_header m_messageHeader;

	int 				camWidth;
	int 				camHeight;

	bool sendLive;
	
	
	void makeMatrixHeader(int planecount, int type, int *dim, int dimcount);
	
	void sendMatrix(t_jit_net_packet_header *headerPacket, 
					t_jit_net_packet_matrix *matrixInfoPacket, 
					char *matrix);
	void sendText(string s);
	
	void readResponse();

	
	
	t_jit_net_packet_header * chunkHeader() {return &m_chunkHeader;}
	t_jit_net_packet_matrix * matrixHeader() {return &m_matrixHeader;}
	
	int numbytes; 
	char buf[MAXDATASIZE]; 
	
	char* peer0_0;
	
	double swap(double d);
	
	
	double lastSent;
	
};


