//
//  ofxIpVideoGrabber.h
//
//  Created by Christopher P. Baker on 4/24/11.
//  Copyright 2011 Murmur Labs LLC. All rights reserved.
//

#pragma once

#include "ofMain.h"

#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPStreamFactory.h"
#include "Poco/Net/HTTPBasicCredentials.h"
#include "Poco/Net/MessageHeader.h"
#include "Poco/Net/NetException.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/StreamCopier.h"
#include "Poco/Path.h"
#include "Poco/URI.h"
#include "Poco/Exception.h"

#include "Poco/Net/NameValueCollection.h"

#include "Poco/StreamTokenizer.h"
#include "Poco/Token.h"

#include <iostream>

using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPStreamFactory;
using Poco::Net::HTTPBasicCredentials;
using Poco::Net::MessageHeader;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::Net::NameValueCollection;
using Poco::Net::NoMessageException;
using Poco::StreamCopier;
using Poco::Path;
using Poco::URI;
using Poco::Exception;

using Poco::StreamTokenizer;
using Poco::Token;
using Poco::trim;
using Poco::trimRightInPlace;

using Poco::icompare;


class ofxIpVideoGrabber : protected ofBaseVideo, protected ofThread {
    
public:
    
    
    ofxIpVideoGrabber();
    virtual ~ofxIpVideoGrabber();
    
    void connect();
    void disconnect();
    void waitForDisconnect();

    // ofBaseVideo
	bool isFrameNew();
	void close();

    // ofBaseHasPixels
	unsigned char * getPixels();
	ofPixelsRef getPixelsRef();
    float getWidth();
    float getHeight();
    
    ofImage getImage();
    
    // ofBaseUpdates
    void update();

    void update(ofEventArgs & a);
    void exit(ofEventArgs & a);
    
    void draw(int x, int y);
    void draw(int x, int y, int width, int height);
    
    float getFps();
    float getBps();
    
    
    // set video URI
    void setURI(string uri);
    void setURI(URI uri);

    string getURI();
    
    // basic authentication
    void setUsername(string username);
    void setPassword(string password);
    
    string getUsername();
    string getPassword();
    
    
    // proxy server
    void setProxyUsername(string username);
    void setProxyPassword(string password);
    void setProxyHost(string host);
    void setProxyPort(int port);

    string getProxyUsername();
    string getProxyPassword();
    string getProxyHost();
    int    getProxyPort();
    
    HTTPClientSession* getSession();
    
    bool isConnected();
    
    ofEvent<ofResizeEventArgs> 	videoResized;
    
protected:
    
    void threadedFunction(); // connect to server
    void imageResized(int width, int height);
    void resetStats();
    
private: 

    
    int ci; // current image index
    ofImage image[2]; // image buffer.  this flips
    bool isNewFrameLoaded;       // is there a new frame ready to be uploaded to glspace
    
    unsigned long t0; // init time
    unsigned long elapsedTime;
    
    unsigned long nBytes;
    unsigned long lastByteTime;
    float bps; // bytes / second
    
    unsigned long nFrames;
    unsigned lastFrameTime;
    float fps; // frames / second
    
    URI     uri;
    HTTPBasicCredentials credentials;
    
    bool connected;
    
    HTTPClientSession session;
    
};
