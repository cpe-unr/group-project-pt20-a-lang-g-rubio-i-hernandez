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
    *@param buffer - the actual audio
    *@param bufferSize - the length of this audio
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
    *@param newDelay - how long the delay in the echo will be
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
*@param newDelay - the new delay is being set
*/
  void setDelay(int newDelay){
    delay = newDelay;
  } 
  
};



#endif

