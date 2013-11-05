#include "ofxNanomsgPublisher.h"

ofxNanomsgPublisher::ofxNanomsgPublisher() : ofxNanomsgSocket(AF_SP, NN_PUB)
{
    
}

ofxNanomsgPublisher::~ofxNanomsgPublisher()
{
    
}

int ofxNanomsgPublisher::bind(string addr)
{
    return ofxNanomsgSocket::bind(addr);
}

int ofxNanomsgPublisher::send(const void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgPublisher::send(void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgPublisher::send(const string &data, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, nonblocking);
}

int ofxNanomsgPublisher::send(const ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, nonblocking);
}

int ofxNanomsgPublisher::send(const string &topic, const string &data, bool nonblocking)
{
    ofxNanomsgSocket::send(topic + " " + data, nonblocking);
}

int ofxNanomsgPublisher::send(const string &topic, const ofBuffer &data, bool nonblocking)
{
    ofxNanomsgSocket::send(topic + " " + data.getBinaryBuffer(), nonblocking);
}