//
//  BaseScene.h
//  
//
//  Created by Christopher P. Baker on 6/5/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "ofMain.h"

class BaseScene {
public:
    
    BaseScene();
    virtual ~BaseScene();
    
    // virtual functions
    // all must be implemented!
    virtual void setup();
    virtual void update();
    
    virtual void reset();
    virtual void start();
    virtual void stop();
    virtual void play();

    bool isPlaying();
    
    virtual bool isComplete();
    
    void nextScene();
    
    
    int setNumLoops(int _numLoops);
    int getNumLoops();
    void setLoop(bool _loop);
    bool getLoop();

    int getCurrentLoop();// { return currentLoop; }

    int getDuration();
    void setDuration(int _duration);
    
    int getElapsedTime();
    int getStartTime();
    
    void setInitialDelay(int _initialDelay);// { initialDelay = _initialDelay;}
    int getInitialDelay();
    
    string getTitle();
    void setTitle(string _title);
    
    string getSubTitle();
    void setSubTitle(string _subtitle);// {subtitle = _subtitle;}
    
    // parent scene
    void setParentScene(BaseScene* scene);// { parent = scene;}
    BaseScene* getParentScene();
    
    // child scenes
    void addChildScene(BaseScene* _scene);
    bool removeChildScene(BaseScene* _scene);

    BaseScene* getCurrentChildScene();
    BaseScene* getChildScene(int i);
    
    int getNumChildScenes();
    int getCurrentChildSceneIndex();

    bool isCurrentChildSceneLast();
    
protected:
    // this scene
    BaseScene* parent;
    int currentTime;
    int initialDelay;
    int startTime;
    int duration;
    
    bool doLoop;
    int  numLoops; // how many times will this loop?
    int  currentLoop; // what loop are we on?
    bool sceneComplete; // is this scene (and all children) completed?
    
    bool playing;
    
    string title;
    string subtitle;
        
    
    // child scenes
    vector<BaseScene*> children;
    int currentChildIndex;
    
    bool allComplete;
};
