
#include "Limiter.h"
#include "Processor.h"
#include <string>
#include <iostream>
#include <fstream>

void Limiter::processBuffer(unsigned char* buffer, int bufferSize){
    int count = 0;
    for(count; count<=bufferSize;count++){
	if(buffer[count]>230){
	    buffer[count]=230;
	}
	if(buffer[count]<26){
	    buffer[count]=26;
	}
    }
}

Limiter::Limiter(){}
Limiter::~Limiter(){}
