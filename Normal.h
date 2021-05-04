#ifndef NORMAL_H
#define NORMAL_H

#include "Processor.h"
#include <cstdint>
#include <cmath>

template<class T>
class Normal : public Processor<T> {
  public:
    /**
    *Takes in the buffer and magnifies the volume
    */
    void processBuffer(T* buffer, int bufferSize)override{
      int count = 0;
      T baseine = (T) (pow(2, bittype)/2);
      T limit = (T) (((pow(2,bitType)/2)-1) * (0.7));
      T upperLim = base + limit;
      T lowerLim = base - limit;
      for(count; count<=bufferSize;count++){
        buffer[count] = buffer[count] > upperLim ? upperLim : buffer[count];
        buffer[count] = buffer[count] < lowerLim ? lowerLim : buffer[count];
        }
      
      }
}

  Normal::Normal(){}
  Normal::~Normal(){}
  };


#endif
