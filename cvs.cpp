#include "csv.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CSV::outputCSV(string OUTPUT,string fileInfo1,string fileInfo2,string fileInfo3,string fileInfo4){
  
  // Create an output filestream object
  OUTPUT = OUTPUT + ".csv";
  std::ofstream myFile(OUTPUT);

  // Send data to the stream
  //TODO: Add more things here, look into what data we are reading in
  myFile << ",Artist,Track,Album,Data,Genre,Track Number,Comments,";
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
