//
// Gustavo Rubio
// Programming Assignment 3
// 3/23/2021
/**************************/
#include"Echo.h"
#include"Processor.h"
#include <string>
#include <fstream>
#include <iostream>
#include "NoiseGate.h"

void NoiseGate::processBuffer(unsigned char* buffer, int bufferSize)
{
    for(NoiseGate::count; NoiseGate::count <= bufferSize; NoiseGate::count++)
	{
	    if(buffer[NoiseGate::count] <= 131 && buffer[NoiseGate::count] >= 125)
	    {
		buffer[NoiseGate::count] = 128;
	    }
	}

}
NoiseGate::NoiseGate()
{
}
NoiseGate::~NoiseGate()
{
}
