//
// Created by Max on 18.03.2022.
//

#include "functions.h"
#include <iostream>

string get_last_lane(const string& filename) {
    ifstream fin;
    fin.open(filename);
    if(fin.is_open()) {
        fin.seekg(-1,ios_base::end);                // go to one spot before the EOF

        bool keepLooping = true;
        while(keepLooping) {
            char ch;
            fin.get(ch);                            // Get current byte's data

            if((int)fin.tellg() <= 1) {             // If the data was at or before the 0th byte
                fin.seekg(0);                       // The first line is the last line
                keepLooping = false;                // So stop there
            }
            else if(ch == '\n') {                   // If the data was a newline
                keepLooping = false;                // Stop at the current position.
            }
            else {                                  // If the data was neither a newline nor at the 0 byte
                fin.seekg(-2,ios_base::cur);        // Move to the front of that data, then to the front of the data before it
            }
        }

        string lastLine;
        getline(fin,lastLine);                      // Read the current line
        return lastLine;
    }


}
