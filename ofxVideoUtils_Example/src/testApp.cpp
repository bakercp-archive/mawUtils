#include "testApp.h"


testApp::~testApp() {
    // deleting
    for(int i = 0; i < buffers.size(); i++) {
        delete buffers[i];
    }
}

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(255,255,255);
	ofSetFrameRate(30);
	
    // video setup
    camWidth 		= 320;	// try to grab at this size. 
	camHeight 		= 240;
	
	//vidGrabber.videoSettings();
	vidGrabber.listDevices();
    
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(camWidth,camHeight);
	//interp.reset(ofPoint(100, ofGetHeight()/2), ofPoint(ofGetWidth()-100, ofGetHeight()/2));	
    
    int fps = 30;
    
    currentBuffer = -1;
    makeBuffer(ofGetWidth()/2,ofGetHeight()/2);
    
    
    currentSource = 0;
    
    cam.execute("http://148.61.142.228/axis-cgi/mjpg/video.cgi?resolution="+ ofToString(camWidth) + "x" + ofToString(camHeight),camWidth,camHeight);
	videoTexture0.allocate(camWidth,camHeight, GL_RGBA) ;//GL_RGBA);

    
	//interp.insert(ofPoint(ofGetWidth()/2,0));//ofGetHeight()/2));
	
	
    //	frameByframe = false;

	/*
	fingerMovie.loadMovie("movies/fingers.mov");
	fingerMovie.play();
	 */
}

