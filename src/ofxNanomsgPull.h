#pragma once

#include "ofxNanomsgSocket.h"
#include "pipeline.h"

class ofxNanomsgPull : public ofxNanomsgSocket
{
    
public:
    
    ofxNanomsgPull();
    
    int bind(string addr);
    
    bool receive(string &data, bool nonblocking = false);
    bool receive(ofBuffer &data, bool nonblocking = false);
    
    bool getNextMessage(string &data, bool nonblocking = false);
	bool getNextMessage(ofBuffer &data, bool nonblocking = false);
};