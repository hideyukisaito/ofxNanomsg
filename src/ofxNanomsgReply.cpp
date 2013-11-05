#include "ofxNanomsgReply.h"

ofxNanomsgReply::ofxNanomsgReply() : ofxNanomsgSocket(AF_SP, NN_REP)
{
    
}

int ofxNanomsgReply::bind(string addr)
{
    return ofxNanomsgSocket::bind(addr);
}

bool ofxNanomsgReply::receive(string &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}

bool ofxNanomsgReply::receive(ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}