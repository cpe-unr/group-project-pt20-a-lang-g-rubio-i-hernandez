#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstring>
#include "wav_reader.h"
#include "WaveHeadMod.h"
#include "chunkHeader.h"
#include "dataBytes.h"










void WavReader::readFile(const std::string &fileName){
	dataBytes byteSizeHolder;
	originalFileName = fileName;
	char chunkLabel[4];	
	int genLblSize = (sizeof(char) * 4);
	int intSize = sizeof(int);
	//opens file in binary read mode
	std::ifstream file(fileName,std::ios::binary | std::ios::in);
	if(file.is_open()){
		file.read((char*)&waveHeader, sizeof(wav_header));

		for (unsigned int i = 0; i < 2; i += 1){
			file.read((char*)&chunkLabel, genLblSize); //Every chunk label should be char[4]
			std::string chunkString(chunkLabel);
			
			if (chunkString == "LIST"){
				
				
				file.read((char*)&byteSizeHolder, sizeof(int)); //Size of the chunk
				metaBuff = new char[byteSizeHolder.chunkBytes];
				metaIndex = byteSizeHolder.chunkBytes;
				file.read((char*)metaBuff, byteSizeHolder.chunkBytes);
				std::string inf(metaBuff);
				
			
				
				
			}else if (chunkString == "data"){
				
				file.read((char*)&byteSizeHolder, sizeof(int)); //Size of the chunk
				dataBuffer = new unsigned char[byteSizeHolder.chunkBytes];
				dataIndex = byteSizeHolder.chunkBytes;
				file.read((char*)dataBuffer, byteSizeHolder.chunkBytes);
			}
		}
		file.close();
	}
	dataChunk.size = dataIndex;
	metaChunk.size = metaIndex;
}



void WavReader::writeFile(const std::string &outFileName){
	
	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    	outFile.write((char*)&waveHeader,sizeof(wav_header));
    	outFile.write((char*)&dataChunk,sizeof(generic_chunk));
    	outFile.write((char*)dataBuffer, dataChunk.size);
    	outFile.write((char*)&metaChunk, sizeof(generic_chunk));
    	outFile.write((char*)&metaBuff, metaChunk.size);
    	outFile.close();
}

unsigned char *WavReader::getDataBuffer(){
	return dataBuffer;
}

char *WavReader::getMetaBuffer(){
	return metaBuff;
}

WavReader::~WavReader(){
	if (dataBuffer != NULL && metaBuff != NULL){
		delete dataBuffer, metaBuff;
	}
}

int WavReader::getDataSize() const{
	return dataIndex;
}

int WavReader::getMetaSize() const{
	return metaIndex;
}

short WavReader::getBitSize() const{
	return waveHeader.bit_depth;
}
		
short WavReader::getStereo() const{
	return waveHeader.num_channels;
}

std::string WavReader::getOriginalName(){
	return originalFileName;
}




std::ostream& operator<<(std::ostream &out, const WavReader &wav){
	std::string metaString(wav.metaBuff);
	
	
	out << metaString << wav.waveHeader.bit_depth << wav.waveHeader.num_channels << std::endl;
	return out;
}


