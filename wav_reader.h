#ifndef WAV_READER_H
#define WAV_READER_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "WaveHeadMod.h"
#include "chunkHeader.h"
/**
 * Reads, writes, and stores data for WAV files.
 */
  
class WavReader{
	public:
		/**
		 * Reads in a file with the given filename
		 * @param fileName - name of file to be read
		 */
		  
		void readFile(const std::string &fileName);
		/**
		 * Writes to a a file with the given name
		 * @param outFileName - name of file to be written
		 */
		  
		void writeFile(const std::string &outFileName);
		/**
		 * returns the buffer with the sound data
		 */
		  
		unsigned char *getDataBuffer();
		/**
		 * Returns the buffer with meta data
		 */
		  
		char *getMetaBuffer();
		
		/**
		 * Deconsturcotr
		 */
		~WavReader();
		
		/**
		 * Returns the size of the dataBuffer
		 */
		  
		int getDataSize() const;
		
		/**
		 * Returns the size of the metaBuffer
		 */
		int getMetaSize() const;
		
		/**
		 * Returns the bit depth
		 */
		short getBitSize() const;
		
		
		/**
		 * Returns the number of channels
		 */
		  
		short getStereo() const;
		
		
		/**
		 *Returns the original file name read in using readFile()
		 */
		  
		std::string getOriginalName();
		
		/**
		 * Overload of the << operator
		 * Will output meta data followed by bit-depth and number of channels.
		 * @param out - an ostream ref
		 * @param wav - a WavReader instance
		 * @return
		 */
		  
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
