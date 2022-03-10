#include "wave_functions.h"

string prompt_user_for_filename(){
    string fileName;
    cout << "Enter the name of the file to open: ";
    cin >> fileName;
    return fileName;
}

bool open_file(ifstream& input, const string FILENAME){
    input.open(FILENAME);                                       //Open input file
    if (input.fail()){
        cout << "Error opening file: " << FILENAME << endl;     //Check if input file opens succesfully, alert user if it doesn't
        return false;
    } else{
        cout << "File: " << FILENAME << " - OPEN" << endl;      //Alert user of successful file opening
        return true;
    }
}

vector<string> read_all(ifstream& input, int &numLines){
    int numLines = 0;
    vector<string> lines;
    string temp;
    while(getline(input, temp)){
        lines.push_back(temp);
        numLines++;
    }
    cout << "Successfully read all " << numLines << " lines..." << endl;
    return lines;
}

