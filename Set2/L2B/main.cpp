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

int generate_random_integer(int minInt, int maxInt, bool inclusiveMax, bool inclusiveMin){
    
    int randInt = rand() % ((maxInt - inclusiveMax) - (minInt + inclusiveMin) + 1) + (minInt + inclusiveMin);
    cout << "\tRandomly generated integer: " << randInt << endl;
    return 0;      
}

float generate_random_float(float minFloat, float maxFloat, bool inclusiveMax, bool inclusiveMin){
    
    float randFloat = float(rand()) / float(RAND_MAX) * ((maxFloat - 0.001*inclusiveMax) - (minFloat + 0.001*inclusiveMin)) + (minFloat + 0.001*inclusiveMin);
    cout << fixed << setprecision(3) << "\tRandomly generated float: " << randFloat << endl;

    return 0;
}


int main(){

    srand(time(NULL));
    
    printf("Enter minimum integer for your range: ");
    scanf("%d", &minInt);
    printf("Do you want this minimum integer to be inclusive? (Y/N): ");
    invalidMinInteger:
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
            goto invalidMinInteger;
    }

    printf("Enter maximum integer for your range: ");
    scanf("%d", &maxInt);
    printf("Do you want this maximum integer to be inclusive? (Y/N): ");
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
            goto invalidMaxInteger;
    }


    for (int i = 0; i < 10; i++) {
        generate_random_integer(minInt, maxInt, inclusiveMax, inclusiveMin);
    }

    printf("Enter minimum float for your range: ");
    scanf("%f", &minFloat);
    printf("Do you want this minimum float to be inclusive? (Y/N): ");
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
            goto invalidMinFloat;
    }

    printf("Enter maximum float for your range: ");
    scanf("%f", &maxFloat);
    printf("Do you want this maximum float to be inclusive? (Y/N): ");
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
            goto invalidMaxFloat;
    }
    
    for (int j = 0; j < 10; j++) {
        generate_random_float(minFloat, maxFloat, inclusiveMax, inclusiveMin);
    }
    
    return 0;
    
}