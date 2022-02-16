#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(){

    int userInput = -1;
    vector<int> nums;
    int i = 0;
    printf("Enter up to 15 non-zero numbers.  Enter zero to signal the end of data or enter all 15 items:\n");
    while (i<15 && userInput != 0)
    {
        cout << "Number " << i + 1 << ": ";
        cin >> userInput;
        if (userInput != 0)
        {
        nums.push_back(userInput);
        }
        i++;
    }
    cout << "The numbers are:";
    for (unsigned int j = 0; j < nums.size(); j++)
    {
        cout << " " << nums[j];
    }
    return 0;
}