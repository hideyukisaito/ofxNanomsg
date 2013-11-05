#include "ofxNanomsgPair.h"

ofxNanomsgPair::ofxNanomsgPair() : ofxNanomsgSocket(AF_SP, NN_PAIR)
{
    
}

ofxNanomsgPair::~ofxNanomsgPair()
{
    ofxNanomsgSocket::shutdown();
}

int ofxNanomsgPair::bind(string addr)
{
    return ofxNanomsgSocket::bind(addr);
}

int ofxNanomsgPair::connect(string addr)
{
    return ofxNanomsgSocket::connect(addr);
}

int ofxNanomsgPair::send(const void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgPair::send(void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgPair::send(const string &data, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, nonblocking);
}

int ofxNanomsgPair::send(const ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, nonblocking);
}

bool ofxNanomsgPair::receive(string &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}

bool ofxNanomsgPair::receive(ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}

bool ofxNanomsgPair::getNextMessage(string &data, bool nonblocking)
{
    return ofxNanomsgSocket::getNextMessage(data, nonblocking);
}

bool ofxNanomsgPair::getNextMessage(ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::getNextMessage(data, nonblocking);
}