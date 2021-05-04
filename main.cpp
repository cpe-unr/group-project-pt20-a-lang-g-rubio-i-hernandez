/** @file */
//#include "csv.h"

#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <vector>
#include "wav_reader.h"

using namespace std;
/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
/* 
void fn(){

}
*/

int main(){
	
  std::vector<std::string> fileList;  
  struct dirent *directory;
  DIR *wav_dr;
  wav_dr = opendir("./wav_folder");

  if(wav_dr!=NULL)
  {
    for(directory=readdir(wav_dr); directory!=NULL; directory=readdir(wav_dr))
      fileList.push_back(directory->d_name);

    closedir(wav_dr);

    for (int i = 2; i < fileList.size(); i++)
    {  
      std::cout << fileList.at(i) << std::endl; // first two entries are junk, start at i = 2
    }
}
else
  std::cout<<"\nEncountered an error";
std::cout << std::endl;


WavReader yourMom;
yourMom.readFile("yes-16-bit-mono.wav");





  //TODO: Call a method that calls all the getters for the meta/technical data, compose into one string for each audio file
  //TODO: Replace "eat,drink,sleep,repeat" with data strings
string fileInfo1 = "eat,drink,sleep,repeat";
string fileInfo2 = "eat,drink,sleep,repeat";
string fileInfo3 = "eat,drink,sleep,repeat";
string fileInfo4 = "eat,drink,sleep,repeat";
  /*
  CSV* csv;
  cout << "Please enter the name of the new file being created (without the .csv):" << endl;
  string OUTPUT;
  cin >> OUTPUT;
  csv->outputCSV(OUTPUT,fileInfo1, fileInfo2, fileInfo3, fileInfo4);
	*/
return 0;
}
