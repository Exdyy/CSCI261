/* CSCI 261: Assignment 6: A6 - A-MAZE-ing
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // Lecture slides, stackOverflow for fixing errors, attempted to learn from youtube videos to no avail
 * This program is supposed to read in a .maze file, and use either BFS or DFS search methods with queues/stacks, but I cannot get it to work properly and I need some amount of points, so here is my attempt.
 */

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

string prompt_user_for_filename();
bool open_file(ifstream&, const string);
vector<string> read_file(ifstream&, int&, int&);
void print_file(const vector<string>);
int find_start(vector<string>);
vector<string> bfs(vector<string>&);

string prompt_user_for_filename(){
    string fileName;
    cout << "Please enter a file name: ";       //Prompt user for filename
    cin >> fileName;                            //Store user input into fileName
    cout << endl;

    return fileName;                            //Return string fileName
}

bool open_file(ifstream& input, const string FILENAME){
    
    input.open(FILENAME);                                       //Open inpuut file
    if (input.fail()){
        cout << "Error opening file: " << FILENAME << endl;     //Check if input file opens succesfully, alert user if it doesn't
        return false;
    } else {
        cout << "File: " << FILENAME << " - OPEN" << endl;      //Alert user of successful file opening
        return true;
    }
}

vector<string> read_file(ifstream& input, int& rows, int& cols){
    string temp;
    vector<string> data = {};
    string size;
    bool firstLine = true;
    while (getline(input, temp)){
        if (firstLine == true){
            size = temp;
            rows = stoi(string(1,size[0]));
            cols = stoi(string(1,size[2]));
            firstLine = false;
        } else {
            data.push_back(temp);
        }
    }
    for (unsigned int i = 0; i < data.size(); i++) {
        cout << data[i] << endl;
    }
    return data;
}

vector<string> bfs(vector<string> &data) {
    int c = data[1].length() - 1;
    int r = (int)data.size() - 1;
    bool checked[r][c] = {false};
    unsigned int i = 0;
    unsigned int j = 0;
    //Finding start position
    while (data[i][j] != 'S'){
        if (j == data[0].length() - 1){
            j = 0;
            i++;
        }
        j++;
    }
    while (data[i][j] != 'E'){
        if (checked[i][j] == false){
            if (data[i][j+1] == '.'){
                checked[i][j] = true;
                data[i][j] = '@';
                j++;
            } else if (data[i][j-1] == '.'){
                checked[i][j] = true;
                data[i][j] = '@';
                j--;
            } else if (data[i+1][j] == '.'){
                checked[i][j] = true;
                data[i][j] = '@';
                i++;
            } else if (data[i-1][j] == '.'){
                checked[i][j] = true;
                data[i][j] = '@';
                i--;
            }
        } else {
            if (j < data[0].length() - 1){
                j++;
            } else {
                i++;
            }
        }
    }
    return data;
}