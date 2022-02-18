#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    int userInput = -1;         //Initialized to -1 to avoid triggering loop exit
    int min, max;               //Initialize min and max integer variables
    vector<int> nums;           //Vector to store user inputs
    int i = 0;                  //Counter initialized to 0

    printf("Enter up to 15 non-zero numbers.  Enter zero to signal the end of data or enter all 15 items:\n");

    while (i < 15 && userInput != 0)            //Loop until 15 iterations, or user inputs zero to quit
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

    for (unsigned int j = 0; j < nums.size(); j++)       //Loop once for each integer held in the nums vector
    {
        cout << " " << nums[j];                 //Output values to console in one line, separated by spaces
    }

    cout << endl;                               //Add endline to separate outputs  
    max = nums.at(0);
    min = nums.at(0);

    for (unsigned int k = 0; k < nums.size(); k++)       //Iterate through nums vector to find minimum and maximum values stored
    {
        if (nums[k] > max)
        {
            max = nums[k];
        }
        if (nums[k] < min)
        {
            min = nums[k];
        }
    }
    cout << "The maximum value is: " << max << endl;    //Print maximum value to console
    cout << "The minimum value is: " << min << endl;    //Print minimum value to console

    return 0;
}