
#include "ppm_functions.h"

using namespace std;
int userSelection;
int imageNum;
int opNum;
string imageSelection;
string opSelection;
ifstream imageFile;
ofstream modifiedImage;

int get_user_input(int min, int max) {


    invalidInput:
    cin >> userSelection;
    if (userSelection < min || userSelection > max){
        printf("Invalid selection. Please try again.\n");
        goto invalidInput;
    } else 
    return userSelection;
}

int print_file_options(){

    printf("Which image to load?\n");
    printf("1: Brick\n");
    printf("2: Wallpaper\n");
    printf("3: Private\n");
    get_user_input(1, 3);

    switch(userSelection) {
        case 1: {
            imageSelection = "brick";
            imageNum = 1;
            break;
        }
        case 2: {
            imageSelection = "wallpaper";
            imageNum = 2;
            break;
        }
        case 3: {
            imageSelection = "private";
            imageNum = 3;
            break;
        }
    }
    return imageNum;
    
}
bool open_files(int imageNum, int opNum)
{
    ifstream imageFile;
    ofstream modifiedImage;
    bool open;
    switch(imageNum){
        case 1:{
        imageFile.open("brick.ppm");

        if (imageFile.is_open()){
            printf("Opening brick.ppm file\n");

            switch(opNum){

                case 1: {
                modifiedImage.open("brick_grayscale.ppm");

                if (modifiedImage.is_open()){
                    printf("Writing brick_grayscale.ppm file\n");
                    open = true;
                    break;

                } else {
                    cerr << "Error opening output file\n";
                    open = false;
                    break;
                    }
                }
                case 2:{
                modifiedImage.open("brick_inverted.ppm");

                if (modifiedImage.is_open()){
                    printf("Writing brick_inverted.ppm file\n");
                    open = true;
                    break;

                } else {
                    cerr << "Error opening output file\n";
                    open = false;
                    break;
                    }
                }
            }
        } else {

            open = false;
            break;
        }
        break;
        }
        case 2:{
        imageFile.open("wallpaper.ppm");

        if (imageFile.is_open()){
            printf("Opening wallpaper.ppm file\n");

            switch(opNum){
                case 1:{
                modifiedImage.open("wallpaper_grayscale.ppm");

                if (modifiedImage.is_open()){
                    printf("Writing wallpaper_grayscale.ppm file\n");
                    open = true;
                    break;
                } else {
                    cerr << "Error opening output file\n";
                    open = false;
                    break;
                }
                }
                case 2:{
                modifiedImage.open("wallpaper_inverted.ppm");

                if (modifiedImage.is_open()){
                    printf("Writing wallpaper_inverted.ppm file\n");
                    open = true;
                    break;

                } else {
                    cerr << "Error opening output file\n";
                    open = false;
                    break;
                }
                }
            }
            break;
        } else {
            open = false;
            break;
            }
        }
        case 3:{
        imageFile.open("private.ppm");

        if (imageFile.is_open()){
            printf("Opening private.ppm file\n");

            switch(opNum){
                case 1:{
                modifiedImage.open("private_grayscale.ppm");

                if (modifiedImage.is_open()){
                    printf("Writing private_grayscale.ppm file");
                    open = true;
                    break;

                } else {
                    cerr << "Error opening output file";
                    open = false;
                    break;
                }
                }

                case 2:{
                modifiedImage.open("private_inverted.ppm");

                if (modifiedImage.is_open()){
                    printf("Writing private_inverted.ppm file");
                    open = true;
                    break;

                } else {
                    cerr << "Error opening output file";
                    open = false;
                    break;
                }
                }
            }
        } else {
            open = false;
            break;
        }
        }
    }
    return open;
}

int print_operation_options(){

    printf("Which operation would you like to perform?\n");
    printf("1: Convert to Grayscale\n");
    printf("2: Invert Colors\n");
    get_user_input(1, 2);
    switch(userSelection){
        case 1: 
            opSelection = "grayscale"; opNum = 1;
            open_files(imageNum, opNum);
            break;
        case 2:
            opSelection = "inverted"; opNum =2;
            open_files(imageNum, opNum);
            break;
    }
    return opNum;
}

// bool read_header_information(ifstream imageFile, int &width, int &height, int &maxVal)
// {
//     string pType;
//     fscanf(imageFile, "%s", &pType);
// }

void test()
{
    string line;
    while(!imageFile.eof())
    {
        getline(imageFile, line);
        printf("%s", line.c_str());
    }
    imageFile.close();
}
    

