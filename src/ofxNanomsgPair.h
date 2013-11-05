#pragma once

#include "ofxNanomsgSocket.h"
#include "pair.h"

class ofxNanomsgPair : public ofxNanomsgSocket
{

public:

    ofxNanomsgPair();
    
    int bind(string addr);
    int connect(string addr);
    
    int send(const void *data, size_t len, bool nonblocking);
    int send(void *data, size_t len, bool nonblocking);
    int send(const string &data, bool nonblocking);
    
    bool receive(string &data, bool nonblocking);
};