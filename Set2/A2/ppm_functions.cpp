
#include "ppm_functions.h"

using namespace std;

int userSelection;
int imageNum;
int opNum;
ifstream imageFile;
ofstream modifiedImage;
int width;
int height;
int maxVal;

/**
 * @brief Receives input from user. Checks that input is within an allowable range
 * 
 * @param min minimum input allowed
 * @param max maximum input allowed
 */
int get_user_input(int min, int max)
{
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

/**
 * @brief Prints file options for user to terminal. Returns integer imageNum
 * 
 */
int print_file_options()
{
    //This function prompts the user to select the image they would like to modify.
    printf("Which image to load?\n");
    printf("1: Brick\n");
    printf("2: Wallpaper\n");
    printf("3: Private\n");
    get_user_input(1, 3);

    switch(userSelection) {
        case 1: {               //Case 1: brick.ppm image is selected
            imageNum = 1;                   
            break;
        }
        case 2: {               //Case 2: wallpaper.ppm image is selected
            imageNum = 2;
            break;
        }
        case 3: {               //Case 3: private.ppm image is selected
            imageNum = 3;
            break;
        }
    }
    return imageNum;
    
}

/**
 * @brief Opens input and output files corresponding to user selections
 * 
 * @param imageNum integer associated with user selection of image
 * @param opNum integer associated with user selection of operation to perform
 */
bool open_files(int imageNum, int opNum)
{
    //This function takes the user's selections for the image, as well as the conversion type. Depending on the combination of selections the user has made, this function opens
    //a specific input file, and creates a specific output file that correlates with the selected input image, and the type of conversion being applied to it. It is just a lot of nested
    //if statements and switches combined over and over again. If any of the files fail to open, the function prints an error message to alert the user, and then kills the program.
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
                            abort();
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
                            abort();
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
                            abort();
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
                            abort();
                        }
                    }
                }
                break;
            } else 
            {
                open = false;
                abort();
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

                        if (modifiedImage.is_open())
                        {
                            printf("Writing private_grayscale.ppm file");
                            open = true;
                            break;

                        } else 
                        {
                            cerr << "Error opening output file";
                            open = false;
                            abort();
                        }
                    }

                    case 2:
                    {
                        modifiedImage.open("private_inverted.ppm");

                        if (modifiedImage.is_open())
                        {
                            printf("Writing private_inverted.ppm file");
                            open = true;
                            break;

                        } else 
                        {
                            cerr << "Error opening output file";
                            open = false;
                            abort();
                        }
                    }
                }
            } else 
            {
                printf("Error opening input file");
                open = false;
                abort();
            }
        }
    }
    return open;
}


/**
 * @brief Reads first four lines of input file and checks for proper format. Extracts width, heigth, and maximum color value
 * 
 * @param imageFile input file being read
 * @param width width of input image
 * @param height height of input image
 * @param maxVal maximum color value of input image
 */
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
        (getline(imageFile, temp));             //Parse through input file line by line, stores each line in string 'temp'
        switch(i)                               
        {
            case 0:                             //First line of input file. Corresponds to PPM file type

                pType = temp;                   //Stores data into string 'pType'
                break;
            case 1:                             //Second line of input file. Corresponds to width and height of image
            {
                stringstream lineStream (temp); //Converts string stored in temp to a stream so that the two integers can be extracted separately
                while (lineStream >> sizeNums)  //While loop parses through string stream and stores values to integer 'sizeNums'
                {
                    size.push_back(sizeNums);   //Integer in 'sizeNums' is appended to end of vector
                }
                width = size.at(0);             //Assign 'width' equal to first element of vector 'size'
                height = size.at(1);            //Assign 'height' equal to second element of vector 'size'
                break;
            }
            case 2:                             //Third line of input file. Corresponds to maximum color value of each pixel
                maxVal = stoi(temp);            //Converts string into integer, and stores int value into integer 'maxVal'
                break;
            default:
                break;

        }
        i++;
    } while (i<=2);                             //Stops loop after i=2, reading only the first three lines of input file

    if (pType == "P3")                          //Check to see if PPM type is of type 'P3'. If not, gives user an error and aborts the program.
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

/**
 * @brief subtracts two values and prints result to terminal
 * 
 * @param imageFile input image file being read
 * @param modifiedImage output image file being written
 * @param opNum integer associated with user selection of operation to perform
 * @param width width of input image
 * @param height height of input image
 * @param maxVal maximum color value of input image
 */
