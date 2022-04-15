#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    string userInput;
    cout << "Enter a file name to open: ";
    cin >> userInput;

    ifstream in;
    char c;
    int size;
    int i = 0;
    int j = 0;
    in.open(userInput);
    if (!in.is_open()){
        cout << "Error opening file..." << endl;
    } else {
        cout << "File opened!" << endl;
    }
    
    in.get(c);
    string cstr (1,c);
    size = stoi(cstr);
    int array[size][size];

    string temp, strNums;
    while (getline(in, temp)){
        stringstream line(temp);
        while (line >> strNums){
            array[i][j] = stoi(strNums);
            j++;
            if (j == size){
                j = 0; i++;
            }
        }
    }
    int max = array[0][0];
    int min = max;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i][j] > max){
                max = array[i][j];
            }
            if (array[i][j] < min){
                min = array[i][j];
            }
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "The min is: " << min << endl;
    cout << "The max is: " << max << endl;

    return 0;
}