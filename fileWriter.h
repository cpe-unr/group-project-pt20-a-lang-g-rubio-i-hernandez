#include <string>
#include <vector>
#include <fstream>
#include "dir_reader.h"

class FileWriter
{
	std::string fileName = " ";
	std::vector<std::string> fileList;
	bool same = true;
	std::ofstream outFile;

public:
	FileWriter(std::vector<std::string>);
	std::string getFileName();
	void setFileName(std::string);
	void writeToFile();

};