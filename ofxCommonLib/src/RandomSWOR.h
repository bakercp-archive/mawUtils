

//  RandomSWR.h
//
//  Random SampleWithoutReplacent
//
//  the fisher yates shuffle
//  
//
//  Created by Christopher P. Baker on 3/21/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "ofMain.h"

class RandomSWOR {
    
public: 
    RandomSWOR(int n, float* _weights = NULL, bool percentWeights = false) {
        if(n == 0) {
            ofLog(OF_LOG_FATAL_ERROR, "RandomSWOR: Started with 0 elements");
            exit(0);
        }
        init(n, _weights, percentWeights);
    }
    
    ~RandomSWOR() {
        delete[] vals;
        delete[] weights;
    }
        
    int next() {
		if (counter==length) { // we have no more to choose from
            counter = 0;  // reset the counter
            shuffle(vals, length);        
			return next();
		} else {
			return vals[counter++];
		}
    }
    
    int size() {return length;}
    
protected:
    
    
    
    void init(int n, float* _weights, bool percentWeights) {
        
        if(_weights == NULL) {
            length = n;
            vals = new int[length];
            for(int i = 0; i < length; i++) vals[i] = i; // init them ... w/out weight
        } else {

            float total = 0;
            weights = new float[n];
            for(int i = 0; i < n; i++) {
                weights[i] = _weights[i]; // copy it while we're at it, just in case we need it later
                total += weights[i];
            }
            
            if(percentWeights) {
                assert(total == 1.0);   
                length = n*100;
            } else {
                length = (int) total;
            }
            
            // allocate our values
            vals = new int[length];

            int valsI = 0;
            
            if(percentWeights) {
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < weights[i]*100; j++, valsI++) {
                        vals[valsI] = i;
                    }
                }
            } else {
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < weights[i]; j++, valsI++) {
                        vals[valsI] = i;
                    }
                }
            }
            
        }
        
        counter = 0;        
        shuffle(vals, length);        
    }
    
    //http://stackoverflow.com/questions/3343797/is-this-c-implementation-of-fisher-yates-shuffle-correct
    static int rand_int(int n) {
        int limit = RAND_MAX - RAND_MAX % n;
        int rnd;
        
        do {
            rnd = rand();
        } while (rnd >= limit);
        return rnd % n;
    }
    
    void shuffle(int *array, int n) {
        int i, j, tmp;
        
        for (i = n - 1; i > 0; i--) {
            j = rand_int(i + 1);
            tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
        }
    }

    
    
    int counter;
    int length;
    int* vals;
    float* weights;
    
};