#include "ofxNanomsgSubscriber.h"

ofxNanomsgSubscriber::ofxNanomsgSubscriber() : ofxNanomsgSocket(AF_SP, NN_SUB)
{
    
}

int ofxNanomsgSubscriber::connect(string addr)
{
    return ofxNanomsgSocket::connect(addr);
}

bool ofxNanomsgSubscriber::receive(string &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}

bool ofxNanomsgSubscriber::receive(ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::receive(data, nonblocking);
}

void ofxNanomsgSubscriber::subscribe(string topic)
{
    ofxNanomsgSocket::setSocketOptions(NN_SUB, NN_SUB_SUBSCRIBE, topic.data(), topic.size());
}

void ofxNanomsgSubscriber::unsubscribe(string topic)
{
    setSocketOptions(NN_SUB, NN_SUB_UNSUBSCRIBE, topic.data(), topic.size());
}

void ofxNanomsgSubscriber::setSocketOptions(int level, int option, const void *optval, size_t optvallen)
{
    ofxNanomsgSocket::setSocketOptions(level, option, optval, optvallen);
}