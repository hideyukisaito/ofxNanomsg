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

bool ofxNanomsgSubscriber::getNextMessage(string &data, bool nonblocking)
{
    return ofxNanomsgSocket::getNextMessage(data, nonblocking);
}

bool ofxNanomsgSubscriber::getNextMessage(ofBuffer &data, bool nonblocking)
{
    return ofxNanomsgSocket::getNextMessage(data, nonblocking);
}

void ofxNanomsgSubscriber::subscribe(string topic)
{
    ofxNanomsgSocket::setSocketOption(NN_SUB, NN_SUB_SUBSCRIBE, topic.data(), topic.size());
}

void ofxNanomsgSubscriber::unsubscribe(string topic)
{
    ofxNanomsgSocket::setSocketOption(NN_SUB, NN_SUB_UNSUBSCRIBE, topic.data(), topic.size());
}