#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(){

    int userInput = -1;         //Initialized to -1 to avoid triggering loop exit
    vector<int> nums;           //Vector to store user inputs
    int i = 0;                  //Counter initialized to 0

    printf("Enter up to 15 non-zero numbers.  Enter zero to signal the end of data or enter all 15 items:\n");

    while (i<15 && userInput != 0)              //Loop until 15 iterations, or user inputs zero to quit
    {
        cout << "Number " << i + 1 << ": ";
        cin >> userInput;                       //Get input from user for each integer
        if (userInput != 0)                     //Loop to append each input to the end of the nums vector
        {
        nums.push_back(userInput);              //Append to vector
        }
        i++;                                    //Increment counter
    }
    cout << "The numbers are:";
    for (unsigned int j = 0; j < nums.size(); j++)  //Loop once for each integer held in the nums vector
    {
        cout << " " << nums[j];                     //Output values to console in one line, separated by spaces
    }
    return 0;
}