#pragma once

#include "ofxNanomsgSocket.h"
#include "bus.h"


class ofxNanomsgBus : public ofxNanomsgSocket
{

public:

    ofxNanomsgBus();
    
    int bind(string addr);
    int connect(string addr);
    void connect(vector<string> addrs);
    
    int send(const void *data, size_t len, bool nonblocking);
    int send(void *data, size_t len, bool nonblocking);
    int send(const string &data, bool nonblocking);
    
    bool receive(string &data, bool nonblocking);
};