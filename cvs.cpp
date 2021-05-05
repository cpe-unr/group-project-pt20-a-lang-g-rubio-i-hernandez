#include "csv.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/** 
  *Create an output filestream object using an inputted file name string
  *Send in the recieved metadata into the CSV file
  *@param OUTPUT - the name of the output file
  *@param fileInfo1 - the data of the first output file
  *@param fileInfo2 - the data of the second output file
  *@param fileInfo3 - the data of the third file
  *@param fileInfo4 - the data of the fourth file
  */
void CSV::outputCSV(string OUTPUT,string fileInfo1,string fileInfo2,string fileInfo3,string fileInfo4){
  
  OUTPUT = OUTPUT + ".csv";
  std::ofstream myFile(OUTPUT);

  // Send data to the stream
  myFile << "Song,Artist,Track,Album,Data,Genre,Track Number,Comments,Bit Type";
  myFile << "\n";
  myFile << fileInfo1;
  myFile << "\n";
  myFile << fileInfo2;
  myFile << "\n";
  myFile << fileInfo3;
  myFile << "\n";
  myFile << fileInfo4;
  
  // Close the file
  myFile.close();
}

