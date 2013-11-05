#pragma once

#include "ofxNanomsgSocket.h"
#include "pubsub.h"

class ofxNanomsgPublisher : public ofxNanomsgSocket
{
    
public:
    
    ofxNanomsgPublisher();
    
    int bind(string addr);
    
    int send(const void *data, size_t len, bool nonblocking = false);
    int send(void *data, size_t len, bool nonblocking = false);
    int send(const string &data, bool nonblocking = false);
    int send(const ofBuffer &data, bool nonblocking = false);
    
    int send(const string &topic, const string &data, bool nonblocking = false);
    int send(const string &topic, const ofBuffer &data, bool nonblocking = false);
};