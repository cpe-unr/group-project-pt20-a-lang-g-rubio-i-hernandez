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
	/**
	 *  Constructor for FileWriter class
	 *  @param fileListInput - contains the names of files
	 */
	FileWriter(std::vector<std::string> fileListInput);

	/**
	 *  gets the file name the user wants to save the processed .wav under
	 *  @return string of the file name
	 */
	std::string getFileName();

	/**
	 *  sets the name to save the new .wav file as
	 *  @param newFName - name inputted by the user for the .wav file
	 */
	void setFileName(std::string newFName);

	/**
	 *  writes contents in fileList to a file
	 */
	void writeToFile();

};