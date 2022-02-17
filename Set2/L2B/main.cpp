#include <cstdlib>
#include <random>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

bool inclusiveMax, inclusiveMin;
int minInt, maxInt;
float minFloat, maxFloat;
char choiceMax, choiceMin;

void generate_random_integer(int minInt, int maxInt, bool inclusiveMax, bool inclusiveMin)
{
    //Function takes in a minimum and maximum integer value, as well as two booleans to determine whether the user wants these values to be inclusive or not.
    //Prints a randomly generated integer within the range out to the console
    int randInt = rand() % ((maxInt - inclusiveMax) - (minInt + inclusiveMin) + 1) + (minInt + inclusiveMin);
    cout << "\tRandomly generated integer: " << randInt << endl;      
}

void generate_random_float(float minFloat, float maxFloat, bool inclusiveMax, bool inclusiveMin)
{
    //Function takes in a minimum and maximum float value, as well as two booleans to determine whether the user wants these values to be inclusive or not.
    //Prints a randomly generated float within the range out to the console
    float randFloat = float(rand()) / float(RAND_MAX) * ((maxFloat - 0.001*inclusiveMax) - (minFloat + 0.001*inclusiveMin)) + (minFloat + 0.001*inclusiveMin);
    cout << fixed << setprecision(3) << "\tRandomly generated float: " << randFloat << endl; //Formats float output to print out to 3 decimal places
}


int main()
{
    srand(time(NULL));
    
    printf("Enter minimum integer for your range: ");                       //Ask user for their input
    scanf("%d", &minInt);                                                   //Take in value from user for minimum integer
    printf("Do you want this minimum integer to be inclusive? (Y/N): ");    //Ask user if they want this value to be inclusive
    invalidMinInteger:                                                      
    scanf(" %c", &choiceMin);

    //Switch statement to evaluate the boolean variable that determines whether the range is inclusive or not
    switch(choiceMin)
    {
        case 'Y':
            inclusiveMin = 0;
            break;
        case 'y':
            inclusiveMin = 0;
            break;
        case 'N':
            inclusiveMin = 1;
            break;
        case 'n':
            inclusiveMin = 1;
            break;
        default:
            printf("Invalid selection, enter (Y/N)");
            goto invalidMinInteger;                                        //Send user back to line 38 if they enter an invalid response
    }

    printf("Enter maximum integer for your range: ");                       //Ask user for their input
    scanf("%d", &maxInt);                                                   //Take in value from user for minimum integer
    printf("Do you want this maximum integer to be inclusive? (Y/N): ");    //Ask user if they want this value to be inclusive
    invalidMaxInteger: 
    scanf(" %c", &choiceMax);
    switch(choiceMax) {
        case 'Y':
            inclusiveMax = 0;
            break;
        case 'y':
            inclusiveMax = 0;
            break;
        case 'N':
            inclusiveMax = 1;
            break;
        case 'n':
            inclusiveMax = 1;
            break;
        default:
            printf("Invalid selection, enter (Y/N)");
            goto invalidMaxInteger;                                        //Send user back to line 64 if they enter an invalid response
    }

    //Print out 10 integers within the range that the user selected.
    for (int i = 0; i < 10; i++) {
        generate_random_integer(minInt, maxInt, inclusiveMax, inclusiveMin);
    }

    printf("Enter minimum float for your range: ");                         //Ask user for their input
    scanf("%f", &minFloat);                                                 //Take in value from user for minimum integer
    printf("Do you want this minimum float to be inclusive? (Y/N): ");      //Ask user if they want this value to be inclusive
    invalidMinFloat:
    scanf(" %c", &choiceMin);
    switch(choiceMin) {
        case 'Y':
            inclusiveMin = 0;
            break;
        case 'y':
            inclusiveMin = 0;
            break;
        case 'N':
            inclusiveMin = 1;
            break;
        case 'n':
            inclusiveMin = 1;
            break;
        default:
            printf("Invalid selection, enter (Y/N)");
            goto invalidMinFloat;                                           //Send user back to line 92 if they enter an invalid response
    }

    printf("Enter maximum float for your range: ");                         //Ask user for their input
    scanf("%f", &maxFloat);                                                 //Take in value from user for minimum integer
    printf("Do you want this maximum float to be inclusive? (Y/N): ");      //Ask user if they want this value to be inclusive
    invalidMaxFloat:
    scanf(" %c", &choiceMax);
    switch(choiceMax) {
        case 'Y':
            inclusiveMax = 0;
            break;
        case 'y':
            inclusiveMax = 0;
            break;
        case 'N':
            inclusiveMax = 1;
            break;
        case 'n':
            inclusiveMax = 1;
            break;
        default:
            printf("Invalid selection, enter (Y/N)");
            goto invalidMaxFloat;                                           //Send user back to line 115 if they enter an invalid response
    }
    //Print out 10 float values within the range that the user selected
    for (int j = 0; j < 10; j++) {
        generate_random_float(minFloat, maxFloat, inclusiveMax, inclusiveMin);
    }
    
    return 0;
    
}