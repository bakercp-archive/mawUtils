#include "testApp.h"

#define RECONNECT_TIME 400

//--------------------------------------------------------------
void testApp::setup(){	 
	
	camWidth 		= 160;	// try to grab at this size. 
	camHeight 		= 120;
	
	sendLive = false;
	
	vidGrabber.setVerbose(false);
	vidGrabber.initGrabber(camWidth,camHeight);

	fingerMovie.loadMovie("movies/fingers_160x120x15fps.mov");
	fingerMovie.play();
	
	// we don't want to be running to fast
	ofSetVerticalSync(true);

	//load our type
	//mono.loadFont("type/mono.ttf",9);
	//monosm.loadFont("type/mono.ttf",8);
	
	//some variables
	
	//have we typed
	typed	= false;
	
	//our typing position
	pos		= 0;
	
	//our send and recieve strings
	msgTx	= "";
	msgRx	= "";
	
	//are we connected to the server - if this fails we 
	//will check every few seconds to see if the server exists
	weConnected = tcpClient.setup("127.0.0.1", 8888);
	
	connectTime = 0;	
	deltaTime = 0;
	
	tcpClient.setVerbose(false);
}

//--------------------------------------------------------------
void testApp::update(){
	
	sendText("helloooooo");
	
	fingerMovie.idleMovie();
	vidGrabber.grabFrame();

	int planecount = 3;
	int dimcount = 2;
	int dim[dimcount];
	dim[0] = fingerMovie.width;
	dim[1] = fingerMovie.height;
	int type = 0; // char
	
	makeMatrixHeader(planecount, type, dim, dimcount);
	lastSent = matrixHeader()->time;
	

	if(weConnected){
		
		if(fingerMovie.isFrameNew() && !sendLive) {
//			sendMatrix(chunkHeader(), matrixHeader(), (char*)fingerMovie.offscreenGWorldPixels);
					sendMatrix(chunkHeader(), matrixHeader(), (char*)fingerMovie.getPixels());
		}
		
		if (vidGrabber.isFrameNew() && sendLive){
//			sendMatrix(chunkHeader(), matrixHeader(), (char*)vidGrabber.offscreenGWorldPixels);
            sendMatrix(chunkHeader(), matrixHeader(), (char*)vidGrabber.getPixels());

		}
		
	}else{		
		//if we are not connected lets try and reconnect every 5 seconds
		deltaTime = ofGetElapsedTimeMillis() - connectTime;
		
		if( deltaTime > 5000 ) {
			weConnected = tcpClient.setup("127.0.0.1", 8888);
			connectTime = ofGetElapsedTimeMillis();
		}
	}
	
		


	ofBackground(230, 230, 230);	
}

void testApp::sendText(string s) {
	
	/* */
	m_messageHeader.id = SWAP32(JIT_MESSAGE_PACKET_ID);
	m_messageHeader.size = SWAP32(sizeof(long) + // size
								  sizeof(long) + // ac
								  sizeof(char) + // type
								  sizeof(char)*s.length() + // number
								  sizeof(char)); // null terminator
	
	tcpClient.sendRawBytes((char *)&m_messageHeader.id, sizeof(long));
	tcpClient.sendRawBytes((char *)&m_messageHeader.size, sizeof(long));
	
	
	//printf("size=%d\n",SWAP32(m_messageHeader.size));
	
	// the packet
	long messageSizeBytes = m_messageHeader.size; //	32-bit integer that contains the size of the serialized message in bytes. 
	long ac = SWAP32(0);      //    Following that another 32-bit integer gives the argument count for the atoms. 
	/// Following that comes the message atoms themselves, starting with the leading symbol if it exists. 
	//  Each atom is represented in memory first with a char that indicates what type of atom it is:
	//		's' for symbol, 'l' for long, and 'f' for float. 
	//		For long and float atoms, the next 4 bytes contain the value of the atom; 
	//		for symbol atoms a null terminated character string follows. 
	
	
	char atomType = 's'; //'s' for symbol, 'l' for long, and 'f' for float. 
	//	long/float;
	//char number[] = {'t','h','i','s'};
	
	const char *cp = s.c_str(); // seriously
	
	char nullTerm = '\0';
	
	tcpClient.sendRawBytes((char *)&messageSizeBytes, sizeof(long));
	tcpClient.sendRawBytes((char *)&ac, sizeof(long));
	tcpClient.sendRawBytes((char *)&atomType, sizeof(char));
	tcpClient.sendRawBytes((char *)cp, s.length()*sizeof(char));
	tcpClient.sendRawBytes((char *)&nullTerm, sizeof(char));
	
	
	//	readResponse();
	
	
}


