
#include <cstdlib>
#include <random>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

bool inclusive1, inclusive2;
int minInt, maxInt;
float minFloat, maxFloat;
char choice1, choice2;

int generate_random_integer(int minInt, int maxInt, bool inclusive1){
    // srand(time(0));
    int randInt = rand() % (maxInt - minInt + inclusive1) + minInt;
    cout << "Randomly generated integer: " << randInt << endl;

    return 0;      
}

float generate_random_float(float minFloat, float maxFloat, bool inclusive2) {
    // srand(time(0));
    float randFloat = rand() / double(RAND_MAX) * (maxFloat - minFloat - 1 + inclusive2) + minFloat;
    cout << fixed << setprecision(3) << " Randomly generated float: " << randFloat << endl;

    return 0;
}


int main(){

    printf("Enter minimum integer for your range: \n");
    scanf("%d",&minInt);
    printf("Enter maximum integer for your range: \n");
    scanf("%d",&maxInt);

    printf("Do you want this range to be inclusive? (Y/N): ");
    scanf(" %c", choice1);
    switch(choice1) {
        case 'Y':
            inclusive1 = 1; break;
        case 'N':
            inclusive1 = 0; break;
    }

    for (int i = 0; i < 10; i++) {
        generate_random_integer(minInt, maxInt, inclusive1);
    }

    printf("Enter minimum float for your range: \n");
    scanf("%f",&minFloat);
    printf("Enter maximum float for your range: \n");
    scanf("%f",&maxFloat);

    printf("Do you want this range to be inclusive? (Y/N): ");
    scanf(" %c", choice2);
    switch(choice2) {
        case 'Y':
            inclusive2 = 1; break;
        case 'N':
            inclusive2 = 0; break;
    }
    
    for (int j = 0; j < 10; j++) {
        generate_random_float(minFloat, maxFloat, inclusive2);
    }
    
    return 0;
    
}