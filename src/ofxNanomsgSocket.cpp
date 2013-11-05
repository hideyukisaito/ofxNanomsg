#include "ofxNanomsgSocket.h"


#pragma mark - Public

ofxNanomsgSocket::ofxNanomsgSocket(int domain, int protocol) : socket(domain, protocol)
{
    
}

ofxNanomsgSocket::~ofxNanomsgSocket()
{
    
}

ofxNanomsgSocket & ofxNanomsgSocket::operator=(const ofxNanomsgSocket &mom)
{
    
}

void ofxNanomsgSocket::setLinger(int millis, int socklevel)
{
    setSocketOptions(socklevel, NN_LINGER, &millis, sizeof(millis));
}

void ofxNanomsgSocket::setReconnectionInterval(int socklevel, int millis)
{
    setSocketOptions(socklevel, NN_RECONNECT_IVL, &millis, sizeof(millis));
}

void ofxNanomsgSocket::setMaxReconnectionInterval(int socklevel, int millis)
{
    setSocketOptions(socklevel, NN_RECONNECT_IVL_MAX, &millis, sizeof(millis));
}

void ofxNanomsgSocket::setUseIPV6(bool value, int socklevel)
{
    int val = value ? 0 : 1;
    setSocketOptions(socklevel, NN_IPV4ONLY, &val, 1);
}


#pragma mark - Protected

int ofxNanomsgSocket::bind(string addr)
{
    int rc;
    try
    {
        rc = socket.bind(addr.c_str());
    }
    catch (nn::exception &e)
    {
        ofLog(OF_LOG_ERROR, "ofxNanomsgSocket::bind: %s", e.what());
    }
    
    return rc;
}

int ofxNanomsgSocket::connect(string addr)
{
    int rc;
    try
    {
        rc = socket.connect(addr.c_str());
    }
    catch (nn::exception &e)
    {
        ofLog(OF_LOG_ERROR, "ofxNanomsgSocket::bind: %s", e.what());
    }
    
    return rc;
}

bool ofxNanomsgSocket::shutdown(int how)
{
    try
    {
        socket.shutdown(how);
    }
    catch (nn::exception &e)
    {
        ofLog(OF_LOG_ERROR, "ofxNanomsgSocket::bind: %s", e.what());
        return false;
    }
    
    return true;
}

void ofxNanomsgSocket::setSocketOptions(int level, int option, const void *optval, size_t optvallen)
{
    try
    {
        socket.setsockopt(level, option, optval, optvallen);
    }
    catch (nn::exception &e)
    {
        ofLog(OF_LOG_ERROR, "ofxNanomsgSocket::setSockopt: %s", e.what());
    }
}

int ofxNanomsgSocket::send(const void *data, size_t len, bool nonblocking)
{
    int rc;
    try
    {
        rc = socket.send(data, len, nonblocking ? NN_DONTWAIT : 0);
    }
    catch (nn::exception &e)
    {
        ofLog(OF_LOG_ERROR, "ofxNanomsgSocket::send: %s", e.what());
    }
    
    return rc;
}

int ofxNanomsgSocket::send(void *data, size_t len, bool nonblocking)
{
    return send((const void*)data, len, nonblocking);
}

int ofxNanomsgSocket::send(const string &data, bool nonblocking)
{
    return send((const void*)data.data(), data.size(), nonblocking);
}

int ofxNanomsgSocket::send(const ofBuffer &data, bool nonblocking)
{
    return send((const void*)data.getBinaryBuffer(), data.size(), nonblocking);
}

bool ofxNanomsgSocket::receive(string &data, bool nonblocking)
{
	data.clear();
    
	void *buf = NULL;
    
	int bytes;
    try
    {
        bytes = socket.recv(&buf, NN_MSG, nonblocking ? NN_DONTWAIT : 0);
        if (0 < bytes)
        {
            string str = string((char *)buf);
            
            const int numBytes = str.size();
            const uint8_t *src = (uint8_t*)str.data();
            
            data.insert(data.end(), src, src + numBytes);
            nn_freemsg(buf);
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (nn::exception &e)
    {
        ofLog(OF_LOG_ERROR, "ofxNanomsgSocket::receive: %s", e.what());
        return false;
    }
}

bool ofxNanomsgSocket::receive(ofBuffer &data, bool nonblocking)
{
    int32_t more = 0;
	size_t more_size = sizeof(more);
	
	data.clear();
	
	stringstream ss;
    void *buf = NULL;
	
    try
    {
        int bytes = socket.recv(&buf, NN_MSG, nonblocking ? NN_DONTWAIT : 0);
        
        if (0 < bytes)
        {
            string str = string((char *)buf);
            
            const int numBytes = str.size();
            const char *src = (const char*)buf;
            ofLog() << "src = " << (const char*)buf;
            ss.write(src, numBytes);
            
            data.set(ss);
            
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (nn::exception &e)
    {
        ofLog(OF_LOG_ERROR, "ofxNanomsgSocket::receive: %s", e.what());
        return false;
    }
}

void ofxNanomsgSocket::setSendBufferSize(int kb, int socklevel)
{
    setSocketOptions(socklevel, NN_SNDBUF, &kb, sizeof(kb));
}

void ofxNanomsgSocket::setReceiveBufferSize(int kb, int socklevel)
{
    setSocketOptions(socklevel, NN_RCVBUF, &kb, sizeof(kb));
}

void ofxNanomsgSocket::setSendTimeout(int millis, int socklevel)
{
    setSocketOptions(socklevel, NN_SNDTIMEO, &millis, sizeof(millis));
}

void ofxNanomsgSocket::setReceiveTimeout(int millis, int socklevel)
{
    setSocketOptions(socklevel, NN_RCVTIMEO, &millis, sizeof(millis));
}

void ofxNanomsgSocket::setSendPriority(int priority, int socklevel)
{
    setSocketOptions(socklevel, NN_SNDPRIO, &priority, sizeof(priority));
}