/*
 *  LimitablePoint.h
 *  livedraw
 *
 *  Created by Christopher P. Baker on 3/6/11.
 *  Copyright 2011 Murmur Labs LLC. All rights reserved.
 *
 */

#pragma once

#include "ofTypes.h"

class ofxLimitedPoint : public ofPoint {
	
    // Good to know!!
    // http://stackoverflow.com/questions/2528039/why-is-flt-min-equal-to-zero/2528046#2528046
	
public:
	
	ofxLimitedPoint( const ofPoint & pnt)
		: ofPoint(pnt) {

		minLimit.set(-FLT_MAX,-FLT_MAX,-FLT_MAX);
		maxLimit.set(FLT_MAX,FLT_MAX,FLT_MAX);

    }
	
	ofxLimitedPoint(float _x=0.0f, float _y=0.0f, float _z=0.0f)
		: ofPoint(_x,_y,_z) {

		minLimit.set(-FLT_MAX,-FLT_MAX,-FLT_MAX);
		maxLimit.set(FLT_MAX,FLT_MAX,FLT_MAX);
			
	};
	 
	~ofxLimitedPoint() {}
	
			
	ofPoint getLimitedPoint() {
		return ofPoint(getLimitedX(), getLimitedY(), getLimitedZ());
	};
	
	float getLimitedX() {return ofClamp(x,minLimit.x,maxLimit.x);}
	float getLimitedY() {return ofClamp(y,minLimit.y,maxLimit.y);}
	float getLimitedZ() {return ofClamp(z,minLimit.z,maxLimit.z);}

	void setMinLimits(ofPoint _minLimit) {minLimit = _minLimit; onLimitChange();};
	void setMaxLimits(ofPoint _maxLimit) {maxLimit = _maxLimit; onLimitChange();};

	void setMinX(float x) {minLimit.x = x; onLimitChange();};
	void setMaxX(float x) {maxLimit.x = x; onLimitChange();};

	void setMinY(float y) {minLimit.y = y; onLimitChange();};
	void setMaxY(float y) {maxLimit.y = y; onLimitChange();};

	void setMinZ(float z) {minLimit.z = z; onLimitChange();};
	void setMaxZ(float z) {maxLimit.z = z; onLimitChange();};

	void clearMaxLimits() { maxLimit.set(FLT_MAX,FLT_MAX,FLT_MAX); onLimitChange();}
	void clearMinLimits() { minLimit.set(-FLT_MAX,-FLT_MAX,-FLT_MAX); onLimitChange();}
	
	void onLimitChange() { /* nothing here now */}

    void incrementX() {
        x++;
    }
    
    void decrementX() {
        x--;
    }
    
    void incrementY() {
        y++;
    }
    
    void decrementY() {
        y--;
    }
    
    void incrementZ() {
        z++;
    }
    
    void decrementZ() {
        z--;
    }
    
	
//private:
	
	ofPoint minLimit;
	ofPoint maxLimit;
		
		
};

