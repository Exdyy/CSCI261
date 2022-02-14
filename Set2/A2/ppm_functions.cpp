
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
        case 1:
        {
            imageFile.open("brick.ppm");

            if (imageFile.is_open()){
                printf("Opening brick.ppm file\n");

                switch(opNum){

                    case 1: 
                    {
                        modifiedImage.open("brick_grayscale.ppm");

                        if (modifiedImage.is_open())
                        {
                            printf("Writing brick_grayscale.ppm file\n");
                            open = true;
                            break;

                        } else 
                        {
                            cerr << "Error opening output file\n";
                            open = false;
                            break;
                        }
                    }
                    case 2:{
                        modifiedImage.open("brick_inverted.ppm");

                        if (modifiedImage.is_open())
                        {
                            printf("Writing brick_inverted.ppm file\n");
                            open = true;
                            break;

                        } else 
                        {
                            cerr << "Error opening output file\n";
                            open = false;
                            break;
                        }
                    }
                }
            } else 
            {
                open = false;
                break;
            }
            break;
        }
        case 2:
        {
            imageFile.open("wallpaper.ppm");
            if (imageFile.is_open()){
                printf("Opening wallpaper.ppm file\n");

                switch(opNum)
                {
                    case 1:
                    {
                        modifiedImage.open("wallpaper_grayscale.ppm");

                        if (modifiedImage.is_open())
                        {
                            printf("Writing wallpaper_grayscale.ppm file\n");
                            open = true;
                            break;
                        } else 
                        {
                            cerr << "Error opening output file\n";
                            open = false;
                            break;
                        }
                    }
                    case 2:
                    {
                        modifiedImage.open("wallpaper_inverted.ppm");

                        if (modifiedImage.is_open())
                        {
                            printf("Writing wallpaper_inverted.ppm file\n");
                            open = true;
                            break;

                        } else 
                        {
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
        case 3:
        {
            imageFile.open("private.ppm");

            if (imageFile.is_open())
            {
                printf("Opening private.ppm file\n");

                switch(opNum){
                    case 1:
                    {
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

                    case 2:
                    {
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
            } else 
            {
                printf("Error opening input file");
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
    
    do 
    {
        (getline(imageFile, temp));
        switch(i)
        {
            case 0:

                pType = temp;
                break;
            case 1:
            {
                stringstream line2 (temp);
                while (line2 >> sizeNums)
                {
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
    } while (i<=2);
    if (pType == "P3")
    {
        valid = true;
    } else 
    {
        printf("Invalid file type");
        valid = false;
        abort();
    }
    return valid;
    
}

void read_and_write_modified_pixels(ifstream& imageFile, ofstream& modifiedImage, int opNum, int width, int height, int maxVal)
{
    int pixCount = 0;
    int lineCount = 0;
    int grayPixel;
    string line;
    vector<int> newPixels = {0, 0, 0};
    while (getline(imageFile, line))
    { 
        switch(opNum)
        {
            case 1:
                if (pixCount == 3)
                {
                    grayPixel = newPixels[0] + newPixels[1] + newPixels[2];
                    pixCount = 0;
                    modifiedImage << grayPixel << endl;
                    modifiedImage << grayPixel << endl;
                    modifiedImage << grayPixel << endl;
                    newPixels = {0, 0, 0};
                }
                if (lineCount % 3 == 0)
                {
                    int r = stoi(line) * 0.2989;
                    newPixels[0] = r;
                } else if (lineCount % 3 == 1)
                {
                    int g = stoi(line) * 0.5870;
                    newPixels[1] = g;
                } else 
                {
                    int b = stoi(line) * 0.1140;
                    newPixels[2] = b;
                }
                pixCount++;
                lineCount++;
                break;

            case 2:
                modifiedImage << maxVal - stoi(line) << endl;
                break;
        }
    }
    if (opNum == 3)
    {
        modifiedImage << grayPixel << endl;
        modifiedImage << grayPixel << endl;
        modifiedImage << grayPixel << endl;
    }
        
    modifiedImage.close();
    printf("\n***IMAGE CONVERSION COMPLETE***\n");
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

    

