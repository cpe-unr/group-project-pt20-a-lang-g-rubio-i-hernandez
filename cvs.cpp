#include "csv.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CSV::outputCSV(string fileInfo1,string fileInfo2,string fileInfo3,string fileInfo4){
  cout << "Please enter the name of the new file being created (without the .csv):" << endl;
  string OUTPUT;
  cin >> OUTPUT;
  // Create an output filestream object
  OUTPUT = OUTPUT + ".csv";
  std::ofstream myFile(OUTPUT);

  // Send data to the stream
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
