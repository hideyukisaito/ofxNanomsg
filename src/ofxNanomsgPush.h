#pragma once

#include "ofxNanomsgSocket.h"
#include "pipeline.h"

class ofxNanomsgPush : public ofxNanomsgSocket
{
    
public:
    
    ofxNanomsgPush();
    
    int connect(string addr);
    
    int send(const void *data, size_t len, bool nonblocking);
    int send(void *data, size_t len, bool nonblocking);
    int send(const string &data, bool nonblocking);
};