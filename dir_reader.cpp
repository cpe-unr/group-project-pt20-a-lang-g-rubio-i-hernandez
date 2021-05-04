#include "dir_reader.h"
#include <iostream>

dir_reader::DirReader(std::string directory)
{
	dirLocation = directory;
}


void dir_reader::readDirectory()
{
	struct dirent *directory;
	DIR *wav_dr;
	wav_dr = opendir("./wav_folder"); // can be changed to be based on user input

	if(wav_dr!=NULL)
	{
    	for(directory=readdir(wav_dr); directory!=NULL; directory=readdir(wav_dr))
    	{
      		fileList.push_back(directory->d_name); // contains fileNames (maybe not necessary)
    	}
    	closedir(wav_dr);

	     // random file ".DS_Store" is being created
  	}
  	else
	    std::cout<<"\nEncountered an error";
}

std::vector<std::string> dir_reader::getFileList() {return fileList;}

void dir_reader::printFileList()
{
	for (int i = 2; i < fileList.size(); i++)
    {  
      std::cout << fileList.at(i) << std::endl; // first two entries are junk, start at i = 2
    } 
}