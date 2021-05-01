#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "wav_reader.h"
#include "WaveHeadMod.h"
#include "chunkHeader.h"








dataBytes byteSizeHolder;

void WavReader::readFile(const std::string &fileName){
	char chunkLabel[4];	
	int genLblSize = (sizeof(char) * 4);
	int intSize = sizeof(int);
	//opens file in binary read mode
	std::ifstream file(fileName,std::ios::binary | std::ios::in);
	if(file.is_open()){
		//First read of HEAD and FMT chunk, will always be the same so no need to track
		file.read((char*)&waveHeader, sizeof(wav_header));
		
		//Tracks the size of the WAV file. 
		//This declaration also subtracts the size of the HEAD and FMT chunk.
		int byteTrackerOverall = waveHeader.wav_size - 12 - waveHeader.fmt_chunk_size;
		int j = 0;
		std::cout << byteTrackerOverall << std::endl;
		
		
		

		for (unsigned int i = 0; i < 2; i += 1){
			file.read((char*)&chunkLabel, genLblSize); //Every chunk label should be char[4]
			std::string chunkString(chunkLabel);
			std::cout << chunkString << std::endl;
			std::cout << "this is the chunk # " << j << std::endl;
			
			j++;
			if (chunkString == "LIST"){
				std::cout << "We're in the list now." << std::endl;
				file.read((char*)&byteSizeHolder, sizeof(int)); //Size of the chunk
				std::cout << "Its size is " << byteSizeHolder.chunkBytes << std::endl;
				metaBuff = new char[byteSizeHolder.chunkBytes];
				metaIndex = byteSizeHolder.chunkBytes;
				file.read((char*)metaBuff, byteSizeHolder.chunkBytes);
				std::string inf(metaBuff);
				std::cout << inf << std::endl;
				byteTrackerOverall -= 8 + byteSizeHolder.chunkBytes;
			}else if (chunkString == "data"){
				std::cout << "We're now in the data." << std::endl;
				file.read((char*)&byteSizeHolder, sizeof(int)); //Size of the chunk
				std::cout << "Its size is " << byteSizeHolder.chunkBytes << std::endl;
				dataBuffer = new unsigned char[byteSizeHolder.chunkBytes];
				dataIndex = byteSizeHolder.chunkBytes;
				file.read((char*)dataBuffer, byteSizeHolder.chunkBytes);
				byteTrackerOverall -= 8 + byteSizeHolder.chunkBytes;
			}
		}
		file.close();
	}
	dataChunk.title = {'d', 'a' , 't', 'a'};
	metaChunk.title = {'L', 'I', 'S', 'T'};
	dataChunk.size = dataIndex;
	metaChunk.size = metaIndex;
}



void WavReader::writeFile(const std::string &outFileName){
	
	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    	outFile.write((char*)&waveHeader,sizeof(wav_header));
    	outFile.write((char*)&dataChunk,sizeof(generic_chunk));
    	outFile.write((char*)dataBuffer, dataChunk.size);
    	outFile.write((char*)&metaChunk, sizeof(generic_chunk));
    	outFile.write((char*)&metaBuff, metaChunk.size)
    	outFile.close();
}

unsigned char *WavReader::getDataBuffer(){
	return buffer;
}

char *WavReader::getMetaBuffer(){
	return metaBuff;
}

WavReader::~WavReader(){
	if (buffer != NULL && metaBuff != NULL){
		delete[] buffer, metaBuff;
	}
}

int WavReader::getDataSize() const{
	return dataIndex;
}

int WavReader::getMetaSize() const{
	return metaIndex;
}

short getBitSize() const{
	return waveHeader.bit_depth;
}
		
short getStereio() const{
	return waveHeader.num_channels;
}



