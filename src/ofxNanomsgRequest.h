#pragma once

#include "ofxNanomsgSocket.h"
#include "reqrep.h"

class ofxNanomsgRepuest : public ofxNanomsgSocket
{
    
public:
    
    ofxNanomsgRepuest();
    
    int connect(string addr);
    
    int send(const void *data, size_t len, bool nonblocking);
    int send(void *data, size_t len, bool nonblocking);
    int send(const string &data, bool nonblocking);
    
    void setResendInterval(int millis);
};