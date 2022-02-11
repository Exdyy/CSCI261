
#include "ppm_functions.h"

using namespace std;
int userSelection;
int imageNum;
int opNum;
string imageSelection;
string opSelection;
ifstream imageFile;
ofstream modifiedImage;
int width = 0;
int height = 0;
int maxVal = 0;

int get_user_input(int min, int max)
{


    invalidInput:
    cin >> userSelection;
    if (userSelection < min || userSelection > max){
        printf("Invalid selection. Please try again.\n");
        goto invalidInput;
    } else 
    return userSelection;
}

int print_file_options()
{

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

bool read_header_information(ifstream& imageFile, int &width, int &height, int &maxVal)

{
    string pType;
    string temp;
    int i = 0;
    int sizeNums;
    vector<int> size;
    bool valid;
    
    while (getline(imageFile, temp) && i < 3)
    {
            switch(i)
            {
                case 0:

                    pType = temp;
                    break;
                case 1:
                {
                    stringstream line2 (temp);
                    while (line2 >> sizeNums){
                        size.push_back(sizeNums);
                    }
                    width = size.at(0);
                    height = size.at(1);
                    break;
                }
                case 2: 

                    maxVal = stoi(temp);
                    break;

                default:
                    break;

            }
            i++;
    }
    if (pType == "P3")
    {
        printf("Valid P3 format\n");
        valid = true;
    } else {
        printf("Invalid file type");
        valid = false;
    }
    imageFile.clear();
    return valid;
}

void read_and_write_modified_pixels(ifstream& imageFile, ofstream& modifiedImage, int opNum, int width, int height, int maxVal)
{
    int lineCount = 0;
    string line;
    while (getline(imageFile, line))
    {
        if(lineCount < 3)
        {
            lineCount++;
            continue;
        } else {
            switch(opNum){
                case 1:
                if (lineCount % 3 == 0){
                    modifiedImage << int(stoi(line) * 0.2989) << endl;
                    
                } else if (lineCount % 3 == 1){
                    modifiedImage << int(stoi(line) * 0.5870) << endl;
                    
                } else {
                    modifiedImage << int(stoi(line) * 0.1140) << endl;
    
                }
                lineCount++;
                break;

                case 2:
                if (lineCount % 3 == 0){
                    modifiedImage << maxVal - stoi(line) << endl;
                   
                } else if (lineCount % 3 == 1){
                    modifiedImage << maxVal - stoi(line) << endl;
                   
                } else {
                    modifiedImage << maxVal - stoi(line) << endl;
                 
                }
                lineCount++;
                break;
            }
                    
        }
        
    }
    modifiedImage.close();
}
void write_header_information(ofstream& modifiedImage, int width, int height, int maxVal)
{
    modifiedImage << "P3" << endl;
    modifiedImage << width << " " << height << endl;
    modifiedImage << maxVal << endl;
    read_and_write_modified_pixels(imageFile, modifiedImage, opNum, width, height, maxVal);
}


int print_operation_options()
{

    printf("Which operation would you like to perform?\n");
    printf("1: Convert to Grayscale\n");
    printf("2: Invert Colors\n");
    get_user_input(1, 2);
    switch(userSelection)
    {
        case 1: 
            opSelection = "grayscale"; opNum = 1;
            open_files(imageNum, opNum);
            read_header_information(imageFile, width, height, maxVal);
            write_header_information(modifiedImage, width, height, maxVal);
            break;
        case 2:
            opSelection = "inverted"; opNum =2;
            open_files(imageNum, opNum);
            read_header_information(imageFile, width, height, maxVal);
            write_header_information(modifiedImage, width, height, maxVal);
            break;
    }
    return opNum;
}

    

