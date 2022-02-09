#include <string> 
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

string imageSelection;
int userSelection;

void get_user_input(int min, int max) {
    invalidInput:
    scanf("%d", &userSelection);
    if (userSelection < min || userSelection > max){
        printf("Invalid selection. Please try again.\n");
        goto invalidInput;
    }

}

void print_file_options(){

    printf("which image to load?\n");
    printf("1: Brick\n");
    printf("2: Wallpaper\n");
    printf("3: Private\n");
    get_user_input(1, 3);

    switch(userSelection) {
        case 1: imageSelection = "brick";
        case 2: imageSelection = "wallpaper";
        case 3: imageSelection = "private";
    }
}

void print_operation_options(int){

    printf("which image to load?\n");
    printf("1: Brick\n");
    printf("2: Wallpaper\n");
    printf("3: Private\n");
    invalidSelection:
    scanf("%d", &userSelection);
}