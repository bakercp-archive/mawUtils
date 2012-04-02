//
//  BaseScene.cpp
//  emptyExample
//
//  Created by Christopher P. Baker on 6/5/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "BaseScene.h"

//--------------------------------------------------------------
BaseScene::BaseScene() {
    
    parent = NULL;
    title = "";
    subtitle = "";
    initialDelay = 0;
    startTime = -1;
    numLoops = 1;
    doLoop = false;
    currentLoop = 0;
    sceneComplete = false;
    allComplete = false;
    duration = 0;
    currentChildIndex = -1;
}

//--------------------------------------------------------------
BaseScene::~BaseScene() {
    for(int i = 0; i < children.size(); i++) {
        delete children[i];
    }
    children.clear();
}

//--------------------------------------------------------------
void BaseScene::setup() {}

//--------------------------------------------------------------
void BaseScene::update() {
    
    currentTime = ofGetElapsedTimeMillis();
    
    if(isComplete() && doLoop) {
        reset();
    }
    
    if(sceneComplete) {
        if(children.size() > 0) {
        
            if(currentChildIndex == -1) {
                nextScene();
            }
            
            BaseScene* bs = getCurrentChildScene();
            
            if(bs->isComplete()) {
                if(isCurrentChildSceneLast()) {
                    cout << "chilren of " << getTitle() << " all complete " << endl;
                    allComplete = true;
                } else {
                    nextScene();
                    getCurrentChildScene()->update();
                    //cout << "GETTINNG NEXT SCENE and updating :: " << getCurrentChildScene()->getTitle() << endl;
                }
            } else {
                //cout << "UPDATING CHILD SCENE : " << bs->getTitle() << endl;
                bs->update(); // update these children
            }
        } else {
            allComplete = true;
            // do nothing else
        }
    } else {
        
        //cout << "UPDATING LOCAL SCENE @ : " << getTitle() << endl;
        
        // do no updating of other stuff
    }

}

//--------------------------------------------------------------
void BaseScene::reset() {
    
    cout << "Resetting " << getTitle() << endl;
    
    currentLoop++;
    sceneComplete = false;
    allComplete = false;
    currentChildIndex = -1;

    for(int i = 0; i < children.size(); i++) {
        children[i]->reset();
    }
    
}
//--------------------------------------------------------------
void BaseScene::start() { 

    startTime = ofGetElapsedTimeMillis();
    cout << getTitle() << " was just started @ " << startTime << endl;
    
}
//--------------------------------------------------------------
void BaseScene::stop() { playing = false; }
//--------------------------------------------------------------
void BaseScene::play() { playing = true; }
//--------------------------------------------------------------

//--------------------------------------------------------------
bool BaseScene::isPlaying() { return playing;}
//--------------------------------------------------------------
bool BaseScene::isComplete() { 
    return sceneComplete && allComplete;
}


//--------------------------------------------------------------
void BaseScene::nextScene() {
    if(children.size() == 0) {
        ofLog(OF_LOG_WARNING, "ScenePlayer: No Scenes!");
        return;
    }    
    

    
    if(!isCurrentChildSceneLast()) {
        currentChildIndex = (currentChildIndex + 1) % children.size();
        getCurrentChildScene()->start();

    }

    /*
    children[currentChildIndex]->stop();
    
    if(doLoop) {
        currentChildIndex = (currentChildIndex + 1) % children.size();
    } else {
        currentChildIndex++;
        if(currentChildIndex >= children.size()) {
            complete = true;
        }
    }
     */
}

//--------------------------------------------------------------
int BaseScene::setNumLoops(int _numLoops) {numLoops = _numLoops;}
//--------------------------------------------------------------
int BaseScene::getNumLoops() {return numLoops;}
//--------------------------------------------------------------
void BaseScene::setLoop(bool _loop) {doLoop = _loop;};
//--------------------------------------------------------------
bool BaseScene::getLoop() {return doLoop;};

//--------------------------------------------------------------
int BaseScene::getCurrentLoop(){ return currentLoop; }


int BaseScene::getDuration() {
    return duration;
}

void BaseScene::setDuration(int _duration) {
    duration = _duration; 
}

//--------------------------------------------------------------
int BaseScene::getElapsedTime() { return ofGetElapsedTimeMillis() - startTime;};
//--------------------------------------------------------------
int BaseScene::getStartTime() {return startTime;};

//--------------------------------------------------------------
void BaseScene::setInitialDelay(int _initialDelay) { initialDelay = _initialDelay;}
//--------------------------------------------------------------
int BaseScene::getInitialDelay() { return initialDelay;}


//--------------------------------------------------------------
string BaseScene::getTitle() {return title;}
//--------------------------------------------------------------
void BaseScene::setTitle(string _title) {title = _title;}

//--------------------------------------------------------------
string BaseScene::getSubTitle() {return subtitle;}
//--------------------------------------------------------------
void BaseScene::setSubTitle(string _subtitle) {subtitle = _subtitle;}

//--------------------------------------------------------------
void BaseScene::setParentScene(BaseScene* _parent) {parent = _parent;}
//--------------------------------------------------------------
BaseScene* BaseScene::getParentScene() {return parent;}



//--------------------------------------------------------------
void BaseScene::addChildScene(BaseScene* _scene) {
    if(_scene->getParentScene() != NULL) {
        
        ofLog(OF_LOG_WARNING, "BaseScene:: Scene " + 
                                _scene->getTitle() + 
                                " already had it's parent set to " + 
                                _scene->getParentScene()->getTitle());
         
    }
    _scene->setParentScene(this); // auto set the parent
    children.push_back(_scene);
}

//--------------------------------------------------------------
bool BaseScene::removeChildScene(BaseScene* _scene) {
    
    vector<BaseScene*>::iterator it;
    it = find (children.begin(), children.end(), _scene);
    if(it != children.end()) {
        children.erase(it);
        return true;
    } else {
        return false;
    }
}


//--------------------------------------------------------------
BaseScene* BaseScene::getCurrentChildScene() { 
    return getChildScene(currentChildIndex);
}

//--------------------------------------------------------------
BaseScene* BaseScene::getChildScene(int i) { 
    if(children.size() == 0 && i < children.size() ) {
        ofLog(OF_LOG_WARNING, "ScenePlayer:: No Scenes OR INDEX OUT OF BOUNDS!");
        return NULL;
    }    
    
    return children[currentChildIndex];
}

//--------------------------------------------------------------
int BaseScene::getNumChildScenes() { return children.size();}
//--------------------------------------------------------------
int BaseScene::getCurrentChildSceneIndex() { return currentChildIndex;}

//--------------------------------------------------------------
bool BaseScene::isCurrentChildSceneLast() {
    if(currentChildIndex == -1) return false;
    
    return (children.size() == 0 || currentChildIndex == (children.size() -1 ));
}


