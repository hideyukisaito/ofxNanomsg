#pragma once

#include "ofxNanomsgSocket.h"
#include "survey.h"

class ofxNanomsgRespondent : public ofxNanomsgSocket
{
    
public:
    
    ofxNanomsgRespondent();
    
    int connect(string addr);
    
    int send(const void *data, size_t len, bool nonblocking);
    int send(void *data, size_t len, bool nonblocking);
    int send(const string &data, bool nonblocking);
    
    bool receive(string &data, bool nonblocking);
};