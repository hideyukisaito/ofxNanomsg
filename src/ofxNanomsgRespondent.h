#pragma once

#include "ofxNanomsgSocket.h"
#include "survey.h"

class ofxNanomsgRespondent : public ofxNanomsgSocket
{
    
public:
    
    ofxNanomsgRespondent();
    ~ofxNanomsgRespondent();
    
    int connect(string addr);
    
    int send(const void *data, size_t len, bool nonblocking = false);
    int send(void *data, size_t len, bool nonblocking = false);
    int send(const string &data, bool nonblocking = false);
    int send(const ofBuffer &data, bool nonblocking = false);
    
    bool receive(string &data, bool nonblocking = false);
    bool receive(ofBuffer &data, bool nonblocking = false);
    
    bool getNextMessage(string &data, bool nonblocking = false);
	bool getNextMessage(ofBuffer &data, bool nonblocking = false);
};