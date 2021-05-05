#ifndef PROCESSOR_H
#define PROCESSOR_H


#include <cstdint>
#include <cmath>

template<class T>
class Processor {
public:
    /**
    *Edits the audio somehow; inplemented in subclasses
    *@param buffer - the actual audio
    *@param bufferSize - the length of this audio
    */
    virtual void processBuffer<T>(T* buffer, int bufferSize) = 0;
};


#endif
