#ifndef NOISEGATE_H
#define NOISEGATE_H

#include "Processor.h"
#include <cstdint>
#include <cmath>

template<class T>
class NoiseGate : public Processor<T> {
public:
/**
*Sets the audio equal to 'zero' (silence) if it's not loud enough
    *@param buffer - the actual audio
    *@param bufferSize - the length of this audio
    */
	void processBuffer(T* buffer, int bufferSize)override{
    const T ZERO = (pow(2, bitType)/2);
    const T threshold = ZERO + (ZERO * .05)
    for(int i = 0; i < bufferSize; i++) {
      if(buffer[i] > (ZERO - threshold) && buffer[i] < (ZERO + threshold)) {
        buffer[i] = ZERO;
        }

      }
    }

  }
  NoiseGate(){}
  ~NoiseGate(){}
};

#endif  
