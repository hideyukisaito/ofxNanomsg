#include "ofxNanomsgBus.h"


ofxNanomsgBus::ofxNanomsgBus() : ofxNanomsgSocket(AF_SP, NN_BUS)
{
    
}

ofxNanomsgBus::~ofxNanomsgBus()
{
    ofxNanomsgSocket::shutdown();
}

int ofxNanomsgBus::bind(string addr)
{
    return ofxNanomsgSocket::bind(addr);
}

int ofxNanomsgBus::connect(string addr)
{
    return ofxNanomsgSocket::connect(addr);
}

void ofxNanomsgBus::connect(vector<string> addrs)
{
    for (int i = 0; i < addrs.size(); ++i)
    {
        ofxNanomsgSocket::connect(addrs[i]);
    }
}

int ofxNanomsgBus::send(const void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgBus::send(void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgBus::send(const string &data, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, nonblocking);
}

int ofxNanomsgBus::send(const ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, nonblocking);
}

bool ofxNanomsgBus::receive(string &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}

bool ofxNanomsgBus::receive(ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}

bool ofxNanomsgBus::getNextMessage(string &data, bool nonblocking)
{
    return ofxNanomsgSocket::getNextMessage(data, nonblocking);
}

bool ofxNanomsgBus::getNextMessage(ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::getNextMessage(data, nonblocking);
}