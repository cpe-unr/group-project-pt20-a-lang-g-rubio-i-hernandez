#include "Echo.h"
#include "Processor.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Wav.h"
using namespace std;

void Echo::processBuffer(unsigned char* buffer, int bufferSize){
    int count;
    for(count = Echo::delay; count <= bufferSize; count++){
	    buffer[count] = (buffer[count] + buffer[count - Echo::delay]) / 2;
    }
}

Echo::Echo(){
	
}

Echo::Echo(int newDelay){
	cout << newDelay << endl;
	Echo::setDelay(newDelay);
}

Echo::~Echo(){}

void Echo::setDelay(int newDelay){
	delay = newDelay;
}
