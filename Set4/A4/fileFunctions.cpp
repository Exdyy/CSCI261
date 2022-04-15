
#include "fileFunctions.h"

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

vector<int> read_file(ifstream& input, vector<string> &allComments, vector<float> &allVertices, vector<int> &allFaces, 
LinkedList<string> &stringList, LinkedList<vector<float>> &vertexList, LinkedList<vector<int>> &faceList){
    string temp;
    unsigned int commentCount(0), vertexCount(0), faceCount(0);
    vector<int> counts;
    while (getline(input, temp)){           //Pull each line in file, store in temp
       stringstream lineReader (temp);      //Create stream of strings from temp
       if (temp[0] == '#'){
           temp.erase(0,1);
           allComments.push_back(temp);
           commentCount += 1;
       }
       if (temp[0] == 'v'){
            vector<float> vertices = [];
            for (unsigned int i = 1; i <= 3; i++){
                vertices.push_back((float)temp[i];
                allVertices.push_back((float)temp[i]);
            }
            vertexList.pushBack(vertices);
            vertexCount += 1;
       }
       if (temp[0] == 'f'){
           vector<float> faces = [];
           for (unsigned int i = 1; i <= 3; i++){
               faces.push_back((int)temp[i]);
               allFaces.push_back((int)temp[i]);
           }
           faceList.pushBack(faces);
           faceCount += ;1
        }
    }
    counts.push_back(commentCount);
    counts.push_back(vertexCount);
    counts.push_back(faceCount);
    return counts;
}

bool check_validity_faces(LinkedList<vector<int>> faceList, vector<int> allFaces, vector<float>allVertices){
    bool valid = true;
    
    for (unsigned int i = 0; i < allFaces.size; i++){
        for (unsigned int j = 0; j < 3; j++){
            if (allFaces[i][j] == 0 || allFaces[i][j] > allVertices.size){
                valid = false;
                cout << "Face " << i << " contains vertices out of range" << endl;
            }
            Node<vector<int>> *curr = faceList;
            if (curr->value[0] == curr->value[1] || curr->value[0] == curr->value[2] || curr->value[1] == curr->value[2]){
                valid = false;
                cout << "Face " << i << " has duplicate indices" << endl;
            }
        }
    }
}

void print_results(vector<int> counts, LinkedList<vector<int>> faceList, vector<int> allFaces, vector<float>allVertices){
    cout << "Read in:" << endl;
    cout << "\t" << counts.at(0) << " comments" << endl;
    cout << "\t" << counts.at(1) << " vertices" << endl;
    cout << "\t" << counts.at(2) << " faces" << endl;

    cout << endl << "Validating faces..." << endl;
    check_validity_faces(faceList, allFaces, allVertices);
}
