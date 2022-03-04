/* CSCI 261: Assignment 3: A3 - Green Eggs and Ham
 *
 * Author: Nick Willis
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *     // In class lectures
 *     // cplusplus.com for proper syntax and functionality of libraries
 *     // stackoverflow.com for troubleshooting and help with syntax errors
 *
 * This program reads in an input file, removes all punctuation characters, capitalizes all characters, counts number of unique words in input file's text,
 * and then prints statistics to the user's console about various things
 */
#include "word_functions.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    // get filename to open
    string filename;
    if(argc == 1) {
        filename = prompt_user_for_filename();
    } else if(argc == 2) {
        filename = argv[1];
    } else {
        cerr << "Usage: " << argv[0] << " [filename]" << endl;
        cerr << "  filename   - optional file to open upon start" << endl;
        return -2;
    }
    
    // open file for parsing
    ifstream fileIn;
    if( !open_file(fileIn, filename) ) {
        cerr << "Could not open file \"" << filename << "\"" << endl;
        cerr << "Shutting down" << endl;
        return -1;
    }

    // read all the words in the file
    vector<string> allWords = read_words_from_file( fileIn );
    fileIn.close();
    cout << "Read in " << allWords.size() << " words" << endl;


    // // clean the words to remove punctuation and convert to uppercase
    remove_punctuation(allWords, "?!.,;:\"()_-'");
    capitalize_words(allWords);

    // find only the unique words in the file
    vector<string> uniqueWords = filter_unique_words(allWords);
    cout << "Encountered " << uniqueWords.size() << " unique words" << endl;

    // count the occurrences of every letter in the entire text
    unsigned int letters[26] = {0};
    count_letters(letters, allWords);
    print_letter_counts(letters);

    // print statistics on letter frequencies
    print_max_min_letter(letters);

    return 0;
}