//--------------------------------------------------------------
void testApp::update() {
    
   // fingerMovie.idleMovie();
    
    if(true) {//cam0.isNewFrame()) {
		unsigned char * pixels = cam.getPixels();
		if (pixels != NULL){
			videoTexture0.loadData(pixels, camWidth, camHeight, GL_BGR);
		}
	}

    
    vidGrabber.grabFrame();
	
    
    
    if(currentSource == 0) {
        if (vidGrabber.isFrameNew()){
            buffers[currentBuffer]->add(vidGrabber.getPixels(), camWidth,camHeight, OF_IMAGE_COLOR);
        }

    } else {
        unsigned char * pixels = cam.getPixels();
		if (pixels != NULL){
            buffers[currentBuffer]->add(pixels, camWidth,camHeight, OF_IMAGE_COLOR);
		}

    }
    
    
    
    
    
    
    for(int i = 0; i < buffers.size(); i++) {
        buffers[i]->update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackground(0,0,0);
    
	ofSetColor(255,255,255,255);
    vidGrabber.draw(20,20,160,120);
    ofDrawBitmapString("LIVE GRABBER", 20,20);


    videoTexture0.draw(20, 140, 160,120);
    ofDrawBitmapString("LIVE WEB", 20,140);

    
    
    for(int i = 0; i < buffers.size(); i++) {
        ofPushMatrix();
        
        ofPoint pos = xform[i].getPosition();
        ofPoint scl = xform[i].getScale();
        ofPoint ap = xform[i].getAnchorPoint();
        ofPoint rot = xform[i].getRotation();
        
        ofTranslate(pos.x,pos.y);//,pos.z);
        ofScale(scl.x,scl.y,scl.z);
        ofRotateX(rot.x);
        ofRotateY(rot.y);
        ofRotateZ(rot.z);
        
      //  cout << "x/y=" << pos.x << "/" << pos.y << endl;
        
        if( i == currentBuffer) {
            ofSetColor(255,0,0);
            ofNoFill();
            ofRect(-buffers[i]->getWidth()/2-1,-buffers[i]->getHeight()/2-1, 323,242);
        }
       
        
        ofFill();
        ofSetColor(255,255,255,xform[i].opacity*255);
        buffers[i]->draw(-buffers[i]->getWidth()/2,-buffers[i]->getHeight()/2);//ap.x,ap.y);

        ofPopMatrix();
    }
   
    
    ofSetColor(255,255,255,200);
    ofNoFill();
    ofRect(10,ofGetHeight()-300, 400, 400);

    string stats = "Current Video " + ofToString(currentBuffer);
    stats+="\n";
    stats+="\n";

    stats+= ("#FramesInBuffer=" + ofToString(buffers[currentBuffer]->getNumBufferedFrames()));
    stats+= (" Frame=" + ofToString(buffers[currentBuffer]->getPosition()));
    stats+="\n";
    stats+=("LoopPoints [qwer]=" + ofToString(buffers[currentBuffer]->getLoopPointsStart()) + "/" + ofToString(buffers[currentBuffer]->getLoopPointsEnd()));
    stats+="\n";
    
    int xx = xform[currentBuffer].getPosition().x;
    int yy = xform[currentBuffer].getPosition().y;
    int zz = xform[currentBuffer].getPosition().z;

    stats+=("pos=[" + ofToString(xx) + "," +ofToString(yy) + "," + ofToString(zz) + "]"); 
    stats+="\n";

    int xxR = xform[currentBuffer].getRotation().x;
    int yyR = xform[currentBuffer].getRotation().y;
    int zzR = xform[currentBuffer].getRotation().z;
    
    stats+=("rot=[" + ofToString(xxR) + "," +ofToString(yyR) + "," + ofToString(zzR) + "]"); 
    stats+="\n";

    float xxS = xform[currentBuffer].getScale().x;
    float yyS = xform[currentBuffer].getScale().y;
    float zzS = xform[currentBuffer].getScale().z;
    
    stats+=("scl=[" + ofToString(xxS) + "," +ofToString(yyS) + "," + ofToString(zzS) + "]"); 
    stats+="\n";
    
    stats+=("opacity=[" + ofToString(xform[currentBuffer].getOpacity()) + "]"); 
    stats+="\n";
    
    stats+="MORE KEYS:\n";
    stats+="xlate=[drag], scale=[drag+!], \n";
    stats+="rotate=[drag+@], [drag+#],[drag+$]\n";
    stats+="Opacity=[o,O]\n";
    stats+="New Video=[click+n]\n";
    stats+="  select video [< and >]\n";
   
    stats+="TO RE-RECORD a BUFFER: R then SPACEBAR\n";
    stats+="To set loop points: start+ [q], start- [w], \n                    end+[e], end-[r]\n";
    
    stats+="LOOP: NONE [0], LOOP [1], PALINDROME[2]\n";
    stats+="SPEED+ (MOUSE RIGHT), SPEED- (MOUSE LEFT)\n";
    stats+="SWITCH ACTIVE SOURCE= ' (apostrophe)\n";

    
    ofDrawBitmapString(stats, 10, ofGetHeight() - 290);
    
    
    
    /*
    if(buffer->peek(20)) {
        ofTexture* t = buffer->peek(0);
        t->draw(360,20);
    }
    */

	//ofSetColor(0,0,0);
	//interp.draw();
	
	//ofPoint o = interp.returnPoint(ofPoint(mouseX,mouseY));

    
    
    
	
/*

    fingerMovie.draw(20,20);
    ofSetColor(0x000000);
    unsigned char * pixels = fingerMovie.getPixels();
    // let's move through the "RGB" char array
    // using the red pixel to control the size of a circle.
    for (int i = 4; i < 320; i+=8){
        for (int j = 4; j < 240; j+=8){
            unsigned char r = pixels[(j * 320 + i)*3];
            float val = 1 - ((float)r / 255.0f);
            ofCircle(400 + i,20+j,10*val);
        }
    }


    ofSetColor(0x000000);
	ofDrawBitmapString("press f to change",20,320);
    if(frameByframe) ofSetColor(0xCCCCCC);
    ofDrawBitmapString("mouse speed position",20,340);
    if(!frameByframe) ofSetColor(0xCCCCCC); else ofSetColor(0x000000);
    ofDrawBitmapString("keys <- -> frame by frame " ,190,340);
    ofSetColor(0x000000);

    ofDrawBitmapString("frame: " + ofToString(fingerMovie.getCurrentFrame()) + "/"+ofToString(fingerMovie.getTotalNumFrames()),20,380);
    ofDrawBitmapString("duration: " + ofToString(fingerMovie.getPosition()*fingerMovie.getDuration(),2) + "/"+ofToString(fingerMovie.getDuration(),2),20,400);
    ofDrawBitmapString("speed: " + ofToString(fingerMovie.getSpeed(),2),20,420);

    if(fingerMovie.getIsMovieDone()){
        ofSetColor(0xFF0000);
        ofDrawBitmapString("end of movie",20,440);
    }
 */
}



//--------------------------------------------------------------
void testApp::keyPressed  (int key){
   
	if(key == '!' || key == '@' || key == '#' || key == '$') {
        thisKey = key;
        return;
    } 
    
    if(key == 'o') {
        float o = xform[currentBuffer].getOpacity();
        xform[currentBuffer].setOpacity(CLAMP(o+0.1,0,1));
        return;
    } else if(key == 'O') {
        float o = xform[currentBuffer].getOpacity();
        xform[currentBuffer].setOpacity(CLAMP(o-0.1,0,1));
        return;
    }
    
    if(key == '\'') {
        currentSource ^= 1;
    }
    
    if (key == 's' || key == 'S'){
		vidGrabber.videoSettings();
	}
    if(key == 'Q') {
        int i = 120;
        buffers[currentBuffer]->resize(i);
        return;
    }
    
    if(key == 'q') {
        int r = 10;
        buffers[currentBuffer]->resize(r);
        return;
    }


    if(key == ' ') {
        buffers[currentBuffer]->setBufferMode(VB_BUFFERING);
    }
    
    if(key == 'p') {
        buffers[currentBuffer]->setBufferMode(VB_PASSTHROUGH);
    }

    
    if(key == 'R') {
        buffers[currentBuffer]->clear();
    }
    
    if(key == '1') {
        buffers[currentBuffer]->setLoopState(OF_LOOP_NONE);
    } else if(key == '2') {
        buffers[currentBuffer]->setLoopState(OF_LOOP_NORMAL);
    } else if(key == '3') {
        buffers[currentBuffer]->setLoopState(OF_LOOP_PALINDROME);
    }
    
    if(key == 'q') {
        buffers[currentBuffer]->setLoopPointsStart( buffers[currentBuffer]->getLoopPointsStart()-1 );
    } else if(key == 'w') {
        buffers[currentBuffer]->setLoopPointsStart( buffers[currentBuffer]->getLoopPointsStart()+1 );
    } else if(key == 'e') {
        buffers[currentBuffer]->setLoopPointsEnd( buffers[currentBuffer]->getLoopPointsEnd()-1 );
    } else if(key == 'r') {
        buffers[currentBuffer]->setLoopPointsEnd( buffers[currentBuffer]->getLoopPointsEnd()+1 );
    }
    
    

    
    if(key == 'n') {
        makeBuffer(mouseX,mouseY);
    }
    
    
    if(key == '<') {
        currentBuffer = MAX(0, currentBuffer-1);
    } else if(key == '>') {
        currentBuffer = (currentBuffer + 1) % buffers.size();
    }
    
    
/*
	switch(key){
        case 'f':
            frameByframe=!frameByframe;
            fingerMovie.setPaused(frameByframe);
        break;
        case OF_KEY_LEFT:
            fingerMovie.previousFrame();
        break;
        case OF_KEY_RIGHT:
            fingerMovie.nextFrame();
        break;
        case '0':
            fingerMovie.firstFrame();
        break;
    }
	*/
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	if(key == '!' || key == '@' || key == '#' || key == '$') {
        thisKey = -1;
        return;
    } 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
    int width = ofGetWidth();
    float pct = (float)x / (float)width;
    float speed = pct * 20;
    buffers[currentBuffer]->setSpeed(speed);
    
    /*
	if(!frameByframe){
        int width = ofGetWidth();
        float pct = (float)x / (float)width;
        float speed = (2 * pct - 1) * 5.0f;
        fingerMovie.setSpeed(speed);
	}
	 */
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
//    cout << "-1. x/y=" << x << "/" << y << endl;
//    cout << "0. x/y=" << xform[currentBuffer].getPosition().x << "/" << xform[currentBuffer].getPosition().y << endl;
    
    
    int xx = xform[currentBuffer].getPosition().x;
    int yy = xform[currentBuffer].getPosition().y;
    int zz = xform[currentBuffer].getPosition().z;
    float d = ofDist(x,y,xx,yy);
    
    if(thisKey == '!') {
        float s = ofMap(d, 0, 500, .1, 10, true);
        xform[currentBuffer].setScale(ofPoint(s,s,s));
    } else if(thisKey == '@') {
        float s = ofMap(d, 0, 500, 0, 600, true);
        xform[currentBuffer].setRotationX(s);
    } else if(thisKey == '#') {
        float s = ofMap(d, 0, 500, 0, 600, true);
        xform[currentBuffer].setRotationY(s);
    } else if(thisKey == '$') {
        float s = ofMap(d, 0, 500, 0, 600, true);
        xform[currentBuffer].setRotationZ(s);
    } else {
        xform[currentBuffer].setPositionX(x);
        xform[currentBuffer].setPositionY(y);
    }
    
    
    
    

//    cout << "1. x/y=" << xform[currentBuffer].getPosition().x << "/" << xform[currentBuffer].getPosition().y << endl;

    
    /*
	if(!frameByframe){
        int width = ofGetWidth();
        float pct = (float)x / (float)width;
        fingerMovie.setPosition(pct);
	}
	 */
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	
	//interp.insert(ofPoint(x,y));
	
	/*
	if(!frameByframe){
        fingerMovie.setPaused(true);
	}
	 */
}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	/*
	if(!frameByframe){
        fingerMovie.setPaused(false);
	}
	 */
}

//--------------------------------------------------------------
void testApp::resized(int w, int h){

}
