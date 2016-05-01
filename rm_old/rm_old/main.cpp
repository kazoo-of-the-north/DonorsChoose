//
//  main.cpp
//  rm_old
//
//  Created by Jim Schlough on 4/22/16.
//  Copyright © 2016 Jim Schlough. All rights reserved.
//

#include <iostream>
#include <fstream>    // for ifstream, ofstream

#include <string>
#include <ctime>
#include <cstdlib>
#include <stdio.h>    // for tmpnam, remove

// for time & date processing:
#include <sstream>
#include <locale>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {

    // insert code here...
    if (argc< 3 )
    {
        std::cout << "Usage rm_old fileInName bottomCutOffDate topCutOffDate dateFieldIndex" << endl;
        std::cout << endl;
        std::cout << "   dateFieldIndex is ONE based" << endl;
    }
    
    char filebuf [L_tmpnam];
    ::strcpy(filebuf, argv[1]);
    
    std::string outFileName;

    int dateFieldIdx = 0;
    dateFieldIdx = std::atoi(argv[4])-2;
    
    
    // TODO: check for clean cutOffDateInput here
    int64_t bottomCutOffDateValue = 0L, topCutOffDateValue = 0L;
    bottomCutOffDateValue = std::atol(argv[2]);
    topCutOffDateValue = std::atol(argv[3]);
    
    // TODO: check for valid (positive integer) date field index (1 based) here
    

    std::ifstream inputFile (filebuf, std::ios::in);
    outFileName.append(filebuf);
    outFileName.erase( outFileName.find(".csv"),4);
    outFileName.append("_output.csv");
    
    std::ofstream outputFile (outFileName, std::ios::out);
    std::string line, submittedDateTimeStr, submittedDateStr;
    bool skipFirst = true;
    
    if (inputFile.is_open())
    {
        std::getline(inputFile, line);
        skipFirst = (line.find('\"') == std::string::npos); // first line is  header
        
        
        while( inputFile)
        {
            if (skipFirst)
            {
                skipFirst = false;
                outputFile << line << endl;
            }
            else std::getline(inputFile, line);
            
            if (line.length() < 2) continue;
            size_t numberCommas = std::count(line.begin(), line.end(), ',');
            if (numberCommas < 43 ||
                line.find("\"") == std::string::npos ) // skip the header line, which has no "
                continue;
            
            // find the position of the date in the 41st field
            int x = 0;
            //std::string::size_type
            int lastPos=0, startOfDatePos = 0, endOfDatePos = 0;
            int64_t dateIntValue = 0L;
            
            // TODO: make magical 39 to be dateFieldIndex in future refinement
            
            while (x<43   &&  inputFile.good() ) {
                lastPos = (int)line.find(',', lastPos+1);
                if (x== (dateFieldIdx)) // date we seek is in the 41st field
                {
                    startOfDatePos = lastPos+2;
                } else if (startOfDatePos != 0)
                {
                    endOfDatePos = (int)line.find(',', startOfDatePos)-1; // ", is end of field, so -1 for " part
                    break;
                }
                x++;
            }
            
            submittedDateTimeStr = line.substr(startOfDatePos, endOfDatePos-startOfDatePos );  ///19);
            
            // truncate the hours, minutes and seconds off of the date
            submittedDateStr = submittedDateTimeStr.substr(0, submittedDateTimeStr.length()-9 );
            while(submittedDateStr.find('-') != std::string::npos )
                submittedDateStr = submittedDateStr.erase( submittedDateStr.find('-'), 1);
            
            
            dateIntValue = std::atol(submittedDateStr.c_str());//, std::locale("en_US.utf-8"));
            
            if (dateIntValue <= bottomCutOffDateValue || dateIntValue >= topCutOffDateValue)
                continue; // skip to the next record if this one is too early or too late
            
            if (outputFile.is_open())
                outputFile << line << endl;
            else
                exit(EXIT_FAILURE);
            
        }
        inputFile.close();
        outputFile.close();

    
    }
    
    return 0;
}
