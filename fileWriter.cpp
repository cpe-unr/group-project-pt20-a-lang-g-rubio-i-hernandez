#include "fileWriter.h"
#include <iostream>

fileWriter::fileWriter(std::vector<std::string> fileListInput)
{
	fileList = fileListInput;
}

std::string fileWriter::getFileName()
{
	do
	{
		std::cout << "Enter the name you want the new file to be called.\nName: ";
		std::cin >> fileName;

		for (int n = 2; n < fileList.size(); n++)
		{
			if (fileList.at(n).compare(fileName) == 0)
			{
				std::cout << "Files cannot be saved with the same name as an extisting file." << std::endl;
				same = true;
				n = fileList.size();
			}
			else
				same = false;
		}
	} while (same == true);
}

void fileWriter::setFileName(std::string newFName)
{
	fileName = newFName;
}

void fileWriter::writeToFile()
{
	outFile.open("./Output_Folder/"+userFileName);

	for (int n = 2; n < fileList.size(); n++)
	{
		outFile << fileList.at(n) << std::endl; // example output
		//actual output should be handled with a wav vector
	}

	outFile.close();
}