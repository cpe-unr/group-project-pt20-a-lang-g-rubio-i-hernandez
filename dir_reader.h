#ifndef DIR_READER
#define DIR_READER

#include <vector>
#include <string>
#include <dirent.h>

class DirReader
{
	std::vector<std::string> fileList;
	std::string dirLocation;
public:
	DirReader(std::string);
	void readDirectory();
	std::vector<std::string> getFileList();
	void printFileList();
};

#endif