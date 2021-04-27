#include "csv.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int output() {
    cout << "Please enter the name of the new file being created (without the .csv):" << endl;
    string OUTPUT;
    cin >> OUTPUT;
    // Create an output filestream object
    OUTPUT = OUTPUT + ".csv";
    std::ofstream myFile(OUTPUT);
    
    

    // Send data to the stream
    myFile << ",Artist,Track,Album,Data,Genre,Track Number,Comments,";
    myFile << "\n1\n";
    myFile << "2\n";
    myFile << "3\n";
    
    // Close the file
    myFile.close();
    
    return 0;
}
