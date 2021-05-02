//
// Gustavo Rubio
// Programming Assignment 3
// 3/23/2021
/**************************/

#ifndef LIMITER_H
#define LIMITER_H

#include "Processor.h"
#include <cstdint>
#include <cmath>

class Limiter : public Processor {
public:
    void processBuffer(unsigned char* buffer, int bufferSize) override;

	Limiter();
	virtual ~Limiter();

	
};


#endif
