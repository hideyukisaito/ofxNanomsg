#include "ofxNanomsgPush.h"

ofxNanomsgPush::ofxNanomsgPush() : ofxNanomsgSocket(AF_SP, NN_PUSH)
{
    
}

ofxNanomsgPush::~ofxNanomsgPush()
{
    ofxNanomsgSocket::shutdown();
}

int ofxNanomsgPush::connect(string addr)
{
    return ofxNanomsgSocket::connect(addr);
}

int ofxNanomsgPush::send(const void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgPush::send(void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgPush::send(const string &data, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, nonblocking);
}

int ofxNanomsgPush::send(const ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, nonblocking);
}