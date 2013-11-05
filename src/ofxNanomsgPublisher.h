#pragma once

#include "ofxNanomsgSocket.h"
#include "pubsub.h"

class ofxNanomsgPublisher : public ofxNanomsgSocket
{
    
public:
    
    ofxNanomsgPublisher();
    ~ofxNanomsgPublisher();
    
    int bind(string addr);
    
    int send(const void *data, size_t len, bool nonblocking);
    int send(void *data, size_t len, bool nonblocking);
    int send(const string &data, bool nonblocking);
    int send(const string &topic, const string &data, bool nonblocking);
};