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

	/**
	 *  Consructor for DirReader class
	 *  @param directory - give the name of the directory to scan
	 */	
	DirReader(std::string);

	/**
	 *  Reads in all the files in a directory
	 */
	void readDirectory();

	/**
	 *  returns the list of all the file names
	 *  @return fileList - vector containing the strings of file names
	 */
	std::vector<std::string> getFileList();

	/**
	 *  prints out all the files names contained in fileList
	 */
	void printFileList();
};

#endif