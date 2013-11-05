#pragma once

#include "ofMain.h"
#include "nn.hpp"

class ofxNanomsgSocket
{
    
public:
    
    ofxNanomsgSocket & operator=(const ofxNanomsgSocket& mom);
    ~ofxNanomsgSocket();
    
    bool shutdown();
    
    bool isConnected();
    
    void setLinger(int millis, int socklevel = NN_SOL_SOCKET);
    void setReconnectionInterval(int millis, int socklevel = NN_SOL_SOCKET);
    void setMaxReconnectionInterval(int millis, int socklevel = NN_SOL_SOCKET);
    void setUseIPV6(bool value, int socklevel = NN_SOL_SOCKET);
    
protected:
    
    nn::socket socket;
    int eid;
    
    ofxNanomsgSocket(int domain, int protocol);
    
    int bind(string addr);
    int connect(string addr);
    
    void setSocketOption(int level, int option, const void *optval, size_t optvallen);
    void getSocketOption(int level, int option, void *optval, size_t *optvallen);
    
    int send(const void *data, size_t len, bool nonblocking);
    int send(void *data, size_t len, bool nonblocking);
    int send(const string &data, bool nonblocking);
    int send(const ofBuffer &data, bool nonblocking);
    
    bool receive(string &data, bool nonblocking);
    bool receive(ofBuffer &data, bool nonblocking);
    
    bool hasWaitingMessage();
	
	bool getNextMessage(string &data, bool nonblocking);
	bool getNextMessage(ofBuffer &data, bool nonblocking);
    
    void setSendBufferSize(int kb, int socklevel = NN_SOL_SOCKET);
    void setReceiveBufferSize(int kb, int socklevel = NN_SOL_SOCKET);
    void setSendTimeout(int millis, int socklevel = NN_SOL_SOCKET);
    void setReceiveTimeout(int millis, int socklevel = NN_SOL_SOCKET);
    void setSendPriority(int priority, int socklevel = NN_SOL_SOCKET);
};