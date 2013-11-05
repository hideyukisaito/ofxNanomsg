#pragma once

#include "ofxNanomsgSocket.h"
#include "pubsub.h"

class ofxNanomsgSubscriber : public ofxNanomsgSocket
{
    
public:
    
    ofxNanomsgSubscriber();
    
    int connect(string addr);
    
    bool receive(string &data, bool nonblocking = false);
    bool receive(ofBuffer &data, bool nonblocking = false);
    
    void subscribe(string topic);
    void unsubscribe(string topic);
    
protected:

    void setSocketOptions(int level, int option, const void *optval, size_t optvallen);
};