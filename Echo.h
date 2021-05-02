//
// Gustavo Rubio
// Programming Assignment 3
// 3/23/2021
/**************************/

#ifndef ECHO_H
#define ECHO_H

#include "Processor.h"
#include <cstdint>
#include <cmath>
using namespace std;

class Echo : public Processor {
public:
	int delay;
    void processBuffer(unsigned char* buffer, int bufferSize) override;

	Echo();
	Echo(int newDelay);

	virtual ~Echo();

	void setDelay(int delay);
};



#endif
