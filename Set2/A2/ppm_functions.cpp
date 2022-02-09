#include <string> 
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

char c;
string imageSelection;
int userSelection;
int imageNum;
int opNum;
string opType;
ifstream imageFile;


void get_user_input(int min, int max) {
    
    invalidInput:
    scanf("%d", &userSelection);
    if (userSelection < min || userSelection > max){
        printf("Invalid selection. Please try again.\n");
        goto invalidInput;
    }

}

void print_file_options(){

    printf("Which image to load?\n");
    printf("1: Brick\n");
    printf("2: Wallpaper\n");
    printf("3: Private\n");
    get_user_input(1, 3);

    switch(userSelection) {
        case 1: 
            imageSelection = "brick";
            imageNum = 1;
            ifstream imageFile("brick.ppm");
        case 2:
            imageSelection = "wallpaper";
            imageNum = 2;
            ifstream imageFile("wallpaper.ppm");
        case 3:
            imageSelection = "private";
            imageNum = 3;
            ifstream imageFile("private.ppm")
    }
    
}

void print_operation_options(int){
    
    printf("Which operation would you like to perform?\n");
    printf("1: Convert to Grayscale\n");
    printf("2: Invert Colors\n");
    get_user_input(1, 2);
    switch(userSelection){
        case 1: 
            opType = "grayscale"; opNum = 1;
            if (imageNum == 1){
                ofstream modifiedImage("grayscale_brick.ppm");
            } else if (imageNum == 2){
                ofstream modifiedImage("grayscale_wallpaper.ppm");
            } else {
                ofstream modifiedImage("grayscale_private.ppm");
            }
        case 2:
            opType = "inverted"; opNum =2;
            if (imageNum == 1){
                ofstream modifiedImage("inverted_brick.ppm");
            } else if (imageNum == 2){
                ofstream modifiedImage("inverted_wallpaper.ppm");
            } else {
                ofstream modifiedImage("inverted_private.ppm");
            }
    }
}

bool open_files(ifstream image, ofstream modifiedImage, int imageNum, int opNum){
    
    if (!imageFile) {
        cerr << "Error opening input file";
        return false;
    } else {
        cout << "Opening %s.ppm file" << imageSelection << endl;
        if (!modifiedImage) {
            cerr << "Error opening output file";
            return false;
        } else {
            cout << "Writing to %s_%s.ppm file" << imageSelection << opType << endl;
            return true;
        }

    }
}

bool read_header_information(ifstream image, int &width, int &height, int &maxVal){
    vector<char> fileInfo;
    while (!imageFile.eof()){
        imageFile.get(c);
        fileInfo.push_back(c);
    }

}