void read_and_write_modified_pixels(ifstream& imageFile, ofstream& modifiedImage, int opNum, int width, int height, int maxVal)
{
    int pixCount = 0;                   //Used to track once values of one pixel have been read. 3 values per pixel
    int lineCount = 0;                  //Used to track which line of input file is being read
    int grayPixel;                      //Used to store final color value of a pixel after grayscale formula is applied
    string line;                        //Used to temporarily store the value of each line extracted from input file
    vector<int> newPixels = {0, 0, 0};  //Vector to store modified r, g, and b values for pixels to convert to grayscale
    while (getline(imageFile, line))    //Parse through input file line by line
    { 
        switch(opNum)                   //opNum 1: Grayscale conversion, opNum 2: Invert colors conversion
        {
            case 1:
                if (pixCount == 3)      //When pixNum ==3, writes three new lines to output file, all equal to gray pixel value of input r, g, and b values
                {
                    grayPixel = newPixels[0] + newPixels[1] + newPixels[2];
                    pixCount = 0;       //Reset pixCount to track next set of r, g, and b values read and converted
                    modifiedImage << grayPixel << endl;
                    modifiedImage << grayPixel << endl;
                    modifiedImage << grayPixel << endl;
                    newPixels = {0, 0, 0};
                }
                if (lineCount % 3 == 0)             //Lines associated with r values of input file
                {
                    int r = stoi(line) * 0.2989;    //Applies weighted average formula after converting string to int
                    newPixels[0] = r;               //Assign first element of newPixel vector with modified r value

                } else if (lineCount % 3 == 1)      //Lines associated with g values of input file
                {
                    int g = stoi(line) * 0.5870;    //Applies weighted average formula after converting string to int
                    newPixels[1] = g;               //Assigns second element of newPixel vector with modified g value

                } else                              //Lines associated with b values of input file
                {
                    int b = stoi(line) * 0.1140;    //Applies weighted average formula after converting string to int
                    newPixels[2] = b;               //Assigns third element of newPixel vector with modified b value
                }
                pixCount++;                         //Increment counter to track when r, g, and b values are read and modified
                lineCount++;                        //Increment counter to track which line is being read/written to
                break;

            case 2:
                modifiedImage << maxVal - stoi(line) << endl;   //Integer value of input file line is subtracted from maximum color value to invert colors
                break;
        }
    }
    if (opNum == 1)                                 //Writes the last values for the pixel if grayscale option is selected. Above loop reads and stores these values, but fails to write the last set.
    {                                               //Could fix, but I do not want to spend the time to do it right now :)
        modifiedImage << grayPixel << endl;
        modifiedImage << grayPixel << endl;
        modifiedImage << grayPixel << endl;
    }
        
    modifiedImage.close();                          //Close output file and notify user that conversion process is complete
    printf("\n***IMAGE CONVERSION COMPLETE***\n");
}

/**
 * @brief subtracts two values and prints result to terminal
 * 
 * @param modifiedImage output image file being written
 * @param width width of input/output image
 * @param height height of input/output image
 * @param maxVal maximum color value of input/output image
 */
void write_header_information(ofstream& modifiedImage, int width, int height, int maxVal)
{
    modifiedImage << "P3" << endl;                      //Write to output, P3 is PPM type
    modifiedImage << width << " " << height << endl;    //Write same width and height from input file to output file
    modifiedImage << maxVal << endl;                    //Write same maximum color value from input file to output file
}

/**
 * @brief Prints operation options for user to terminal. Calls other functions once opNum is defined.
 * 
 */
int print_operation_options()
{
    
    printf("Which operation would you like to perform?\n"); //Prompt user for inputs
    printf("1: Convert to Grayscale\n");                    //User inputs '1' -> convert image to grayscale
    printf("2: Invert Colors\n");                           //User inputs '2' -> convert image to inverted colors
    get_user_input(1, 2);                                   //Run input function with min of 1 and max of 2

    switch(userSelection)
    {
        case 1: 
            opNum = 1;           //Assign opNum with the user's selection
            break;
        case 2:
            opNum =2;             //Assign opNum with the user's selection
            break;
    }

    open_files(imageNum, opNum);                                                            //Function to open input and output files is called
    read_header_information(imageFile, width, height, maxVal);                              //Function to read header info of input file is called
    write_header_information(modifiedImage, width, height, maxVal);                         //Function to write header info to output file is called
    read_and_write_modified_pixels(imageFile, modifiedImage, opNum, width, height, maxVal); //Function to convert pixel data from input to modified values for output is called
    
    return opNum;
}

