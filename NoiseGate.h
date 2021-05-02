//
// Gustavo Rubio
// Programming Assignment 3
// 3/23/2021
/**************************/

#ifndef NOISEGATE_H
#define NOISEGATE_H

#include "Processor.h"
#include <cstdint>
#include <cmath>

class NoiseGate : public Processor {
public:
	int count = 0;
    void processBuffer(unsigned char* buffer, int bufferSize) override;
	NoiseGate();
	virtual ~NoiseGate();
};


#endif  
