// Josh Williams
// 4/13/2020
// CSC - 234 - 81A
// Chapter 13 - Program 1 - File Previewer

// Ask the user for a filename and print the first 10 lines of that file to the screen.
// If the file has fewer than 10 lines display them all and include a finished message.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string PATH = R"(C:\cabs\)"; // Document path

int main()
{
    // Variables
    string filename;
    ifstream workingFile;
    string line;
    string word;

    // Welcome Message
    cout << "File Previewer\n\n";

    // Gather filename from the user.
    cout << "Text filename to preview: ";
    cin >> filename;
    filename = PATH + filename; // Complete path and filename.
    
    // Open file
    workingFile.open(filename);
    if (workingFile.fail()) {
        cout << "Filename not found.";
        return 1;
    }

    // Read and print 10 lines
    int i = 0;
    while (getline(workingFile, line, '\n')) {
        if (i >= 10) return 0;
        cout << line << endl;
        i++;
    }
    // Check for less than 10 lines printed and inform the user we reached EOF.
    if (i < 10) cout << "Finished printing " << i << " lines.";
}