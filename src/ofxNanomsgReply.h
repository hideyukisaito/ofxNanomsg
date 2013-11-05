#pragma once

#include "ofxNanomsgSocket.h"
#include "reqrep.h"

class ofxNanomsgReply : public ofxNanomsgSocket
{
    
public:
    
    ofxNanomsgReply();
    
    int bind(string addr);
    
    bool receive(string &data, bool nonblocking);
};