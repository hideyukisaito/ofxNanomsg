#include "ofxNanomsgRespondent.h"

ofxNanomsgRespondent::ofxNanomsgRespondent() : ofxNanomsgSocket(AF_SP, NN_RESPONDENT)
{
    
}

int ofxNanomsgRespondent::connect(string addr)
{
    return ofxNanomsgSocket::connect(addr);
}

int ofxNanomsgRespondent::send(const void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgRespondent::send(void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgRespondent::send(const string &data, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, nonblocking);
}

int ofxNanomsgRespondent::send(const ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, nonblocking);
}

bool ofxNanomsgRespondent::receive(string &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}

bool ofxNanomsgRespondent::receive(ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}