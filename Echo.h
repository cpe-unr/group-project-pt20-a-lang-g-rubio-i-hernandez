#ifndef ECHO_H
#define ECHO_H

#include "Processor.h"
#include <cstdint>
#include <cmath>
using namespace std;

template<class T>
class Echo : public Processor<T> {
public:
    int delay;
    /**
    *Adds previous, quieter portions of the buffer unto itself
    *@param 
    */
  void processBuffer(T* buffer, int bufferSize)override{
    int count;
      for(count = delay; count <= bufferSize; count++){
        buffer[count] = (buffer[count] + buffer[count - delay]) / 2;
      }
      
  }

  Echo(){
    
  }
  /**
    *parameterized ctor
    */
  Echo(int newDelay){
    Echo::setDelay(newDelay);
  }
/**
 *Echo deconstructor
*/
  ~Echo(){}
/**
*Set what the audio delay will be
*/
  void setDelay(int newDelay){
    delay = newDelay;
  } 
  
};



#endif

