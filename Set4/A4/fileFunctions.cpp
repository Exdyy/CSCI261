
#include "fileFunctions.h"

unsigned int stringCount = 0;
unsigned int vertexCount = 0;
unsigned int faceCount = 0;

string prompt_user_for_filename(){
    string fileName;
    cout << "Please enter a file name: ";       //Prompt user for filename
    cin >> fileName;                            //Store user input into fileName

    return fileName;                            //Return string fileName
}

bool open_file(ifstream& input, const string FILENAME){
    cout << "Opening file " << "\"" << FILENAME << "\"" << endl;
    input.open(FILENAME);                                       //Open inpuut file
    if (input.fail()){
        return false;
    } else {
        cout << "File: " << FILENAME << " - OPEN" << endl;      //Alert user of successful file opening
        return true;
    }
}

void read_file(ifstream& input){
    LinkedList<string> stringList;
    LinkedList<string> vertexList;
    LinkedList<string> faceList;
    string temp;
    while (getline(input, temp)){           //Pull each line in file, store in temp
       stringstream lineReader (temp);      //Create stream of strings from temp
       if (temp[0] == '#'){
           temp.erase(0,1);
           stringList.pushBack(temp);
           stringCount += 1;
       }
       if (temp[0] == 'v'){
           temp.erase(0,1);
           vertexList.pushBack(temp);
           vertexCount += 1;
       }
       if (temp[0] == 'f'){
           temp.erase(0,1);
           faceList.pushBack(temp);
           faceCount += 1;
       }
    }
}

bool check_validity(const LinkedList<string> obj){
    bool valid = true;
    vector<string> list;
    vector<int> duplicates;
    for (int i = 0; i < obj.size(); i++) {
        list.push_back(obj.at(i));
    }
    for (int i = 0; i < list.size(); i++) { 
        for (int j = 0; i < list.size(); j++){
            if (i != j && list.at(i) == list.at(j)){
                duplicates.push_back(j);
                valid = false;
            }
        }
    }
    return valid;
}

void print_results(){
    cout << "Read in:" << endl;
    cout << "\t" << stringCount << " comments" << endl;
    cout << "\t" << vertexCount << " vertices" << endl;
    cout << "\t" << faceCount << " faces" << endl;
}
