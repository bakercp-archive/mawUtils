//
//  GenenricScenePlayer.h
//  
//
//  Created by Christopher P. Baker on 6/6/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "BaseScene.h"

class GenericScenePlayer : public BaseScene {
public:
    
    GenericScenePlayer() : BaseScene() {
        sceneComplete = true; // automatically jump to the children
        doLoop = true;
    }
    
    void update() {
        BaseScene::update();
        sceneComplete = true;
        
    }
    
};