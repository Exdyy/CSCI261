/* CSCI 261: Assignment 2: A2 - PPM Image Editor
 *
 *     //Author: Nick Willis
 *     //cplusplus.com for information on string, vector, and stringstream methods
 *     //lecture materials
 *     //https://youtu.be/KJgsSFOSQv0 - C++ tutorial video
 * 
 * This program takes in user selection for an image file, and a conversion type. It reads in the input file, completes the conversion using functions defined in the ppm_functions.cpp file,
 * and writes a new modified image file with the pixel conversion applied.
 */
#include "ppm_functions.h"
using namespace std;

int main()
{
    print_file_options();
    print_operation_options();
    
    return 0;
}

    