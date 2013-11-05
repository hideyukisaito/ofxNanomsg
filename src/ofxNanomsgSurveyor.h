#pragma once

#include "ofxNanomsgSocket.h"
#include "survey.h"

class ofxNanomsgSurveyor : public ofxNanomsgSocket
{

public:

    ofxNanomsgSurveyor();
    
    int bind(string addr);
    
    int send(const void *data, size_t len, bool nonblocking);
    int send(void *data, size_t len, bool nonblocking);
    int send(const string &data, bool nonblocking);
    
    bool receive(string &data, bool nonblocking);
    
    void setTimeout(int millis);
};