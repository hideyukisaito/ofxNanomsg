#include "ofxNanomsgRequest.h"

ofxNanomsgRepuest::ofxNanomsgRepuest() : ofxNanomsgSocket(AF_SP, NN_REQ)
{
    
}

int ofxNanomsgRepuest::connect(string addr)
{
    return ofxNanomsgSocket::connect(addr);
}

int ofxNanomsgRepuest::send(const void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgRepuest::send(void *data, size_t len, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, len, nonblocking);
}

int ofxNanomsgRepuest::send(const string &data, bool nonblocking)
{
    return ofxNanomsgSocket::send(data, nonblocking);
}

void ofxNanomsgRepuest::setResendInterval(int millis)
{
    ofxNanomsgSocket::setSocketOptions(NN_REQ, NN_REQ_RESEND_IVL, &millis, sizeof(millis));
}