#include <iostream> 
#include <fstream>
/* CSCI 261: Lab 2A
 *
 *     //Author: Nick Willis
 *     //lecture materials
 *     //https://youtu.be/KJgsSFOSQv0 - C++ tutorial video
 * 
 * This program reads an input file, applies transformations to each character depending on what their individual values are, and writes a new, deciphered text file as an output.
 */
using namespace std;

int main() {
    // Open secretMessage.txt to read and create decipheredMessage.txt to write to. 
    ofstream decipheredMessage("decipheredMessage.txt");
    ifstream secretMessage("secretMessage.txt");
    char c; // Initialize character variable to store values in.
    
    // Check to see if input file opens properly. Print error message if it does not.
    if (!secretMessage) {
        cerr << "Error opening input file";
        return -1;
    }

    if ( decipheredMessage.fail() ) {
        cerr << "Error opening output file~";
        return -1;
    }


    if (secretMessage.is_open()) { // If input file is open, run the following code
        printf("DEBUG: secretMessage is open\n");
        while (!secretMessage.eof()) { // Parse through each character of the input file
            secretMessage.get(c);      // Store character in variable c
            printf("c: %c\n", c);

            // Switch statement writes to output file after checking whether input file character is equal to a space (' '), newline ('\n'), or any other character.
            switch (c) {
                case '~':
                decipheredMessage << ' ';
                break;

                case '\n':
                decipheredMessage << '\n';
                break;

                default:
                decipheredMessage << (char)(c + 1);
                break;

            }
        }

    }

        secretMessage.close();
        decipheredMessage.close();


        return 0;
}