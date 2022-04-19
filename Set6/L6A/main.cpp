#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    string userInput;
    cout << "Enter a file name: ";
    cin >> userInput;

    ifstream in;
    char c;
    int size;
    int i = 0;
    int j = 0;

    //Open file and check for errors
    in.open(userInput);
    if (!in.is_open()){
        //If file does not open properly, abort program
        cout << "Error opening file..." << endl;
        return -1;
    } else {
        cout << "File: " << userInput << " opened" << endl << endl;
    }
    
    //Read in first character, which correlates to the size of the square 2D array
    in.get(c);
    string cstr (1,c);      //Convert char 'c' to a string value
    size = stoi(cstr);      //Convert string 'cstr' to integer 'size' to create array with
    int array[size][size];  //Create 2D array (size x size)

    string temp, strNums;
    while (getline(in, temp)){              //Read each line from ifstream 'in', store in string 'temp'
        stringstream line(temp);            //Convert string 'temp' to stream of strings 'line'
        while (line >> strNums){            //Read in each string from 'line' stream. This corresponds to each value in the array from .dat file read in
            array[i][j] = stoi(strNums);    //Assign values from .dat file to corresponding array indices    
            j++;                            //Increment j, which moves down the row being read
            if (j == size){                 //Set j to 0, and increment i when j == size, meaning it has reached the end of the row
                j = 0; i++;                 //This moves to the next row in the 2D array, and begins to fill in the values.
            }
        }
    }
    int max = array[0][0];                  //Initialize min and max to equal first value of array
    int min = max;
    for (int i = 0; i < size; i++) {        //For loop to iterate through each row
        for (int j = 0; j < size; j++) {    //For loop to iterate each column
            if (array[i][j] > max){         //Assign max to new value if new value is greater than max
                max = array[i][j];
            }
            if (array[i][j] < min){         //Assign min to new value if new value is less than min
                min = array[i][j];
            }
            cout << array[i][j] << ' ';     //Print array to console as program runs through the for loops
        }
        cout << endl;                       //Start new line after each row is printed, printing a 2D array to console
    }
    cout << endl << "The min is: " << min << endl;  //Display minimum and maximum values to user
    cout << "The max is: " << max << endl;

    return 0;
}