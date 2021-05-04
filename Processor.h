#ifndef PROCESSOR_H
#define PROCESSOR_H


#include <cstdint>
#include <cmath>

template<class T>
class Processor {
public:
    virtual void processBuffer<T>(T* buffer, int bufferSize) = 0;
};


#endif