//--------------------------------------------------------------
void testApp::draw(){
	ofSetHexColor(0xFFFFFF);
	fingerMovie.draw(20,20);
	vidGrabber.draw(20,160);
	
	ofSetHexColor(0x000000);//, <#int g#>, <#int b#>)
	ofDrawBitmapString("this is a video playing\nin openframeworks and\nbeing sent over tcp to port\n8888 in Jitter above ...\n\n\npress (space) to toggle\nbetween video sources\n\nmessage sending, bangs, lists, etc \nto jit.net.recv outlet is\nin the works ...\n(this works in jit 4.5 too)", 200, 100);
		
	
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){ 
	sendLive = !sendLive;
	
	
	
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


void testApp::windowResized(int w, int h) {}
void testApp::dragEvent(ofDragInfo dragInfo) {}
void testApp::gotMessage(ofMessage msg) {}



void testApp::makeMatrixHeader(int planecount, int type, int *dim, int dimcount)
{
	long i, j, k;
	int typeSize;
	
	switch(type)
	{
		case 3:		
            typeSize = sizeof(double);
			break;
		case 2:		
            typeSize = sizeof(float);
			break;
		case 1:		
            typeSize = sizeof(long);
			break;
		case 0:
		default:	
            typeSize = sizeof(char);
			break;
	}
	
	m_chunkHeader.id = SWAP32(JIT_MATRIX_PACKET_ID);
	m_chunkHeader.size = sizeof(t_jit_net_packet_matrix);
	
	m_matrixHeader.id = JIT_MATRIX_PACKET_ID;
	m_matrixHeader.size = SWAP32(sizeof(t_jit_net_packet_matrix));
	m_matrixHeader.planecount = SWAP32(planecount);
	m_matrixHeader.type = SWAP32(type);
	m_matrixHeader.dimcount = SWAP32(dimcount);
	
	for(i=0; i < dimcount; i++) {
		m_matrixHeader.dim[i] = SWAP32(dim[i]);
	}
	
	while(i < JIT_MATRIX_MAX_DIMCOUNT) {
		m_matrixHeader.dim[i] = SWAP32(0); // <-- in the jitter one, they seem to just copy the dim through ...
		i++;
	}
	
	//special case for first value
	m_matrixHeader.dimstride[0] = SWAP32(typeSize * planecount);
	
	for(i=1; i <= dimcount; i++) {
		m_matrixHeader.dimstride[i] = SWAP32(dim[i-1]*SWAP32(m_matrixHeader.dimstride[i-1])); // watch out for these .. they need to come back ...
	}
	
	while(i < JIT_MATRIX_MAX_DIMCOUNT) {
		m_matrixHeader.dimstride[i] = SWAP32(0);
		i++;
	}
	
	m_matrixHeader.datasize = SWAP32(SWAP32(m_matrixHeader.dimstride[dimcount-1])*SWAP32(m_matrixHeader.dim[dimcount-1]));
	m_matrixHeader.time = ofGetElapsedTimef();
}


void testApp :: sendMatrix(t_jit_net_packet_header *headerPacket, 
						   t_jit_net_packet_matrix *matrixInfoPacket, 
						   char *matrix)
{
	int packSize;
	
	//////SEND ONE MATRIX
	packSize = sizeof(t_jit_net_packet_header);
	tcpClient.sendRawBytes((char *)(headerPacket), packSize);
	
	packSize = sizeof(t_jit_net_packet_matrix);
	tcpClient.sendRawBytes((char *)(matrixInfoPacket), packSize);
	
	packSize = SWAP32(m_matrixHeader.dimstride[SWAP32(m_matrixHeader.dimcount)-1])*SWAP32(m_matrixHeader.dim[SWAP32(m_matrixHeader.dimcount)-1]);
	tcpClient.sendRawBytes(matrix, packSize);
}


void testApp :: readResponse()
{
	//////READ RESPONSE
	///////////
	if ((numbytes=tcpClient.receiveRawBytes(buf, MAXDATASIZE-1)) == -1) {
		//perror("recv error\n");
		// skip it, there's nothing there
	} else {
		buf[numbytes] = '\0'; // end it

		m_latencyPacket.id = ((t_jit_net_packet_latency *)buf)->id; // cast it to get the id
		m_latencyPacket.client_time_original = ((t_jit_net_packet_latency *)buf)->client_time_original;
		m_latencyPacket.server_time_before_data = ((t_jit_net_packet_latency *)buf)->server_time_before_data;
		m_latencyPacket.server_time_after_data = ((t_jit_net_packet_latency *)buf)->server_time_after_data;
		
		//printf("id: %d\n", (m_latencyPacket.id));
		//printf("client time original %f\n",m_latencyPacket.client_time_original);
		//printf("before Data %fl\n",m_latencyPacket.server_time_before_data);
		//printf("after Data %f\n",m_latencyPacket.server_time_after_data);
		//printf("diff=%f\n\n",m_latencyPacket.server_time_after_data - m_latencyPacket.server_time_before_data);
		
		if(lastSent >= m_latencyPacket.client_time_original) {
			printf("GTOE => last sent=%f and client_time_original=%f\n",lastSent,m_latencyPacket.client_time_original);	
		} else {
			printf("NNNWWW => last sent=%f and client_time_original=%f\n",lastSent,m_latencyPacket.client_time_original);	
		}
		
		
	}
}

