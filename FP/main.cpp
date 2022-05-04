#include "Employee.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
int min;
int max;

int get_user_input(int min, int max){
    int userSelection;
    bool valid = false;                                         //Initialize boolean variable that checks for input validity
    while (valid == false)
    {
        cin >> userSelection;                                   //User inputs a value
        if (userSelection < min || userSelection > max)         //If value is below min or above max, boolean returns false and user is notified. Loop repeats
        {
            valid = false;
            printf("Invalid selection. Please try again.\n");
        } else 
        {
            valid = true;                                       //User inputs a valid value, boolean returns true and breaks out of loop
        }
    }
    return userSelection;
}

int main(){


    return 0;
}