#include "ofxNanomsgReply.h"

ofxNanomsgReply::ofxNanomsgReply() : ofxNanomsgSocket(AF_SP, NN_REP)
{
    
}

int ofxNanomsgReply::bind(string addr)
{
    return ofxNanomsgSocket::bind(addr);
}

int ofxNanomsgReply::send(const void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgReply::send(void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgReply::send(const string &data, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, nonblocking);
}

int ofxNanomsgReply::send(const ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, nonblocking);
}

bool ofxNanomsgReply::receive(string &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}

bool ofxNanomsgReply::receive(ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}

bool ofxNanomsgReply::getNextMessage(string &data, bool nonblocking)
{
    return ofxNanomsgSocket::getNextMessage(data, nonblocking);
}

bool ofxNanomsgReply::getNextMessage(ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::getNextMessage(data, nonblocking);
}