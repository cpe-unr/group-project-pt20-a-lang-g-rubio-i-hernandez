#ifndef WAV_READER_H
#define WAV_READER_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "WaveHeadMod.h"
#include "chunkHeader.h"
class WavReader{
	public:
		void readFile(const std::string &fileName);
		void writeFile(const std::string &outFileName);
		unsigned char *getDataBuffer();
		char *getMetaBuffer();
		~WavReader();
		int getDataSize() const;
		int getMetaSize() const;
		short getBitSize() const;
		short getStereo() const;
		std::string getOriginalName();
		friend std::ostream& operator<<(std::ostream &out, const WavReader &wav);

	private:
		wav_header waveHeader;
		unsigned char* dataBuffer = NULL;
		char* metaBuff = NULL;
		int dataIndex, metaIndex;
		generic_chunk metaChunk{"LIST"}, dataChunk{"data"};
		std::string originalFileName;
};


#endif //WAV_READER_H
