#include "ofxNanomsgPull.h"

ofxNanomsgPull::ofxNanomsgPull() : ofxNanomsgSocket(AF_SP, NN_PULL)
{
    
}

int ofxNanomsgPull::bind(string addr)
{
    return ofxNanomsgSocket::bind(addr);
    
}

bool ofxNanomsgPull::receive(string &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}

bool ofxNanomsgPull::receive(ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}